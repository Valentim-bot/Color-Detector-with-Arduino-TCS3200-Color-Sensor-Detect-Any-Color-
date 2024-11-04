
// Define color sensor pins
#define RedLED 9
#define GreenLED 10
#define BlueLED 11

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Calibration Values
// Get these from Calibration Sketch

int redMin = 90; // Red minimum value
int redMax = 285; // Red maximum value
int greenMin = 95; // Green minimum value
int greenMax = 295; // Green maximum value
int blueMin = 75; // Blue minimum value
int blueMax = 235; // Blue maximum value

// Variables for Color Pulse Width Measurements

int redPW = 0;
int greenPW = 0;
int bluePW = 0;

// Variables for final Color values

int redValue;
int greenValue;
int blueValue;

void setup() {

  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(RedLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  
  // Set Sensor output as input
  pinMode(sensorOut, INPUT);
  
  // Set Frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
  
  // Read Red value
  redPW = getRedPW();
  // Map to value from 0-255
  redValue = map(redPW, redMin,redMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  
  // Read Green value
  greenPW = getGreenPW();
  // Map to value from 0-255
  greenValue = map(greenPW, greenMin,greenMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  
  // Read Blue value
  bluePW = getBluePW();
  // Map to value from 0-255
  blueValue = map(bluePW, blueMin,blueMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  

// Assuming redValue, greenValue, and blueValue hold the current RGB readings

//Blue LED

if (redValue>236 && redValue<260 && greenValue>200 && greenValue<260 && blueValue>174 && blueValue<201) {
    // This is BLUE

   Serial.println("This is blue");
   digitalWrite(BlueLED, 1);
   digitalWrite(GreenLED, 0);
   digitalWrite(RedLED, 0);
}
   // Green LED
if (redValue>165 && redValue<190 && greenValue>178 && greenValue<203 && blueValue>153 && blueValue<178) {
 

   Serial.println("This is green");
   digitalWrite(BlueLED, 0);
   digitalWrite(GreenLED, 1);
   digitalWrite(RedLED, 0);
}
    // Red LED
if (redValue>180 && redValue<204 && greenValue>26 && greenValue<50 && blueValue>38 && blueValue<62) {


   Serial.println("This is red");
    digitalWrite(BlueLED, 0);
   digitalWrite(GreenLED, 0);
   digitalWrite(RedLED, 1);
}

// when the R G B Colors are absents
else if(redValue>250 && redValue<285 && greenValue>250 && greenValue<275 && blueValue>190 && blueValue<215){

  Serial.println("Color: YELLOW");
 
    digitalWrite(BlueLED, 0);
   digitalWrite(GreenLED, 0);
   digitalWrite(RedLED, 0);
  

}


  // Print output to Serial Monitor
  Serial.print("Red = ");
  Serial.print(redValue);
  Serial.print(" - Green = ");
  Serial.print(greenValue);
  Serial.print(" - Blue = ");
  Serial.println(blueValue);
  
}


// Function to read Red Pulse Widths
int getRedPW() {

  // Set sensor to read Red only
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;

}

// Function to read Green Pulse Widths
int getGreenPW() {

  // Set sensor to read Green only
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;

}

// Function to read Blue Pulse Widths
int getBluePW() {

  // Set sensor to read Blue only
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;

}