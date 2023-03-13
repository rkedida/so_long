#include <stdio.h>
#include <fcntl.h>
// #include "mlx/<mlx.h>"
#include "libs/get_next_line/get_next_line.h"
#include "libs/libft/libft.h"


int main()
{
	// if (open("so_long", O_RDONLY))
	// 	printf("YES\n");
	// else
	// 	printf("NO\n");

	char *buf = NULL;
	char *line = NULL;
	char **split_line = NULL;
	int fd = 0;
	char *s1 = "maps/maps.ber";
	int i = 0;
	int cols = 0;
	int num_cols = 0;
	int rows = 0;

	fd = open(s1, O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);

		line = get_next_line(fd);
	if (!line)
		printf("Map is empty\n");

	// split the first line into individual characters
	split_line = ft_split(line, '\0');
	if (!split_line)
		printf("Failed to split map\n");

	// count the number of columns in the first line
	while (split_line[num_cols])
		num_cols++;

	// free the memory allocated for the split line
	free(split_line);
	rows++;
	while ((line = get_next_line(fd)) != NULL)
	{
		split_line = ft_split(line, '\0');
		if (!split_line)
			printf("failed to split map.\n");
		while (split_line[cols])
			cols++;
		if (cols != num_cols)
			printf("Map is not rectangular\n");
		free(split_line);
		rows++;
	}

	// for (int i = 0; split_line; i++)
	printf("%c", split_line[1][0]);

	return (0);
}