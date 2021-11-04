#include "cconsolef.h"

char * sfromf(const char* __filename){
	FILE * file = fopen(__filename, "r");
	if(file){
		fseek(file, 0, SEEK_END);
		size_t l = ftell(file);
		fseek(file, 0, SEEK_SET);
		char * txt = new char[l];
		fread(txt, sizeof(char), l, file);
		txt[l-1] = '\0';
		fclose(file);
		return txt;
	}else{
		return nullptr;
	}
}


void consoleLoop(consoleController* ccll){
	FILE * term_file;
	while(ccll->active){
		if(ccll->time_test>1000){
			ccll->time_test = 0;
			ccll->console_file = sfromf(ccll->config_file);
		}
		if(!ccll->messages.empty()){
			char * text = ccll->messages.front();
			ccll->messages.pop();
			if(ccll->console_file){
				term_file = fopen(ccll->console_file, "a");
				if(term_file){
					fprintf(term_file, "%s", text);
					fclose(term_file);
				}else{
					printf("%s", text);
				}
			}
			delete text;
		}
		usleep(ccll->time);
		ccll->time_test++;
	}
}

void consolef(consoleController* ccll, const char * __format, ...){
	va_list args, args1;
	va_start(args, __format);
	int len = vsnprintf(NULL, 0, __format, args);
	va_end(args);
	char * outp = (char*)malloc(sizeof(char)*(len+1));
	va_start(args1, __format);
	vsnprintf(outp, len+1, __format, args1);
	va_end(args1);
	ccll->messages.push(outp);
}

consoleController* consoleStart(const char * config_file){
	consoleController* ccll = new consoleController();
	ccll->config_file = ssprintf("/tmp/%s", config_file);
	ccll->active = true;
	ccll->time_test = 9999999;
	ccll->time = 100;
	ccll->console_file = nullptr;
	ccll->messages = std::queue<char*>();
	std::thread thread(consoleLoop, ccll);
	thread.detach();
	return ccll;
}


char * ssprintf(const char * __format, ...){
	va_list args, args1;
	va_start(args, __format);
	int len = vsnprintf(NULL, 0, __format, args);
	va_end(args);
	char * outp = (char*)malloc(sizeof(char)*(len+1));
	va_start(args1, __format);
	vsnprintf(outp, len+1, __format, args1);
	va_end(args1);
	return outp;
}
