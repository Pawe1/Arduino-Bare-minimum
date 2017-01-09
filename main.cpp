#include <Arduino.h>

// Declared weak in Arduino.h to allow user redefinitions.
int atexit(void (* /*func*/ )()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

void setupUSB() __attribute__((weak));
void setupUSB() { }

int main(void)
{
	init();   // Initialize Arduino functionality. Requires Arduino.h

	initVariant();

#if defined(USBCON)
	USBDevice.attach();   // Attach USB for applicable processors.
#endif
	
	// ...
	
	return 0;   // Execution should never reach this point.
}
