#define FORWARD_CMD 'F'
#define BACK_CMD 'B'
#define LEFT_CMD 'L'
#define RIGHT_CMD 'R'
#define STOP_CMD 'S'
#define VELOCITY_CMD 'V'

class Commander {
Movement mover;

public:
Commander (Movement m) {
  mover = m;
}
void ackCommand(char cmd) {
  Serial.print("ack:");
  Serial.println(cmd);
}

void nackCommand(char cmd) {
  Serial.print("nack:");
  Serial.println(cmd);
}

void ChangeSpeed(int spd) {
  mover.ChangeSpeed(spd);
}
void processCommand(char cmd, String param) {
  switch (cmd) {
  case FORWARD_CMD:
    ackCommand(cmd);
    mover.Forward();
    break;
  case BACK_CMD:  
    ackCommand(cmd);
    mover.Backward();
    break;
  case LEFT_CMD:
    ackCommand(cmd);
    mover.TurnLeft();
    break;
  case RIGHT_CMD:
    ackCommand(cmd);
    mover.TurnRight();
    break;
  case STOP_CMD:
    ackCommand(cmd);
    mover.Stop();
    break;  
  default:  
    nackCommand(cmd);
  }
}
};

