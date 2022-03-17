String sendData(String command, const int timeout)
{
  String response = "";
  Serial2.print(command);
  char c ;
  long int Ctime = millis();
  while ( (Ctime + timeout) > millis())
  {
    while (Serial2.available())
    {
      c = Serial2.read();
      response.concat(c);
    }
  }
  Serial.print(response);
  return response;
}

String sendData_2(String command, const int timeout)
{
  String response = "";
  Serial2.print(command);
  char c ;
  char o = 0;
  long int Ctime = millis();
  while (((Ctime + timeout) > millis()) && (o == 0))
  {
    while (Serial2.available())
    {
      c = Serial2.read();
      response.concat(c);
    }
    if (response.indexOf("OK") > 0)
    {
      o = 1;
    }
  }
  Serial.print(response);
  Serial.print("    ");
  Serial.print(millis() - Ctime);
  Serial.println("ms");
  return response;
}

String sendData_3(String command, const int timeout)
{
  String response = "";
  Serial2.print(command);
  char c ;
  char o = 0;
  long int Ctime = millis();
  while (((Ctime + timeout) > millis()) && (o == 0))
  {
    while (Serial2.available())
    {
      c = Serial2.read();
      response.concat(c);
    }
    if (response.indexOf("CLOSED") > 0)
    {
      o = 1;
    }
  }
  Serial.print(response);
  Serial.print("    ");
  Serial.print(millis() - Ctime);
  Serial.println("ms");
  return response;
}

char sendData_4()
{
  char ch;
  long int Ctime = millis();
  while ((Ctime + 3) > millis())
  {
    while (Serial3.available())
    {
      ch = Serial3.read();
    }
  }

  return ch;
}

void EspInit()
{
  sendData("AT+RST\r\n", 500);
  sendData("AT+CWMODE=1\r\n", 500);
  //  sendData("AT+CWJAP_CUR=\"El_Net_Fasel\",\"mafee4Wifi\"\r\n", 11000);
  sendData("AT+CWJAP_CUR=\"U3\",\"mmyralimmo1\"\r\n", 11000);
}
