#include "c_timer.h"
#include <stdio.h>

int main() {
	Timer t;
	startTimer(&t);
	printStart(&t);

	int i = 0;
	while(i < 1000000000) {
		i++;
	}

	endTimer(&t);
	printEnd(&t);
	timeDiff(&t);
	printDiff(&t);
	return 0;
}
