// AIR HOCKEY CONTROLER - TIME RELAY
// CREATED BY JAKUB TENK

// Arrays with IN / OUT pins number
int outputPins[3] = {
  9, // RELAY
  8, // GREEN LED
  7 // RED LED
};

int inputPins[5] = {
  6, // 5 min
  5, // 10 min
  4, // 15 min
  3, // 20 min
  2 // STOP BTN
};

// Initialization - setup pins
void setup()
{
  for(int i = 0; i < sizeof(outputPins); i++)
  	pinMode(outputPins[i], OUTPUT);
  
  for(int i = 0; i < sizeof(inputPins); i++)
  	pinMode(inputPins[i], INPUT);
	
  //Serial.begin(9600);
}

// Main loop
void loop()
{  
  // Disable relay and turn off green led, turn on red led
  digitalWrite(outputPins[0], LOW);
  digitalWrite(outputPins[1], LOW);
  digitalWrite(outputPins[2], HIGH);
  
  // Time variables
  float time = 0;
  float timeMultiplier = 300000; // 5 min
  int numberOfTimeSelectionBtns = 4;
  
  
  // Read input pins  
  for(int i = 0; i < 5; i++)
  {
  	if (digitalRead(inputPins[i]) && i != numberOfTimeSelectionBtns)
  	{  
      		time = (i + 1) * timeMultiplier;
      		break;
      	}
      	else
        	time = 0;
  }
  
  if (time > 0)
  {
      	/*
        Serial.write("\n\rSTARTING PROCESS\n\r");
      	Serial.write("TIME: ");
      	Serial.print(time);
      	Serial.write(" ms\n\r\n\r");
      	*/
      
      	process(time);
  }
  
  delay(0);
}

// Process function for enabled relay
void process(float time)
{
  // Enable relay and turn on green led
  digitalWrite(outputPins[0], HIGH);
  digitalWrite(outputPins[1], HIGH);
  digitalWrite(outputPins[2], LOW);
	
  // Check if stop btn is pressed while counting time
  for (int i = 0; i <= time; i++) {
  	if (digitalRead(inputPins[4]))
        	break;
	  
      	delay(1);
    }
}
