#ifndef FOS_H
#define FOS_H

#include <stdint.h>
#include <stddef.h>
#include <sys/va_list.h>
#define ARM_TIMER_LOD 0x2000B400
#define ARM_TIMER_VAL 0x2000B404
#define ARM_TIMER_CTL 0x2000B408
#define ARM_TIMER_DIV 0x2000B41C
#define ARM_TIMER_CNT 0x2000B420

#define SYSTIMERCLO 0x20003004
#define OK_LED		35
#define FAIL_LED	47
//#define TIMEOUT 20000000
#define TIMEOUT 2000000



extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void dummy ( unsigned int );


/* Loop <delay> times in a way that the compiler won't optimize away. */
static inline void delay(int32_t count)
{
	asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
		 : "=r"(count): [count]"0"(count) : "cc");
}
 

//------------------------------------------------GPIO.H


#define OUTPUT 1
#define INPUT 0
#define ALT0 4
#define ALT1 5
#define ALT2 6
#define ALT3 7
#define ALT4 3
#define ALT5 2

#define HIGH 1
#define LOW 0

// GPIO Function selects 
#define GPFSEL0 0x20200000
#define GPFSEL1 0x20200004
#define GPFSEL2 0x20200008
#define GPFSEL3 0x2020000C
#define GPFSEL4 0x20200010
#define GPFSEL5 0x20200014

// GPIO Pin Output Sets
#define GPSET0  0x2020001C
#define GPSET1  0x20200020

// GPIO Pin Output Clears
#define GPCLR0  0x20200028
#define GPCLR1  0x2020002C

// GPIO Pin Levels
#define GPLEV0  0x20200034
#define GPLEV1  0x20200038

// GPIO Event Detect Status
#define GPEDS0  0x20200040
#define GPEDS1  0x20200044

// GPIO Pin Rising Edge Detect Enables
#define GPREN0  0x2020004C
#define GPREN1  0x20200050

// GPIO Pin Falling Edge Detect Enables
#define GPFEN0  0x20200058
#define GPFEN1  0x2020005C

// GPIO Pin Falling High Detect Enables
#define GPHEN0  0x20200064
#define GPHEN1  0x20200068

// GPIO Pin Falling Low Detect Enables
#define GPLEN0  0x20200070
#define GPLEN1  0x20200074

// GPIO Pin Async: Rising Edge Detect Enables
#define GPAREN0  0x2020007C
#define GPAREN1  0x20200080

// GPIO Pin Async: Falling Edge Detect Enables
#define GPAFEN0  0x20200088
#define GPAFEN1  0x2020008C

// GPIO Pin Pull-up/down Enable
#define GPPUD  0x20200094

// GPIO Pin Pull-up/down Enable Clocks
#define GPPUDCLK0  0x20200098
#define GPPUDCLK1  0x2020009C

#define TEST  0x202000B0


void pinMode(
			int gpio_pin
			, int state
			);

void digitalWrite	(
					int gpio_pin
					, int state
					);

int digitalRead	(
				int gpio_pin
				);

int eventRead	(
				int gpio_pin
				);

int risingEdgeRead	(
					int gpio_pin
					);

int fallingEdgeRead	(
					int gpio_pin
					);

int highDetectRead	(
					int gpio_pin
					);

int lowDetectRead	(
					int gpio_pin
					);

int asyncRisingEdgeRead	(
						int gpio_pin
						);

int asyncFallingEdgeDetectRead	(
								int gpio_pin
								);

int pullUpDownRead();

int pullUpDownClockRead	(
						int gpio_pin
						);

void eventWrite(
				int gpio_pin
				, int value
				);

void risingEdgeWrite(
					int gpio_pin
					, int value
					);

void fallingEdgeWrite(
					int gpio_pin
					, int value
					);

void highDetectWrite(
					int gpio_pin
					, int value
					);

void lowDetectWrite(
					int gpio_pin
					, int value
					);

void asyncRisingEdgeWrite(
						int gpio_pin
						, int value
						);

void asyncFallingEdgeDetectWrite(
								int gpio_pin
								, int value
								);

void pullUpDownWrite(
					int value
					);

void pullUpDownClockWrite	(
							int gpio_pin
							, int value
							);

void gpio_install();

//------------------------------------------------UART.H

#define AUX_IRQ 		0x20215000
#define AUX_ENABLES     0x20215004
#define AUX_MU_IO_REG   0x20215040
#define AUX_MU_IER_REG  0x20215044
#define AUX_MU_IIR_REG  0x20215048
#define AUX_MU_LCR_REG  0x2021504C
#define AUX_MU_MCR_REG  0x20215050
#define AUX_MU_LSR_REG  0x20215054
#define AUX_MU_MSR_REG  0x20215058
#define AUX_MU_SCRATCH  0x2021505C
#define AUX_MU_CNTL_REG 0x20215060
#define AUX_MU_STAT_REG 0x20215064
#define AUX_MU_BAUD_REG 0x20215068
						
#define UART_BASE		0x20201000
#define UART_DR			0x20201000
#define UART_RSRECR		0x20201004
#define UART_FR			0x20201018
#define UART_ILPR		0x20201020
#define UART_IBRD		0x20201024
#define UART_FBRD		0x20201028
#define UART_LCRH		0x2020102C
#define UART_CR			0x20201030
#define UART_IFLS		0x20201034
#define UART_IMSC		0x20201038
#define UART_RIS		0x2020103C
#define UART_MIS		0x20201040
#define UART_ICR		0x20201044
#define UART_DMACR		0x20201048
#define UART_ITCR		0x20201080
#define UART_ITIP		0x20201084
#define UART_ITOP		0x20201088
#define UART_TDR		0x2020108C

void mini_uart_puts (
                    char* s
                    );

void mini_uart_install();

void uart_install();



//------------------------------------------------LCD.H

void lcd_install();

//------------------------------------------------SPI.H

#define AUX_SPI0_CNTL0_REG	0x20215080
#define AUX_SPI0_CNTL1_REG	0x20215084
#define AUX_SPI0_STAT_REG	0x20215088
#define AUX_SPI0_IO_REG		0x20215090
#define AUX_SPI0_PEEK_REG	0x20215094

void spi_install();


//------------------------------------------------STRING.H

int32_t strlen  (
                char* str
                );

//------------------------------------------------PRINT.H

int kprintf	(
			const char *fmt,
			...
	   		);

int sprintf	(
			const char *fmt,
			...
			);

//------------------------------------------------MALLOC.H

void *memset(
			void *dest
			, char val
			, size_t count
			);

void * memcpy   (
				void * restrict dest
				, const void * restrict src
				, size_t count
				);

void * memmove  (
				void * restrict dest
				, const void * restrict src
				, size_t count
				);




#endif