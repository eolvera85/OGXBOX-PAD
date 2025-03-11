#include "OGXBOX.h"

OgXbox::OgXbox(xid_type_t type)
{
	_type = type;
}

void OgXbox::begin(bool autoReport)
{
	_autoReport = autoReport;
	_usbd_xid.setType(_type);
	
	_xbox_in.startByte = 0x00;
	_xbox_in.bLength = sizeof(usbd_duke_in_t);
  
	_xbox_out.bLength = sizeof(usbd_duke_out_t);
	
	sendReport();
}

void OgXbox::setButton(ogx_button button, bool isPressed)
{
	if (isPressed)
		pressButton(button);
	else
		releaseButton(button);
}

void OgXbox::pressButton(ogx_button button)
{
	switch (button)
	{
		case A:
			_xbox_in.A = 0xFF;
			break;
		case B:
			_xbox_in.B = 0xFF;
			break;			
		case X:
			_xbox_in.X = 0xFF;
			break;	
		case Y:
			_xbox_in.Y = 0xFF;
			break;
		case WHITE:
			_xbox_in.WHITE = 0xFF;
			break;	
		case BLACK:
			_xbox_in.BLACK = 0xFF;
			break;
		case START:
			_xbox_in.wButtons |= DUKE_START;
			break;
		case BACK:
			_xbox_in.wButtons |= DUKE_BACK;
			break;	
		case LS:
			_xbox_in.wButtons |= DUKE_LS;
			break;	
		case RS:
			_xbox_in.wButtons |= DUKE_RS;
			break;				
	}
	
	if (_autoReport)
		sendReport();
}

void OgXbox::releaseButton(ogx_button button)
{
	switch (button)
	{
		case A:
			_xbox_in.A = 0x00;
			break;
		case B:
			_xbox_in.B = 0x00;
			break;			
		case X:
			_xbox_in.X = 0x00;
			break;	
		case Y:
			_xbox_in.Y = 0x00;
			break;
		case WHITE:
			_xbox_in.WHITE = 0x00;
			break;	
		case BLACK:
			_xbox_in.BLACK = 0x00;
			break;
		case START:
			_xbox_in.wButtons &= ~DUKE_START;
			break;
		case BACK:
			_xbox_in.wButtons &= ~DUKE_BACK;
			break;	
		case LS:
			_xbox_in.wButtons &= ~DUKE_LS;
			break;	
		case RS:
			_xbox_in.wButtons &= ~DUKE_RS;
			break;				
	}
	
	if (_autoReport)
		sendReport();
}

void OgXbox::releaseAll()
{
	memset(&_xbox_in, 0x00, sizeof(_xbox_in));
	_xbox_in.bLength = sizeof(usbd_duke_in_t);
	
	if (_autoReport)
		sendReport();
}

void OgXbox::setDpad(bool up, bool down, bool left, bool right)
{
	_xbox_in.wButtons &= ~DUKE_DUP;
	_xbox_in.wButtons &= ~DUKE_DDOWN;
	_xbox_in.wButtons &= ~DUKE_DLEFT;
	_xbox_in.wButtons &= ~DUKE_DRIGHT;
	
	if (up)
		_xbox_in.wButtons |= DUKE_DUP;
	
	if (down)
		_xbox_in.wButtons |= DUKE_DDOWN;
	
	if (left)
		_xbox_in.wButtons |= DUKE_DLEFT;
	
	if (right)
		_xbox_in.wButtons |= DUKE_DRIGHT;
	
	if (_autoReport)
		sendReport();	
}

void OgXbox::setLeftTrigger(uint8_t value)
{
	_xbox_in.L = value;
	
	if (_autoReport)
		sendReport();	
}

void OgXbox::setRightTrigger(uint8_t value)
{
	_xbox_in.R = value;
	
	if (_autoReport)
		sendReport();	
}

void OgXbox::setLeftJoystick(int16_t x, int16_t y)
{
	_xbox_in.leftStickX = x;
	_xbox_in.leftStickY = y;
	
	if (_autoReport)
		sendReport();	
}

void OgXbox::setRightJoystick(int16_t x, int16_t y)
{
	_xbox_in.rightStickX = x;
	_xbox_in.rightStickY = y;
	
	if (_autoReport)
		sendReport();	
}

void OgXbox::sendReport()
{
	_usbd_xid.sendReport(&_xbox_in, sizeof(usbd_duke_in_t));
}

boolean OgXbox::getRumble(uint8_t& leftMotor, uint8_t& rightMotor)
{
	leftMotor = 0x00;
	rightMotor = 0x00;
	
	_usbd_xid.getReport(&_xbox_out, sizeof(usbd_duke_out_t));

    if (_xbox_out.lValue > 0 || _xbox_out.hValue > 0)
	{
		leftMotor = _xbox_out.lValue;
		rightMotor = _xbox_out.hValue;
    }	

	return _xbox_out.bLength == 0x06;
}