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
#ifndef NERIAN_STEREO__CAMERA_INFO_SPLITTER_HPP_
#define NERIAN_STEREO__CAMERA_INFO_SPLITTER_HPP_

#define BOOST_BIND_NO_PLACEHOLDERS
#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "nerian_stereo/nerian_stereo_node.h"
#include "sensor_msgs/msg/camera_info.h"

class CameraInfoSplitter : public rclcpp::Node
{
    public:
    /**
     * @brief Construct a new Camera Info Splitter object
     * 
     */
        CameraInfoSplitter();

    private:
        rclcpp::Subscription<nerian_stereo::msg::StereoCameraInfo>::SharedPtr nerian_camera_info_;

        // Declare the publishers for the camera left and right
        rclcpp::Publisher<sensor_msgs::msg::CameraInfo>::SharedPtr camera_left_info_;
        rclcpp::Publisher<sensor_msgs::msg::CameraInfo>::SharedPtr camera_right_info_;

        /**
         * @brief Create a callback for nerian stereo_camera_info
         * 
         * @param msg stereo_camera_info message
         */
        void nerian_info_callback(const nerian_stereo::msg::StereoCameraInfo::SharedPtr msg) const;
};

#endif  // NERIAN_STEREO__CAMERA_INFO_SPLITTER_HPP_
