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



void setup_scr_screen_MeasurePage(lv_ui *ui)
{
    //Write codes screen_MeasurePage
    ui->screen_MeasurePage = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_MeasurePage, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen_MeasurePage, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_MeasurePage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage, 245, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage, lv_color_hex(0x0a1414), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_cont_1
    ui->screen_MeasurePage_cont_1 = lv_obj_create(ui->screen_MeasurePage);
    lv_obj_set_pos(ui->screen_MeasurePage_cont_1, 1, 20);
    lv_obj_set_size(ui->screen_MeasurePage_cont_1, 294, 270);
    lv_obj_set_scrollbar_mode(ui->screen_MeasurePage_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_MeasurePage_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_MeasurePage_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_MeasurePage_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_MeasurePage_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_MeasurePage_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_ch8
    ui->screen_MeasurePage_bar_ch8 = lv_bar_create(ui->screen_MeasurePage_cont_1);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_ch8, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_ch8, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_ch8, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch8, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_ch8, 149, 169);
    lv_obj_set_size(ui->screen_MeasurePage_bar_ch8, 120, 10);

    //Write style for screen_MeasurePage_bar_ch8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch8, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch8, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch8, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_ch8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_ch8, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch8, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch8, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch8, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch8, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_ch7
    ui->screen_MeasurePage_bar_ch7 = lv_bar_create(ui->screen_MeasurePage_cont_1);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_ch7, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_ch7, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_ch7, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch7, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_ch7, 149, 117);
    lv_obj_set_size(ui->screen_MeasurePage_bar_ch7, 120, 10);

    //Write style for screen_MeasurePage_bar_ch7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch7, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch7, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch7, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_ch7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_ch7, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch7, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch7, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch7, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch7, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_1
    ui->screen_MeasurePage_label_1 = lv_label_create(ui->screen_MeasurePage_cont_1);
    lv_label_set_text(ui->screen_MeasurePage_label_1, "CH1");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_1, 23, 16);
    lv_obj_set_size(ui->screen_MeasurePage_label_1, 96, 17);

    //Write style for screen_MeasurePage_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_1, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_1, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_ch1
    ui->screen_MeasurePage_bar_ch1 = lv_bar_create(ui->screen_MeasurePage_cont_1);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_ch1, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_ch1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_ch1, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_ch1, 17, 38);
    lv_obj_set_size(ui->screen_MeasurePage_bar_ch1, 120, 10);

    //Write style for screen_MeasurePage_bar_ch1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_ch1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_ch1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_ch4
    ui->screen_MeasurePage_bar_ch4 = lv_bar_create(ui->screen_MeasurePage_cont_1);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_ch4, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_ch4, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_ch4, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch4, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_ch4, 17, 188);
    lv_obj_set_size(ui->screen_MeasurePage_bar_ch4, 120, 10);

    //Write style for screen_MeasurePage_bar_ch4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch4, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch4, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_ch4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_ch4, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch4, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch4, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch4, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch4, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_ch3
    ui->screen_MeasurePage_bar_ch3 = lv_bar_create(ui->screen_MeasurePage_cont_1);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_ch3, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_ch3, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_ch3, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch3, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_ch3, 16, 138);
    lv_obj_set_size(ui->screen_MeasurePage_bar_ch3, 120, 10);

    //Write style for screen_MeasurePage_bar_ch3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch3, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_ch3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_ch3, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch3, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch3, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch3, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch3, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_ch5
    ui->screen_MeasurePage_bar_ch5 = lv_bar_create(ui->screen_MeasurePage_cont_1);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_ch5, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_ch5, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_ch5, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch5, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_ch5, 17, 238);
    lv_obj_set_size(ui->screen_MeasurePage_bar_ch5, 120, 10);

    //Write style for screen_MeasurePage_bar_ch5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch5, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch5, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_ch5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_ch5, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch5, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch5, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch5, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch5, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_ch6
    ui->screen_MeasurePage_bar_ch6 = lv_bar_create(ui->screen_MeasurePage_cont_1);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_ch6, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_ch6, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_ch6, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch6, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_ch6, 149, 65);
    lv_obj_set_size(ui->screen_MeasurePage_bar_ch6, 120, 10);

    //Write style for screen_MeasurePage_bar_ch6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch6, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch6, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch6, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_ch6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_ch6, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch6, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch6, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch6, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch6, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_ch2
    ui->screen_MeasurePage_bar_ch2 = lv_bar_create(ui->screen_MeasurePage_cont_1);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_ch2, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_ch2, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_ch2, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_ch2, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_ch2, 17, 88);
    lv_obj_set_size(ui->screen_MeasurePage_bar_ch2, 120, 10);

    //Write style for screen_MeasurePage_bar_ch2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch2, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_ch2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_ch2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_ch2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_ch2, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_ch2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_ch2, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_2
    ui->screen_MeasurePage_label_2 = lv_label_create(ui->screen_MeasurePage_cont_1);
    lv_label_set_text(ui->screen_MeasurePage_label_2, "CH2");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_2, 23, 66);
    lv_obj_set_size(ui->screen_MeasurePage_label_2, 96, 17);

    //Write style for screen_MeasurePage_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_2, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_2, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_3
    ui->screen_MeasurePage_label_3 = lv_label_create(ui->screen_MeasurePage_cont_1);
    lv_label_set_text(ui->screen_MeasurePage_label_3, "CH3");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_3, 23, 116);
    lv_obj_set_size(ui->screen_MeasurePage_label_3, 96, 17);

    //Write style for screen_MeasurePage_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_3, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_3, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_4
    ui->screen_MeasurePage_label_4 = lv_label_create(ui->screen_MeasurePage_cont_1);
    lv_label_set_text(ui->screen_MeasurePage_label_4, "CH4");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_4, 23, 167);
    lv_obj_set_size(ui->screen_MeasurePage_label_4, 96, 17);

    //Write style for screen_MeasurePage_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_4, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_4, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_5
    ui->screen_MeasurePage_label_5 = lv_label_create(ui->screen_MeasurePage_cont_1);
    lv_label_set_text(ui->screen_MeasurePage_label_5, "CH5");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_5, 23, 216);
    lv_obj_set_size(ui->screen_MeasurePage_label_5, 96, 17);

    //Write style for screen_MeasurePage_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_5, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_5, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_6
    ui->screen_MeasurePage_label_6 = lv_label_create(ui->screen_MeasurePage_cont_1);
    lv_label_set_text(ui->screen_MeasurePage_label_6, "CH6");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_6, 158, 44);
    lv_obj_set_size(ui->screen_MeasurePage_label_6, 96, 17);

    //Write style for screen_MeasurePage_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_6, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_6, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_7
    ui->screen_MeasurePage_label_7 = lv_label_create(ui->screen_MeasurePage_cont_1);
    lv_label_set_text(ui->screen_MeasurePage_label_7, "CH7");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_7, 158, 96);
    lv_obj_set_size(ui->screen_MeasurePage_label_7, 96, 17);

    //Write style for screen_MeasurePage_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_7, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_7, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_8
    ui->screen_MeasurePage_label_8 = lv_label_create(ui->screen_MeasurePage_cont_1);
    lv_label_set_text(ui->screen_MeasurePage_label_8, "CH8");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_8, 158, 148);
    lv_obj_set_size(ui->screen_MeasurePage_label_8, 96, 17);

    //Write style for screen_MeasurePage_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_8, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_8, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_state
    ui->screen_MeasurePage_bar_state = lv_bar_create(ui->screen_MeasurePage);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_state, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_state, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_state, 0, 1000);
    lv_bar_set_value(ui->screen_MeasurePage_bar_state, 1000, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_state, 193, 252);
    lv_obj_set_size(ui->screen_MeasurePage_bar_state, 30, 30);

    //Write style for screen_MeasurePage_bar_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_state, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_state, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_state, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_state, lv_color_hex(0x34e30b), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_state, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_state, 30, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_state
    ui->screen_MeasurePage_label_state = lv_label_create(ui->screen_MeasurePage);
    lv_label_set_text(ui->screen_MeasurePage_label_state, "IDLE STATE");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_state, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_state, 239, 257);
    lv_obj_set_size(ui->screen_MeasurePage_label_state, 215, 22);

    //Write style for screen_MeasurePage_label_state, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_state, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_state, &lv_font_montserratMedium_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_state, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_state, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_state, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_temperature
    ui->screen_MeasurePage_bar_temperature = lv_bar_create(ui->screen_MeasurePage);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_temperature, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_temperature, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_temperature, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_temperature, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_temperature, 314, 33);
    lv_obj_set_size(ui->screen_MeasurePage_bar_temperature, 21, 151);

    //Write style for screen_MeasurePage_bar_temperature, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_temperature, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_temperature, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_temperature, lv_color_hex(0x3cb31b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_temperature, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_temperature, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_temperature, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_temperature, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_temperature, lv_color_hex(0x34e30b), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_temperature, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_humidity
    ui->screen_MeasurePage_bar_humidity = lv_bar_create(ui->screen_MeasurePage);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_humidity, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_humidity, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_humidity, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_humidity, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_humidity, 370, 33);
    lv_obj_set_size(ui->screen_MeasurePage_bar_humidity, 21, 151);

    //Write style for screen_MeasurePage_bar_humidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_humidity, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_humidity, lv_color_hex(0xf50026), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_humidity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_humidity, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_humidity, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_humidity, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_humidity, lv_color_hex(0xf50026), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_humidity, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_humidity, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_bar_pressure
    ui->screen_MeasurePage_bar_pressure = lv_bar_create(ui->screen_MeasurePage);
    lv_obj_set_style_anim_time(ui->screen_MeasurePage_bar_pressure, 1000, 0);
    lv_bar_set_mode(ui->screen_MeasurePage_bar_pressure, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_MeasurePage_bar_pressure, 0, 100);
    lv_bar_set_value(ui->screen_MeasurePage_bar_pressure, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_MeasurePage_bar_pressure, 426, 33);
    lv_obj_set_size(ui->screen_MeasurePage_bar_pressure, 21, 151);

    //Write style for screen_MeasurePage_bar_pressure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_pressure, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_pressure, lv_color_hex(0xff6c00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_pressure, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_pressure, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_bar_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_MeasurePage_bar_pressure, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_bar_pressure, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_MeasurePage_bar_pressure, lv_color_hex(0xff6c00), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_MeasurePage_bar_pressure, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_bar_pressure, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_temperature
    ui->screen_MeasurePage_label_temperature = lv_label_create(ui->screen_MeasurePage);
    lv_label_set_text(ui->screen_MeasurePage_label_temperature, "12.36");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_temperature, LV_LABEL_LONG_SCROLL);
    lv_obj_set_pos(ui->screen_MeasurePage_label_temperature, 299, 196);
    lv_obj_set_size(ui->screen_MeasurePage_label_temperature, 51, 20);

    //Write style for screen_MeasurePage_label_temperature, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_temperature, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_temperature, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_temperature, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_temperature, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_9
    ui->screen_MeasurePage_label_9 = lv_label_create(ui->screen_MeasurePage);
    lv_label_set_text(ui->screen_MeasurePage_label_9, "RH%");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_9, 355, 220);
    lv_obj_set_size(ui->screen_MeasurePage_label_9, 51, 20);

    //Write style for screen_MeasurePage_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_9, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_9, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_10
    ui->screen_MeasurePage_label_10 = lv_label_create(ui->screen_MeasurePage);
    lv_label_set_text(ui->screen_MeasurePage_label_10, "°C");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_10, 298, 220);
    lv_obj_set_size(ui->screen_MeasurePage_label_10, 51, 20);

    //Write style for screen_MeasurePage_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_10, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_10, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_11
    ui->screen_MeasurePage_label_11 = lv_label_create(ui->screen_MeasurePage);
    lv_label_set_text(ui->screen_MeasurePage_label_11, "hPa");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_11, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_MeasurePage_label_11, 412, 220);
    lv_obj_set_size(ui->screen_MeasurePage_label_11, 51, 20);

    //Write style for screen_MeasurePage_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_11, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_11, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_humidity
    ui->screen_MeasurePage_label_humidity = lv_label_create(ui->screen_MeasurePage);
    lv_label_set_text(ui->screen_MeasurePage_label_humidity, "27.65");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_humidity, LV_LABEL_LONG_SCROLL);
    lv_obj_set_pos(ui->screen_MeasurePage_label_humidity, 356, 196);
    lv_obj_set_size(ui->screen_MeasurePage_label_humidity, 51, 20);

    //Write style for screen_MeasurePage_label_humidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_humidity, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_humidity, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_humidity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_humidity, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_label_pressure
    ui->screen_MeasurePage_label_pressure = lv_label_create(ui->screen_MeasurePage);
    lv_label_set_text(ui->screen_MeasurePage_label_pressure, "1003.5\n");
    lv_label_set_long_mode(ui->screen_MeasurePage_label_pressure, LV_LABEL_LONG_SCROLL);
    lv_obj_set_pos(ui->screen_MeasurePage_label_pressure, 418, 196);
    lv_obj_set_size(ui->screen_MeasurePage_label_pressure, 56, 20);

    //Write style for screen_MeasurePage_label_pressure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_MeasurePage_label_pressure, lv_color_hex(0xe7e8da), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_MeasurePage_label_pressure, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_MeasurePage_label_pressure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_MeasurePage_label_pressure, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_MeasurePage_label_pressure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_MeasurePage_img_arrowDown
    ui->screen_MeasurePage_img_arrowDown = lv_img_create(ui->screen_MeasurePage);
    lv_obj_add_flag(ui->screen_MeasurePage_img_arrowDown, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_MeasurePage_img_arrowDown, &_down_alpha_128x17);
    lv_img_set_pivot(ui->screen_MeasurePage_img_arrowDown, 50,50);
    lv_img_set_angle(ui->screen_MeasurePage_img_arrowDown, 0);
    lv_obj_set_pos(ui->screen_MeasurePage_img_arrowDown, 176, 295);
    lv_obj_set_size(ui->screen_MeasurePage_img_arrowDown, 128, 17);

    //Write style for screen_MeasurePage_img_arrowDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_MeasurePage_img_arrowDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_MeasurePage_img_arrowDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_MeasurePage_img_arrowDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_MeasurePage_img_arrowDown, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_MeasurePage.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_MeasurePage);

}
