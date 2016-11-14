//
// Created by lupasic on 08.10.16.
//

#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/PoseStamped.h>
#include <cmath>
#include <std_msgs/String.h>
#include <fstream>


class Converting
{
protected:
    ros::NodeHandle nh;
    ros::Subscriber curPoseData;
    std::ofstream fout;
    std::ofstream fout2;
    void putInFilePose(const geometry_msgs::PoseStamped::ConstPtr &msg);

public:
    Converting(std::string name);
    void poseCallback(const geometry_msgs::PoseStamped::ConstPtr &msg);

};

