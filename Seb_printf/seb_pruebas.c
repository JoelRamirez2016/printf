#include "../holberton.h"

void spb(char *buffer, unsigned int size)
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
	int i, l;
	char s1[5000] = "\n% % % % ", *s2 = "C";
	/* char *format = "A%s%s%%%c%s%s%s\n"; */
	char largo[4000];
	int fin = 256;
	flag flags[] = {{'+', 0}, {' ', 0}, {'#', 0}, {0, 0}};

	len = _printf("%lo\n", ULONG_MAX);
	len2 = printf("%lo\n", ULONG_MAX);
	printf("len = %d | len2 = %i\n", len, len2);

#if 0
	_printf("hello %s %d %d %d %d", "hello");

//	write(1, s1, 10);
	len = _printf(s1);
	len2 = printf(s1);
	printf("\nlen = %d | len2 = %i\n", len, len2);



	len = _printf("%#o\n", 0);
	len2 = printf("%#o\n", 0);
	printf("len = %d | len2 = %i\n", len, len2);

	write(1, "\nz%z%z%z%z", 10);
	len = _printf("\nz%z%z%z%z");
	len2 = printf("\nz%z%z%z%z");
	printf("\nlen = %d | len2 = %i\n", len, len2);

	l = INT_MAX + 1024;
	len = _printf("%+d\n", l);
	len2 = printf("%+d\n", l);
	printf("len = %d | len2 = %i\n", len, len2);

	len = _printf("% +  i\n", INT_MAX);
	len2 = printf("% +  i\n", INT_MAX);
	printf("len = %d | len2 = %i\n", len, len2);

	len = _printf("%#b\n", 100);
	len2 = printf("%#b\n", 100);
	printf("len = %d | len2 = %i\n", len, len2);


	len2 = printf("% #x - %#X\n", 31, 31);
	len = _printf("% #x - %#X\n", 31, 31);
	printf("len = %d | len2 = %i\n", len, len2);


	for (i = 1; i < fin; i++)
	{
		s1[i - 1] = (char) i;
	}

	s1[fin - 1] = 0;
	len = _printf("%s\n", s1);
	len2 = _printf("%S\n", s1);
	printf("len = %d | len2 = %i\n", len, len2);

	spb(s1, 3);
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
	len2 = printf("naoA%s%s%%%c%s%s\n", s1, s2, '\t', "D", NULL);
	len = _printf("mioA%s%s%%%c%s%s\n", s1, s2, '\t', "D", NULL);
	printf("len = %d | len2 = %i\n", len, len2);

	len2 = printf("%s\n", largo);
	len = _printf("%s\n", largo);
	printf("len = %d | len2 = %i\n", len, len2);

	s1[fin] = '\t';
	s1[fin] = 0;
	len = _printf("%s\n", s1);
	len2 = _printf("%S\n", s1);
	printf("len = %d | len2 = %i\n", len, len2);


	printf("len = %d | len2 = %i\n", len, len2);
#endif
	return (0);
}
