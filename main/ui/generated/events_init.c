/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "freertos/FreeRTOS.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

static void arrow_down_event_handler(lv_event_t * e) {
    lv_ui * ui = (lv_ui *) lv_event_get_user_data(e);
    lv_scr_load(ui->screen_SettingPage);  
}

static void arrow_up_event_handler(lv_event_t * e) {
    lv_ui * ui = (lv_ui *) lv_event_get_user_data(e);
    lv_scr_load(ui->screen_MeasurePage);  
}

void events_init(lv_ui *ui)
{      
    lv_obj_add_event_cb(ui->screen_MeasurePage_img_arrowDown, arrow_down_event_handler, LV_EVENT_CLICKED, ui);
    lv_obj_add_event_cb(ui->screen_SettingPage_img_arrowUp, arrow_up_event_handler, LV_EVENT_CLICKED, ui);
    
    lv_obj_move_foreground(ui->screen_MeasurePage_img_arrowDown);
}



