// Pin 3: input for reading the Button
// Pin 2: output for controlling the LED
int buttonValue = 0;

int delayBeforeTurningRed = 2000;
int timeForGreenLight = 8000;
int delayBeforeTurningGreenOff = 2000;

int button = 3;

int driverYellowLed = 5;
int driverGreenLed = 4;
int driverRedLed = 2;

int differenceBetweenPeopleAndDrivers = 1000;

int peopleGreenLed = 6;
int peopleRedLed = 7;


void setup() {

  pinMode(button, INPUT);
  pinMode(driverRedLed, OUTPUT);
  pinMode(driverGreenLed, OUTPUT);
  pinMode(driverYellowLed, OUTPUT);
  pinMode(peopleRedLed, OUTPUT);
  pinMode(peopleGreenLed, OUTPUT);
}

void buttonPressed() {
    digitalWrite(driverYellowLed, HIGH);

    delay(delayBeforeTurningGreenOff);

    digitalWrite(driverGreenLed,LOW);

    delay(delayBeforeTurningRed);

    turnGreenDrivers();
    
    digitalWrite(peopleRedLed,LOW);
    digitalWrite(peopleGreenLed, HIGH);
    
    delay(timeForGreenLight);
    
    digitalWrite(peopleGreenLed, LOW);
    digitalWrite(peopleRedLed, HIGH);

    delay(differenceBetweenPeopleAndDrivers);

    digitalWrite(driverRedLed, LOW);
}

void turnGreenDrivers() {
    digitalWrite(driverYellowLed, LOW);
    digitalWrite(driverGreenLed, LOW);
    digitalWrite(driverRedLed, HIGH);
}



void loop() {
  buttonValue = digitalRead(button); // read the value gathered by the button pin
  digitalWrite(driverGreenLed, HIGH);
  digitalWrite(peopleRedLed, HIGH);

  if( buttonValue != 0) {
    buttonPressed();
  } else {
    digitalWrite(driverGreenLed, HIGH);
    digitalWrite(peopleRedLed, HIGH);
  }

}
