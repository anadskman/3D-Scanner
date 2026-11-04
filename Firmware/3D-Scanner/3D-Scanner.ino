#include <AccelStepper.h>
#include <FastLED.h>

#define MOTOR_EN   33
#define TUR_STEP   25
#define ARC_STEP   26
#define TURN_DIR   27
#define ARC_DIR    14
#define LED_DATA   22
#define ARC_LIMIT  21
#define ARC_HOME   19
#define TURN_HOME  18
#define NUM_LEDS 12
CRGB leds[NUM_LEDS];

AccelStepper turntable(AccelStepper::DRIVER, TUR_STEP, TURN_DIR);
AccelStepper arch(AccelStepper::DRIVER, ARC_STEP, ARC_DIR);

const int TURN_HOME_DIRECTION = -1;
const int ARC_HOME_DIRECTION = -1;
const int SWITCH_ACTIVE = LOW;
const int MOTOR_ENABLED = LOW;
const int MOTOR_DISABLED = HIGH;
const float TURN_SPEED = 500;
const float ARC_SPEED = 300;
const unsigned long HOME_TIMEOUT = 30000;

bool motorsEnabled = false;

void enableMotors() {
  digitalWrite(MOTOR_EN, MOTOR_ENABLED);
  motorsEnabled = true;
  Serial.println("Motors enabled");
}

void disableMotors() {
  digitalWrite(MOTOR_EN, MOTOR_DISABLED);
  motorsEnabled = false;
  Serial.println("Motors disabled");
}

void stopMotors() {
  turntable.stop();
  arch.stop();
  Serial.println("Stopping motors");
}


bool turnHomePressed() {
  return digitalRead(TURN_HOME) == SWITCH_ACTIVE;
}

bool arcHomePressed() {
  return digitalRead(ARC_HOME) == SWITCH_ACTIVE;
}

bool arcLimitPressed() {
  return digitalRead(ARC_LIMIT) == SWITCH_ACTIVE;
}


bool homeTurntable() {
  Serial.println("Homing turntable...");

  if (turnHomePressed()) {
    turntable.setCurrentPosition(0);
    Serial.println("Turntable already at home");
    return true;
  }

  turntable.setSpeed(TURN_HOME_DIRECTION * 200);

  unsigned long startTime = millis();

  while (!turnHomePressed()) {
    turntable.runSpeed();

    if (millis() - startTime > HOME_TIMEOUT) {
      Serial.println("ERROR: Turntable homing timeout");
      turntable.setSpeed(0);
      return false;
    }

    delay(1);
  }

  turntable.setCurrentPosition(0);
  Serial.println("Turntable homed");
  return true;
}

bool homeArch() {
  Serial.println("Homing arch...");

  if (arcHomePressed()) {
    arch.setCurrentPosition(0);
    Serial.println("Arch already at home");
    return true;
  }

  arch.setSpeed(ARC_HOME_DIRECTION * 150);

  unsigned long startTime = millis();

  while (!arcHomePressed()) {
    if (arcLimitPressed()) {
      arch.setSpeed(0);
      Serial.println("ERROR: Arch limit reached while homing");
      return false;
    }

    arch.runSpeed();

    if (millis() - startTime > HOME_TIMEOUT) {
      arch.setSpeed(0);
      Serial.println("ERROR: Arch homing timeout");
      return false;
    }

    delay(1);
  }

  arch.setCurrentPosition(0);
  Serial.println("Arch homed");
  return true;
}

void homeAll() {
  enableMotors();

  if (!homeTurntable()) {
    disableMotors();
    return;
  }

  if (!homeArch()) {
    disableMotors();
    return;
  }

  Serial.println("All axes homed");
}

void moveTurntable(long steps) {
  enableMotors();

  turntable.move(steps);

  Serial.print("Turntable moving ");
  Serial.print(steps);
  Serial.println(" steps");
}

void moveArch(long steps) {
  enableMotors();

  if (steps > 0 && arcLimitPressed()) {
    Serial.println("Arch limit is pressed. Movement blocked.");
    return;
  }

  arch.move(steps);

  Serial.print("Arch moving ");
  Serial.print(steps);
  Serial.println(" steps");
}

void ledTest() {
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
  delay(500);

  fill_solid(leds, NUM_LEDS, CRGB::Green);
  FastLED.show();
  delay(500);

  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
  delay(500);

  FastLED.clear();
  FastLED.show();

  Serial.println("LED test complete");
}

void printHelp() {
  Serial.println();
  Serial.println("===== SCANNER CONTROL =====");
  Serial.println("T 2000   Turntable +2000 steps");
  Serial.println("T -2000  Turntable -2000 steps");
  Serial.println("A 1000   Arch +1000 steps");
  Serial.println("A -1000  Arch -1000 steps");
  Serial.println("HOME     Home both axes");
  Serial.println("STOP     Stop both motors");
  Serial.println("ON       Enable motors");
  Serial.println("OFF      Disable motors");
  Serial.println("LED      Test LED ring");
  Serial.println("STATUS   Show switch states");
  Serial.println("===========================");
  Serial.println();
}

void handleCommand(String command) {
  command.trim();
  command.toUpperCase();

  if (command == "HOME") {
    homeAll();
  }
  else if (command == "STOP") {
    stopMotors();
  }
  else if (command == "ON") {
    enableMotors();
  }
  else if (command == "OFF") {
    disableMotors();
  }
  else if (command == "LED") {
    ledTest();
  }
  else if (command == "STATUS") {
    Serial.print("Turn home: ");
    Serial.println(turnHomePressed() ? "PRESSED" : "OPEN");

    Serial.print("Arch home: ");
    Serial.println(arcHomePressed() ? "PRESSED" : "OPEN");

    Serial.print("Arch limit: ");
    Serial.println(arcLimitPressed() ? "PRESSED" : "OPEN");
  }
  else if (command.startsWith("T ")) {
    long steps = command.substring(2).toInt();
    moveTurntable(steps);
  }
  else if (command.startsWith("A ")) {
    long steps = command.substring(2).toInt();
    moveArch(steps);
  }
  else {
    Serial.println("Unknown command. Type HELP.");
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(MOTOR_EN, OUTPUT);
  disableMotors();

  pinMode(TURN_HOME, INPUT_PULLUP);
  pinMode(ARC_HOME, INPUT_PULLUP);
  pinMode(ARC_LIMIT, INPUT_PULLUP);

  turntable.setMaxSpeed(TURN_SPEED);
  turntable.setAcceleration(300);

  arch.setMaxSpeed(ARC_SPEED);
  arch.setAcceleration(200);

  FastLED.addLeds<WS2812B, LED_DATA, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(80);
  FastLED.clear();
  FastLED.show();

  Serial.println();
  Serial.println("Portable 3D Scanner Firmware");
  Serial.println("ESP32 started successfully");

  printHelp();
}

void loop() {
  // Read serial commands.
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    handleCommand(command);
  }

  if (arcLimitPressed() && arch.distanceToGo() > 0) {
    arch.stop();
    Serial.println("WARNING: Arch limit reached");
  }

  turntable.run();
  arch.run();
}
