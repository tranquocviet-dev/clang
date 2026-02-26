#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int progress, bars = 0;
    for (int i=0; i<101; i++)
    {
	system("clear");
	printf("%d%\n", progress);
	for (int i=0; i<bars; i++)
	{
	    printf("-");
	}
	printf(">\n");
	sleep(0.5);
	bars += 1;
	progress += 1;
    }
    return 0;
}
