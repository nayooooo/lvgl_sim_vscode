#include "lvgl_app.h"

static lv_obj_t *page;
static lv_obj_t *btn2home;
static lv_obj_t *btn2home_txt;

static void lvgl_page_event_cb(lv_event_t * e)
{
    lv_obj_t *target = lv_event_get_target(e);

    if (target == btn2home)
    {
        if (e->code == LV_EVENT_CLICKED)
        {
            lv_scr_load_anim(lvgl_get_home_page(), LV_SCR_LOAD_ANIM_OVER_LEFT, 900, 100, false);
        }
    }
}

#if LVGL_APP_USE_SIM
void lvgl_config_page_init(lv_style_t *scr_border_style)
#else
void lvgl_config_page_init(void)
#endif  // LVGL_APP_USE_SIM
{
    page = lv_obj_create(NULL);
#if LVGL_APP_USE_SIM
    lv_obj_add_style(page, scr_border_style, LV_STATE_DEFAULT);
#endif  // LVGL_APP_USE_SIM
    lv_obj_set_style_bg_color(page, lv_color_hex(0x55BB11), LV_STATE_DEFAULT);

    btn2home = lv_btn_create(page);
    lv_obj_set_size(btn2home, 80, 40);
    lv_obj_set_style_align(btn2home, LV_ALIGN_CENTER, LV_STATE_DEFAULT);
    lv_obj_set_pos(btn2home, 0, 0);
    btn2home_txt = lv_label_create(btn2home);
    lv_label_set_text(btn2home_txt, "home");
    lv_obj_add_event_cb(btn2home, lvgl_page_event_cb, LV_EVENT_CLICKED, NULL);
}

void lvgl_config_page_load(void)
{
    lv_scr_load(page);
}

lv_obj_t *lvgl_get_config_page(void)
{
    return page;
}
