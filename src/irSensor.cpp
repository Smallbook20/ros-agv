#include "ros/ros.h"
#include "beginner_tutorials/irSensor.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "irSensor");
  if (argc != 7)
  {
    ROS_INFO("usage: irSensor ir1 ir2 ir3 ir4 ir5 barrier");
    ROS_INFO("%s", argv[6]);
    return 1;
  }
  ros::NodeHandle n;
  ros::Publisher irSensor = n.advertise<beginner_tutorials::irSensor>("send_ir_signal", 1000);
  ros::Publisher alertSensor = n.advertise<beginner_tutorials::irSensor>("alert_with_ir_exceed_10s", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
  beginner_tutorials::irSensor msg;
  msg.ir1 = atoll(argv[1]);
  msg.ir2 = atoll(argv[2]);
  msg.ir3 = atoll(argv[3]);
  msg.ir4 = atoll(argv[4]);
  msg.ir5 = atoll(argv[5]);
  msg.barrier = atoll(argv[6]);

  irSensor.publish(msg);
  alertSensor.publish(msg);
  ros::spinOnce();
  }
  return 0;
}