#include "ros/ros.h"
#include "std_msgs/String.h"


void consumerCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "consumer_node");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatting", 1, consumerCallback);

  ros::spin();

  return 0;
}