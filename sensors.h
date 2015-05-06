class Sensors {
private:
  MeUltrasonicSensor UltrasonicSensor;
  MeLineFollower lineFinder;

  long lineTime = 0;
  int lineState = -10;

  int distance=0;
  long distanceTime = 0;

public:
  Sensors() : UltrasonicSensor(PORT_4),lineFinder(PORT_5) {
  }
  
void reportDistance() {
  if (millis() - distanceTime > 300) { 
    distanceTime = millis();
    int newDistance = UltrasonicSensor.distanceCm();
    if (newDistance < 500 && abs(newDistance - distance) > 2) {
      Serial.print("distance:");
      Serial.println(distance);
      distance = newDistance;
    }
  }
}

void reportLine() {
  if (millis() - lineTime > 200) { 
    int sensorState = lineFinder.readSensors();
    if (sensorState != lineState) {
      lineState = sensorState;
      switch(sensorState)
      {
        case S1_IN_S2_IN:
          Serial.println("line1:in");
          Serial.println("line2:in");
          break;
        case S1_IN_S2_OUT:
          Serial.println("line1:in");
          Serial.println("line2:out");
          break;
        case S1_OUT_S2_IN:
           Serial.println("line1:out");
           Serial.println("line2:in");      
           break;
        case S1_OUT_S2_OUT:
          Serial.println("line1:out");
          Serial.println("line2:out");        
          break;
        default:break;
      }
    }
  }
}

};
