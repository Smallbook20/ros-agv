#include "ros/ros.h"
#include "beginner_tutorials/AverageScore.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cal_average_score_client");
  if (argc != 4)
  {
    ROS_INFO("usage: cal_average_score_client X Y Z");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AverageScore>("cal_average_score");
  beginner_tutorials::AverageScore srv;
  srv.request.scoreA = atoll(argv[1]);
  srv.request.scoreB = atoll(argv[2]);
  srv.request.scoreC = atoll(argv[3]);
  if (client.call(srv))
  {
    ROS_INFO("Average Score is: %f", srv.response.averageScore);
  }
  else
  {
    ROS_ERROR("Failed to call service cal_average_score");
    return 1;
  }

  return 0;
}