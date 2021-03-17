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
	int len = 0, len2 = 0;
	int i;
	char s1[5000] = "dia", *s2 = "C";
	/* char *format = "A%s%s%%%c%s%s%s\n"; */
	char largo[4000];
	int fin = 2;


	s1[1] = 200;
	len = _printf("%s\n", s1);
	len2 = _printf("%S\n", s1);
	printf("len = %d | len2 = %i\n", len, len2);
	flag flags[] = {{'+', 0}, {' ', 0}, {'#', 0}, {0, 0}};

	for (i = 0; flags[i].c; i++)
	{
		_printf("%c\n", flags[i].c);
	}
	arrangeFlags("# +", flags);
	for (i = 0; flags[i].c; i++)
	{
		_printf("%c\n", flags[i].c);
	}
	len2 = printf("% #x - %X\n", 31, 31);
	len = _printf("% #x - %X\n", 31, 31);
	printf("len = %d | len2 = %i\n", len, len2);
#if 0
	len2 = printf("aaa% s", "hola");
	len = _printf("bbb%");
	printf("len = %d | len2 = %i\n", len, len2);

	len2 = printf("%%%y");
	len = _printf("%%%y");
	printf("len = %d | len2 = %i\n", len, len2);

	len2 = printf("%%% +s\n", " hola");
	len = _printf("%%% +s\n", " hola");
	printf("len = %d | len2 = %i\n", len, len2);


	for (i = 0; i < 3; i++)
		largo[i] = 'r';
	largo[i] = 0;
	len2 = printf("naoA%s%s%%%c%s%s\n", s1, s2, '\t', "D", "hola");
	len = _printf("mioA%s%s%%%c%s%s\n", s1, s2, '\t', "D", NULL);
	printf("len = %d | len2 = %i\n", len, len2);

	len2 = printf("%s\n", largo);
	len = _printf("%s\n", largo);
	printf("len = %d | len2 = %i\n", len, len2);

	for (i = 0; i < fin; i++)
		s1[i] = '\n';
	s1[fin] = '\t';
	s1[fin] = 0;
	len = _printf("%s\n", s1);
	len2 = _printf("%S\n", s1);
	printf("len = %d | len2 = %i\n", len, len2);

	/* len2 = printf("%#d\n", 35); */
	len = _printf("%#d\n", 35);
	/* len2 = printf("%++i\n", 5); */
	/* len2 = printf("% d\n", 5); */
	/* len2 = printf("% i\n", 5); */
	/* len2 = printf("%+ d\n", 5); */
	/* len2 = printf("% +d\n", 5); */
	/* len2 = printf("%++d\n", 5); */
	/* len2 = printf("%  d\n", 5); */
	/* len2 = printf("%#d\n", 5); */
	printf("len = %d | len2 = %i\n", len, len2);
#endif


	
	return (0);
}
