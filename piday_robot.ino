#include <Makeblock.h>
#include <SoftwareSerial.h>
#include <Wire.h>

#include "movement.h"
#include "commander.h"
#include "sensors.h"
#include "infraredCmd.h"
#include "serialCmd.h"

Movement mover;
Commander cmdr(mover);
InfraredCommands ir(cmdr);
SerialCommands ser(cmdr);
Sensors sensors;

void setup()
{  
gst-launch-1.0 -e -v tcpclientsrc host="172.17.166.255" port=5001  ! ^
application/x-gdp ! gdpdepay ! rtpjitterbuffer !  ^
rtph264depay ! ^
avdec_h264 ! ^
autovideosink sync=false text-overlay=false  Serial.begin(9600);
}

void loop()
{
  ser.processSerialCommand();
  ir.processInfraredCommand();
  sensors.reportDistance();
  sensors.reportLine();
}
