#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#define BUFF_SIZE 1024

int _printf(const char * const format, ...);
int makeBuffer(char*, const char * const, va_list a, int);
int alloc_c(char*, char);


int main()
{
    int len1 = 0, len2 = 0;
    len1 = _printf("Hello %c World\n", 'F');
    len2  = printf("Hello %c World\n", 'F');
    printf(" %i %i ", len1, len2);

    return 0;
}

int _printf(const char * const format, ...)
{
    va_list args;
    int i = 0, buffers_used = 0, r = 0;
    char *buffer = 0;

    va_start(args, format);
    
    while (format[i])
    {
        buffers_used++;
        buffer = realloc(buffer, BUFF_SIZE * buffers_used);
        r = makeBuffer(buffer + i, format, args, i);   
        printf("%i %i %c %s;\n", i, r, format[i+r], buffer);
        i += r;
        // printf("%i ", i);
        // write(1, buffer, r);
    }
    printf("%s", buffer);
    free(buffer);
    va_end(args);
    return i;
}

int makeBuffer(char *buffer, const char * const format, va_list a, int position)
{
    int i, j, chars = 0;

    for (i = position, j = 0; format[i] && format[i] != '%' && j < BUFF_SIZE; i++, j++)  
        buffer[j] = format[i];
    
    // printf("%s\n", buffer);
    if(format[i] == '%')
    {
        switch ( format[i + 1] )
        {
            case 'c':
                buffer[j] = va_arg(a, int);
                chars += 1;
                // printf("%s\n", buffer);
                return j + chars + 1 + makeBuffer(buffer + j + chars, format, a, i + 2);
            default:
                buffer[j] = '%';
                chars += 1; 
                return j + makeBuffer(buffer + j + chars, format, a, i + 1);
        }
    }
    // buffer[j] = 0;
    return j;
}

// alloc_c(char* buf, char c)
// {
//     buf[0] = c;
//     return 1;    
// }
