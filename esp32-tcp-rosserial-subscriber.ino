#include <WiFi.h>
#include <WiFiClient.h>
#include <ros.h>
#include <std_msgs/Int32MultiArray.h>

const char* ssid = "Viva 2_2.4G";
const char* password = "9998367868";
IPAddress ros_ip(192,168,1,17);  // Replace with the IP address of your ROS master
const int ros_port = 11311;

WiFiClient client;
ros::NodeHandle nh;

void arrayCallback(const std_msgs::Int32MultiArray& array_msg) {
  int rows = 4;
  int cols = 4;
  int count = 0;
  Serial.println("Received array from ROS:");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      Serial.print(array_msg.data[count]);
      Serial.print("\t");
      count++;
    }
    Serial.println();
  }
}

ros::Subscriber<std_msgs::Int32MultiArray> array_sub("esp32_array_topic", arrayCallback);

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  Serial.print("ROS IP: ");
  Serial.println(ros_ip);
  Serial.print("ROS Port: ");
  Serial.println(ros_port);

  while (!client.connected()) {
    if (client.connect(ros_ip, ros_port)) {
      Serial.println("Connected to ROS master");
    } else {
      Serial.println("Connection to ROS master failed, retrying in 5 seconds...");
      delay(5000);
    }
  }

  nh.initNode();
  nh.subscribe(array_sub);
}

void loop() {
  nh.spinOnce();
  Serial.println("Trying...");
  delay(10);
}
