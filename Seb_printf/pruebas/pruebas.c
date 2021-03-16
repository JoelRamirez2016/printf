#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	printf("hello\n");
	write(1, "hola como estas", 3);
	write(1, "\n", 1);

	char *s = "hola";

	printf("%s\n", s);
	free(s);
	return (0);
}
