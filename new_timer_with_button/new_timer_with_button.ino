int HH=00;
int MM=01;
bool timerRunning = false;

unsigned long previousMillis = 0;
long interval= 1000;
int a,b,c,d,e;
int i=5;
//byte On=0;
int button_1 = A0;                                //for updating hour
int button_2 = A1;                                //for updating second
int button_3 = A2;                                //for updating minute


int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;

int digit1=9;
int digit2=10;
int digit3=11;
int digit4=12;
int dot=13;

void setup() {
  pinMode(segA ,OUTPUT);
  pinMode(segB ,OUTPUT);
  pinMode(segC ,OUTPUT);
  pinMode(segD ,OUTPUT);
  pinMode(segE ,OUTPUT);
 // pinMode(segE ,OUTPUT);
  pinMode(segF ,OUTPUT);
  pinMode(segG ,OUTPUT);

  pinMode(digit1 ,OUTPUT);
  pinMode(digit2 ,OUTPUT);
  pinMode(digit3 ,OUTPUT);
  pinMode(digit4 ,OUTPUT);
  pinMode(13, OUTPUT);

    
    pinMode(button_1,INPUT_PULLUP);
    pinMode(button_2,INPUT_PULLUP);
    pinMode(button_3,INPUT_PULLUP);
// Serial.begin(9600);
// Serial.println("multiplexing");

}


void loop() {


// Start timer if button 1 (A0) is pressed
if (digitalRead(button_1) == LOW) {
  timerRunning = true;
  delay(200);  // Debounce
}

// Increase HH if button 2 (A1) is pressed
if (digitalRead(button_2) == LOW && !timerRunning) {
  HH = (HH + 1) % 100;  // You can cap it at 24 if needed
  delay(200);
}

// Increase MM if button 3 (A2) is pressed
if (digitalRead(button_3) == LOW && !timerRunning) {
  MM = (MM + 1) % 60;
  delay(200);
}




 unsigned long currentMillis= millis();
if (timerRunning && (currentMillis - previousMillis >= interval)) {
 
  previousMillis = currentMillis;





  digitalWrite(13, LOW); // LED off during countdown

  if (MM == 0) {
    if (HH == 0) {
      HH = 0; MM = 0;
    } else {
      HH -= 1;
      MM = 59;
    }
  } else {
    MM -= 1;
  }
 if (HH == 0 && MM == 0) {
 a = b = c = d = 11;  // Use 11 for dash
  return;
 }

  Serial.print(HH);
  Serial.print(":");
  if (MM < 10) Serial.print("0");
  Serial.println(MM);
}
  
  a= int(HH/10);
  b= int(HH%10);
  c= int(MM/10);
  d= int(MM%10);


if (HH == 0 && MM == 0) {
  digitalWrite(13, HIGH);

  if ((millis() / 500) % 2 == 0) {
    a = b = c = d = 11;  // Dash
  } else {
    a = b = c = d = 10;  // Blank
  }
}


  
    lightNumber(a);
  digitalWrite(digit1,HIGH);
  digitalWrite(digit2,LOW);
  digitalWrite(digit3,LOW);
  digitalWrite(digit4,LOW);
  delay(i);
  
    lightNumber(b);
  digitalWrite(digit1,LOW);
  digitalWrite(digit2,HIGH);
  digitalWrite(digit3,LOW);
  digitalWrite(digit4,LOW);
  delay(i);

    lightNumber(c);
  digitalWrite(digit1,LOW);
  digitalWrite(digit2,LOW);
  digitalWrite(digit3,HIGH);
  digitalWrite(digit4,LOW);
  delay(i);

    lightNumber(d);
  digitalWrite(digit1,LOW);
  digitalWrite(digit2,LOW);
  digitalWrite(digit3,LOW);
  digitalWrite(digit4,HIGH);
  delay(i);

//  lightNumber(e);
//   digitalWrite(digit1,HIGH);
//   digitalWrite(digit2,HIGH);
//   digitalWrite(digit3,HIGH);
//   digitalWrite(digit4,HIGH);
//   delay(i);

  //if(HH==01){digitalWrite(dot,HIGH);}
}

void lightNumber(int numberToDisplay){

  #define SEGMENT_ON LOW
  #define SEGMENT_OFF HIGH

    switch (numberToDisplay){
      

      case 0: 
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_OFF);
      break;

      case 1: 
      digitalWrite(segA, SEGMENT_OFF);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_OFF);
      break;

      case 2: 
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_OFF);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_ON);
      break;


      case 3: 
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_ON);
      break;

      case 4: 
      digitalWrite(segA, SEGMENT_OFF);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;

      case 5: 
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;

      case 6: 
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_OFF);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;

      case 7: 
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_OFF);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_OFF);
      digitalWrite(segG, SEGMENT_OFF);
      break;

    case 8: 
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_ON);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;

    case 9: 
      digitalWrite(segA, SEGMENT_ON);
      digitalWrite(segB, SEGMENT_ON);
      digitalWrite(segC, SEGMENT_ON);
      digitalWrite(segD, SEGMENT_ON);
      digitalWrite(segE, SEGMENT_OFF);
      digitalWrite(segF, SEGMENT_ON);
      digitalWrite(segG, SEGMENT_ON);
      break;

    case 10: // Blank segment
  digitalWrite(segA, SEGMENT_OFF);
  digitalWrite(segB, SEGMENT_OFF);
  digitalWrite(segC, SEGMENT_OFF);
  digitalWrite(segD, SEGMENT_OFF);
  digitalWrite(segE, SEGMENT_OFF);
  digitalWrite(segF, SEGMENT_OFF);
  digitalWrite(segG, SEGMENT_OFF);
  break;

  case 11: // Dash
  digitalWrite(segA, SEGMENT_OFF);
  digitalWrite(segB, SEGMENT_OFF);
  digitalWrite(segC, SEGMENT_OFF);
  digitalWrite(segD, SEGMENT_OFF);
  digitalWrite(segE, SEGMENT_OFF);
  digitalWrite(segF, SEGMENT_OFF);
  digitalWrite(segG, SEGMENT_ON); // Only middle segment ON
  break;


        
    }
}