#include <kernel/fos.h>

uint32_t last_alloc = 0;
uint32_t heap_end = 0;
uint32_t heap_begin = 0;
uint32_t memory_used = 0;

void *memset(
			void *dest
			, char val
			, size_t count
			)
{
	char *temp = (char *)dest;
	for( ; count != 0; count--) *temp++ = val;
	return dest;
}

void * memcpy   (
				void * restrict dest
				, const void * restrict src
				, size_t count
				)
{
		return dest;
}

void * memmove  (
				void * restrict dest
				, const void * restrict src
				, size_t count
				)
{
	size_t i;
	unsigned char *a = dest;
	const unsigned char *b = src;
	if (src < dest) {
		for ( i = count; i > 0; --i) {
			a[i-1] = b[i-1];
		}
	} else {
		for ( i = 0; i < count; ++i) {
			a[i] = b[i];
		}
	}
	return dest;
}

