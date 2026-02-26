#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define TB_HEIGHT 3
#define TB_WIDTH 20


typedef struct Raindrop
{
    float x, y, vx, vy;
} Raindrop;

#define COUNT_DROPS 50

Raindrop drops[COUNT_DROPS];

// regen raindrop at index i at raindrop array
void genRaindrop(int i, bool scatter)
{
    int width, height;
    getmaxyx(stdscr, height, width);
    
    drops[i].x = rand() % (width-2);
    drops[i].y = scatter ? rand() % (height-2) : 0;
    drops[i].vx = 0;
    drops[i].vy = 1;
}

void moveRain(WINDOW *rain_win)
{
    int width, height;
    getmaxyx(rain_win, height, width);
    
    for (int i=0; i<COUNT_DROPS; i++)
    {
	drops[i].x += drops[i].vx;
	drops[i].y += drops[i].vy;
	// has rain left win?
	if (drops[i].x > width || drops[i].y > height)
	{
	    genRaindrop(i, false);
	}
    }
}

WINDOW *drawRain()
{
    int width, height;
    getmaxyx(stdscr, height, width);

    WINDOW *rain_win = newwin(height-2, width-2, 1, 1);
    for (int i=0; i<COUNT_DROPS; i++)
    {
	mvwaddch(rain_win, drops[i].y, drops[i].x, '|'); 
    }
    return rain_win;
}

WINDOW *drawTitleBox()
{
    int width, height;
    getmaxyx(stdscr, height, width);

    WINDOW *title_win = newwin(TB_HEIGHT, TB_WIDTH, (height-TB_HEIGHT)/2, (width-TB_WIDTH)/2);
    box(title_win, 0, 0);
    char *title_str = "Rain";
    mvwaddstr(title_win, 1, (TB_WIDTH-strlen(title_str))/2, title_str);

    return title_win;
}

void drawOuterBox()
{
	box(stdscr, 0, 0);
}

void initRaindrops()
{
    for (int i=0; i<COUNT_DROPS; i++)
    {
	genRaindrop(i, true);
    }
}

int main()
{
    initscr();
    initRaindrops();
    int width, height;
    WINDOW *rain_win, *title_win;
    getmaxyx(stdscr, height, width);
    drawOuterBox();
    mvprintw(height-2, 1, "Width=%d, height=%d", width, height);
    refresh();
    while (1)
    {
	rain_win = drawRain();
	
	moveRain(rain_win);

	title_win = drawTitleBox();
	
	wnoutrefresh(rain_win);
	wnoutrefresh(title_win);
	doupdate();
	usleep(100000);
    }
    getch();
    endwin();
    return 0;
}
