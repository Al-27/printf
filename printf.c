#include "printf.h"

/**
 * _printf - desc
 * @format: const char*
 * @...: va_args
 *
 * Return: int
 */
int _printf(const char* format, ...)
{
    const char* curs = format;
    char *str;
    /*char _char;
    int num;*/int printed_chars;/*
    float fnum;*/
    va_list args;

    printed_chars = 0;
    va_start(args, format);
    while(*curs)
    {
        if(*curs == '%')
        {
            curs++;
            switch(*curs)
            {
                case 's':
                    str = va_arg(args, char*);
                    if(!str)
                        exit(550);
                    printed_chars += print_str(str) - 1;
                    curs++;
                    break;
                case 'c':
                    write(1,(curs++),1);
                    break;
                case '%':
                    write(1,(curs++),1);
                    break;
                default:
                    write(1,(curs-1),1);
                    write(1,(curs++),1);
                    break;
            }
        }
        else
        {
            write(1,(curs++),1);
        }
        printed_chars++;
    }
    va_end(args);
    return printed_chars;
}


/**
 * print_str - print string/char
 * @string: char*
 *
 * Return: int
 */
int print_str(char* str)
{
    int printed;

    printed = 0;
    while(*str)
    {
        write(1,str,1);
        str++;
        printed++;
    }
    return printed;
}
