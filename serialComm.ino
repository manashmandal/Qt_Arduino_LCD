#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
	lcd.begin(16, 4);
	lcd.setCursor(0, 0);
	lcd.print("Hello, ");

	Serial.begin(9600);
	//pinMode(13, OUTPUT);
	Serial.println("Available");
	
  /* add setup code here */
	
}

void loop()
{
	
	int x ;
	String the_string;
	
	if (Serial.available() > 0) {
		the_string = Serial.readString();
		Serial.print("I received: ");
		Serial.println(the_string);

		if (the_string.length() == 1){
			lcd.clear();
		}
		else {
			lcd.print(the_string);
		}
	}

	
	delay(10);
  /* add main program code here */
	
}
