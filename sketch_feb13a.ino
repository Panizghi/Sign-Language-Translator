// Constants for flex sensor pins
const int NUM_FLEX_SENSORS = 5;
const int FLEX_PINS[NUM_FLEX_SENSORS] = {A0, A1, A2, A3, A4};

// Constants for analog input values
const int ANALOG_MIN = 0;
const int ANALOG_MAX = 1023;

// Constants for mapped values
const int MAPPED_MIN = 0;
const int MAPPED_MAX = 90;

// Data representation
const int CHAR_S = 0;
const int CHAR_O = 1;
const int CHAR_F = 2;
const int CHAR_T = 3;
const int CHAR_W = 4;
const int CHAR_A = 5;
const int CHAR_R = 6;
const int CHAR_E = 7;
const int CHAR_SPACE = 8;
const int CHAR_N = 9;
const int CHAR_G = 10;

class FlexSensor {
public:
  FlexSensor(int pin) : pin(pin), minValue(ANALOG_MAX), maxValue(ANALOG_MIN) {}

  void calibrate() {
    for (int i = 0; i < 5; i++) {
      double value = analogRead(pin);
      updateMinMax(value);
    }
  }

  double getMappedValue() const {
    double value = analogRead(pin);
    return map(value, maxValue, minValue, MAPPED_MIN, MAPPED_MAX);
  }

private:
  int pin;
  int minValue;
  int maxValue;

  void updateMinMax(double value) {
    if (value < minValue) {
      minValue = value;
    }
    if (value > maxValue) {
      maxValue = value;
    }
  }
};

// Create an array of FlexSensor objects
FlexSensor flexSensors[NUM_FLEX_SENSORS] = {
    FlexSensor(FLEX_PINS[0]),
    FlexSensor(FLEX_PINS[1]),
    FlexSensor(FLEX_PINS[2]),
    FlexSensor(FLEX_PINS[3]),
    FlexSensor(FLEX_PINS[4])
};

int prev = -1;

void setup() {
  // Serial begin and wait for it to complete loading
  Serial.begin(9600);
  while (!Serial)
    ;

  // Calibrate sensors
  for (int i = 0; i < NUM_FLEX_SENSORS; i++) {
    flexSensors[i].calibrate();
  }

  Serial.println("");
}

void printChar(int charCode) {
  switch (charCode) {
  case CHAR_S:
    Serial.println("S");
    break;

  case CHAR_O:
    Serial.println("O");
    break;

  case CHAR_F:
    Serial.println("F");
    break;

  case CHAR_T:
    Serial.println("T");
    break;

  case CHAR_W:
    Serial.println("W");
    break;

  case CHAR_A:
    Serial.println("A");
    break;

  case CHAR_R:
    Serial.println("R");
    break;

  case CHAR_E:
    Serial.println("E");
    break;

  case CHAR_SPACE:
    Serial.println(" ");
    break;

  case CHAR_N:
    Serial.println("N");
    break;

  case CHAR_G:
    Serial.println("G");
    break;

  default:
    Serial.println("^");
  }
}

void loop() {
  double mappedValues[NUM_FLEX_SENSORS];

  // Read and map values for all flex sensors
  for (int i = 0; i < NUM_FLEX_SENSORS; i++) {
    mappedValues[i] = flexSensors[i].getMappedValue();
  }

  // Print characters based on mapped values
  int letter = prev;
  if (mappedValues[0] <= 25 && mappedValues[1] <= 25 && mappedValues[2] <= 35 &&
      mappedValues[3] <= 25 && mappedValues[4] <= 25) {
    letter = CHAR_S;
  } else if (mappedValues[0] <= 45 && mappedValues[1] > 25 &&
             mappedValues[1] <= 60 && mappedValues[2] > 25 &&
             mappedValues[2] <= 60 && mappedValues[3] > 25 &&
             mappedValues[3] <= 60 && mappedValues[4] > 25 &&
             mappedValues[4] <= 60) {
    letter = CHAR_O;
  } else if (mappedValues[0] > 20 && mappedValues[1] > 20 &&
             mappedValues[1] <= 40 && mappedValues[2] > 50 &&
             mappedValues[3] > 75 && mappedValues[4] > 75) {
    letter = CHAR_F;
  } else if (mappedValues[0] > 25 && mappedValues[1] > 15 &&
             mappedValues[1] <= 45 && mappedValues[2] <= 25 &&
             mappedValues[3] <= 30 && mappedValues[4] > 15 &&
             mappedValues[4] <= 40) {
    letter = CHAR_T;
  } else if (mappedValues[0] > 45 && mappedValues[1] > 80 &&
             mappedValues[2] > 80 && mappedValues[3] > 80 &&
             mappedValues[4] > 30 && mappedValues[4] <= 60) {
    letter = CHAR_W;
  } else if (mappedValues[0] > 50 && mappedValues[0] <= 60 &&
             mappedValues[1] <= 30 && mappedValues[2] <= 30 &&
             mappedValues[3] <= 30 && mappedValues[4] <= 45) {
    letter = CHAR_A;
  } else if (mappedValues[0] > 45 && mappedValues[1] > 80 &&
             mappedValues[2] > 55 && mappedValues[3] <= 35 &&
             mappedValues[4] > 20 && mappedValues[4] <= 45) {
    letter = CHAR_R;
  } else if (mappedValues[0] <= 20 && mappedValues[1] > 25 &&
             mappedValues[1] <= 45 && mappedValues[2] <= 35 &&
             mappedValues[3] <= 45 && mappedValues[4] <= 40) {
    letter = CHAR_E;
  } else if (mappedValues[0] >= 40 && mappedValues[1] >= 80 &&
             mappedValues[2] >= 80 && mappedValues[3] >= 80 &&
             mappedValues[4] >= 80) {
    letter = CHAR_SPACE;
  } else if (mappedValues[0] <= 20 && mappedValues[1] > 25 &&
             mappedValues[1] <= 45 && mappedValues[2] <= 35 &&
             mappedValues[3] <= 45 && mappedValues[4] <= 40) {
    letter = CHAR_N;
  } else if (mappedValues[0] <= 20 && mappedValues[1] > 25 &&
             mappedValues[1] <= 45 && mappedValues[2] <= 35 &&
             mappedValues[3] <= 45 && mappedValues[4] <= 40) {
    letter = CHAR_G;
  }

  if (letter != prev) {
    prev = letter;
    printChar(letter);
  }
}
