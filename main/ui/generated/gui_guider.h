/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen_MeasurePage;
	bool screen_MeasurePage_del;
	lv_obj_t *screen_MeasurePage_cont_1;
	lv_obj_t *screen_MeasurePage_bar_ch8;
	lv_obj_t *screen_MeasurePage_bar_ch7;
	lv_obj_t *screen_MeasurePage_label_1;
	lv_obj_t *screen_MeasurePage_bar_ch1;
	lv_obj_t *screen_MeasurePage_bar_ch4;
	lv_obj_t *screen_MeasurePage_bar_ch3;
	lv_obj_t *screen_MeasurePage_bar_ch5;
	lv_obj_t *screen_MeasurePage_bar_ch6;
	lv_obj_t *screen_MeasurePage_bar_ch2;
	lv_obj_t *screen_MeasurePage_label_2;
	lv_obj_t *screen_MeasurePage_label_3;
	lv_obj_t *screen_MeasurePage_label_4;
	lv_obj_t *screen_MeasurePage_label_5;
	lv_obj_t *screen_MeasurePage_label_6;
	lv_obj_t *screen_MeasurePage_label_7;
	lv_obj_t *screen_MeasurePage_label_8;
	lv_obj_t *screen_MeasurePage_bar_state;
	lv_obj_t *screen_MeasurePage_label_state;
	lv_obj_t *screen_MeasurePage_bar_temperature;
	lv_obj_t *screen_MeasurePage_bar_humidity;
	lv_obj_t *screen_MeasurePage_bar_pressure;
	lv_obj_t *screen_MeasurePage_label_temperature;
	lv_obj_t *screen_MeasurePage_label_9;
	lv_obj_t *screen_MeasurePage_label_10;
	lv_obj_t *screen_MeasurePage_label_11;
	lv_obj_t *screen_MeasurePage_label_humidity;
	lv_obj_t *screen_MeasurePage_label_pressure;
	lv_obj_t *screen_MeasurePage_img_arrowDown;
	lv_obj_t *screen_SettingPage;
	bool screen_SettingPage_del;
	lv_obj_t *screen_SettingPage_img_arrowDown;
	lv_obj_t *screen_SettingPage_img_arrowUp;
	lv_obj_t *screen_SettingPage_ta_sampleText;
	lv_obj_t *screen_SettingPage_label_1;
	lv_obj_t *screen_SettingPage_tileview_1;
	lv_obj_t *screen_SettingPage_tileview_1_tile_Prep;
	lv_obj_t *screen_SettingPage_tileview_1_tile_Meas;
	lv_obj_t *screen_SettingPage_tileview_1_tile_Clean;
	lv_obj_t *screen_SettingPage_ddlist_PrepDuration;
	lv_obj_t *screen_SettingPage_label_3;
	lv_obj_t *screen_SettingPage_label_4;
	lv_obj_t *screen_SettingPage_ddlist_MeasDuration;
	lv_obj_t *screen_SettingPage_label_5;
	lv_obj_t *screen_SettingPage_ddlist_CleanDuration;
	lv_obj_t *screen_SettingPage_btn_start;
	lv_obj_t *screen_SettingPage_btn_start_label;
	lv_obj_t *screen_SettingPage_label_2;
	lv_obj_t *screen_AnalysisPage;
	bool screen_AnalysisPage_del;
	lv_obj_t *screen_AnalysisPage_img_arrowUp;
	lv_obj_t *screen_AnalysisPage_ddlist_file_in_SPIFFS;
	lv_obj_t *screen_AnalysisPage_btn_classify;
	lv_obj_t *screen_AnalysisPage_btn_classify_label;
	lv_obj_t *screen_AnalysisPage_label_1;
	lv_obj_t *screen_AnalysisPage_label_2;
	lv_obj_t *screen_AnalysisPage_label_3;
	lv_obj_t *screen_AnalysisPage_label_4;
	lv_obj_t *screen_AnalysisPage_label_5;
	lv_obj_t *screen_AnalysisPage_label_6;
	lv_obj_t *screen_AnalysisPage_label_7;
	lv_obj_t *screen_AnalysisPage_label_predicted_Gram;
	lv_obj_t *screen_AnalysisPage_label_predicted_species;
	lv_obj_t *screen_AnalysisPage_label_predicted_concentrations;
	lv_obj_t *screen_AnalysisPage_btn_upload;
	lv_obj_t *screen_AnalysisPage_btn_upload_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen_MeasurePage(lv_ui *ui);
void setup_scr_screen_SettingPage(lv_ui *ui);
void setup_scr_screen_AnalysisPage(lv_ui *ui);
LV_IMG_DECLARE(_down_alpha_128x17);
LV_IMG_DECLARE(_down_alpha_128x17);
LV_IMG_DECLARE(_up_alpha_128x17);
LV_IMG_DECLARE(_up_alpha_128x17);

LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_23)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_17)
LV_FONT_DECLARE(lv_font_montserratMedium_22)


#ifdef __cplusplus
}
#endif
#endif
