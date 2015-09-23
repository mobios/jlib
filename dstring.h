#ifndef __C__JLIB__DSTRING
#define __C__JLIB__DSTRING

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Tag_String
{
	size_t size;
	size_t _M_CAPACITY;
	char* data;

} String;

String* String_construct(size_t);

int String_append(String*, const char*);
void String_print(String*);
void String_empty(String*);

void String_touint(String*, unsigned int*);

unsigned int String_find_after(String*, unsigned int, unsigned char);

#endif