#include <stdio.h>
#include <fcntl.h>


int main()
{
	// if (open("so_long", O_RDONLY))
	// 	printf("YES\n");
	// else
	// 	printf("NO\n");

	int x = 100;
	int y = 0;

	y = x % 2;

	printf("%d\n", y);

	return (0);
}