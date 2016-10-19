//
// Created by lupasic on 08.10.16.
//

#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <cmath>
#include <std_msgs/String.h>
#include <fstream>


class Converting
{
protected:
    ros::NodeHandle nh;
    ros::Subscriber curPathData, curOdomData;
    std::ofstream fout;
    std::ofstream fout2;
    void putInFilePath(const nav_msgs::Path::ConstPtr &msg);
    void putInFileOdom(const nav_msgs::Odometry::ConstPtr &msg);

public:
    Converting(std::string name);
    void pathCallback(const nav_msgs::Path::ConstPtr &msg);
    void odomCallback(const nav_msgs::Odometry::ConstPtr &msg);

};

