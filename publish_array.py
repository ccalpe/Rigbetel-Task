#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32MultiArray

def array_4_4():
    my_array = [[1, 2, 3, 4],[5, 6, 7, 8],[9, 10, 11, 12],[13, 14, 15, 16]]
    return my_array

def pub_array(my_array):
    pub = rospy.Publisher('esp32_array_topic', Int32MultiArray, queue_size=10)
    rospy.init_node('esp32_array_generator', anonymous=True)
    rate = rospy.Rate(1) # Publish once every second
    while not rospy.is_shutdown():
        array_msg = Int32MultiArray(data=sum(my_array, []))
        pub.publish(array_msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        my_array = array_4_4()
        print("The transmitted Array is: \n{}".format(my_array))
        pub_array(my_array)
    except rospy.ROSInterruptException:
        pass

