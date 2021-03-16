#include "holberton.h"

int main(void)
{
	int len = 0, len2 = 0, i = 0;
	char *s1 = "B", *s2 = "C";
	char *format = "A%s%s%%%c%s%s%s\n";
	char largo[4000];

	for (i = 0; i < 3500; i++)
	{
		largo[i] = 'r';
	}
	largo[i] = 0;

	/* len2 = printf("naoA%s%s%%%c%s%s\n", s1, s2, '\t', "D", NULL); */
	/* len = _printf("mioA%s%s%%%c%s%s\n", s1, s2, '\t', "D", NULL); */
	/* printf("len = %d | len2 = %i\n", len, len2); */

	len2 = printf("%s\n", largo);
	len = _printf("%s\n", largo);
	printf("len = %d | len2 = %i\n", len, len2);
	return (0);
}
