/*
 * @author Paul
 */

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <String.h>

struct Logger;
int Logger_New (struct String ** ppLogger);
int Logger_Delete (struct String * pLogger);

int Logger_LogString (struct Logger * const pLogger, struct String * const pString);
int Logger_LogChars (struct Logger * const pLogger, char * const pChars);

#endif
