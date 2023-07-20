from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    nerian_stereo_node = Node(
                package='nerian_stereo',
                executable='nerian_stereo_node',
                parameters=[
                    {'remote_host':                  '192.168.1.130'},
                    {'remote_port':                  '7681'},
                    {'use_tcp':                       False},

                    {'top_level_frame':               'base_nerian'},
                    {'internal_frame':                'nerian_stereo'},
                    {'left_camera_frame':             'left_stereo_link'},
                    {'right_camera_frame':            'right_stereo_link'},
                    {'pcl_frame':                     'left_fake_link'},
                    {'ros_coordinate_system':         True},
                    {'ros_timestamps':                True},

                    {'max_depth':                     -1},
                    {'point_cloud_intensity_channel', 'mono8'},
                    {'color_code_disparity_map',      ''},
                    {'color_code_legend':             False},

                    {'calibration_file':              ''},
                    {'q_from_calib_file':             False},
                    {'delay_execution':               0.0},
                    {'use_sim_time': False}
 
                ],
                output='screen'
            )
    camera_info_splitter = Node(
        package='nerian_stereo',
        executable='camera_info_splitter',
        output='screen'
    )
    
    ld.add_action(nerian_stereo_node)
    ld.add_action(camera_info_splitter)

    return ld

