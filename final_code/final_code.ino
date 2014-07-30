const int button1Pin = 2;  // pushbutton 1 pin
const int button2Pin = 3;  // pushbutton 2 pin
const int ledPin =  13;    // LED pin

const int buzzerPin = 9;
const int songLength = 18;
char notes[] = "cdfda ag cdfdg gf "; // a space represents a rest
int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
int tempo = 150;

void setup()
{
  //5
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);

  // Set up the LED pin to be an output:
  pinMode(ledPin, OUTPUT);  

//9
 pinMode(buzzerPin, OUTPUT);  
}


void loop()
{
  //9
  int i, duration;
  
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
    
    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
  
   while(true){
     int button1State, button2State;  // variables to hold the pushbutton states
     button1State = digitalRead(button1Pin);
     button2State = digitalRead(button2Pin);
     if (((button1State == LOW) || (button2State == LOW))  // if we're pushing button 1 OR button 2
        && !                                               // AND we're NOT
        ((button1State == LOW) && (button2State == LOW))) // pushing button 1 AND button 2                                                     // then...
     {
        digitalWrite(ledPin, HIGH);  // turn the LED on
     }
     else
     {
        digitalWrite(ledPin, LOW);  // turn the LED off
     }
   }
  }
  
int frequency(char note) 
{
   
  int i;
  const int numNotes = 8;  // number of notes we're storing
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}
