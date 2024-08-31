cmake_minimum_required(VERSION 3.22)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32cubemx INTERFACE 
	USE_HAL_DRIVER 
	STM32H743xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(stm32cubemx INTERFACE
    ../../Core/Inc
    ../../Drivers/STM32H7xx_HAL_Driver/Inc
    ../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy
    ../../Drivers/CMSIS/Device/ST/STM32H7xx/Include
    ../../Drivers/CMSIS/Include
    ../../App/lcd_driver
    ../../App/lvgl
    ../../App/lvgl/
    ../../App/lvgl/src
    ../../App/lvgl/src/core
    ../../App/lvgl/src/draw
    ../../App/lvgl/src/font
    ../../App/lvgl/src/hal
    ../../App/lvgl/src/misc
    ../../App/lvgl/src/widgets
    ../../App/lvgl/src/extra
    ../../App/lvgl/examples
    ../../App/lvgl/examples/anim
    ../../App/lvgl/examples/event
    ../../App/lvgl/examples/assets
    ../../App/lvgl/examples/get_started
    ../../App/lvgl/examples/layouts
    ../../App/lvgl/examples/libs
    ../../App/lvgl/examples/others
    ../../App/lvgl/examples/porting
    ../../App/lvgl/examples/scroll
    ../../App/lvgl/examples/styles
    ../../App/lvgl/examples/widgets

    )

target_sources(stm32cubemx INTERFACE
    ../../Core/Src/main.c
    ../../Core/Src/gpio.c
    ../../Core/Src/usart.c
    ../../Core/Src/stm32h7xx_it.c
    ../../Core/Src/stm32h7xx_hal_msp.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c
    ../../Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_qspi.c
    ../../App/lcd_driver/lcd.c
    ../../App/lcd_driver/lcd_init.c
    ../../App/lcd_driver/QSPI.c
    ../../App/lvgl/src/core/lv_disp.c
    ../../App/lvgl/src/core/lv_event.c
    ../../App/lvgl/src/core/lv_group.c
    ../../App/lvgl/src/core/lv_indev.c
    ../../App/lvgl/src/core/lv_indev_scroll.c
    ../../App/lvgl/src/core/lv_obj.c
    ../../App/lvgl/src/core/lv_obj_class.c
    ../../App/lvgl/src/core/lv_obj_draw.c
    ../../App/lvgl/src/core/lv_obj_pos.c
    ../../App/lvgl/src/core/lv_obj_scroll.c
    ../../App/lvgl/src/core/lv_obj_style.c
    ../../App/lvgl/src/core/lv_obj_style_gen.c
    ../../App/lvgl/src/core/lv_obj_tree.c
    ../../App/lvgl/src/core/lv_refr.c
    ../../App/lvgl/src/core/lv_theme.c
    ../../App/lvgl/src/draw/lv_draw.c
    ../../App/lvgl/src/draw/lv_draw_arc.c
    ../../App/lvgl/src/draw/lv_draw_img.c
    ../../App/lvgl/src/draw/lv_draw_label.c
    ../../App/lvgl/src/draw/lv_draw_layer.c
    ../../App/lvgl/src/draw/lv_draw_line.c
    ../../App/lvgl/src/draw/lv_draw_mask.c
    ../../App/lvgl/src/draw/lv_draw_rect.c
    ../../App/lvgl/src/draw/lv_draw_transform.c
    ../../App/lvgl/src/draw/lv_draw_triangle.c
    ../../App/lvgl/src/draw/lv_img_buf.c
    ../../App/lvgl/src/draw/lv_img_decoder.c
    ../../App/lvgl/src/draw/lv_img_cache.c
    ../../App/lvgl/src/extra/lv_extra.c
    ../../App/lvgl/src/extra/layouts/flex/lv_flex.c
    ../../App/lvgl/src/extra/layouts/grid/lv_grid.c
    ../../App/lvgl/src/extra/libs/bmp/lv_bmp.c
    ../../App/lvgl/src/extra/libs/ffmpeg/lv_ffmpeg.c
    ../../App/lvgl/src/extra/libs/freetype/lv_freetype.c
    ../../App/lvgl/src/extra/libs/gif/gifdec.c
    ../../App/lvgl/src/extra/libs/gif/lv_gif.c
    ../../App/lvgl/src/extra/libs/png/lodepng.c
    ../../App/lvgl/src/extra/libs/png/lv_png.c
    ../../App/lvgl/src/extra/libs/qrcode/qrcodegen.c
    ../../App/lvgl/src/extra/libs/qrcode/lv_qrcode.c
    ../../App/lvgl/src/extra/libs/rlottie/lv_rlottie.c
    ../../App/lvgl/src/extra/libs/sjpg/lv_sjpg.c
    ../../App/lvgl/src/extra/libs/sjpg/tjpgd.c
    ../../App/lvgl/src/extra/libs/tiny_ttf/lv_tiny_ttf.c
    ../../Core/Src/system_stm32h7xx.c
    ../../Core/Src/sysmem.c
    ../../Core/Src/syscalls.c
    ../../startup_stm32h743xx.s
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


