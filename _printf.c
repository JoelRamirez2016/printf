#include "holberton.h"

/**
 * _printf - prints buffer
 * @format: format to print buffer
 * Return: return number of bytes printed
 */
int _printf(const char *format, ...)
{
	int printed_bytes;
	va_list args;
	placeholders ph[] = {
		{'c', place_c},
		{'s', place_s},
		{'d', place_d},
		{'i', place_d},
		{'S', place_S},
		{'b', place_b},
		{'u', place_u},
		{'o', place_o},
		{'x', place_x},
		{'X', place_X},
		{0, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(args, format);
	printed_bytes = trav_format(args, ph, format);
	va_end(args);

	return (printed_bytes);
}

/**
 * trav_format - go trought format and prints all the parameters found
 * in args following the functions found in ph.
 * @args: list of arguments to print
 * @ph: struct with the placeholders and the functions to print the
 * arguments found in args.
 * @format: format to print buffer
 * Return: return number of bytes printed
 */
int trav_format(va_list args, placeholders *ph, const char *format)
{
	int b_cnt = 0, used_buff = 0;
	char buff[BUFF_SIZE];
	const char *trav;

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
			trav_holders(ph, &trav, &used_buff,
				     args, buff, &b_cnt);
		}
	}
	write(1, buff, b_cnt);
	return (BUFF_SIZE * used_buff + b_cnt);
}

/**
 * trav_holders - go trought ph and prints the next argument in args acording
 * to the next character found in trav.
 * @ph: struct with the placeholders and the functions to print the
 * arguments found in args.
 * @trav: string being readed
 * @used_buff: buffer used
 * @args: list of arguments to print
 * @buff: buffer to copy the argument with the according format
 * @b_cnt: counter of bytes used in current buffer
 * Return: nothing
 */
void trav_holders(placeholders *ph, const char **trav, int *used_buff,
		    va_list args, char *buff, int *b_cnt)
{
	int i;

	for (i = 0; ph[i].c; i++)
	{
		if (*(*trav + 1) == ph[i].c)
		{
			*used_buff +=
				ph[i].place_function
				(args, buff, b_cnt);
			(*trav)++;
			break;
		}
	}
	if (*(*trav + 1) == '%' && ph[i].c == 0)
	{
		if (*b_cnt == BUFF_SIZE)
		{
			write(1, buff, BUFF_SIZE);
			used_buff++;
			b_cnt = 0;
		}
		buff[(*b_cnt)++] = '%';
		(*trav)++;
	}
}
