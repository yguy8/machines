#include <LiquidCrystal.h>

int seconds = 0;
int dt = 500;
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.

  // Print a message to the LCD.
  lcd_1.print("HOLA");
  lcd_1.setCursor(1, 1);
  lcd_1.print("          Como estas");
}

void loop()
{
  // set the cursor to column 0, line 1, (note: line 1 is the second row, since counting ,begins with 0):
  lcd_1.setCursor(0, 1);
  
  lcd_1.autoscroll(); 
  // print the number of seconds since reset:
  lcd_1.print(seconds);
  delay(dt); // Wait for 1000 millisecond(s)
  seconds += 1;
}
