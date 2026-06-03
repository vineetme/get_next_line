#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
/*
int	main(void)
{
	int		fd;
	char	*line;

	// Open a test file in read-only mode
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}

	// Loop through and print every line until the end of the file
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line); // Super important to free the line returned by GNL!
	}
	close(fd);
	return (0);
}
*/
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}

	// First manual call
	line = get_next_line(fd);
	printf("1st Call Output:\n%s", line);
	free(line);

	printf("-----------------------------\n");

	// Second manual call
	line = get_next_line(fd);
	printf("2nd Call Output:\n%s", line);
	free(line);

	close(fd);
	return (0);
}
