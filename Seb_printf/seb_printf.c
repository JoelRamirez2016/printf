#include "seb_holberton.h"

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0, b_cnt = 0, used_buff = 0;
	char buff[1024];
	char *trav = NULL;

	va_start(args, format);

	placeholders ph[] = {
		{'c', place_c},
		{'s', place_s},
		{NULL, NULL}
	};
	for (trav = format, *trav, trav++)
	{
		if (*trav != '%')
		{
			buff[b_cnt++] = *trav;
		}
		else
		{
			for (i = 0, ph[i].c, i++)
			{
				if (*trav == ph[i].c)
				{
					used_buff +=
						ph[i].f(args, buff, &b_cnt);
				}
			}
		}
	}
	write(1, buff, b_cnt);
	return (1024 * used_buff + b_cnt);
}

int place_s(va_list args, char *buff, int *b_cnt)
{
	char *s = va_arg(args, char *);
	int new_buff = 0, len, available;

	len = _strlen(s);
	available = 1024 - *b_cnt;

	if (available >= len)
	{
		_strncpy(buff[*b_cnt], s, len);
		(*b_cnt) += len;
	}
	else
	{
		_strncpy(buff[*b_cnt], s, available);
		write(1, buff, 1024);
		new_buff = 1;
		_strncpy(buff[*b_cnt], s + available, len - available);
		(*b_cnt) = len - available;
	}
	return (new_buff);
}
