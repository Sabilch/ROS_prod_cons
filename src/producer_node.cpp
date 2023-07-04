#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char **argv)
{

  ros::init(argc, argv, "producer_node");


   
  ros::NodeHandle n;


  ros::Publisher producer_pub = n.advertise<std_msgs::String>("chatting", 1);

  ros::Rate loop_rate(1);

  while (ros::ok())
  {
  
    std_msgs::String msg;

    msg.data = "publishing";

    producer_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}