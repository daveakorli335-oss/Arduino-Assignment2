// Buzzer pin
int buzzerPin = 8;

// Segment pins: a, b, c, d, e, f, g
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};
int numSegments = 7;

// Digit patterns for 0 - 9
// Order: a, b, c, d, e, f, g
byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

// Function to display a digit
void showDigit(int n)
{
  if (n < 0 || n > 9)
    return;

  for (int i = 0; i < numSegments; i++)
  {
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}

void setup()
{
  Serial.begin(9600);

  // Set buzzer pin as output
  pinMode(buzzerPin, OUTPUT);

  // Set segment pins as outputs
  for (int i = 0; i < numSegments; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }

  Serial.println("=== Beeping Countdown Starting ===");

  int count = 9;

  while (count >= 1)
  {
    Serial.print("Counting: ");
    Serial.println(count);

    showDigit(count);

    // Short beep
    tone(buzzerPin, 1000, 200);

    delay(1000);

    count = count - 1;
  }

  // Display 0
  showDigit(0);

  // Long completion tone
  tone(buzzerPin, 1500, 1000);

  Serial.println("=== Countdown Complete ===");
}

void loop()
{
  // Empty - countdown runs only once
}