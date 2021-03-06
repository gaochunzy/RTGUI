#include <rtthread.h>
#include "board.h"
#include <Windows.h>

void rt_platform_init(void)
{
#ifdef RT_USING_DFS
    /* initialize sd card */
    rt_hw_sdcard_init();

#if defined(RT_USING_MTD_NAND)
    rt_hw_mtd_nand_init();
#endif

#if defined(RT_USING_MTD_NOR)
    sst25vfxx_mtd_init("nor", 0, RT_UINT32_MAX);
#endif

#endif /* RT_USING_DFS */

#ifdef RT_USING_RTGUI
    /* start sdl thread to simulate an LCD */
    rt_hw_sdl_start();
#endif /* RT_USING_RTGUI */

#ifdef _WIN32
    rt_thread_idle_sethook(rt_hw_win32_low_cpu);
#endif
}

