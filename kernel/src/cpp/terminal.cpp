#include "terminal.hpp"
#include "types.hpp"

uint16* vga_buffer = (uint16*)0xb8000;

uint16 terminal_row = 0;
uint16 terminal_column = 0;

uint8 terminal_text_color = GREY;
uint8 terminal_background_color = BLACK;

uint16 vga_entry(unsigned char c, uint8 fore_color, uint8 back_color)
{
	uint16 ax = 0;
	uint8 ah = 0, al = 0;

	ah = back_color;
	ah <<= 4;
	ah |= fore_color;
	ax = ah;
	ax <<= 8;
	al = c;
	ax |= al;

	return ax;
}

void init_terminal()
{
	terminal_row = 0;
	terminal_column = 0;

	terminal_text_color = GREY;
	terminal_background_color = BLUE;

	vga_buffer = (uint16 *)0xb8000;

	for (int y = 0; y < VGA_HEIGHT; y++)
	{
		for (int x = 0; x < VGA_WIDTH; x++)
		{
			vga_buffer[y * VGA_WIDTH + x] = vga_entry(' ', terminal_background_color, terminal_background_color);
		}
	}
}
void terminal_newline()
{
	terminal_column = 0;
	if (++terminal_row == VGA_HEIGHT)
	{
		for (int row = 1; row < VGA_HEIGHT; row++)
		{
			for (int col = 0; col < VGA_WIDTH; col++)
			{
				vga_buffer[(row - 1) * VGA_WIDTH + col] = vga_buffer[row * VGA_WIDTH + col];
			}
		}

		terminal_row = VGA_HEIGHT - 1;
		for (int i = 0; i < VGA_WIDTH; i++)
		{
			vga_buffer[(VGA_HEIGHT - 1) * VGA_WIDTH + i] = vga_entry(' ', terminal_text_color, terminal_background_color);
		}
	}
}
void terminal_setcolor(uint8 text, uint8 bg)
{
	terminal_text_color = text;
	terminal_background_color = bg;
}

void kprintchar(unsigned char c, uint8 fore_color, uint8 back_color)
{
	if (c == '\n')
	{
		terminal_newline();
		return;
	}

	vga_buffer[terminal_row * VGA_WIDTH + terminal_column] = vga_entry(c, fore_color, back_color);

	if (++terminal_column == VGA_WIDTH)
	{
		terminal_newline();
	}
}

void kprint(const char *str)
{
	uint32 i = 0;
	while (str[i])
	{
		kprintchar(str[i], terminal_text_color, terminal_background_color);
		i++;
	}
}