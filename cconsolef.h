#include <iostream>
#include <queue>
#include <unistd.h>
#include <thread>
#include <cstdarg>
#include <queue>

#ifndef __CCONSOLE_H__
#define __CCONSOLE_H__

typedef struct{
	char * config_file;
	bool active;
	unsigned long time;
	char * console_file;
	int time_test;
	std::queue<char*> messages;

} consoleController;

char * ssprintf(const char*, ...);
char * sfromf(const char*);
consoleController* consoleStart(const char*);
void consoleLoop(consoleController*);
void consolef(consoleController*, const char *, ...);
void consoleDelete(consoleController*);

#endif