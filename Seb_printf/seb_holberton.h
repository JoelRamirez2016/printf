#ifndef printflib

#define printflib

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define BUFF_SIZE 10

int _printf(const char *, ...);
int place_s(va_list args, char *buff, int *b_cnt);
int place_c(va_list args, char *buff, int *b_cnt);
int place_d(va_list args, char *buff, int *b_cnt);

/**
 * struct placeholders - struct of differtent placeholders used in
 * printf
 *
 * @c: char found after a '%' character in printf's format
 * @place_function: The function associated
 */
typedef struct placeholders
{
	char c;
	int (*place_function)(va_list, char *, int *);
} placeholders;



/* miscellaneous functions */
int _strlen(char *);
char *_strncpy(char *dest, char *src, int n);
int fillnewbuff(char *buff, char *src, int n, int buff_size, int *b_cnt);
char *_itoa(int num, char *nums);


#endif
