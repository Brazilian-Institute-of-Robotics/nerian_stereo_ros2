// Copyright (c) 2023, SENAI Cimatec
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#define BOOST_BIND_NO_PLACEHOLDERS
#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "nerian_stereo/nerian_stereo_node.h"
#include "nerian_stereo/camera_info_splitter.hpp"
#include "sensor_msgs/msg/camera_info.h"

using namespace std::chrono_literals;
using std::placeholders::_1;

CameraInfoSplitter::CameraInfoSplitter()
 : Node("camera_info_splitter") {
    nerian_camera_info_ = this->create_subscription<nerian_stereo::msg::StereoCameraInfo>(
       "/nerian_stereo/stereo_camera_info", 10,
       std::bind(&CameraInfoSplitter::nerian_info_callback, this, _1));

    camera_left_info_ = this->create_publisher<sensor_msgs::msg::CameraInfo>(
       "/nerian_stereo/left_camera_info", 10);

    camera_right_info_ = this->create_publisher<sensor_msgs::msg::CameraInfo>(
       "/nerian_stereo/right_camera_info", 10);
 }

void CameraInfoSplitter::nerian_info_callback(
    const nerian_stereo::msg::StereoCameraInfo::SharedPtr msg) const {
    camera_left_info_->publish(msg->left_info);
    camera_right_info_->publish(msg->right_info);
}
