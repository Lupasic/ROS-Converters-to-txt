//
// Created by lupasic on 08.10.16.
//

#include "converting.h"

Converting::Converting(std::string name)
{
    std::string subscribe_path_topic, subscribe_odom_topic, output_file;
    nh.getParam("/path_convert/path_topic", subscribe_path_topic);
    nh.getParam("/path_convert/odom_topic", subscribe_odom_topic);
    nh.getParam("/path_convert/output_file_path", output_file);
    fout.open(output_file.c_str());
    nh.getParam("/path_convert/output_file_odom", output_file);
    fout2.open(output_file.c_str());

    curPathData = nh.subscribe(subscribe_path_topic, 1 ,&Converting::pathCallback, this);
    curOdomData = nh.subscribe(subscribe_odom_topic, 1 ,&Converting::odomCallback, this);
}

void Converting::pathCallback(const nav_msgs::Path::ConstPtr &msg)
{
    putInFilePath(msg);
}

void Converting::odomCallback(const nav_msgs::Odometry::ConstPtr &msg)
{
    putInFileOdom(msg);
}

void Converting::putInFilePath(const nav_msgs::Path::ConstPtr &msg)
{
    for(auto ct = msg->poses.begin(); ct != msg->poses.end(); ++ct)
    {

        geometry_msgs::PoseStamped cur_pose = *ct;
        fout << cur_pose.pose.position.x << " " << cur_pose.pose.position.y << std::endl;
    }
}

void Converting::putInFileOdom(const nav_msgs::Odometry::ConstPtr &msg)
{
        geometry_msgs::PoseWithCovariance cur_pose = msg->pose;
        fout2 << cur_pose.pose.position.x << " " << cur_pose.pose.position.y << std::endl;
}
