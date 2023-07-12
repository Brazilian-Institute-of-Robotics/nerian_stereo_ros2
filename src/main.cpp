#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "nerian_stereo/camera_info_splitter.hpp"

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CameraInfoSplitter>());
    rclcpp::shutdown();
    return 0;
}