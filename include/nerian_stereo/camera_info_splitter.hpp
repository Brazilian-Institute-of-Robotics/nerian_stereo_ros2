#define BOOST_BIND_NO_PLACEHOLDERS
#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "nerian_stereo/nerian_stereo_node.h"
#include "sensor_msgs/msg/camera_info.h"

using namespace std::chrono_literals;
using std::placeholders::_1;

class CameraInfoSplitter : public rclcpp::Node
{
    public:
        CameraInfoSplitter();
    
    private:
        //Declaring the subscriber variable
        rclcpp::Subscription<nerian_stereo::msg::StereoCameraInfo>::SharedPtr nerian_camera_info_;

        //Declare the publishers for the camera left and right
        rclcpp::Publisher<sensor_msgs::msg::CameraInfo>::SharedPtr camera_left_info_;
        rclcpp::Publisher<sensor_msgs::msg::CameraInfo>::SharedPtr camera_right_info_;

        void nerian_info_callback(const nerian_stereo::msg::StereoCameraInfo::SharedPtr msg) const;
};