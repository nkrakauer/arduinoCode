int calibrationTime = 30;
long unsigned int pause = 4000;
int notes[] = {262, 200, 340, 355, 250};
int notesSize = 5;
int speakerOut = 7;
int pirSensor = 11;
int val = 0;

//star wars

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speakerOut, OUTPUT); //pizeo as output
  pinMode(pirSensor, INPUT); //pir sensor as input

  Serial.print("calibrating sensor ");
  for(int i = 0; i < calibrationTime; i++)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("done");
  Serial.println("sensor active");
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(pirSensor);

  //if motion detected play sound
  if(val == HIGH)
  {
    Serial.print(" motion detected ");
    tone(speakerOut, notes[0]);
  }

  if(val == LOW)
  {
    noTone(speakerOut);
  }

}
