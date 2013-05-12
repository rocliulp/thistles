/*
 * @author Paul
 */

#ifndef _STRING_H_
#define _STRING_H_

struct String;
int String_New (struct String ** ppString);
int String_Delete (struct String * pString);
int String_SetChars (struct String * pString, char * const pChars);
int String_GetChars (struct String * const pString, char ** ppChars);

#endif
