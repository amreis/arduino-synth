void setup()
{
}

void loop()
{
  int pinCounter;
  for (pinCounter = 22; pinCounter <= 36; pinCounter += 2)
  {
    digitalWrite(pinCounter, HIGH);
    delay(200);
    digitalWrite(pinCounter, LOW);
    delay(200);
  }
}
