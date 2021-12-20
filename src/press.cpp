#include "ros/ros.h"
#include "beginner_tutorials/press.h"
#include <cstdlib>

// void separateStringToArray
int main(int argc, char **argv)
{
  ros::init(argc, argv, "press");
  ros::NodeHandle n;
  ros::Publisher press_pub = n.advertise<beginner_tutorials::press>("send_press_key_board", 1000);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
  beginner_tutorials::press msg;
  std::string inputKeyBoard;
  std::getline(std::cin, inputKeyBoard);
  msg.pressedKey = inputKeyBoard.c_str();

  press_pub.publish(msg);
  ros::spinOnce();
  }
  return 0;
}