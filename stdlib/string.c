#include <kernel/fos.h>

int32_t strlen  (
                char* str
                )
{
    int32_t len=0;
    while (str[len++]);
    return len;
}