/*
 *  servodriver.c
 *
 *  Author: ulfjen
 */

#include <stdio.h>
#include <time.h>
#include <wiringPi.h>
#include <stdlib.h>


int main()
{
	struct timespec start_time, end_time;
	//long diff;
	long i=2000000;
	int  d=0,diff;
	// WiringPi
	wiringPiSetup () ;
	pinMode(0, OUTPUT);
	srand(time(NULL));

	// ==============

	diff = 50000;
	while (1)
	{

		// Start timer
		clock_gettime(CLOCK_MONOTONIC_RAW,&start_time);
		// Sleep one ms
		
		clock_gettime(CLOCK_MONOTONIC_RAW,&end_time);
		digitalWrite(0,HIGH);

		while (i >(end_time.tv_sec - start_time.tv_sec)*(long)1e9 + (end_time.tv_nsec-start_time.tv_nsec))
		{
			clock_gettime(CLOCK_MONOTONIC_RAW,&end_time);
		}

		digitalWrite(0,LOW);
		//diff = (end_time.tv_sec - start_time.tv_sec)*(long)1e9 + (end_time.tv_nsec-start_time.tv_nsec);

		//printf("Is 1ms:%ld\n",diff);

		
		i=i+diff;
		
		//d= rand()%3;
		
		delay(15+d);


		if (i>2000000)
		{
		  //return 0;
		  diff = -50000;

		}
		if (i<1000000)
		{
		  diff = 50000;
		}

		

	}

	return 0;
}
