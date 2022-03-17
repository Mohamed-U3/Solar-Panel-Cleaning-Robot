//  Pins configration
#define M1a           PA5
#define M1b           PA6
#define M1pwm         PB0

#define M2a           PA4
#define M2b           PB1
#define M2pwm         PA7

#define PUMP1         PB15
#define PUMP2         PB14
#define PUMPpwm       PA8

#define proximity1    PB9
#define proximity2    PB8

String operationStatues;
char Statues;
char manualStatues;
boolean manual = 0;
volatile char modes = 0;

void setup()
{
  Serial.begin(9600);
  Serial2.begin(115200);
  Serial3.begin(115200);
  ProximityInit();
  MotorsInit();
  EspInit();
}
void loop()
{
  long int Stime = millis();
  manualStatues = sendData_4();
  if (manualStatues == 'A')
  {
    manual = 0;
  }
  else if (manualStatues == 'B')
  {
    manual = 1;
    Statues = 'S';
  }

  if (manual == 0)
  {
    sendData_2("AT+CIPSTART=\"TCP\",\"162.253.155.225\",80\r\n", 3000);                // it was 550 ms
    sendData_2("AT+CIPSEND=39\r\n", 3000);                                             // it was 350 ms
    operationStatues = sendData_3("GET http://eee.orgfree.com/status.txt\r\n", 3000);  // it was 350 ms
    Statues = operationStatues[41];
  }
  else
  {
    if ((manualStatues == '0') || (manualStatues == '1') || (manualStatues == '2') || (manualStatues == '4') || (manualStatues == 'S' || (manualStatues == 'T')))
    {
      Statues = manualStatues;
    }
  }

  if (Statues == 'S')        //Stop cleaning
  {
    StopCleaningMode();
    modes = 3;
  }
  else if (Statues == 'T')   //Start cleaning
  {
    switch (modes)
    {
      case 0:   FastCleaningMode(); break;
      case 1:   DeepCleaningMode(); break;
      case 2:   WetCleaningMode();  break;
      case 3:   StopCleaningMode(); break;
      case 4:   GoHomeMode();       break;
      default:  StopCleaningMode(); break;
    }
  }
  else if (Statues == '0')  //Fast cleaning mode
    modes = 0;
  else if (Statues == '1')  //Deep cleaning mode
    modes = 1;
  else if (Statues == '2')  //wet cleaning mode
    modes = 2;
  else if (Statues == '4')  //Go Home mode
    modes = 4;

  Serial.print(Statues);
  Serial.print("    <<######>>  ");
  Serial.print(millis() - Stime);
  Serial.println(" ms <<######");
}
