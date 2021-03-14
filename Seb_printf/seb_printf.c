#include "seb_holberton.h"

/**
 * _printf - prints buffer
 * @format: format to print buffer
 * Return: return number of bytes printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, b_cnt = 0, used_buff = 0;
	char buff[BUFF_SIZE];
	const char *trav;
	placeholders ph[] = {
		{'c', place_c},
		{'s', place_s},
		{'d', place_d},
		{'i', place_d},
		{0, NULL}
	};

	va_start(args, format);
	for (trav = format; *trav; trav++)
	{
		if (*trav != '%')
		{
			if (b_cnt == BUFF_SIZE)
			{
				write(1, buff, BUFF_SIZE);
				used_buff++;
				b_cnt = 0;
			}
			buff[b_cnt++] = *trav;
		}
		else
		{
			for (i = 0; ph[i].c; i++)
			{
				if (*(trav + 1) == ph[i].c)
				{
					used_buff +=
						ph[i].place_function
						(args, buff, &b_cnt);
					trav++;
				}
			}
		}
	}
	write(1, buff, b_cnt);
	va_end(args);
	return (BUFF_SIZE * used_buff + b_cnt);
}


/**
 * place_s - finds string in args and copy it to buffer, in
 * case the buffers fill up. buffer is printed and emptied.
 * @args: argument list
 * @buff: buffer
 * @b_cnt: bytes printed counter
 * Return: return number of new buffers needed to print string
 */
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

/**
 * place_c - finds char in args and copy it to buffer, in
 * case the buffers fill up. buffer is printed and emptied.
 * @args: argument list
 * @buff: buffer
 * @b_cnt: bytes printed counter
 * Return: return number of new buffers needed to print string
 */
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


/**
 * place_d - finds int in args and copy it to buffer, in
 * case the buffers fill up. buffer is printed and emptied.
 * @args: argument list
 * @buff: buffer
 * @b_cnt: bytes printed counter
 * Return: return number of new buffers needed to print string
 */
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
