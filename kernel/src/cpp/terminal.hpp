#pragma once
#include "types.hpp"

enum vga_color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	GREY,
	DARK_GREY,
	BRIGHT_BLUE,
	BRIGHT_GREEN,
	BRIGHT_CYAN,
	BRIGHT_RED,
	BRIGHT_MAGENTA,
	YELLOW,
	WHITE,
};

extern uint16* vga_buffer;
static const uint16 VGA_WIDTH = 80;
static const uint16 VGA_HEIGHT = 25;

extern uint16 terminal_row;
extern uint16 terminal_column;

extern uint8 terminal_text_color;
extern uint8 terminal_background_color;

uint16 vga_entry(unsigned char c, uint8 fore_color, uint8 back_color);

void init_terminal();
void terminal_newline();
void terminal_setcolor(uint8 text, uint8 bg);
void kprintchar(unsigned char c, uint8 fore_color, uint8 back_color);
void kprint(const char* str);


