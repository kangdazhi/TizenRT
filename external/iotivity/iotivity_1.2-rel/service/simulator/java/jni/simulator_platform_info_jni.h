/******************************************************************
 *
 * Copyright 2015 Samsung Electronics All Rights Reserved.
 *
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************/

#ifndef SIMULATOR_PLATFORM_INFO_JNI_H_
#define SIMULATOR_PLATFORM_INFO_JNI_H_

#include "simulator_platform_info.h"
#include <jni.h>

class JniPlatformInfo
{
    public:
        JniPlatformInfo(JNIEnv *env) : m_env(env) {}
        JniPlatformInfo(const JniPlatformInfo &) = delete;
        JniPlatformInfo &operator=(const JniPlatformInfo &) = delete;
        JniPlatformInfo(const JniPlatformInfo &&) = delete;
        JniPlatformInfo &operator=(const JniPlatformInfo && ) = delete;
        jobject toJava(PlatformInfo &platformInfo);
        PlatformInfo toCpp(jobject jPlatformInfo);

    private:
        void setFieldValue(jobject jPlatformInfo, const std::string &fieldName,
                           const std::string &value);
        std::string getFieldValue(jobject jPlatformInfo, const std::string &fieldName);

        JNIEnv *m_env;
};

#endif
