//
// Created by lupasic on 08.10.16.
//

#include "converting.h"

Converting::Converting(std::string name)
{
    std::string subscribe_pose_topic, output_file;
    nh.getParam("/pose_stamped_convert/pose_topic", subscribe_pose_topic);
    nh.getParam("/pose_stamped_convert/output_file_pose", output_file);
    fout.open(output_file.c_str());

    curPoseData = nh.subscribe(subscribe_pose_topic, 1 ,&Converting::poseCallback, this);
    
}

void Converting::poseCallback(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
    putInFilePose(msg);
}


void Converting::putInFilePose(const geometry_msgs::PoseStamped::ConstPtr &msg)
{
    fout << msg->pose.position.x << " " << msg->pose.position.y << std::endl;
}

