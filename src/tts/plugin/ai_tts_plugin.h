/****************************************************************************
 * frameworks/ai/src/tts_plugin/ai_tts_plugin.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef FRAMEWORKS_AI_PLUGIN_H_
#define FRAMEWORKS_AI_PLUGIN_H_
#include <uv.h>

#include "ai_tts_defs.h"

typedef struct tts_engine_plugin_s {
    const char* name;
    int priv_size;
    int (*init)(void* engine, const tts_engine_init_params_t* param);
    int (*uninit)(void* engine);
    int (*event_cb)(void* engine, tts_engine_callback_t callback, void* cookie);
    int (*speak)(void* engine, const char* text, const tts_engine_audio_info_t* audio_info);
    int (*stop)(void* engine);
    tts_engine_env_params_t* (*get_env)(void* engine);
} tts_engine_plugin_t;

void* tts_plugin_init(tts_engine_plugin_t* plugin, const tts_engine_init_params_t* param);
void tts_plugin_uninit(tts_engine_plugin_t* plugin, void* engine, int sync);

#endif // FRAMEWORKS_AI_PLUGIN_H_
