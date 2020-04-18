#include "terminal.hpp"
#include "stringutils.hpp"
#include "types.hpp"

void kprint_rainbow(const char* str)
{
	uint32 i = 0;
	uint8 back_color = 1;

	while(str[i])
	{
		kprintchar(str[i], BLACK, (back_color % 16) + 1);
		i++;
		back_color++;
	}
}
extern "C" void kmain()
{

	init_terminal();
	kprint_rainbow("                \n");
	kprint("Hey, its booting!\n");
	kprint("Hello from x86_64-citrusos0.0.0.0.1-unknown!  ");

	kprint("0x");
	kprint(itoa(1337, 16));

	kprint("\n\nBasic terminal driver is complete\n");

	kprint("\nTODO:\nLiterally everything except outputting to the screen. I have a long journey ahead of myself. :)");

	//uint8* pit = (uint8*)0x40;
	//pit[3] |= 0x0;


	while (true)
	{
	}
}