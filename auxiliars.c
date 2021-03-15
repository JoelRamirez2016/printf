#include "holberton.h"

int place_s(va_list args, char *buff, int *b_cnt)
{
	char *s = va_arg(args, char *);
	int new_buffs = 0, len, available;

	len = _strlen(s);
	available = BUFF_SIZE - *b_cnt;

	if (available >= len)
	{
		_strncpy(buff + *b_cnt, s, len);
		(*b_cnt) += len;
	}
	else
	{
		_strncpy(buff + *b_cnt, s, available);
		write(1, buff, BUFF_SIZE);
		(*b_cnt) = 0;
		new_buffs += fillnewbuff(buff, s + available, len - available,
			    BUFF_SIZE, b_cnt);
	}
	return (new_buffs);
}

int place_S(va_list args, char *buff, int *b_cnt)
{
	char *s = va_arg(args, char *);
	int new_buffs = 0, len, available;

	s = conv_non_printable(s);
	len = _strlen(s);
	available = BUFF_SIZE - *b_cnt;

	if (available >= len)
	{
		_strncpy(buff + *b_cnt, s, len);
		(*b_cnt) += len;
	}
	else
	{
		_strncpy(buff + *b_cnt, s, available);
		write(1, buff, BUFF_SIZE);
		(*b_cnt) = 0;
		new_buffs += fillnewbuff(buff, s + available, len - available,
			    BUFF_SIZE, b_cnt);
	}
	free(s);
	return (new_buffs);
}



int place_c(va_list args, char *buff, int *b_cnt)
{
	char c = va_arg(args, int);
	int new_buff = 0, available;

	available = BUFF_SIZE - *b_cnt;

	if (available >= 1)
		buff[(*b_cnt)++] = c;
	else
	{
		write(1, buff, BUFF_SIZE);
		new_buff = 1;
		buff[0] = c;
		(*b_cnt) = 1;
	}
	return (new_buff);
}


int place_d(va_list args, char *buff, int *b_cnt)
{
	int num = va_arg(args, int);
	int new_buffs = 0, len, available;
	char num_holder[12], *num_s;

	num_s = _itoa(num, num_holder);
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
		new_buffs += fillnewbuff(buff, num_s + available, len - available,
			    BUFF_SIZE, b_cnt);

	}
	return (new_buffs);
}
