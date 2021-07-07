/*  KH 2021 keitharris89@gmail.com
    Test Code to demo 4d Systems display capabilities 
    and test event handler method
*/

#include <genieArduino.h>
#define DisplaySerial Serial1
const int ledPin = 13;
Genie genie;
const int RESTLINE = 2;
const int buzzer = 4;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);//for debugging, remove for production 
  DisplaySerial.begin(256000);
  genie.Begin(Serial1);
  genie.AttachEventHandler(myGenieEventHandler);
  pinMode(RESTLINE, OUTPUT);
  pinMode(buzzer, OUTPUT);//Set the 2 on Arduino to Output (4D Arduino adpater V2 - Display Reset)
  digitalWrite(RESTLINE, 0); //Reset the display via 
  delay(500);
  digitalWrite(RESTLINE, 1); //unreset the Display via 
  delay(5000); //Let the display start up after the reset (This is important!)
  digitalWrite(buzzer, 0);
}


int gaugeVal = 0;
int scopeVal = 0;
int countDir = 0;
int butVal = 0;
int digitVal = 0;
int i = 0;
int Dbutton;
void loop() {


  while (1) {
    genie.DoEvents();

    if (Dbutton == 1) {
      digitVal++;
      digitalWrite(buzzer, 1);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0, digitVal);

      Dbutton = 0;
      delay(10);//haptic feedback
      digitalWrite(buzzer, 0);
    }

    if (Dbutton == 2) {
      digitVal--;
      digitalWrite(buzzer, 1);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0, digitVal);

      Dbutton = 0;
      delay(10);//haptic feedback
      digitalWrite(buzzer, 0);
    }

    // writing values to scope object temporarily removed to test anibuttons
    //scopeVal = 80;
    //delay(100);
    //scopeVal = 0;

    //    for (i; i >= 0; i <= 6) {
    //      scopeVal = 0;
    //      genie.WriteObject(GENIE_OBJ_SCOPE, 0, scopeVal);
    //      i++;

    //    }
    //    for (i; i <= 6; i >= 0) {
    //      scopeVal = 80;
    //      genie.WriteObject(GENIE_OBJ_SCOPE, 0, scopeVal);
    //      i--;
    //    }


  }
}
void myGenieEventHandler(void)//needed to load up events that you want to monitored
{

  genieFrame Event;
  genie.DequeueEvent(&Event); // Remove the next queued event from the buffer, and process it below
  // I wanted to keep event handler simple. I Did not want to obfuscate logic
  //If the cmd received is from a Reported Event (Events triggered from the Events tab of Workshop4 objects)
  if (Event.reportObject.cmd == GENIE_REPORT_EVENT)
  {
    if (Event.reportObject.object == GENIE_OBJ_ANIBUTTON) //checks to see if anibutton is in que can add any object
    {
      if (Event.reportObject.index == 0)//checks the index of anibutotn
      {
        Dbutton = 1; //do something
      }
      
      if (Event.reportObject.index == 1)//checks the index of anibutotn
      {
        Dbutton = 2; //do a different something
      }
    }
  }
}
