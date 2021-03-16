#include "../holberton.h"

void spf(char *buffer, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (i % 10)
		{
			printf(" ");
		}
		if (!(i % 10) && i)
		{
			printf("\n");
		}
		printf("0x%02x", buffer[i]);
		i++;
	}
	printf("\n");
}

int main(void)
{
	int len = 0, len2 = 0, i = 0;
	char s1[5000] = "dia", *s2 = "C";
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

	/* len2 = printf("%s\n", largo); */
	/* len = _printf("%s\n", largo); */
	/* printf("len = %d | len2 = %i\n", len, len2); */


	for (i = 0; i <= 40; i++)
		s1[i] = '\n';
	s1[41] = 0;
//	len = _printf("%s\n", s1);
//	len2 = _printf("%s\n", s1);
	len2 = _printf("%S\n", s1);
	printf("len = %d | len2 = %i\n", len, len2);

	spf(s1, 10);

	return (0);
}
