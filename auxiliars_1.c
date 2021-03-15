#include "holberton.h"

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
	char snull[] = "(null)";

	if (s == NULL)
		s = snull;
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
 * place_S - finds string in args and copy it to buffer, in
 * case the buffers fill up. buffer is printed and emptied.
 * non-printable characters are copyed as \xXX where XX is their
 * value in hexadecimal
 * @args: argument list
 * @buff: buffer
 * @b_cnt: bytes printed counter
 * Return: return number of new buffers needed to print string
 */
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

/**
 * place_b - finds int in args and copy it to buffer with bynary
 * format, in case the buffers fill up. buffer is printed and emptied.
 * @args: argument list
 * @buff: buffer
 * @b_cnt: bytes printed counter
 * Return: return number of new buffers needed to print string
 */
int place_b(va_list args, char *buff, int *b_cnt)
{
	int num = va_arg(args, int);
	int new_buffs = 0, len, available;
	char num_holder[33], *num_s;

	num_s = _itobi(num, num_holder, 31);
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
