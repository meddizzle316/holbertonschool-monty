#include "monty.h"

/**
 * extract_number -- my function for getting an int from a char string
 * @string: given string to extract from
 * 
 * Return: always void; sets push_number to int extracted or -1 if none found
 */
extern int pn;

void extract_number(char *string)
{
	char *p;
	
	p = NULL;	
	if (string)
		p = string;
	if (p == NULL)
	{
		pn = -1;
		exit(2);
	}
	while (*p)
	{
		if(isdigit(*p) || ((*p == '-' || *p == '+') && isdigit(*(p + 1))))
		{
			pn = (int)strtol(p, &p, 10);
			break;
		}
		else
		{
			p++;
		}
		pn = -1;
	}
}
