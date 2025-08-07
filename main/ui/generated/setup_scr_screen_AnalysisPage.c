/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_AnalysisPage(lv_ui *ui)
{
    //Write codes screen_AnalysisPage
    ui->screen_AnalysisPage = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_AnalysisPage, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen_AnalysisPage, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_AnalysisPage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage, 247, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_AnalysisPage, lv_color_hex(0x0a1414), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_AnalysisPage, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_img_arrowUp
    ui->screen_AnalysisPage_img_arrowUp = lv_img_create(ui->screen_AnalysisPage);
    lv_obj_add_flag(ui->screen_AnalysisPage_img_arrowUp, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_AnalysisPage_img_arrowUp, &_up_alpha_128x17);
    lv_img_set_pivot(ui->screen_AnalysisPage_img_arrowUp, 50,50);
    lv_img_set_angle(ui->screen_AnalysisPage_img_arrowUp, 0);
    lv_obj_set_pos(ui->screen_AnalysisPage_img_arrowUp, 176, 8);
    lv_obj_set_size(ui->screen_AnalysisPage_img_arrowUp, 128, 17);

    //Write style for screen_AnalysisPage_img_arrowUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_AnalysisPage_img_arrowUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_AnalysisPage_img_arrowUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_img_arrowUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_AnalysisPage_img_arrowUp, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_ddlist_file_in_SPIFFS
    ui->screen_AnalysisPage_ddlist_file_in_SPIFFS = lv_dropdown_create(ui->screen_AnalysisPage);
    lv_dropdown_set_options(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, "");
    lv_obj_set_pos(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 57, 67);
    lv_obj_set_size(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 226, 39);

    //Write style for screen_AnalysisPage_ddlist_file_in_SPIFFS, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked
    static lv_style_t style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked;
    ui_init_style(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS), &style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default
    static lv_style_t style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default;
    ui_init_style(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default);

    lv_style_set_max_height(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS), &style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_scrollbar_default
    static lv_style_t style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_scrollbar_default;
    ui_init_style(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS), &style_screen_AnalysisPage_ddlist_file_in_SPIFFS_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_btn_classify
    ui->screen_AnalysisPage_btn_classify = lv_btn_create(ui->screen_AnalysisPage);
    ui->screen_AnalysisPage_btn_classify_label = lv_label_create(ui->screen_AnalysisPage_btn_classify);
    lv_label_set_text(ui->screen_AnalysisPage_btn_classify_label, "Predict");
    lv_label_set_long_mode(ui->screen_AnalysisPage_btn_classify_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_AnalysisPage_btn_classify_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_AnalysisPage_btn_classify, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_AnalysisPage_btn_classify_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_AnalysisPage_btn_classify, 299, 84);
    lv_obj_set_size(ui->screen_AnalysisPage_btn_classify, 152, 38);

    //Write style for screen_AnalysisPage_btn_classify, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_btn_classify, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_AnalysisPage_btn_classify, lv_color_hex(0xf8f9ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_AnalysisPage_btn_classify, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_btn_classify, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_AnalysisPage_btn_classify, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_AnalysisPage_btn_classify, lv_color_hex(0x5482a9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_AnalysisPage_btn_classify, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_btn_classify, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_btn_classify, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_btn_classify, lv_color_hex(0x150c37), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_btn_classify, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_btn_classify, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_btn_classify, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_1
    ui->screen_AnalysisPage_label_1 = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_1, "Select File:");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_1, 39, 38);
    lv_obj_set_size(ui->screen_AnalysisPage_label_1, 155, 20);

    //Write style for screen_AnalysisPage_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_1, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_1, &lv_font_montserratMedium_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_2
    ui->screen_AnalysisPage_label_2 = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_2, "");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_2, 119, 141);
    lv_obj_set_size(ui->screen_AnalysisPage_label_2, 242, 33);

    //Write style for screen_AnalysisPage_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_2, lv_color_hex(0x0094e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_2, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_2, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_AnalysisPage_label_2, lv_color_hex(0xf7f7f7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_AnalysisPage_label_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_3
    ui->screen_AnalysisPage_label_3 = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_3, "Gram Stain:");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_3, 90, 114);
    lv_obj_set_size(ui->screen_AnalysisPage_label_3, 141, 20);

    //Write style for screen_AnalysisPage_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_3, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_3, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_4
    ui->screen_AnalysisPage_label_4 = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_4, "Species:");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_4, 90, 178);
    lv_obj_set_size(ui->screen_AnalysisPage_label_4, 115, 20);

    //Write style for screen_AnalysisPage_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_4, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_4, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_5
    ui->screen_AnalysisPage_label_5 = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_5, "Concentrations:");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_5, 90, 242);
    lv_obj_set_size(ui->screen_AnalysisPage_label_5, 194, 20);

    //Write style for screen_AnalysisPage_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_5, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_5, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_6
    ui->screen_AnalysisPage_label_6 = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_6, "");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_6, 119, 203);
    lv_obj_set_size(ui->screen_AnalysisPage_label_6, 242, 33);

    //Write style for screen_AnalysisPage_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_6, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_6, lv_color_hex(0x0094e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_6, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_6, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_AnalysisPage_label_6, lv_color_hex(0xf7f7f7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_AnalysisPage_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_7
    ui->screen_AnalysisPage_label_7 = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_7, "");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_7, 119, 265);
    lv_obj_set_size(ui->screen_AnalysisPage_label_7, 242, 33);

    //Write style for screen_AnalysisPage_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_7, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_7, lv_color_hex(0x0094e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_7, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_7, 48, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_AnalysisPage_label_7, lv_color_hex(0xf7f7f7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_AnalysisPage_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_predicted_Gram
    ui->screen_AnalysisPage_label_predicted_Gram = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_predicted_Gram, "-");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_predicted_Gram, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_predicted_Gram, 172, 148);
    lv_obj_set_size(ui->screen_AnalysisPage_label_predicted_Gram, 141, 20);

    //Write style for screen_AnalysisPage_label_predicted_Gram, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_predicted_Gram, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_predicted_Gram, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_predicted_Gram, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_predicted_Gram, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_predicted_Gram, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_predicted_species
    ui->screen_AnalysisPage_label_predicted_species = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_predicted_species, "-");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_predicted_species, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_predicted_species, 172, 210);
    lv_obj_set_size(ui->screen_AnalysisPage_label_predicted_species, 141, 20);

    //Write style for screen_AnalysisPage_label_predicted_species, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_predicted_species, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_predicted_species, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_predicted_species, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_predicted_species, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_predicted_species, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_label_predicted_concentrations
    ui->screen_AnalysisPage_label_predicted_concentrations = lv_label_create(ui->screen_AnalysisPage);
    lv_label_set_text(ui->screen_AnalysisPage_label_predicted_concentrations, "-");
    lv_label_set_long_mode(ui->screen_AnalysisPage_label_predicted_concentrations, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_AnalysisPage_label_predicted_concentrations, 172, 272);
    lv_obj_set_size(ui->screen_AnalysisPage_label_predicted_concentrations, 141, 20);

    //Write style for screen_AnalysisPage_label_predicted_concentrations, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_label_predicted_concentrations, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_label_predicted_concentrations, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_label_predicted_concentrations, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_label_predicted_concentrations, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_label_predicted_concentrations, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_AnalysisPage_btn_upload
    ui->screen_AnalysisPage_btn_upload = lv_btn_create(ui->screen_AnalysisPage);
    ui->screen_AnalysisPage_btn_upload_label = lv_label_create(ui->screen_AnalysisPage_btn_upload);
    lv_label_set_text(ui->screen_AnalysisPage_btn_upload_label, "Mount");
    lv_label_set_long_mode(ui->screen_AnalysisPage_btn_upload_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_AnalysisPage_btn_upload_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_AnalysisPage_btn_upload, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_AnalysisPage_btn_upload_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_AnalysisPage_btn_upload, 325, 25);
    lv_obj_set_size(ui->screen_AnalysisPage_btn_upload, 100, 32);

    //Write style for screen_AnalysisPage_btn_upload, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_AnalysisPage_btn_upload, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_AnalysisPage_btn_upload, lv_color_hex(0x3f8def), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_AnalysisPage_btn_upload, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_AnalysisPage_btn_upload, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_AnalysisPage_btn_upload, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_AnalysisPage_btn_upload, lv_color_hex(0x5482a9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_AnalysisPage_btn_upload, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_AnalysisPage_btn_upload, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_AnalysisPage_btn_upload, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_AnalysisPage_btn_upload, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_AnalysisPage_btn_upload, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_AnalysisPage_btn_upload, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_AnalysisPage_btn_upload, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_AnalysisPage.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_AnalysisPage);

}
