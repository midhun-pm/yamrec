#ifndef _PROGRAM_HANDLER_H
#define _PROGRAM_HANDLER_H
#include<fstream>

extern std::ofstream fobj;
extern const char *filename;

extern bool correct_conf;

extern void createFile();
extern void closeFile();
extern void makeExe();

#endif
