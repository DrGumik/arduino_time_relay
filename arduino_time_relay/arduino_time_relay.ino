// TIME RELAY CONTROLLER
// CREATED BY JAKUB TENK

// PINS
int pinRelay = 9; // Relay
int pinLedOn = 8; // Led if relay is on
int pinLedOff = 7; // Led if relay is off
int pinSwitchPos1 = 6; // 10 min
int pinSwitchPos2 = 5; // 15 min
int pinSwitchPos3 = 4; // 20 min
int pinSwitchPos4 = 3; // 25 min
int pinStopBtn = 2; // STOP BUTTON

// VARIABLES
bool loopCheck = true;
int time = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int stopBtn = 0;

// CODE
void setup()
{
    //Serial.begin(9600);
    pinMode(pinRelay, OUTPUT);
    pinMode(pinLedOn, OUTPUT);
    pinMode(pinLedOff, OUTPUT);
    pinMode(pinSwitchPos1, INPUT);
    pinMode(pinSwitchPos2, INPUT);
    pinMode(pinSwitchPos3, INPUT);
    pinMode(pinSwitchPos4, INPUT);
}

void loop()
{  
  	pos1 = digitalRead(pinSwitchPos1);
  	pos2 = digitalRead(pinSwitchPos2);
  	pos3 = digitalRead(pinSwitchPos3);
  	pos4 = digitalRead(pinSwitchPos4);
  
  	if (pos1==1) time = 600000;
  	if (pos2==1) time = 900000;
  	if (pos3==1) time = 1200000;
  	if (pos4==1) time = 1500000;
  	if (pos1!=1&&pos2!=1&&pos3!=1&&pos4!=1) time = 0;
  
    if (loopCheck == true && time > 0) {
		//Serial.write(" START \n");
      	loopCheck = false;
      	process();
    }
  	delay(0);
}

void process()
{
  	digitalWrite(pinRelay, HIGH);
    digitalWrite(pinLedOn, HIGH);
    digitalWrite(pinLedOff, LOW);
  
  	for (int i = 0; i <= time; i++) {
  		stopBtn = digitalRead(pinStopBtn);
      
      	if (stopBtn==1) {
  			//Serial.write(" STOP \n");
        	break;
      	}
      
      	delay(1);
    }
  
    digitalWrite(pinRelay, LOW);
    digitalWrite(pinLedOn, LOW);
    digitalWrite(pinLedOff, HIGH);
    loopCheck = true;
    delay(1);
}
