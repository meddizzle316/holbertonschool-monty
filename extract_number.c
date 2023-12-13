#include "monty.h"
#include <limits.h>
/**
 * extract_number -- my function for getting an int from a char string
 * @string: given string to extract from
 * 
 * Return: 1 if number found, -1 if not
 */
extern int pn;

int extract_number(char *string)
{
	char *p;
	char *end;
	p = NULL;
	end = NULL;
	if (string == NULL)
	{
		pn = INT_MIN;
		return(-1);
	}
	if (string)
	{
		p = string;
	}
	while (*p)
	{
		if(isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p + 1))))
		{
			pn = (int)strtol(p, &end, 10);
			if (*end != '\0')
			{
				pn = INT_MIN;
				return (-1);
			}
			return (1);
		}
		else
		{
			p++;
		}
		pn = INT_MIN;
	}
	return (-1);
}
