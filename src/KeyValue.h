/*
 * @author Paul
 */

#ifndef _KEY_VALUE_H_
#define _KEY_VALUE_H_

#include <types.h>

#define KEY_CAPACITY 64
#define VALUE_CAPACITY 64

struct KeyValue;
int KeyValue_GetKey (byte key [], int len);
int KeyValue_GetValue (byte value [], int len);

#endif
