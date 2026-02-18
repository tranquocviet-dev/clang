#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int minutes = 5;
    for (int i = 1; i < argc; i++) {
	if (strcmp(argv[i], "-m") == 0) {
	    if (i + 1 < argc) {
		minutes = atoi(argv[++i]);
	    }
	    else {
		printf("No number of minute value found\n");
		return 1;
	    }
	}
    }
    if (minutes <= 0) {
	printf("use a minute count more than 0 please\n");
	return 1;
    }
    while (minutes > 0) {
	printf("%d minute(s) remaining\n", minutes);
	sleep(60);
	minutes--;
    } 
    printf("Time is up!\n");
    return 0;
}
