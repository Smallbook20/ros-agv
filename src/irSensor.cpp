#include "ros/ros.h"
#include "beginner_tutorials/irSensor.h"
#include <cstdlib>

// void separateStringToArray
int main(int argc, char **argv)
{
  ros::init(argc, argv, "irSensor");
  ros::NodeHandle n;
  ros::Publisher irSensor = n.advertise<beginner_tutorials::irSensor>("send_ir_signal", 1000);
  ros::Publisher alertSensor = n.advertise<beginner_tutorials::irSensor>("alert_with_ir_exceed_10s", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
  beginner_tutorials::irSensor msg;
  std::string inputSensorValue;
  std::getline(std::cin, inputSensorValue);
  msg.irSensor = inputSensorValue.c_str();

  irSensor.publish(msg);
  alertSensor.publish(msg);
  ros::spinOnce();
  }
  return 0;
}