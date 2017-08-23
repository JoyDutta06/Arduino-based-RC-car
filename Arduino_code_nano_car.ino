

char dataIn = 'S';        //Character/Data coming from the phone.
int RightMotorEnablePin = 2;
int RightMotorPin1 = 9;
int RightMotorPin2 = 8;
int LeftMotorEnablePin = 3;
int LeftMotorPin1 = 6;
int LeftMotorPin2 = 5;
char determinant;         //Used in the check function, stores the character received from the phone.
char det;                 //Used in the loop function, stores the character received from the phone.
int velocity = 0;    //Stores the speed based on the character sent by the phone.

int incomingByte;
 
void setup() {
  // set the SN754410 pins as outputs:
  pinMode(LeftMotorPin1, OUTPUT);
  pinMode(LeftMotorPin2, OUTPUT);
  pinMode(LeftMotorEnablePin, OUTPUT);
  digitalWrite(LeftMotorEnablePin, HIGH);
  pinMode(RightMotorPin1, OUTPUT);
  pinMode(RightMotorPin2, OUTPUT);
  pinMode(RightMotorEnablePin, OUTPUT);
  digitalWrite(RightMotorEnablePin, HIGH);
  
  // start sending data at 9600 baud rate
  Serial.begin(9600);
}
 
void loop() {
  
     det = check();
      while (det == 'F')   //if incoming data is a F, move forward
      {     
          digitalWrite(LeftMotorPin1, LOW);
          digitalWrite(LeftMotorPin2, HIGH);
          digitalWrite(RightMotorPin1, LOW);
          digitalWrite(RightMotorPin2, HIGH);
              
          det = check();          
      }  
      while (det == 'B')   //if incoming data is a B, move back
      {    
          digitalWrite(LeftMotorPin1, HIGH);
          digitalWrite(LeftMotorPin2, LOW);
          digitalWrite(RightMotorPin1, HIGH);
          digitalWrite(RightMotorPin2, LOW);
          
          det = check();          
      } 
         while (det == 'L')   //if incoming data is a L, move left
      {     
          digitalWrite(LeftMotorPin1, LOW);
          digitalWrite(LeftMotorPin2, HIGH);
          digitalWrite(RightMotorPin1, HIGH);
          digitalWrite(RightMotorPin2, LOW);
          
              
          det = check();          
      }  
      while (det == 'R')   //if incoming data is a R, move right
      {    
          
          digitalWrite(LeftMotorPin1, HIGH);
          digitalWrite(LeftMotorPin2, LOW);
          digitalWrite(RightMotorPin1, LOW);
          digitalWrite(RightMotorPin2, HIGH);
          
          det = check();          
      } 
      while (det == 'S')   //if incoming data is a S, stop
      {
          digitalWrite(LeftMotorPin1, LOW);
          digitalWrite(LeftMotorPin2, LOW);  
          digitalWrite(RightMotorPin1, LOW);
          digitalWrite(RightMotorPin2, LOW);      
          det = check(); 
      }
    }


int check()
{
  if (Serial.available() > 0)    //Check for data on the serial lines.
  {   
    dataIn = Serial.read();  //Get the character sent by the phone and store it in 'dataIn'.
        if (dataIn == 'F')
        {     
          determinant = 'F';
        }  
       else if (dataIn == 'B')
        { 
          determinant = 'B'; 
         }
       else if (dataIn == 'S') 
        {
          determinant = 'S';
        }
       else if (dataIn == 'R')
        {     
          determinant = 'R';
        }  
       else if (dataIn == 'L')
        { 
          determinant = 'L'; 
         }
         
  }
return determinant;
}
