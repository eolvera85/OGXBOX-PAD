#include <OGXBOX.h>

OgXbox ogxbox;

void setup() {
	//autoReport
	ogxbox.begin(false);
}
  
void loop() {
	bool upButton = true;
	bool downButton = false;
	bool leftButton = false;
	bool rightButton = false;
	
	ogxbox.setDpad(upButton, downButton, leftButton, rightButton);
	ogxbox.setButton(A, true); // press Button 	A, B, X, Y, START, BACK, WHITE,	BLACK, LS, RS
	ogxbox.setButton(B, false); // release Button A, B, X, Y, START, BACK, WHITE,	BLACK, LS, RS

	ogxbox.setLeftTrigger(0); // Min value 0
	ogxbox.setRightTrigger(255); // Max value 255
	
	ogxbox.setLeftJoystick(-32767, 32767);  // Min value -32767 Max value 32767
	ogxbox.setRightJoystick(0x00, 0x00); // Center

	ogxbox.sendReport();

	uint8_t leftMotor;
	uint8_t rightMotor;
	ogxbox.getRumble(leftMotor, rightMotor); // Min value 0x00 - Max value 0xFF
}
  