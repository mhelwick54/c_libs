#ifndef C_TIMER_H
#define C_TIMER_H

#include <time.h>
#include <stdio.h>

typedef struct timer {
	clockid_t 		clk_id;
	struct timespec res;
	struct timespec start;
	struct timespec end;
	struct timespec diff;
} Timer;

void 	startTimer(Timer *t);
void 	endTimer(Timer *t);
void 	timeDiff(Timer *t);
double 	getDiff(Timer *t);
void 	printStart(Timer *t);
void 	printEnd(Timer *t);
void 	printDiff(Timer *t);

#endif
