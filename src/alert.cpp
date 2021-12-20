#include "ros/ros.h"
#include "beginner_tutorials/irSensor.h"

void checkBarrier(std::string irSensor) {
    if (irSensor.compare(5, 1, "1") == 0) {
        ROS_INFO("We have a barrier, AGV is temporary stop");
    } else {
    ROS_INFO("No barrier, AGV is active");
  }
    
}

void alert(const beginner_tutorials::irSensor::ConstPtr& msg)
{
  checkBarrier(msg->irSensor.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "alert");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("alert_with_ir_exceed_10s", 1000, alert);
  ros::spin();

  return 0;
}