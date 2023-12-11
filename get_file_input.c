#include "monty.h"
#include <fcntl.h>
#include <unistd.h>
/**
 * get_file_input -- first attempt  to open file and save in buffer
 * @filename: filename to be read
 *
 * Return: buffer of read content
 */
char *get_file_input(char *filename)
{
	char *buffer;
	size_t buff_size;
	int fd;
	int rd;
	int i;

	buff_size = 1024;

	buffer = malloc(sizeof(char) * buff_size);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("file cannot be found");
		close(fd);
	}
	else
	{
		printf("file was opened successfully\n");
	}
	rd = read(fd, buffer, buff_size);
	if (rd == -1)
	{
		perror("error reading file");
		close(fd);
	}
	else
	{
		printf("successfully read file\n");
	}
	buffer[rd] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '\n')
			buffer[i] = ' ';
	}


	printf("The read buffer is %s\n", buffer);

	close(fd);
	return (buffer);
}
