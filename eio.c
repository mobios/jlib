#include "eio.h"

String* readline(String* str)
{
	String* ret_string = str ? str : String_construct(10);
	String_empty(str);

	while(1)
	{
		char buffer[21];
		buffer[20] = 0;
		fgets(buffer, sizeof(buffer), stdin);
		String_append(ret_string, buffer);

		if(strlen(buffer)!=sizeof(buffer)-1)
			break;
	}
	return ret_string;
};