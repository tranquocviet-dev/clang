#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void drawTitleBox()
{
	box(stdscr, 0, 0);
}

int main()
{
	initscr();
	drawTitleBox();
	
	refresh();
	getch();
	endwin();
	return 0;
}
