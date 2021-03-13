#include "seb_holberton.h"

int main(void)
{
	int len;
	int len2;
	char palabras[] = "E\nr";

	len = _printf("Le %s cuando estabas %s jojo%s\n", "algo",
		      "dormido como una cabra", palabras);
	len2 = printf("Le %s cuando estabas %s jojo%s\n", "algo",
		      "dormido como una cabra", palabras);
	printf("len = %d len2 = %d\n", len, len2);

	return (0);
}
