const int button1Pin = 2;  // pushbutton 1 pin
const int button2Pin = 3;  // pushbutton 2 pin
const int button3Pin = 4;  // pushbutton 3 pin
const int button4Pin = 5;  // pushbutton 4 pin
const int ledPin =  13;    // LED pin

String morse = "";         // message
int counter = 0;           // beats

const int buzzerPin = 9;   // buzzer pin

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  
  // Set up the LED pin to be an output:
  pinMode(ledPin, OUTPUT);
  // Set up the buzzer to be an output:
  pinMode(buzzerPin, OUTPUT);  
}


void loop()
{
     // making the pins boolean values to read:
     int button1State, button2State, button3State, button4State;  // variables to hold the pushbutton states
     button1State = digitalRead(button1Pin);
     button2State = digitalRead(button2Pin);
     button3State = digitalRead(button3Pin);
     button4State = digitalRead(button4Pin);
     
       
     // Function for button 1:
     if (button1State == LOW && (button2State == HIGH && button3State == HIGH)) {
       tone(buzzerPin, 262, 500);
       digitalWrite(ledPin, HIGH);
       delay(500);
       digitalWrite(ledPin, LOW);
       morse += '0';
       counter++;
     }
     
    
     // Function for button 2:
     if (button2State == LOW && (button1State == HIGH && button3State == HIGH)) {
       tone(buzzerPin, 262, 1500);
       digitalWrite(ledPin, HIGH);
       delay(1500);
       digitalWrite(ledPin, LOW);
       morse += '1';
       counter++;
     }
     
     
     // Function for button 3:
     if (button3State == LOW  && (button1State == HIGH && button2State == HIGH)) {
       digitalWrite(ledPin, HIGH);
       delay(500);
       digitalWrite(ledPin, LOW);
       morse += 's';
       counter++;
     }
     
     
     //Function for button 43
     if (button4State == LOW) {
        for (int i = 0; i < counter; i++) {
         
         if (morse.charAt(i) == '0') {
           tone(buzzerPin, 262, 500);
           digitalWrite(ledPin, HIGH);
           delay(500);
           digitalWrite(ledPin, LOW);
         }
         
         if (morse.charAt(i) == '1') {
           tone(buzzerPin, 262, 1500);
           digitalWrite(ledPin, HIGH);
           delay(1500);
           digitalWrite(ledPin, LOW);           
         }
         
         if (morse.charAt(i) == 's') {
           digitalWrite(ledPin, HIGH);
           delay(500);
           digitalWrite(ledPin, LOW);
         }
         
         delay(500);

       }
     }
     
     
     
   
     
  }
