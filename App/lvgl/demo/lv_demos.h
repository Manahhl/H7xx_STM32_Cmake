/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-09-02 15:09:12
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-09-02 17:25:58
 * @FilePath: \H7xx_Cmake_4\App\lvgl\demo\lv_demos.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
/**
 * @file lv_demos.h
 *
 */

#ifndef LV_DEMOS_H
#define LV_DEMOS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../lvgl.h"

#if LV_USE_DEMO_WIDGETS
#include "widgets/lv_demo_widgets.h"
#endif

#if LV_USE_DEMO_BENCHMARK
#include "benchmark/lv_demo_benchmark.h"
#endif

#if LV_USE_DEMO_STRESS
#include "../../App/lvgl/demo/stress/lv_demo_stress.h"
#endif

#if LV_USE_DEMO_KEYPAD_AND_ENCODER
#include "keypad_encoder/lv_demo_keypad_encoder.h"
#endif

#if LV_USE_DEMO_MUSIC
#include "lv_demo_music.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_DEMO_H*/
