#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include <conio.h>

void startStopper(struct tm *start_time);
void stopStopper(struct tm *stop_time);
void time_diff(struct tm t1, struct tm t2, struct tm *diff);

struct tm start(time_t raw_tm);
struct tm stop(time_t raw_tm);

//TODO: write a stopwatch program. If you hit enter start the stopwatch, if you hit enter again stop the watch. If you hit escape, the program should exit.
//use the time.h header: https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm
//it's enough if you can measure the elapsed seconds, and minutes

int main()
{
    struct tm start_time, stop_time, diff;
	time_t raw_time;
	char key;
	uint8_t stopper_is_running = 0;

	printf("The Ultimate Stopper Software\n"
		   "-----------------------------\n"
		   "Press [enter] to start!\n\n");

    do {
    	//Detecting keypressed
    	key = getch();

    	//If enter is pressed & the stopper is not running...
    	if (key == 13 && stopper_is_running == 0) {
    		startStopper(&start_time);
    		stopper_is_running = 1;
    	}
    	//If enter is pressed & the stopper is running...
    	else if (key == 13 && stopper_is_running == 1) {
    		stopStopper(&stop_time);
    		stopper_is_running = 0;
    		time_diff(start_time, stop_time, &diff);
    		printf("\tTime elapsed: %d mins %d sec\n", diff.tm_min, diff.tm_sec);
    		printf("----------------\n\n");
    	}

	} while(key != 27);

	printf("\n\nExiting stopper...\n\n");

    return 0;
}

void startStopper(struct tm *start_time) {
    time_t raw_time;
	struct tm *time_info;

	time(&raw_time);
    time_info = localtime(&raw_time);

    *start_time = *time_info;
  	printf("Stopper  starts:\t%d:%d:%d\tHit [Enter] to stop...\n", (*start_time).tm_hour, (*start_time).tm_min, (*start_time).tm_sec);
}

void stopStopper(struct tm *stop_time) {
    time_t raw_time;
	struct tm *time_info;

	time(&raw_time);
    time_info = localtime(&raw_time);

    *stop_time = *time_info;
  	printf("Stopper stopped:\t%d:%d:%d\tHit [Enter] to start again...\n", (*stop_time).tm_hour, (*stop_time).tm_min, (*stop_time).tm_sec);
}

void time_diff(struct tm t1, struct tm t2, struct tm *diff) {
	(*diff).tm_min = t2.tm_min - t1.tm_min;
	(*diff).tm_sec = t2.tm_sec - t1.tm_sec;

	if ((*diff).tm_sec < 0) {
        (*diff).tm_min -= 1;
        (*diff).tm_sec += 60;
	}
}
