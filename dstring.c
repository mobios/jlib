#include "dstring.h"

String* String_construct(size_t len)
{
	String* new_string = malloc(sizeof(String));
	new_string->data = malloc(len);
	new_string->_M_CAPACITY = len;
	new_string->size=0;
	return new_string;
};


int String_append(String* str, const char* source)
{
	size_t length = strlen(source);
	++length;

	if(length + str->size > str->_M_CAPACITY)
	{
		void* newalloc = realloc(str->data, length + str->size + 20);
		if(!newalloc)
		{
			fprintf(stderr, "Error: out of memory.\nString_append.\n\nSrc: %s\nDest: %s", str->data, source);
			return 1;
		}

		str->_M_CAPACITY = length + str->size + 20;
		str->data = newalloc;
	}

	memcpy(str->data+str->size, source, length);
	str->size += length-1;
	return 0;
};


void String_print(String* str)
{
	printf("%s", str->data);
};


void String_empty(String* str)
{
	str->size = 0;
	str->data[0] = 0;
};


void String_touint(String*, unsigned int*)
{
	
};


unsigned int String_find_after(String* str, unsigned int offset, unsigned char delim)
{
	if(offset > str->size)
		return 0;

	while(++offset)
	{
		unsigned char temp = str->data[offset];
		if(temp == delim)
			return offset;
		if(temp == 0)
			return temp;
	}

	return 0;
};