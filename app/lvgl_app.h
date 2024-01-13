#ifndef __LVGL_APP_H__
#define __LVGL_APP_H__

#include "lvgl.h"

#define LVGL_APP_USE_SIM        (1)

int lvgl_app_watch_init(void);

#if LVGL_APP_USE_SIM
void lvgl_home_page_init(lv_style_t *scr_border_style);
void lvgl_config_page_init(lv_style_t *scr_border_style);
#else
void lvgl_home_page_init(void);
void lvgl_config_page_init(void);
#endif  // LVGL_APP_USE_SIM

void lvgl_home_page_load(void);
void lvgl_config_page_load(void);

lv_obj_t *lvgl_get_home_page(void);
lv_obj_t *lvgl_get_config_page(void);

#endif  // !__LVGL_APP_H__
