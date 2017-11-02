#include <kernel/fos.h>
void setup(){
	pinMode(OK_LED, OUTPUT);
	pinMode(FAIL_LED, OUTPUT);
}

void loop(){
	digitalWrite(OK_LED, HIGH);
	digitalWrite(FAIL_LED, LOW);
	delay(0x100000);
	digitalWrite(OK_LED, LOW);
	digitalWrite(FAIL_LED, HIGH);
	delay(0x100000);
}