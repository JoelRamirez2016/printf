#include "holberton.h"

int main(void)
{
	int len;
	int len2;
	char palabras[110] = "E\nr cualquiera";
	char c = 's';

	len = _printf("Le %s cuando %c%ctabas %s jojo%s\n", "algo", 'e', c, "dormido como una cabra", palabras);
	len2 = printf("Le %s cuando %c%ctabas %s jojo%s\n", "algo", 'e', c, "dormido como una cabra", palabras);
	printf("len = %d len2 = %d\n", len, len2);

	len = _printf("numeros: %d %i %i %d %d\n", INT_MIN, INT_MAX, 0, -1, 34);
	len2 = printf("numeros: %d %i %i %d %d\n", INT_MIN, INT_MAX, 0, -1, 34);
	printf("len = %d len2 = %d\n", len, len2);


	len = _printf("128 binary is: %b\n", 5 );
	printf("len = %d\n", len);

	len = _printf("394 in hex min is: %x\n", 394);
        printf("len = %d\n", len);


        len = _printf("394 in hex MAX is: %X\n", 394);
        printf("len = %d\n", len);


        len = _printf("394 in octal is: %o\n", 394);
        printf("len = %d\n", len);

	len = _printf("%%%%%%%%%%\n");
	printf("len = %d\n", len);

	/* len = _printf("%s\n", NULL); */

	return (0);
}
