# Rigbetel-Task
This repo contains the files that were needed to be built for completing the follow-on task given after the Interview

The file contains the python publisher script _"publish_array.py"_ used to generate the 4x4 Array and the ESP32 Arduino IDE file _"esp32-tcp-rosserial-subscriber.ino"_ used to receive it via TCP and Print the incoming data on the Serial Monitor

Steps to execute the task
1. Start ROS Master
2. Run the esp32-array-generator rosnode using publish_array.py
3. Make sure the ESP32 Dev Board has the required file and wait for the Message "Connected to ROS Master"
4. Run the command _rosrun rosserial_python serial_node.py tcp_ node to enable TCP connection between rosserial on the client ESP32 and the local ROS instance.
5. The array published by the esp-32-array-generator will be received by the esp32 via the "esp32_array_topic" topic
