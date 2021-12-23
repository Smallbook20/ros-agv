#include "ros/ros.h"
#include "beginner_tutorials/locationMap.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "locationMap");
  ros::NodeHandle n;
  ros::Publisher locationMap = n.advertise<beginner_tutorials::locationMap>("send_location", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
  beginner_tutorials::locationMap msg;
  std::string inputSensorValue;
  std::getline(std::cin, inputSensorValue);
  msg.locationMap = inputSensorValue.c_str();
  locationMap.publish(msg);
  ros::spinOnce();
  }
  return 0;
}