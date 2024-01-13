#include "lvgl_app.h"

#include <stdio.h>

static lv_obj_t *scr;

#if LVGL_APP_USE_SIM
static lv_style_t scr_border_style;
#endif  // LVGL_APP_USE_SIM

int lvgl_app_watch_init(void)
{
    /*************************************
     * create all screen
     *************************************/

    scr = lv_scr_act();

#if LVGL_APP_USE_SIM
    lv_style_set_radius(&scr_border_style, 120);
    lvgl_home_page_init(&scr_border_style);
    lvgl_config_page_init(&scr_border_style);
#else
    lvgl_home_page_init();
    lvgl_config_page_init();
#endif  // LVGL_APP_USE_SIM

    /*************************************
     * load
     *************************************/

    lvgl_home_page_load();

    return 0;
}
