#include <iostream>
#include <unistd.h>
#include <thread>
#include <cstdarg>
#include <queue>

#include "cconsolef.h"

int main(){
	consoleController* term = consoleStart("term001");

	for(size_t i=1; i<10001; i++){
		consolef(term, "Hola mundo %lu\n", i*i);
	}


	usleep(10000000);
	delete term;
	return 0;
}
