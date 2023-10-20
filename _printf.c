#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    int count = 0;
    char c;
    
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            
            switch (*format)
            {
                case 'c':
                    c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                
                case 's':
                {
                    char *str = va_arg(args, char *);
                    while (*str != '\0')
                    {
                        putchar(*str);
                        count++;
                        str++;
                    }
                    break;
                }
                
                case '%':
                    putchar('%');
                    count++;
                    break;
                
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        
        format++;
    }
    
    va_end(args);
    return count;
}
