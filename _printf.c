#include <stdio.h>
#include <stdarg.h>

int _printf(const char *, ...);

int main()
{
    _printf("Hello World %i", 2);
    return 0;
}


int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, j = 0;
    char *s;
    
    va_start (args, format);
    
    
    for(j = 0; format[j] ; j++)    
    {
        if (format[j] == '%')
        {
            write(1, format + i, j);
            write(1, "2", j);
            i = j;
        }
    }
    // write(1, format + i, j);
    
    va_end (args);              

    return 0;
}


int _printf(const char *format, ...)
{
    va_list args;
    int i;
    char *s;
    
    va_start (args, format);
    
    while (format[i])
    {
        while (format[i] != '%')
        {
            printf("%c", format[i]);
            i++;
        }
        
        switch (format[i+1])
        {
            case 'i':
                printf("%i", va_arg(args, int));
                break;
            case 'd':
                printf("%d", va_arg(args, double));
                break;
            case 'c':
                printf("%c", va_arg(args, int));            
                break;
            case 's':
                printf("%i", va_arg(args, char*));            
                break;
            case 'p':
                printf("%p", va_arg(args, int));            
                break;
            default:
                printf("%c", format[i]);
        }
        
        printf("%c", format[i+1]);
        i++;
    }

    va_end (args);              

    return 0;
}
