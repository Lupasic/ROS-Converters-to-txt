//
// Created by lupasic on 08.10.16.
//
#include "converting.h"

int main(int argc, char** argv)
{
    ros::init(argc,argv,"path_convert");
    Converting p(ros::this_node::getName());
    ros::spin();
    return 0;
}
