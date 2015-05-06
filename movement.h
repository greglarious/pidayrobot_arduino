
class Movement {
private:
  MeDCMotor MotorL;  
  MeDCMotor MotorR;
  
  int moveSpeed = 190;
  int turnSpeed = 200;

  int minSpeed = 45;
  int factor = 23;

public:
  Movement() : MotorL(M1), MotorR(M2) {
  }
  
  void Forward()
  {
    MotorL.run(-moveSpeed);
    MotorR.run(-moveSpeed);
  }

  void Backward()
  {
    MotorL.run(moveSpeed);
    MotorR.run(moveSpeed);
  }

  void BackwardAndTurnLeft()
  {
    MotorL.run(-moveSpeed/2);
    MotorR.run(-moveSpeed);
  }
  void BackwardAndTurnRight()
  {
    MotorL.run(-moveSpeed);
    MotorR.run(-moveSpeed/2);
  }
  void TurnLeft()
  {
    MotorL.run(-moveSpeed);
    MotorR.run(moveSpeed);
  }
  void TurnRight()
  {
    MotorL.run(moveSpeed);
    MotorR.run(-moveSpeed);
  }
  void Stop()
  {
    MotorL.run(0);
    MotorR.run(0);
  }
  void ChangeSpeed(int spd)
  {
    moveSpeed = factor * spd + minSpeed;
  }
};
