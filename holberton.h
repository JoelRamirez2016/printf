#ifndef printflib

#define printflib
#define BUFF_SIZE 1024

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


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


int _printf(const char *, ...);
int trav_format(va_list args, placeholders *ph, const char *format);
void trav_holders(placeholders *ph, const char **trav, int *used_buff,
		  va_list args, char *buff, int *b_cnt);
int place_s(va_list args, char *buff, int *b_cnt);
int place_c(va_list args, char *buff, int *b_cnt);
int place_d(va_list args, char *buff, int *b_cnt);
int place_S(va_list args, char *buff, int *b_cnt);
int place_b(va_list args, char *buff, int *b_cnt);
int place_x(va_list args, char *buff, int *b_cnt);
int place_X(va_list args, char *buff, int *b_cnt);
int place_o(va_list args, char *buff, int *b_cnt);
int place_u(va_list args, char *buff, int *b_cnt);
/* miscellaneous functions */

int _strlen(char *);
char *_strncpy(char *dest, char *src, int n);
int fillnewbuff(char *buff, char *src, int n, int buff_size, int *b_cnt);
char *_itoa(char sign, unsigned int num, char *nums);

char *conv_non_printable(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void itohex_2bytes(int n, char *dest);
char *_itobi(unsigned int n, char *buff, int size);

char *base_convert(char*, int, unsigned int, int, int);

#endif
