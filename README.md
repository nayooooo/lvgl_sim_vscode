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

## 无法找到<SDL2/SDL.h>

下载`https://github.com/libsdl-org/SDL`的`mingw.zip`版本源代码，并将`x86_64-w64-mingw32`目录下的`include`和`lib`复制到`{mingw}/x86_64-w64-mingw32`的`include`和`lib`下。

## 没有找到makefile文件

可尝试使用`cmake .. -G "MinGW Makefiles"`生成构建文件
