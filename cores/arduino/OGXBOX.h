#ifndef OGXBOX_H
#define OGXBOX_H

#include <usbd_xid.h>

typedef enum
{
	A,
	B,
	X,
	Y,
	START,
	BACK,
	WHITE,
	BLACK,
	LS,
	RS
} ogx_button;

class OgXbox
{
	private:
	usbd_duke_in_t _xbox_in;
	usbd_duke_out_t _xbox_out;
	bool _autoReport;
	xid_type_t _type;
	XID_ _usbd_xid;
	
	public:
	OgXbox(xid_type_t type = DUKE);
	void begin(bool autoReport = false);
	void setButton(ogx_button button, bool isPressed);
	void pressButton(ogx_button button);
	void releaseButton(ogx_button button);
	void releaseAll();
	void setDpad(bool up, bool down, bool left, bool right);
	void setLeftTrigger(uint8_t value);
	void setRightTrigger(uint8_t value);
	void setLeftJoystick(int16_t x, int16_t y);
	void setRightJoystick(int16_t x, int16_t y);
	void sendReport();
	boolean getRumble(uint8_t& leftMotor, uint8_t& rightMotor);
};

#endif // OGXBOX_H