#include "c_timer.h"

void startTimer(Timer *t) {
	t->clk_id = CLOCK_MONOTONIC;
	clock_getres(t->clk_id, &(t->res));
	clock_gettime(t->clk_id, &(t->start));
}

void endTimer(Timer *t) {
	clock_gettime(t->clk_id, &(t->end));
}

void timeDiff(Timer *t) {
	if((t->end.tv_nsec - t->start.tv_nsec) < 0) {
		t->diff.tv_sec = t->end.tv_sec - t->start.tv_sec - 1;
		t->diff.tv_nsec = 1000000000 + t->end.tv_nsec - t->start.tv_nsec;
	} else {
		t->diff.tv_sec = t->end.tv_sec - t->start.tv_sec;
		t->diff.tv_nsec = t->end.tv_nsec - t->start.tv_nsec;
	}
}

double getDiff(Timer *t) {
	return (t->diff.tv_sec + ((double)t->diff.tv_nsec / (double)1000000000));
}

void printStart(Timer *t) {
	fprintf(stdout, "%lu.%06ld\n", t->start.tv_sec, t->start.tv_nsec);
}

void printEnd(Timer *t) {
	fprintf(stdout, "%lu.%06ld\n", t->end.tv_sec, t->end.tv_nsec);
}

void printDiff(Timer *t) {
	fprintf(stdout, "%lu.%06ld\n", t->diff.tv_sec, t->diff.tv_nsec);
}
