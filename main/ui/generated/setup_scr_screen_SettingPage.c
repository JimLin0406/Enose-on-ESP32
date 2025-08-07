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



void setup_scr_screen_SettingPage(lv_ui *ui)
{
    //Write codes screen_SettingPage
    ui->screen_SettingPage = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_SettingPage, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen_SettingPage, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_SettingPage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_SettingPage, 247, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_SettingPage, lv_color_hex(0x0a1414), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_SettingPage, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_img_arrowDown
    ui->screen_SettingPage_img_arrowDown = lv_img_create(ui->screen_SettingPage);
    lv_obj_add_flag(ui->screen_SettingPage_img_arrowDown, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_SettingPage_img_arrowDown, &_down_alpha_128x17);
    lv_img_set_pivot(ui->screen_SettingPage_img_arrowDown, 50,50);
    lv_img_set_angle(ui->screen_SettingPage_img_arrowDown, 0);
    lv_obj_set_pos(ui->screen_SettingPage_img_arrowDown, 176, 295);
    lv_obj_set_size(ui->screen_SettingPage_img_arrowDown, 128, 17);

    //Write style for screen_SettingPage_img_arrowDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_SettingPage_img_arrowDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_SettingPage_img_arrowDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_img_arrowDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_SettingPage_img_arrowDown, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_img_arrowUp
    ui->screen_SettingPage_img_arrowUp = lv_img_create(ui->screen_SettingPage);
    lv_obj_add_flag(ui->screen_SettingPage_img_arrowUp, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_SettingPage_img_arrowUp, &_up_alpha_128x17);
    lv_img_set_pivot(ui->screen_SettingPage_img_arrowUp, 50,50);
    lv_img_set_angle(ui->screen_SettingPage_img_arrowUp, 0);
    lv_obj_set_pos(ui->screen_SettingPage_img_arrowUp, 176, 8);
    lv_obj_set_size(ui->screen_SettingPage_img_arrowUp, 128, 17);

    //Write style for screen_SettingPage_img_arrowUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_SettingPage_img_arrowUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_SettingPage_img_arrowUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_img_arrowUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_SettingPage_img_arrowUp, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_ta_sampleText
    ui->screen_SettingPage_ta_sampleText = lv_textarea_create(ui->screen_SettingPage);
    lv_textarea_set_text(ui->screen_SettingPage_ta_sampleText, "");
    lv_textarea_set_placeholder_text(ui->screen_SettingPage_ta_sampleText, "Sample name");
    lv_textarea_set_password_bullet(ui->screen_SettingPage_ta_sampleText, "*");
    lv_textarea_set_password_mode(ui->screen_SettingPage_ta_sampleText, false);
    lv_textarea_set_one_line(ui->screen_SettingPage_ta_sampleText, false);
    lv_textarea_set_accepted_chars(ui->screen_SettingPage_ta_sampleText, "");
    lv_textarea_set_max_length(ui->screen_SettingPage_ta_sampleText, 32);
#if LV_USE_KEYBOARD != 0 || LV_USE_ZH_KEYBOARD != 0
    lv_obj_add_event_cb(ui->screen_SettingPage_ta_sampleText, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif
    lv_obj_set_pos(ui->screen_SettingPage_ta_sampleText, 100, 65);
    lv_obj_set_size(ui->screen_SettingPage_ta_sampleText, 280, 44);

    //Write style for screen_SettingPage_ta_sampleText, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_SettingPage_ta_sampleText, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_ta_sampleText, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_ta_sampleText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_SettingPage_ta_sampleText, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_SettingPage_ta_sampleText, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_ta_sampleText, 53, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_SettingPage_ta_sampleText, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_SettingPage_ta_sampleText, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_SettingPage_ta_sampleText, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_SettingPage_ta_sampleText, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_SettingPage_ta_sampleText, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_SettingPage_ta_sampleText, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_ta_sampleText, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_SettingPage_ta_sampleText, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_SettingPage_ta_sampleText, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_SettingPage_ta_sampleText, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_ta_sampleText, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_SettingPage_ta_sampleText, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_ta_sampleText, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_SettingPage_ta_sampleText, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_SettingPage_ta_sampleText, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_ta_sampleText, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_label_1
    ui->screen_SettingPage_label_1 = lv_label_create(ui->screen_SettingPage);
    lv_label_set_text(ui->screen_SettingPage_label_1, "Sample");
    lv_label_set_long_mode(ui->screen_SettingPage_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_SettingPage_label_1, 182, 38);
    lv_obj_set_size(ui->screen_SettingPage_label_1, 115, 20);

    //Write style for screen_SettingPage_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_SettingPage_label_1, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_SettingPage_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_tileview_1
    ui->screen_SettingPage_tileview_1 = lv_tileview_create(ui->screen_SettingPage);
    ui->screen_SettingPage_tileview_1_tile_Prep = lv_tileview_add_tile(ui->screen_SettingPage_tileview_1, 0, 0, LV_DIR_RIGHT);
    ui->screen_SettingPage_tileview_1_tile_Meas = lv_tileview_add_tile(ui->screen_SettingPage_tileview_1, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
    ui->screen_SettingPage_tileview_1_tile_Clean = lv_tileview_add_tile(ui->screen_SettingPage_tileview_1, 2, 0, LV_DIR_LEFT);
    lv_obj_set_pos(ui->screen_SettingPage_tileview_1, 18, 112);
    lv_obj_set_size(ui->screen_SettingPage_tileview_1, 442, 111);
    lv_obj_set_scrollbar_mode(ui->screen_SettingPage_tileview_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_SettingPage_tileview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_SettingPage_tileview_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_tileview_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_SettingPage_tileview_1, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_SettingPage_tileview_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_tileview_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



    //Write codes screen_SettingPage_ddlist_PrepDuration
    ui->screen_SettingPage_ddlist_PrepDuration = lv_dropdown_create(ui->screen_SettingPage_tileview_1_tile_Prep);
    lv_dropdown_set_options(ui->screen_SettingPage_ddlist_PrepDuration, "10\n20\n30\n40\n50\n60\n70\n80\n90\n100\n110\n120\n130\n140\n150\n160\n170\n180\n190\n200");
    lv_obj_set_pos(ui->screen_SettingPage_ddlist_PrepDuration, 118, 60);
    lv_obj_set_size(ui->screen_SettingPage_ddlist_PrepDuration, 216, 37);

    //Write style for screen_SettingPage_ddlist_PrepDuration, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_SettingPage_ddlist_PrepDuration, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_ddlist_PrepDuration, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_ddlist_PrepDuration, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_SettingPage_ddlist_PrepDuration, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_SettingPage_ddlist_PrepDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_SettingPage_ddlist_PrepDuration, lv_color_hex(0x3600fe), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_SettingPage_ddlist_PrepDuration, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_SettingPage_ddlist_PrepDuration, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_SettingPage_ddlist_PrepDuration, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_SettingPage_ddlist_PrepDuration, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_ddlist_PrepDuration, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_ddlist_PrepDuration, 47, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_SettingPage_ddlist_PrepDuration, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_SettingPage_ddlist_PrepDuration, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_ddlist_PrepDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked
    static lv_style_t style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked;
    ui_init_style(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_SettingPage_ddlist_PrepDuration), &style_screen_SettingPage_ddlist_PrepDuration_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default
    static lv_style_t style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default;
    ui_init_style(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default);

    lv_style_set_max_height(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_SettingPage_ddlist_PrepDuration), &style_screen_SettingPage_ddlist_PrepDuration_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_SettingPage_ddlist_PrepDuration_extra_list_scrollbar_default
    static lv_style_t style_screen_SettingPage_ddlist_PrepDuration_extra_list_scrollbar_default;
    ui_init_style(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_screen_SettingPage_ddlist_PrepDuration_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_SettingPage_ddlist_PrepDuration), &style_screen_SettingPage_ddlist_PrepDuration_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_label_3
    ui->screen_SettingPage_label_3 = lv_label_create(ui->screen_SettingPage_tileview_1_tile_Prep);
    lv_label_set_text(ui->screen_SettingPage_label_3, "Prepare");
    lv_label_set_long_mode(ui->screen_SettingPage_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_SettingPage_label_3, 164, 37);
    lv_obj_set_size(ui->screen_SettingPage_label_3, 115, 20);

    //Write style for screen_SettingPage_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_SettingPage_label_3, lv_color_hex(0x33a7fd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_label_3, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_SettingPage_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes screen_SettingPage_label_4
    ui->screen_SettingPage_label_4 = lv_label_create(ui->screen_SettingPage_tileview_1_tile_Meas);
    lv_label_set_text(ui->screen_SettingPage_label_4, "Measure");
    lv_label_set_long_mode(ui->screen_SettingPage_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_SettingPage_label_4, 164, 37);
    lv_obj_set_size(ui->screen_SettingPage_label_4, 115, 20);

    //Write style for screen_SettingPage_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_SettingPage_label_4, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_label_4, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_SettingPage_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_ddlist_MeasDuration
    ui->screen_SettingPage_ddlist_MeasDuration = lv_dropdown_create(ui->screen_SettingPage_tileview_1_tile_Meas);
    lv_dropdown_set_options(ui->screen_SettingPage_ddlist_MeasDuration, "10\n20\n30\n40\n50\n60\n70\n80\n90\n100\n110\n120\n130\n140\n150\n160\n170\n180\n190\n200");
    lv_obj_set_pos(ui->screen_SettingPage_ddlist_MeasDuration, 118, 60);
    lv_obj_set_size(ui->screen_SettingPage_ddlist_MeasDuration, 216, 37);

    //Write style for screen_SettingPage_ddlist_MeasDuration, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_SettingPage_ddlist_MeasDuration, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_ddlist_MeasDuration, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_ddlist_MeasDuration, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_SettingPage_ddlist_MeasDuration, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_SettingPage_ddlist_MeasDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_SettingPage_ddlist_MeasDuration, lv_color_hex(0x3600fe), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_SettingPage_ddlist_MeasDuration, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_SettingPage_ddlist_MeasDuration, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_SettingPage_ddlist_MeasDuration, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_SettingPage_ddlist_MeasDuration, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_ddlist_MeasDuration, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_ddlist_MeasDuration, 47, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_SettingPage_ddlist_MeasDuration, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_SettingPage_ddlist_MeasDuration, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_ddlist_MeasDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked
    static lv_style_t style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked;
    ui_init_style(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_SettingPage_ddlist_MeasDuration), &style_screen_SettingPage_ddlist_MeasDuration_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default
    static lv_style_t style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default;
    ui_init_style(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default);

    lv_style_set_max_height(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_SettingPage_ddlist_MeasDuration), &style_screen_SettingPage_ddlist_MeasDuration_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_SettingPage_ddlist_MeasDuration_extra_list_scrollbar_default
    static lv_style_t style_screen_SettingPage_ddlist_MeasDuration_extra_list_scrollbar_default;
    ui_init_style(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_screen_SettingPage_ddlist_MeasDuration_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_SettingPage_ddlist_MeasDuration), &style_screen_SettingPage_ddlist_MeasDuration_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



    //Write codes screen_SettingPage_label_5
    ui->screen_SettingPage_label_5 = lv_label_create(ui->screen_SettingPage_tileview_1_tile_Clean);
    lv_label_set_text(ui->screen_SettingPage_label_5, "Clean");
    lv_label_set_long_mode(ui->screen_SettingPage_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_SettingPage_label_5, 164, 37);
    lv_obj_set_size(ui->screen_SettingPage_label_5, 115, 20);

    //Write style for screen_SettingPage_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_SettingPage_label_5, lv_color_hex(0xff8100), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_label_5, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_SettingPage_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_ddlist_CleanDuration
    ui->screen_SettingPage_ddlist_CleanDuration = lv_dropdown_create(ui->screen_SettingPage_tileview_1_tile_Clean);
    lv_dropdown_set_options(ui->screen_SettingPage_ddlist_CleanDuration, "10\n20\n30\n40\n50\n60\n70\n80\n90\n100\n110\n120\n130\n140\n150\n160\n170\n180\n190\n200");
    lv_obj_set_pos(ui->screen_SettingPage_ddlist_CleanDuration, 118, 60);
    lv_obj_set_size(ui->screen_SettingPage_ddlist_CleanDuration, 216, 37);

    //Write style for screen_SettingPage_ddlist_CleanDuration, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_SettingPage_ddlist_CleanDuration, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_ddlist_CleanDuration, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_ddlist_CleanDuration, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_SettingPage_ddlist_CleanDuration, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_SettingPage_ddlist_CleanDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_SettingPage_ddlist_CleanDuration, lv_color_hex(0x3600fe), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_SettingPage_ddlist_CleanDuration, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_SettingPage_ddlist_CleanDuration, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_SettingPage_ddlist_CleanDuration, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_SettingPage_ddlist_CleanDuration, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_ddlist_CleanDuration, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_ddlist_CleanDuration, 47, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_SettingPage_ddlist_CleanDuration, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_SettingPage_ddlist_CleanDuration, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_ddlist_CleanDuration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked
    static lv_style_t style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked;
    ui_init_style(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_SettingPage_ddlist_CleanDuration), &style_screen_SettingPage_ddlist_CleanDuration_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default
    static lv_style_t style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default;
    ui_init_style(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default);

    lv_style_set_max_height(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_SettingPage_ddlist_CleanDuration), &style_screen_SettingPage_ddlist_CleanDuration_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_SettingPage_ddlist_CleanDuration_extra_list_scrollbar_default
    static lv_style_t style_screen_SettingPage_ddlist_CleanDuration_extra_list_scrollbar_default;
    ui_init_style(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_screen_SettingPage_ddlist_CleanDuration_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_SettingPage_ddlist_CleanDuration), &style_screen_SettingPage_ddlist_CleanDuration_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_btn_start
    ui->screen_SettingPage_btn_start = lv_btn_create(ui->screen_SettingPage);
    ui->screen_SettingPage_btn_start_label = lv_label_create(ui->screen_SettingPage_btn_start);
    lv_label_set_text(ui->screen_SettingPage_btn_start_label, "Start");
    lv_label_set_long_mode(ui->screen_SettingPage_btn_start_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_SettingPage_btn_start_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_SettingPage_btn_start, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_SettingPage_btn_start_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_SettingPage_btn_start, 171, 232);
    lv_obj_set_size(ui->screen_SettingPage_btn_start, 137, 34);

    //Write style for screen_SettingPage_btn_start, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_btn_start, 185, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_SettingPage_btn_start, lv_color_hex(0x0071ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_SettingPage_btn_start, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_SettingPage_btn_start, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_SettingPage_btn_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_SettingPage_btn_start, lv_color_hex(0x5482a9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_SettingPage_btn_start, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_btn_start, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_btn_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_SettingPage_btn_start, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_btn_start, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_btn_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_SettingPage_btn_start, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_SettingPage_label_2
    ui->screen_SettingPage_label_2 = lv_label_create(ui->screen_SettingPage);
    lv_label_set_text(ui->screen_SettingPage_label_2, "Duration");
    lv_label_set_long_mode(ui->screen_SettingPage_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_SettingPage_label_2, 182, 126);
    lv_obj_set_size(ui->screen_SettingPage_label_2, 115, 20);

    //Write style for screen_SettingPage_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_SettingPage_label_2, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_SettingPage_label_2, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_SettingPage_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_SettingPage_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_SettingPage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_SettingPage.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_SettingPage);

}
