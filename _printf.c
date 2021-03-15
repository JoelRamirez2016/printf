#include "holberton.h"

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
		{'S', place_S},
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
