#include "monty.h"
#include <limits.h>
/**
 * extract_number -- my function for getting an int from a char string
 * @string: given string to extract from
 * 
 * Return: 1 if number found, -1 if not
 */

int extract_number(char *string)
{
	char *p;
	char *end;
	
	pn = 0;
	p = NULL;
	end = NULL;
	if (string == NULL)
	{
		return (-1);
	}
	if (string)
	{
		p = strtok(string, " ");
		if (p)
			p = strtok(NULL, " ");
	}
	while (p && *p)
	{
		if(isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p + 1))))
		{
			pn = (int)strtol(p, &end, 10);
			if (*end != '\0')
			{
				return (-1);
			}
			return (1);
		}
		else
		{
			p++;
		}
	}
	return (-1);
}
