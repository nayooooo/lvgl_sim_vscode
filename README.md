# lvgl_sim_vscode

LVGL在VSCode上的模拟器

如果需要改变屏幕大小，请同时修改以下两个文件：

`./lv_drivers/lv_drv_conf.h`:

	#if USE_SDL || USE_SDL_GPU
	#  define SDL_HOR_RES     480
	#  define SDL_VER_RES     320

`./porting/lv_porting.c`:

	#define MONITOR_HOR_RES  480
	#define MONITOR_VER_RES  320
	#define MONITOR_BUF_SIZE MONITOR_HOR_RES * 10

