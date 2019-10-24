const int pumpPin = 9;    //This is the number of the pin that the pump is connected to
int pumpState = LOW;      //Pump initial state
long previousMillis = 0;  //Will store the last time the pump was updated
long onInterval = 4000UL; // 3 seconds on, 1 second off
long offInterval = 1000UL;

void setup()
{
  pinMode(pumpPin, OUTPUT); // Set pump pin as output
}

void loop()
{
  long currentInterval = (pumpState == LOW) ? offInterval : onInterval;

  unsigned long currentMillis = millis();

  // rollover millis
  if ((unsigned long)(currentMillis - previousMillis) >= currentInterval)
  {
    previousMillis = currentMillis;
    if (pumpState == LOW)
      pumpState = HIGH;
    else
      pumpState = LOW;

    digitalWrite(pumpPin, pumpState);
  }
}