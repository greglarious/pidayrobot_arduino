class SerialCommands {
  Commander& cmdr;

public:  
  SerialCommands(Commander& c) : cmdr(c){
  }

  void processSerialCommand() {
    String serialCmd;
    //
    // read command from serial first
    while (Serial.available() > 0)
    {
    char recieved = Serial.read();
        
    if (recieved == '\n')
    {
      char cmd_code = serialCmd[0];
      String cmd_param = serialCmd.substring(1);
      cmdr.processCommand(cmd_code, cmd_param);
      serialCmd = ""; // Clear recieved buffer
    } else {
      serialCmd += recieved; 
    }
    }
  }
  
};
