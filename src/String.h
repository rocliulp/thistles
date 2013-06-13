/*
 * @author Paul
 */

#ifndef _STRING_H_
#define _STRING_H_

#include <wchar.h>

struct String;
int String_New (struct String ** ppString);
int String_NewByChars (struct String ** ppString, char * const pChars);
int String_NewByWChars (struct String ** ppString, wchar_t * const pWChars);
int String_Delete (struct String * pString);
int String_SetChars (struct String * pString, char * const pChars);
int String_SetWChars (struct String * pString, wchar_t * const pWChars);
int String_GetWChars (struct String * const pString, wchar_t ** ppWChars);

#endif
