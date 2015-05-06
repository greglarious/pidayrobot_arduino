class InfraredCommands {
private:  
  MeInfraredReceiver infraredReceiverDecode;
  Commander& cmdr;
  
public:
  InfraredCommands(Commander& c) : infraredReceiverDecode(PORT_3), cmdr(c){
    infraredReceiverDecode.begin();
  }
  
  void processInfraredCommand() {
    if(infraredReceiverDecode.available() || infraredReceiverDecode.buttonState())
    {
        switch(infraredReceiverDecode.read())
        {
        case IR_BUTTON_PLUS: 
               cmdr.processCommand(FORWARD_CMD,"");
               break;
        case IR_BUTTON_MINUS:
               cmdr.processCommand(BACK_CMD,"");
               break;
        case IR_BUTTON_NEXT:
               cmdr.processCommand(RIGHT_CMD,"");
               break;
        case IR_BUTTON_PREVIOUS:
               cmdr.processCommand(LEFT_CMD,"");
               break;
        case IR_BUTTON_0: 
               cmdr.processCommand(STOP_CMD,"");
               break;
        case IR_BUTTON_9:
               cmdr.ChangeSpeed(9);
               break;
        case IR_BUTTON_8:
               cmdr.ChangeSpeed(8);
               break;
        case IR_BUTTON_7:
               cmdr.ChangeSpeed(7);
               break;
        case IR_BUTTON_6:
               cmdr.ChangeSpeed(6);
               break;
        case IR_BUTTON_5:
               cmdr.ChangeSpeed(5);
               break;
        case IR_BUTTON_4:
               cmdr.ChangeSpeed(4);
               break;
        case IR_BUTTON_3:
               cmdr.ChangeSpeed(3);
               break;
        case IR_BUTTON_2:
               cmdr.ChangeSpeed(2);
               break;
        case IR_BUTTON_1:
               cmdr.ChangeSpeed(1);
               break;
        case IR_BUTTON_TEST:
           break;
        }
    } // ir data was available
  }
};
