#include "ros/ros.h"
#include "beginner_tutorials/irSensor.h"


void alert(const beginner_tutorials::irSensor::ConstPtr& msg)
{
  ROS_INFO("barrier: [%d]", msg->barrier);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "alert");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("alert_with_ir_exceed_10s", 1000, alert);
  ros::spin();

  return 0;
}