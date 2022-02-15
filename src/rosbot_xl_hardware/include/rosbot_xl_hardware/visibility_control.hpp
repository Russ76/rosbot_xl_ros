
// Copyright 2017 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef ROSBOT_XL_HARDWARE__VISIBILITY_CONTROL_H_
#define ROSBOT_XL_HARDWARE__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define ROSBOT_XL_HARDWARE_EXPORT __attribute__((dllexport))
#define ROSBOT_XL_HARDWARE_IMPORT __attribute__((dllimport))
#else
#define ROSBOT_XL_HARDWARE_EXPORT __declspec(dllexport)
#define ROSBOT_XL_HARDWARE_IMPORT __declspec(dllimport)
#endif
#ifdef ROSBOT_XL_HARDWARE_BUILDING_DLL
#define ROSBOT_XL_HARDWARE_PUBLIC ROSBOT_XL_HARDWARE_EXPORT
#else
#define ROSBOT_XL_HARDWARE_PUBLIC ROSBOT_XL_HARDWARE_IMPORT
#endif
#define ROSBOT_XL_HARDWARE_PUBLIC_TYPE ROSBOT_XL_HARDWARE_PUBLIC
#define ROSBOT_XL_HARDWARE_LOCAL
#else
#define ROSBOT_XL_HARDWARE_EXPORT __attribute__((visibility("default")))
#define ROSBOT_XL_HARDWARE_IMPORT
#if __GNUC__ >= 4
#define ROSBOT_XL_HARDWARE_PUBLIC __attribute__((visibility("default")))
#define ROSBOT_XL_HARDWARE_LOCAL __attribute__((visibility("hidden")))
#else
#define ROSBOT_XL_HARDWARE_PUBLIC
#define ROSBOT_XL_HARDWARE_LOCAL
#endif
#define ROSBOT_XL_HARDWARE_PUBLIC_TYPE
#endif

#endif  // ROSBOT_XL_HARDWARE__VISIBILITY_CONTROL_H_

