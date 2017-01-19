#include <kernel/fos.h>
void setup(){
	Serial.begin(115200);
	int init_v = millis();
}

void loop(){
	int fin_v = millis();
	Serial.println("Time Elapsed:%d",fin_v);
}