void ProximityInit()
{
  pinMode(proximity1, INPUT_PULLUP);
  pinMode(proximity2, INPUT_PULLUP);
  attachInterrupt(proximity1, prox1, FALLING);
  attachInterrupt(proximity2, prox2, FALLING);
}

void prox1()
{
  StopCleaningMode();
  operationStatues[37] = 'S';
  modes = 3;
  //write something that gonna stop the system from moving and tells the other fucntion that
  //the system has reached to the end .... maybe you gonna let the system go back to the begaining and
  //start cleaing again for numbers of counts to ensure the cleaning
}
void prox2()
{
  StopCleaningMode();
  operationStatues[37] = 'S';
  modes = 3;
  //write something that gonna stop the system from moving and tells the other fucntion that
  //the system has reached to the end .... maybe you gonna let the system go back to the begaining and
  //start cleaing again for numbers of counts to ensure the cleaning
}
