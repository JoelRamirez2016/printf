#include "seb_holberton.h"

int _strlen(char *s)
{
	int i = 0;

	while (*(s + i))
		i++;

	return (i);
}

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (; i < n && *(src + i) != 0; i++)
		*(dest + i) = *(src + i);
	for (; i < n; i++)
		*(dest + i) = 0;

	return (dest);
}

int fillnewbuff(char *buff, char *src, int to_write, int buff_size, int *b_cnt)
{
	int used_buff;

	if (buff_size >= to_write)
	{
		_strncpy(buff, src, to_write);
		*(b_cnt) = to_write;
		return (1);
	}

	write(1, src, buff_size);
	used_buff = fillnewbuff(buff, src + buff_size, to_write - buff_size,
				buff_size, b_cnt);
	return (used_buff + 1);
}
