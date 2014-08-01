
PImage img;
PImage chart;
int pressed;
String morse, translated;
String[] alpha = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
            "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
            "w", "x", "y", "z", "1", "2", "3", "4", "5", "6", "7", "8",
            "9", "0", " " };
String[] dots = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
            "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
            "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--..", ".----", "..---", "...--", "....-", ".....",
            "-....", "--...", "---..", "----.", "-----", "|" };
int index;  
boolean show;

void setup() {
  size(700, 500);
  img = loadImage("aluminum-foil.jpg");
  //chart = loadImage("chart.png");
  pressed = 0;
  morse = "";
  translated = "";
  index = 0;
  show = true;
}

void draw() {
  stroke(0);
  fill(255);
  ellipse(80, 120, 50, 50);
  
  image(img, 0, 200, 270, 200);
 // image(chart, 0, 0);
  
 // line(443, 0, 443, 700);
  line(300, 0, 300, 700);
  
  noStroke();
  fill(0);
  rect(301, 0, 400, 500);
  
  stroke(255);
  fill(255);
  textSize(26);
  text(morse, 306, 50);
  text(translated, 306, 450);
  fill(0);
  if (show) text("click", 56, 300);
  
  if (mousePressed == true && mouseX >= 0 && mouseX <= 270 && mouseY >= 200 && mouseY <= 400) {
    stroke(0);
    fill(255, 0, 0);
    ellipse(80, 120, 50, 50);
    pressed++;
    show = false;
  }
  
}

void mouseReleased() {
  if (pressed <= 20 && pressed != 0) morse += ".";
  if (pressed > 20) morse += "-";
  pressed = 0;
}

void keyPressed() {
  if (key == 'r') {
      morse = "";
      translated = "";
      index = 0;
  }           
  if (key == ' ') {
    String mletter = morse.substring(index, morse.length());
    int j = 0;
    boolean match = false;
    for (int i = 0; i < 37; i++) {
      if (dots[i].equals(mletter)) {
        j = i;
        match = true;
      }
    }
    if (match == true) {
      String aletter = alpha[j];
      translated += aletter;
      morse += " ";
      index = morse.length();
    }
  }
  if (key == ',') {
    morse += "|";
  }
  
}



