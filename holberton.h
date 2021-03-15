#ifndef printflib

#define printflib
#define BUFF_SIZE 1024

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef struct placeholders
{
	char c;
	int (*place_function)(va_list, char *, int *);
} placeholders;


int _printf(const char *, ...);
int place_s(va_list args, char *buff, int *b_cnt);
int place_c(va_list args, char *buff, int *b_cnt);
int place_d(va_list args, char *buff, int *b_cnt);
int place_S(va_list args, char *buff, int *b_cnt);
int place_b(va_list args, char *buff, int *b_cnt);
int place_x(va_list args, char *buff, int *b_cnt);
int place_X(va_list args, char *buff, int *b_cnt);
int place_o(va_list args, char *buff, int *b_cnt);
/* miscellaneous functions */

int _strlen(char *);
char *_strncpy(char *dest, char *src, int n);
int fillnewbuff(char *buff, char *src, int n, int buff_size, int *b_cnt);
char *_itoa(int num, char *nums);

char *conv_non_printable(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void itohex_2bytes(int n, char *dest);
char *_itobi(unsigned int n, char *buff, int size);

char *base_convert(char *, int, int n, int , int );

#endif
