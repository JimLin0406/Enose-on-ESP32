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
#include <dirent.h>
#include "tusb_msc_storage.h"
#include "esp_log.h"
#include "sdmmc.h"         // self-defined sdmmc.h

extern TaskHandle_t start_measurement_task_handle;
extern TaskHandle_t classification_task_handle;

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

static void arrow_down_event_handler(lv_event_t * e) {
    lv_ui * ui = (lv_ui *) lv_event_get_user_data(e);
    lv_obj_t *current_screen = lv_scr_act();

    lv_dir_t gesture_dir = lv_indev_get_gesture_dir(lv_indev_get_act());
    if(gesture_dir == LV_DIR_TOP){
        if (lv_obj_get_screen(current_screen) == ui->screen_SettingPage){
            lv_scr_load(ui->screen_AnalysisPage);  
        }
        else if (lv_obj_get_screen(current_screen) == ui->screen_MeasurePage){
            lv_scr_load(ui->screen_SettingPage);  
        }
    }
}

static void arrow_up_event_handler(lv_event_t * e) {
    lv_ui * ui = (lv_ui *) lv_event_get_user_data(e);
    lv_obj_t *current_screen = lv_scr_act();

    lv_dir_t gesture_dir = lv_indev_get_gesture_dir(lv_indev_get_act());
    if(gesture_dir == LV_DIR_BOTTOM){
        if (lv_obj_get_screen(current_screen)  == ui->screen_SettingPage) {
            lv_scr_load(ui->screen_MeasurePage);  
        }
        else if (lv_obj_get_screen(current_screen)  == ui->screen_AnalysisPage) {
            lv_scr_load(ui->screen_SettingPage);  
        }
    }
}

static void start_btn_event_cb(lv_event_t * e) {
    xTaskNotifyGive(start_measurement_task_handle);
}

static void file_list_event_cb(lv_event_t * e) {
    lv_obj_t *list = lv_event_get_target(e);
    lv_dropdown_clear_options(list);

    DIR *dir = opendir("/sd_card/USB Drive");
    if (!dir) {
        ESP_LOGE("events_init.c", "Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        const char *filename = entry->d_name;
        printf("%s\n",filename);
        const char *ext = strrchr(filename, '.');  // 從右邊找最後一個'.'
        if (ext && (strcmp(ext, ".csv") == 0||strcmp(ext, ".CSV") == 0)) {
            lv_dropdown_add_option(list, filename, LV_DROPDOWN_POS_LAST);
        }
    }
    closedir(dir);
}

// // Output csv file through serial monitor
// static void test_btn_event_cb(lv_event_t * e) {
//     lv_ui * ui = (lv_ui *) lv_event_get_user_data(e);
    
//     uint16_t sel = lv_dropdown_get_selected(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS);

//     char filename[128];
//     lv_dropdown_get_selected_str(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, filename, sizeof(filename));

//     char filepath[256];
//     snprintf(filepath, sizeof(filepath), "/sd_card/%s", filename);
    
//     FILE *file = fopen(filepath, "r");
//     if (!file) {
//         printf("Failed to open file: %s\n", filepath);
//         return;
//     }

//     printf("Reading file: %s\n", filepath);
//     char line[256];
//     while (fgets(line, sizeof(line), file)) {
//         printf("%s", line);
//     }
//     printf("\n");  

//     fclose(file);
// }

// Classification task
static void classify_btn_event_cb(lv_event_t * e) {
    xTaskNotifyGive(classification_task_handle);
}

static bool enable_usb_msc = false; 

static void toggle_usb_mount_cb(lv_event_t *e) {
    lv_ui * ui = (lv_ui *) lv_event_get_user_data(e);

    if (!host_disconnected) {
        _mount();  // ESP32 自行重新掛載 FATFS
    }
}

void events_init(lv_ui *ui) {

    lv_obj_add_event_cb(ui->screen_MeasurePage, arrow_down_event_handler, LV_EVENT_GESTURE, ui);
    lv_obj_add_event_cb(ui->screen_SettingPage, arrow_up_event_handler, LV_EVENT_GESTURE, ui);
    lv_obj_add_event_cb(ui->screen_SettingPage, arrow_down_event_handler, LV_EVENT_GESTURE, ui);
    lv_obj_add_event_cb(ui->screen_AnalysisPage, arrow_up_event_handler, LV_EVENT_GESTURE, ui);

    lv_obj_add_event_cb(ui->screen_SettingPage_btn_start, start_btn_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(ui->screen_AnalysisPage_btn_classify, classify_btn_event_cb, LV_EVENT_CLICKED, ui);

    lv_obj_add_event_cb(ui->screen_AnalysisPage_ddlist_file_in_SPIFFS, file_list_event_cb, LV_EVENT_PRESSED, NULL);

    lv_obj_add_event_cb(ui->screen_AnalysisPage_btn_upload, toggle_usb_mount_cb, LV_EVENT_CLICKED, ui); 

    // lv_obj_move_foreground(ui->screen_MeasurePage_img_arrowDown);
}



