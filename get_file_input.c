#include "monty.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
/**
 * get_file_input -- first attempt  to open file and save in buffer
 * @filename: filename to be read
 *
 * Return: buffer of read content
 */
char *get_file_input(char *filename, int *new_lines_removed, size_t *rd)
{
	char *buffer;
	int fd;
	int i;
	struct stat sb;
	FILE *file;
	/**
	buff_size = 1024;

	buffer = malloc(sizeof(char) * buff_size);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	**/
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		close(fd);
		return (NULL);
	}
	file = fopen(filename, "r");
	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		close(fd);
		fclose(file);
		return (NULL);
	}
	fstat(fd, &sb);

	/* mallocing buffer now that we have size */
	buffer = malloc(sizeof(char) * (sb.st_size + 1));
	*rd = fread(buffer, 1, (sb.st_size + 1), file);
	if (*rd == 0)
	{
		close(fd);
		fclose(file);
		free(buffer);
		return (NULL);
	}
	buffer[*rd] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		  if (buffer[i] == '\t')
			buffer[i] = ' ';
		  if (buffer[i] == '\n' && buffer[i + 1] == '\n')
			{	
			  buffer[i] = ' ';
			  (*new_lines_removed)++;
			}
	} 
	close(fd);
	fclose(file);
	return (buffer);
}
