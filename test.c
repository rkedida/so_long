#include <stdio.h>
#include <fcntl.h>


int main()
{
	if (open("so_long", O_RDONLY))
		printf("YES\n");
	else
		printf("NO\n");

	return (0);
}