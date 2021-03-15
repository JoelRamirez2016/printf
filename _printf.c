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
		{0, NULL}
	};

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
	int i = 0, b_cnt = 0, used_buff = 0;
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
			for (i = 0; ph[i].c; i++)
			{
				if (*(trav + 1) == ph[i].c)
				{
					used_buff +=
						ph[i].place_function
						(args, buff, &b_cnt);
					trav++;
					break;
				}
			}
			if (!ph[i].c)
				buff[b_cnt++] = '%';
		}
	}
	write(1, buff, b_cnt);
	return (BUFF_SIZE * used_buff + b_cnt);
}
