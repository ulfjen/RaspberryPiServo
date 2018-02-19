/*
 *  servodriver.c
 *
 *  Author: ulfjen
 */

#include <stdio.h>
#include <time.h>
#include <wiringPi.h>



int main()
{
	struct timespec start_time, end_time;
	long diff;
	// WiringPi
	wiringPiSetup () ;
	pinMode(0, OUTPUT);

	// ==============

	while (1)
	{
		// Start timer
		clock_gettime(CLOCK_MONOTONIC_RAW,&start_time);
		// Sleep one ms
		delay(1);
		clock_gettime(CLOCK_MONOTONIC_RAW,&end_time);

		diff = (end_time.tv_sec - start_time.tv_sec)*(long)1e9 + (end_time.tv_nsec-start_time.tv_nsec);

		printf("Is 1ms:%ld \n",diff);

		delay(1000);
		
	}

	return 0;
}
