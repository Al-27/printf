#include "printf.h"
#include "std_funcs.h"

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
                    printed_chars += print_str(str) - 1;
                    break;
                case 'c':
                    ch = va_arg(args,int);
                    write(1,&ch,1);
                    break;
                case 'i':
                    num = va_arg(args,int);
                    str = i_to_str(num);
                    printed_chars += str_len(str) - 1;
                    print_str(str);
                    free(str);
                    break;
                case 'd':
                    num = va_arg(args,int);
                    str = i_to_str(num);
                    printed_chars += str_len(str) - 1;
                    print_str(str);
                    free(str);
                    break;
                case '%':
                    write(1,(curs),1);
                    break;
                default:
                    write(1,(curs-1),1);
                    write(1,(curs),1);
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
