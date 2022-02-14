const int FPIN0 = A0;
const int FPIN1 = A1;
const int FPIN2 = A2;
const int FPIN3 = A3;
const int FPIN4 = A4;

// data
const int S = 0;
const int O = 1;
const int F = 2;
const int T = 3;
const int W = 4;
const int A = 5;
const int R = 6;
const int E = 7;
const int SPACE = 8;
const int N = 9;
const int G = 10;
int prev = -1;

// make the minimum to 999999999 (a value that can never be reached by the flexsensor) max to 0 and create a difference for all the sensor values
double fmin0 = 999999999;
double fmax0 = 0;

double fmin1 = 999999999;
double fmax1 = 0;

double fmin2 = 999999999;
double fmax2 = 0;

double fmin3 = 999999999;
double fmax3 = 0;

double fmin4 = 999999999;
double fmax4 = 0;

void setup() {
  
  char temp = '\0';

  // serial begin and if wait for it to completly load before completed 
  Serial.begin(9600);
  while(!Serial){
    ;
  }

  while(millis() < 15000){

    // the sensor read
    double fr0 = analogRead(FPIN0);
    double fr1 = analogRead(FPIN1);
    double fr2 = analogRead(FPIN2);
    double fr3 = analogRead(FPIN3);
    double fr4 = analogRead(FPIN4);

    // get min and max for all
    if(fr0 < fmin0){
      fmin0 = fr0;
    }
    if(fr0 > fmax0){
      fmax0 = fr0;
    }
    
    if(fr1 < fmin1){
      fmin1 = fr1;
    }
    if(fr1 > fmax1){
      fmax1 = fr1;
    }
    
    if(fr2 < fmin2){
      fmin2 = fr2;
    }
    if(fr2 > fmax2){
      fmax2 = fr2;
    }
    
    if(fr3 < fmin3){
      fmin3 = fr3;
    }
    if(fr3 > fmax3){
      fmax3 = fr3;
    }
    
    if(fr4 < fmin4){
      fmin4 = fr4;
    }
    if(fr4 > fmax4){
      fmax4 = fr4;
    }
    
  }

  Serial.println("");

}

void printfunc(double r0, double r1, double r2, double r3, double r4){

  int letter = prev;
  
  if(r0 <= 25 && r1 <= 25 && r2 <= 35 && r3 <= 25 && r4 <= 25){
    letter = S;
  }
  else if(r0 <= 45 && r1 > 25 && r1 <= 60 && r2 > 25 && r2 <= 60 && r3 > 25 && r3 <= 60 && r4 > 25 && r4 <= 60){
    letter = O;
  }
  else if(r0 > 20 && r1 > 20 && r1 <= 40 && r2 > 50 && r3 > 75 && r4 > 75){
    letter = F;   
  }
  else if(r0 > 25 && r1 > 15 && r1 <= 45 && r2 <= 25 && r3 <= 30 && r4 > 15 && r4 <= 40){
    letter = T;
  }
  else if(r0 > 45 && r1 > 80 && r2 > 80 && r3 > 80 && r4 > 30 && r4 <= 60){
    letter = W;
  }
  else if(r0 > 50 && r0 <= 60 && r1 <= 30 && r2 <= 30 && r3 <= 30 && r4 <= 45){
    letter = A;
  }
  else if(r0 > 45 && r1 > 80 && r2 > 55 && r3 <= 35 && r4 > 20 && r4 <= 45){
    letter = R;
  }
  else if(r0 <= 20 && r1 > 25 && r1 <= 45 && r2 <= 35 && r3 <= 45 && r4 <= 40){
    letter = E;
  }
  else if(r0 >= 40 && r1 >= 80 && r2 >= 80 && r3 >= 80 && r4 >= 80){
    letter = SPACE;
  }
  else if(r0 <= 20 && r1 > 25 && r1 <= 45 && r2 <= 35 && r3 <= 45 && r4 <= 40){
    letter = N;
  }
  else if(r0 <= 20 && r1 > 25 && r1 <= 45 && r2 <= 35 && r3 <= 45 && r4 <= 40){
    letter = G;
  }

  if(letter != prev){
    prev = letter;
    switch(letter){
    
    case S: 
      Serial.println("S");
      break;
    
    case O:
      Serial.println("O");
      break;
    
    case F:
      Serial.println("F");
      break;
    
    case T:
      Serial.println("T");
      break;
    
    case W:
      Serial.println("W");
      break;
    
    case A:
      Serial.println("A");
      break;
    
    case R:
      Serial.println("R");
      break;
    
    case E:
      Serial.println("E");
      break;
    
    case SPACE:
      Serial.println("E");
      break;
    
    case N:
      Serial.println("E");
      break;
    
    case G:
      Serial.println("E");
      break;

    default:
      Serial.println("^");
    }
  }
  
}

void loop() {

  // the sensor read
  double fr0 = analogRead(FPIN0);
  double fr1 = analogRead(FPIN1);
  double fr2 = analogRead(FPIN2);
  double fr3 = analogRead(FPIN3);
  double fr4 = analogRead(FPIN4);

  // the mapped sensor read
  double mfr0 = map(fr0, fmax0, fmin1, 0, 90);
  double mfr1 = map(fr1, fmax1, fmin1, 0, 90);
  double mfr2 = map(fr2, fmax2, fmin2, 0, 90);
  double mfr3 = map(fr3, fmax3, fmin3, 0, 90);
  double mfr4 = map(fr4, fmax4, fmin4, 0, 90);

  //Serial.println("For testing purpose only: ");

  //Serial.println(mfr0);
  //Serial.println(mfr1);
  //Serial.println(mfr2);
  //Serial.println(mfr3);
  //Serial.println(mfr4);
  //Serial.println("");

 
  delay(10000);

  // to delay 1000 to stablize


}
