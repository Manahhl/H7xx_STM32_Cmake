set(LV_CONF_INCLUDE_SIMPLE ON)
set(LV_USE_DEMO_WIDGETS OFF)

project(lvgl)

file(GLOB_RECURSE lvgl_source ${CMAKE_SOURCE_DIR}/App/lvgl/*.c ${CMAKE_SOURCE_DIR}/App/lvgl/*.h)

add_library(lvgl STATIC ${lvgl_source})

target_link_directories(lvgl PUBLIC ${CMAKE_SOURCE_DIR}/App/lvgl)

target_include_directories(lvgl PUBLIC 
../../Core/Inc
../../App/lcd_driver
)

# target_sources(${CMAKE_PROGRAM_NAME} PRIVITE ${})














