#include "lvgl_app.h"

static lv_obj_t *page;
static lv_obj_t *btn2config;
static lv_obj_t *btn2config_txt;

static void lvgl_page_event_cb(lv_event_t * e)
{
    lv_obj_t *target = lv_event_get_target(e);

    if (target == btn2config)
    {
        if (e->code == LV_EVENT_CLICKED)
        {
            lv_scr_load_anim(lvgl_get_config_page(), LV_SCR_LOAD_ANIM_MOVE_RIGHT, 900, 100, false);
        }
    }
}

#if LVGL_APP_USE_SIM
void lvgl_home_page_init(lv_style_t *scr_border_style)
#else
void lvgl_home_page_init(void)
#endif  // LVGL_APP_USE_SIM
{
    page = lv_obj_create(NULL);
#if LVGL_APP_USE_SIM
    lv_obj_add_style(page, scr_border_style, LV_STATE_DEFAULT);
#endif  // LVGL_APP_USE_SIM
    lv_obj_set_style_bg_color(page, lv_color_hex(0xF4B183), LV_STATE_DEFAULT);

    btn2config = lv_btn_create(page);
    lv_obj_set_size(btn2config, 80, 40);
    lv_obj_set_style_align(btn2config, LV_ALIGN_CENTER, LV_STATE_DEFAULT);
    lv_obj_set_pos(btn2config, 0, 0);
    btn2config_txt = lv_label_create(btn2config);
    lv_label_set_text(btn2config_txt, "config");
    lv_obj_add_event_cb(btn2config, lvgl_page_event_cb, LV_EVENT_CLICKED, NULL);
}

void lvgl_home_page_load(void)
{
    lv_scr_load(page);
}

lv_obj_t *lvgl_get_home_page(void)
{
    return page;
}
