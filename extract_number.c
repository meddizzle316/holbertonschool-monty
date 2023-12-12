#include "monty.h"

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
	
	p = NULL;	
	if (string)
		p = string;
	if (p == NULL)
	{
		pn = -1;
		return(-1);
	}
	while (*p)
	{
		if(isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p + 1))))
		{
			pn = (int)strtol(p, &p, 10);
			return (1);
		}
		else
		{
			p++;
		}
		pn = -1;
	}
}
