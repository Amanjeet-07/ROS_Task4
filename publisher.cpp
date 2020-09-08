#include<ros/ros.h>
#include<task_5/CombinedInfo.h>

void Input(task_5::CombinedInfo& msgs)
{
  int i,j,k;
  std::cout<<"Enter linear Acceleration :";
  for(i=0;i<3;i++)
  {
 	 std::cin>>msgs.linear_acceleration[i];
  }
  std::cout<<"Enter Angular Velocity Coordinates :";
  for(j=0;j<3;j++)
  {
  	std::cin>>msgs.angular_velocity[j];
  }
  std::cout<<"Enter Rotation Coordinates :";
  for(k=0;k<3;k++)
  {
  	 std::cin>>msgs.rotation[k];
  }
}
/*void Return_message_type()
{
   ROS_INFO("Message_Type=CombinedInfo"); 
} */
int main(int argc ,char** argv)
{
   ros::init(argc, argv, "Publisher");
   ros::NodeHandle nh;
   ros:: Publisher pub = nh.advertise<task_5::CombinedInfo>("ContinousCombinedInfo",1000);
   task_5::CombinedInfo msg;
   while(ros::ok())
   {  
	 Input(msg);  
	 pub.publish(msg);
         ros::spinOnce();
  
   }
   return 0;
}
