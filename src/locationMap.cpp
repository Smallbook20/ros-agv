#include "ros/ros.h"
#include "beginner_tutorials/locationMap.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "locationMap");
  if (argc != 2)
  {
    ROS_INFO("usage: locationMap Str");
    return 1;
  }
  ros::NodeHandle n;
  ros::Publisher locationMap = n.advertise<beginner_tutorials::locationMap>("send_location", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
  beginner_tutorials::locationMap msg;
  msg.locationMap = argv[1];
  locationMap.publish(msg);
  ros::spinOnce();
  }
  return 0;
}