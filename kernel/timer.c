#include <kernel/fos.h>


int32_t millis(){
	return GET32(TIMER_CLO);
}


void timer_install(){
	
}