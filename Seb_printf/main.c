#include "seb_holberton.h"

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



	/* len = _printf("%s\n", NULL); */
	/* len2 = printf("%s\n", NULL); */
	/* printf("len = %d len2 = %d\n", len, len2);*/
	return (0);
}
