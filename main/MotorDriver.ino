void MotorsInit()
{
  //A Motor1
  pinMode(M1a, OUTPUT);
  pinMode(M1b, OUTPUT);
  pinMode(M1pwm, PWM);
  //B Motor2
  pinMode(M2a, OUTPUT);
  pinMode(M2b, OUTPUT);
  pinMode(M2pwm, PWM);
  //Pump Motor
  pinMode(PUMP1, OUTPUT);
  pinMode(PUMP2, OUTPUT);
  pinMode(PUMPpwm, PWM);
}
void PUMP_on()
{
  digitalWrite(PUMP1, LOW);
  digitalWrite(PUMP2, HIGH);
  pwmWrite(PUMPpwm, 65535);
}
void PUMP_off()
{
  digitalWrite(PUMP1, LOW);
  digitalWrite(PUMP2, LOW);
  pwmWrite(PUMPpwm, 0);
}
void Motor1CW(unsigned int pwm_val)
{
  digitalWrite(M1a, LOW);
  digitalWrite(M1b, HIGH);
  pwmWrite(M1pwm, pwm_val);
}
void Motor2CW(unsigned int pwm_val)
{
  digitalWrite(M2a, LOW);
  digitalWrite(M2b, HIGH);
  pwmWrite(M2pwm, pwm_val);
}

void Motor1CCW(unsigned int pwm_val)
{
  digitalWrite(M1a, HIGH);
  digitalWrite(M1b, LOW);
  pwmWrite(M1pwm, pwm_val);
}
void Motor2CCW(unsigned int pwm_val)
{
  digitalWrite(M2a, HIGH);
  digitalWrite(M2b, LOW);
  pwmWrite(M2pwm, pwm_val);
}

void Motor1Stop()
{
  digitalWrite(M1a, LOW);
  digitalWrite(M1b, LOW);
  pwmWrite(M1pwm, 0);
}
void Motor2Stop()
{
  digitalWrite(M2a, LOW);
  digitalWrite(M2b, LOW);
  pwmWrite(M2pwm, 0);
}

void FastCleaningMode()
{
  if (digitalRead(proximity1) == LOW)
  {
    StopCleaningMode();
    operationStatues[37] = 'S';
    modes = 3;
  }
  else
  {
    Motor1CW(65535);
    Motor2CW(65535);
    PUMP_off();
  }
}
void DeepCleaningMode()
{
  if (digitalRead(proximity1) == LOW)
  {
    StopCleaningMode();
    operationStatues[37] = 'S';
    modes = 3;
  }
  else
  {
    Motor1CW(65535);
    Motor2CW(65535 / 2);
    PUMP_off();
  }
}
void WetCleaningMode()
{
  if (digitalRead(proximity1) == LOW)
  {
    StopCleaningMode();
    operationStatues[37] = 'S';
    modes = 3;
  }
  else
  {
    Motor1CW(65535 / 3);
    Motor2CW(65535 / 2);
    PUMP_on();
  }
}
void GoHomeMode()
{
  if (digitalRead(proximity2) == LOW)
  {
    StopCleaningMode();
    operationStatues[37] = 'S';
    modes = 3;
  }
  else
  {
    Motor1CCW(65535);
    Motor2CCW(65535);
    PUMP_off();
  }
}
void StopCleaningMode()
{
  Motor1Stop();
  Motor2Stop();
  PUMP_off();
}
