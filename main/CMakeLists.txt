file (GLOB_RECURSE srcs *.c
                        ui/custom/*.c
                        ui/generated/*.c
                        ui/generated/guider_customer_fonts/*.c
                        ui/generated/guider_fonts/*.c
                        ui/generated/images/*.c
                        *.cpp
                        )

set(requires    esp-dl
                lvgl
                spiffs
                fatfs
                esp_driver_gpio
                )


set(include_dirs
    .
    ui/custom
    ui/generated
    ui/generated/guider_customer_fonts
    ui/generated/guider_fonts
    ui/generated/images)


idf_component_register(SRCS ${srcs}
    INCLUDE_DIRS ${include_dirs}
    REQUIRES ${requires}
    )

add_compile_definitions(LV_LVGL_H_INCLUDE_SIMPLE)

if(CONFIG_MODEL_FILE_PATH)
    message("CONFIG_MODEL_FILE_PATH is defined")
endif()
message("CONFIG_MODEL_FILE_PATH: ${CONFIG_MODEL_FILE_PATH}")
message("PROJECT_DIR: ${PROJECT_DIR}")

set(MVMODEL_EXE ${PROJECT_DIR}/pack_model.py)
idf_build_get_property(build_dir BUILD_DIR)

set(MODEL_FILE_PATH_1 ${PROJECT_DIR}/models/model_MTL.espdl)
set(image_file_1 ${build_dir}/espdl_models/model.espdl)
                

add_custom_command(
    OUTPUT ${image_file_1}
    COMMENT "Move and Pack model 1..."
    COMMAND python ${MVMODEL_EXE} --model_path=${MODEL_FILE_PATH_1} --out_file=${image_file_1}
    DEPENDS ${MODEL_FILE_PATH_1}
    VERBATIM)

add_custom_target(models_espdl ALL DEPENDS ${image_file_1})

# 模型燒錄到分區
partition_table_get_partition_info(size "--partition-name model" "size")
partition_table_get_partition_info(offset "--partition-name model" "offset")

if("${size}" AND "${offset}")
    esptool_py_flash_to_partition(flash "model" "${image_file_1}")
else()
    set(message "Failed to find model in partition table file"
                "Please add a line(Name=model, Size>recommended size in log) to the partition file.")
endif()

add_dependencies(flash models_espdl)

# spiffs_create_partition_image(files ../test_data FLASH_IN_PROJECT)
