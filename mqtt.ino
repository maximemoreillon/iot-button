void mqtt_publish_pressed(){
  Serial.println("[MQTT] Publishing pressed state");


  StaticJsonDocument<MQTT_MAX_PACKET_SIZE> outbound_JSON_message;
  
  outbound_JSON_message["pressed"] = "true";
  
  char mqtt_payload[MQTT_MAX_PACKET_SIZE];
  serializeJson(outbound_JSON_message, mqtt_payload, sizeof(mqtt_payload));

  String topic = iot_kernel.mqtt_base_topic + "/pressed";

  iot_kernel.mqtt.publish(topic.c_str(), mqtt_payload, MQTT_RETAIN);
  
}
