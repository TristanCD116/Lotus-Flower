#include <IRremote.h>
#include <Arduino.h>

// Replace with your remote button adresses
#define PINK 0xFF9867     // 0
#define RED 0xFFA25D      // 1
#define GREEN 0xFF629D    // 2
#define BLUE 0xFFE21D     // 3
#define MAGENTA 0xFF22DD  // 4
#define CYAN 0xFF02FD     // 5
#define ORANGE 0xFFC23D   // 6
#define MIX1 0xFFE01F     // 7
#define MIX2 0xFFA857     // 8
#define MIX3 0xFF906F     // 9

const int RGB_PINS[] = { 5, 6, 9 };  // PWM Pins: Blue, Green, Red
const int RECPIN = 10;               // IR receiver pin
const int MAX_ANALOG = 250;

IRrecv irrecv(RECPIN);
decode_results results;

int mix_pin1, mix_pin2;
bool mixing_active = false;  // Flag to indicate if color mixing is active

void setup() {
  Serial.begin(9600);  // Open a Serial Port
  while (!Serial)      // Wait for Serial Monitor to open
    ;

  irrecv.enableIRIn();  // Enable IR input

  for (int i = 0; i < sizeof(RGB_PINS) / sizeof(RGB_PINS[0]); i++) {
    pinMode(RGB_PINS[i], OUTPUT);  // Set PWM pins to output
  }

  // Set default colors (white)
  analogWrite(RGB_PINS[0], MAX_ANALOG);
  analogWrite(RGB_PINS[1], MAX_ANALOG);
  analogWrite(RGB_PINS[2], MAX_ANALOG);
}

void loop() {
  if (irrecv.decode(&results)) {
    int hex_value = results.value;

    switch (hex_value) {

      case PINK:
        mixing_active = false;
        analogWrite(RGB_PINS[0], MAX_ANALOG);  // Pink (0)
        analogWrite(RGB_PINS[1], MAX_ANALOG);
        analogWrite(RGB_PINS[2], MAX_ANALOG);
        break;
      case RED:
        mixing_active = false;
        analogWrite(RGB_PINS[0], MAX_ANALOG);  // Red (1)
        analogWrite(RGB_PINS[1], 0);
        analogWrite(RGB_PINS[2], 0);
        break;
      case GREEN:
        mixing_active = false;
        analogWrite(RGB_PINS[0], 0);  // Green (2)
        analogWrite(RGB_PINS[1], MAX_ANALOG);
        analogWrite(RGB_PINS[2], 0);
        break;
      case BLUE:
        mixing_active = false;
        analogWrite(RGB_PINS[0], 0);  // Blue (3)
        analogWrite(RGB_PINS[1], 0);
        analogWrite(RGB_PINS[2], MAX_ANALOG);
        break;
      case MAGENTA:
        mixing_active = false;
        analogWrite(RGB_PINS[0], MAX_ANALOG);  // Magenta (4)
        analogWrite(RGB_PINS[1], MAX_ANALOG);
        analogWrite(RGB_PINS[2], 0);
        break;
      case CYAN:
        mixing_active = false;
        analogWrite(RGB_PINS[0], 0);  // Cyan (5)
        analogWrite(RGB_PINS[1], MAX_ANALOG);
        analogWrite(RGB_PINS[2], MAX_ANALOG);
        break;
      case ORANGE:
        mixing_active = false;
        analogWrite(RGB_PINS[0], MAX_ANALOG);  // Orange (6)
        analogWrite(RGB_PINS[1], 0);
        analogWrite(RGB_PINS[2], MAX_ANALOG);
        break;
      case MIX1:
        mixing_active = false;
        startColorMix(0, 2);  // Color Mix RB (7)
        break;
      case MIX2:
        mixing_active = false;
        startColorMix(1, 2);  // Color Mix GB (8)
        break;
      case MIX3:
        mixing_active = false;
        startColorMix(0, 1);  // Color Mix RG (9)
        break;
    }

    // Note: since HEX is considered as an int, we can use a switch statement
    irrecv.resume();  // Resume IR receiver
  }

  // Continuously mix colors if the mixing flag is active
  if (mixing_active) {
    colorMix();
  }
}

void startColorMix(int color_pin1, int color_pin2) {
  // Set the pins to mix and activate the mixing state
  mixing_active = true;
  // Store which pins to use
  mix_pin1 = color_pin1;
  mix_pin2 = color_pin2;
}

void colorMix() {
  static int increment = 1;
  static int gradient_color1 = 0;
  static int gradient_color2;
  const int COLORSHIFT_DELAY = 45;

  gradient_color2 = MAX_ANALOG - gradient_color1;

  // Set LED colors
  analogWrite(RGB_PINS[mix_pin1], gradient_color1);
  analogWrite(RGB_PINS[mix_pin2], gradient_color2);

  // Update gradient
  gradient_color1 += increment;

  // Reverse direction if out of range
  if (gradient_color1 <= 0 || gradient_color1 >= MAX_ANALOG) {
    increment = -increment;
  }
  Serial.println(gradient_color1);
  // Delay to create the color shift effect
  delay(COLORSHIFT_DELAY);
}
