PImage img;
int pressed, released;
String morse, translated;
char[] alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
            'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
            'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8',
            '9', '0', ' ' };
String[] dots = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
            "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--..", ".----", "..---", "...--", "....-", ".....",
            "-....", "--...", "---..", "----.", "-----", "|" };
int index;            

void setup() {
  size(700, 500);
  img = loadImage("aluminum-foil.jpg");
  pressed = 0;
  morse = "";
  index = 0;
}

void draw() {
  stroke(0);
  fill(255);
  ellipse(80, 120, 50, 50);
  
  image(img, 0, 200, 270, 200);
  
  line(300, 0, 300, 700);
  
  noStroke();
  fill(255);
  rect(301, 0, 400, 500);
  
  stroke(0);
  fill(0);
  textSize(26);
  text(morse, 400, 50);
  
  if (mousePressed == true && mouseX >= 0 && mouseX <= 270 && mouseY >= 200 && mouseY <= 400) {
    stroke(0);
    fill(255, 0, 0);
    ellipse(80, 120, 50, 50);
    pressed++;
  }
  
  released++;
}

void mouseReleased() {
  if (pressed <= 20) morse += '.';
  if (pressed > 20) morse += '-';
  println(morse);
  pressed = 0;
}

void mousePressed() {
  if (released > 60 && released < 170) {
    morse += ' ';
    String mletter = morse.substring(index, morse.length() - 1);
    int j = 0;
    for (int i = 0; i < 37; i++) {
      if (dots[i].equals(mletter)) j = i;
    }
    char aletter = alpha[j];
    translated += aletter;
    
    index = morse.length() - 1;
  }
  if (released > 170) {
    morse += '|';
    translated += ' ';
  }
  released = 0;
}

void keyPressed() {
  if (key == ' ') morse = "";
}



