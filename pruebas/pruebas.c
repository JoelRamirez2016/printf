#include <stdio.h>
#include <unistd.h>

int main (void)
{
	printf("hello\n");
	write(1, "hola como estas", 3);
	write(1, "\n", 1);
	return (0);
}
