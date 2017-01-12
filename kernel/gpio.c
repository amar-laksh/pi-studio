#include <kernel/fos.h>
#define CHECK_ON_GPIO_PINS(SEL0, SEL1)	if(gpio_pin <= 31)\
											{a = GET32(SEL0);\
										}else\
										{a  = GET32(SEL1);}

#define CHECK_ON_GPIO_PINS_WRITE(SEL0, SEL1) if(gpio_pin <= 31){ \
											PUT32(SEL0 \
											,value<<(32-gpio_pin));}\
										else{\
											PUT32(SEL1 \
											, value<<(gpio_pin-32));}
void pinMode(
			int gpio_pin
			, int state
			)
{
	unsigned int ra;
	int8_t offset=21;
	int SEL;
	switch((gpio_pin%10)){
				case 0: offset = 0; break;
				case 1: offset = 3; break;
				case 2: offset = 6; break;
				case 3: offset = 9; break;
				case 4: offset = 12; break;
				case 5: offset = 15; break;
				case 6: offset = 18; break;
				case 7: offset = 21; break;
				case 8: offset = 24; break;
				case 9: offset = 27; break;
			}
	if(gpio_pin >= 0 && gpio_pin <= 9)
		SEL = GPFSEL0;
	if(gpio_pin >= 10 && gpio_pin <= 19)
		SEL = GPFSEL1;
	if(gpio_pin >= 20 && gpio_pin <= 29)
		SEL = GPFSEL2;
	if(gpio_pin >= 30 && gpio_pin <= 39)
		SEL = GPFSEL3;
	if(gpio_pin >= 40 && gpio_pin <= 49)
		SEL = GPFSEL4;
	if(gpio_pin >= 50 && gpio_pin <= 53)
		SEL = GPFSEL5;

	if(state == 1 || state == OUTPUT){
		ra=GET32(SEL);
		ra&=~(7<<offset);
		ra|=1<<offset;
		PUT32(SEL,ra);
	}
	else if(state == 0 || state == INPUT){		
		ra=GET32(SEL);
		ra&=~(7<<offset);
		ra |= (0<<offset);
		PUT32(SEL,ra);
	}
	else if(state == 4 || state == ALT0){
		ra=GET32(SEL);
		ra&=~(7<<offset);
		ra|=4<<offset;
		PUT32(SEL,ra);
	}
	else if(state == 5 || state == ALT1){
		ra=GET32(SEL);
		ra&=~(7<<offset);
		ra|=5<<offset;
		PUT32(SEL,ra);
	}
	else if(state == 6 || state == ALT2){
		ra=GET32(SEL);
		ra&=~(7<<offset);
		ra|=6<<offset;
		PUT32(SEL,ra);
	}
	else if(state == 7 || state == ALT3){
		ra=GET32(SEL);
		ra&=~(7<<offset);
		ra|=7<<offset;
		PUT32(SEL,ra);
	}
	else if(state == 3 || state == ALT4){
		ra=GET32(SEL);
		ra&=~(7<<offset);
		ra|=3<<offset;
		PUT32(SEL,ra);
	}
	else if(state == 2 || state == ALT5){
		ra=GET32(SEL);
		ra&=~(7<<offset);
		ra|=2<<offset;
		PUT32(SEL,ra);
	}
}


void digitalWrite	(
					int gpio_pin
					, int state
					)
{
	int value;
	if(gpio_pin < 32)
		value = 1<<(gpio_pin);
	if(gpio_pin >= 32)
		value = 1<<(gpio_pin - 32);

	if(state == 1 || state == HIGH){
		if(gpio_pin >= 0 && gpio_pin <= 31)
			PUT32(GPSET0, value);
		if(gpio_pin > 31 && gpio_pin <= 53)
			PUT32(GPSET1, value);
	}
	else{
		if(gpio_pin >= 0 && gpio_pin <= 31)
			PUT32(GPCLR0, value);
		if(gpio_pin > 31 && gpio_pin <= 53)
			PUT32(GPCLR1, value);
	}
}


int digitalRead	(
				int gpio_pin
				)
{
	int value;
	if(gpio_pin >= 0 && gpio_pin <= 31){
		
		value =(GET32(GPLEV0) & (1<<(gpio_pin)) );
	}else{
		value =(GET32(GPLEV1) & (1<<(gpio_pin - 32)) );
	}
	return value;
}





int eventRead	(
				int gpio_pin
				)
{
	int a;
	CHECK_ON_GPIO_PINS(GPEDS0, GPEDS1);
	return (a & (1<<gpio_pin));
}

int risingEdgeRead	(
					int gpio_pin
					)
{
	int a;
	CHECK_ON_GPIO_PINS(GPREN0, GPREN1);
	return (a & (1<<gpio_pin));
}

int fallingEdgeRead	(
					int gpio_pin
					)
{
	int a;
	CHECK_ON_GPIO_PINS(GPFEN0, GPFEN1);
	return (a & (1<<gpio_pin));
}

int highDetectRead	(
					int gpio_pin
					)
{
	int a;
	CHECK_ON_GPIO_PINS(GPHEN0, GPHEN1);
	return (a & (1<<gpio_pin));
}

int lowDetectRead	(
					int gpio_pin
					)
{
	int a;
	CHECK_ON_GPIO_PINS(GPLEN0, GPLEN1);
	return (a & (1<<gpio_pin));
}

int asyncRisingEdgeRead	(
						int gpio_pin
						)
{
	int a;
	CHECK_ON_GPIO_PINS(GPAREN0, GPAREN1);
	return (a & (1<<gpio_pin));
}

int asyncFallingEdgeDetectRead	(
								int gpio_pin
								)
{
	int a;
	CHECK_ON_GPIO_PINS(GPLEN0, GPLEN1);
	return (a & (1<<gpio_pin));
}

int pullUpDownRead()
{
	int a;
	a = GET32(GPPUD);
	return a;
}

int pullUpDownClockRead	(
						int gpio_pin
						)
{
	int a;
	CHECK_ON_GPIO_PINS(GPPUDCLK0, GPPUDCLK1);
	return (a & (1<<gpio_pin));
}












void eventWrite(
				int gpio_pin
				, int value
				)
{
	CHECK_ON_GPIO_PINS_WRITE(GPEDS0, GPEDS1);
}

void risingEdgeWrite(
					int gpio_pin
					, int value
					)
{
	CHECK_ON_GPIO_PINS_WRITE(GPREN0, GPREN1);
}

void fallingEdgeWrite(
					int gpio_pin
					, int value
					)
{
	CHECK_ON_GPIO_PINS_WRITE(GPFEN0, GPFEN1);
}

void highDetectWrite(
					int gpio_pin
					, int value
					)
{
	CHECK_ON_GPIO_PINS_WRITE(GPHEN0, GPHEN1);
}

void lowDetectWrite(
					int gpio_pin
					, int value
					)
{
	CHECK_ON_GPIO_PINS_WRITE(GPLEN0, GPLEN1);
}

void asyncRisingEdgeWrite(
						int gpio_pin
						, int value
						)
{
	CHECK_ON_GPIO_PINS_WRITE(GPAREN0, GPAREN1);
}

void asyncFallingEdgeDetectWrite(
								int gpio_pin
								, int value
								)
{
	CHECK_ON_GPIO_PINS_WRITE(GPLEN0, GPLEN1);
}

void pullUpDownWrite(
					int value
					)
{
	PUT32(GPPUD, value);
}

void pullUpDownClockWrite	(
							int gpio_pin
							, int value
							)
{
	if(gpio_pin >= 0 && gpio_pin <= 31)
		PUT32(GPPUDCLK0, value);
	if(gpio_pin > 31 && gpio_pin <= 53)
		PUT32(GPPUDCLK1, value);
}


void gpio_install(){
	//unsigned int ra;
	pinMode(35, OUTPUT);
	pinMode(47, OUTPUT);
	pinMode(24, OUTPUT);
	// Testing leds ten times
	for (int i = 0; i < 10; ++i){
		digitalWrite(35, HIGH);
		digitalWrite(47, LOW);
		digitalWrite(24, LOW);
        delay(0x200000);//for(ra=0;ra<0x100000;ra++) dummy(ra);
        digitalWrite(35, LOW);
        digitalWrite(47, HIGH);
       	digitalWrite(24, HIGH);
        delay(0x200000);//for(ra=0;ra<0x100000;ra++) dummy(ra);
	}
	digitalWrite(35, LOW);
	digitalWrite(47, LOW);
	digitalWrite(24, LOW);
}