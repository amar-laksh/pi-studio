#include <kernel/fos.h>


int kmain (uint32_t r0, uint32_t r1, uint32_t atags)
{
	gpio_install();
	setup();
	while(1){
		loop();
	}
	(void) r0;
	(void) r1;
	(void) atags;
	return(0);
}
