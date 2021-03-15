#include "holberton.h"

int place_X(va_list args, char *buff, int *b_cnt)
{
	int num = va_arg(args, int);
	int new_buffs = 0, len, available;
	char num_holder[10], *num_s;

	num_holder[10]= 0;

	num_s = base_convert(num_holder, 10,num, 16, 55);
	len = _strlen(num_s);
	available = BUFF_SIZE - *b_cnt;

	if (available >= len)
	{
		_strncpy(buff + *b_cnt, num_s, len);
		(*b_cnt) += len;
	}
	else
	{
		_strncpy(buff + *b_cnt, num_s, available);
		write(1, buff, BUFF_SIZE);
		(*b_cnt) = 0;
		new_buffs += fillnewbuff(buff, num_s + available,
							len - available,
							BUFF_SIZE, b_cnt);
	}
	return (new_buffs);
}

int place_o(va_list args, char *buff, int *b_cnt)
{
	int num = va_arg(args, int);
	int new_buffs = 0, len, available;
	char num_holder[10], *num_s;

	num_holder[10]= 0;

	num_s = base_convert(num_holder, 10,num, 8, 0);
	len = _strlen(num_s);
	available = BUFF_SIZE - *b_cnt;

	if (available >= len)
	{
		_strncpy(buff + *b_cnt, num_s, len);
		(*b_cnt) += len;
	}
	else
	{
		_strncpy(buff + *b_cnt, num_s, available);
		write(1, buff, BUFF_SIZE);
		(*b_cnt) = 0;
		new_buffs += fillnewbuff(buff, num_s + available,
							len - available,
							BUFF_SIZE, b_cnt);
	}
	return (new_buffs);
}
