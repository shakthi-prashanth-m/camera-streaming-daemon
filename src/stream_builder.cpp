/*
 * This file is part of the Dronecode Camera Manager
 *
 * Copyright (C) 2017  Intel Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <algorithm>
#include <vector>

#include "stream_builder.h"

StreamBuilder::StreamBuilder()
{
    get_builders().push_back(this);
}

StreamBuilder::~StreamBuilder()
{
    StreamBuilder *b = this;
    std::vector<StreamBuilder *> &builders = get_builders();
    std::vector<StreamBuilder *>::iterator it = std::find(builders.begin(), builders.end(), b);
    if (it != builders.end()) {
        std::swap(*it, builders.back());
        builders.pop_back();
    }
}

std::vector<StreamBuilder *> &StreamBuilder::get_builders()
{
    static std::vector<StreamBuilder *> builders;
    return builders;
}
