#include <LiquidCrystal.h>		// LCD library

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);	// pins RS, E, D4, D5, D6, D7 

// Example of figura "Person" 
byte figure[8] = {
B01110,
B01110,
B00100,
B11111,
B00100,
B01010,
B10001,
B00000,
};

void setup() {
  lcd.begin(16, 2);			                      // Start the display of 16 colums and 2 rows   
  lcd.createChar (7,figure);                 // Create the figure
}

void loop() {
  lcd.clear();                              // Clean the LCD
  lcd.setCursor(0, 0);			               // locates cursor in colum and row
  lcd.print("Welcome to a new video");		// Writes text
  delay(2000);
  for(int i=0; i<22;i++){
    lcd.scrollDisplayLeft();		        // Funtion to move the text to the left 

    delay(1000);				              // time to wait
  }
  for(int i=0; i<10;i++){
    
  lcd.clear();
  lcd.setCursor(0, 0);			    // locates cursor in colum and row
	lcd.print("microUDers");	  	// Writes text
  lcd.setCursor(i, 1);			    // locates cursor in colum and row
	lcd.write (byte (7));
  lcd.display();		           	// Enable text
  delay(500);				           // time to wait
  lcd.noDisplay();			       // Disable text
  delay(500);				           // time to wait
  }
  lcd.display();			         // Enable text
}