#include "../porting/lv_porting.h"
#include "lvgl.h"

#include "lvgl_app.h"

int main(int argc, char const *argv[])
{
    lv_porting_init();

    lvgl_app_watch_init();

    while (1) {
        lv_timer_handler();
        lv_porting_delay();
    }
}
