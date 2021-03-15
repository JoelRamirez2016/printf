#include "holberton.h"

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

char *_itoa(int num, char *nums)
{
	int i = 10, negative = 0, digit;

	nums[11] = 0;
	if (num < 0)
	{
		negative = 1;
	}
	do {
		digit = num % 10;
		digit = (digit < 0) ? -digit : digit;
		nums[i] = digit + '0';
		num = num / 10;
		i--;
	} while (num);
	if (negative)
	{
		nums[i] = '-';
		return (nums + i);
	}
	return (nums + i + 1);
}


char *_itobi(unsigned int n, char *buff, int size)
{
	if (size == 31)
	{
		buff[size + 1] = 0;
		if (!n)
		{
		    buff[size] = '0';
		    return (buff + size);
		}
	}
	if (!n)
		return (buff + size + 1);
	buff[size] = n % 2 + '0';
	return (_itobi(n / 2, buff, size - 1));
}

char *_itoX(int n, char *buff, int size_b)
{
	if (!n)
		return (buff + size_b);

	if (n % 16 < 10)
		buff[size_b - 1]= (n % 16) + 48;
	else
		buff[size_b - 1]= (n % 16) + 55;

	_itox(n/16, buff, size_b - 1);
}

char *_itox(int n, char *buff, int size_b)
{
	if (!n)
		return (buff + size_b);

	if (n % 16 < 10)
		buff[size_b - 1]= (n % 16) + 48;
	else
		buff[size_b - 1]= (n % 16) + 87;

	_itox(n/16, buff, size_b - 1);
}
