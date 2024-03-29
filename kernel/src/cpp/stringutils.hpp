#include "types.hpp"
#include "terminal.hpp"

uint32 strlen(const char *str)
{
	uint32 length = 0;
	while (str[length])
		length++;
	return length;
}
char* itoa(int val, int base){

	if(val == 0)
		return "0";

    static char buf[32] = {0};

    int i = 30;

    for(; val && i ; --i, val /= base)

        buf[i] = "0123456789abcdef"[val % base];

    return &buf[i+1];

}