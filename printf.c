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
    unsigned char ch;
    int printed_chars, num;
    /*float fnum;*/
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
                        str = "(null)";
                    printed_chars += print_str(str);
                    break;
                case 'c':
                    ch = va_arg(args,int);
                    write(1,&ch,1);
                    break;
                case 'i':
                    num = va_arg(args,int);
                    printed_chars += print_num(num,0,0);
                    break;
                case 'd':
                    num = va_arg(args,int);
                    printed_chars += print_num(num,0,0);
                    break;
                case 'b':
                    num = va_arg(args,unsigned int);
                    printed_chars += print_bin(num);
                    break;
                case 'o':
                    num = va_arg(args,unsigned int);
                    printed_chars += print_oct(num);
                    break;
                case 'u':
                    num = va_arg(args,unsigned int);
                    printed_chars += print_num(0,num,1);
                    break;
                case 'x':
                    num = va_arg(args,unsigned int);
                    printed_chars += print_hex(num,0);
                    break;
                case 'X':
                    num = va_arg(args,unsigned int);
                    printed_chars += print_hex(num,1);
                    break;
                case '%':
                    write(1,(curs),1);
                    break;
                default:
                    write(1,(curs-1),1);
                    write(1,(curs),1);
                    printed_chars++;
                    break;
            }
            curs++;
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
 * @str: char*
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
    return printed - 1 ;
}

/**
 * str_len - desciption
 * @string: string
 *
 * Return: length
 */
int str_len(char* string)
{
    char* p;

    for(p = string; *p ; p++);

    return p-string;
}
