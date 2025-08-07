
// sdmmc.h
#ifndef SDMMC_H
#define SDMMC_H

#include "esp_log.h"
#include "diskio_impl.h"
#include "diskio_sdmmc.h"
#include "tusb_msc_storage.h"
#include "esp_check.h"
#include "tusb_msc_storage.h"
#include "tinyusb.h"
#include <dirent.h>
#include <errno.h>

#define BASE_PATH "/sd_card"

#ifdef __cplusplus
extern "C" {
#endif

extern volatile bool host_disconnected;

extern const char *string_desc_arr[];
extern const uint8_t msc_fs_configuration_desc[];
extern const tinyusb_config_t tusb_cfg;
extern tusb_desc_device_t descriptor_config;

esp_err_t storage_init_sdmmc(sdmmc_card_t **card);
void storage_mount_changed_cb(tinyusb_msc_event_t *event);
void storage_premount_changed_cb(tinyusb_msc_event_t *event);
void _mount(void);



#ifdef __cplusplus
}
#endif

#endif // SDMMC_H