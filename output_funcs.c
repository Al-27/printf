#include "output_funcs.h"
/**
 * print_bin - desciption
 * @num: Uint
 *
 * Return: int
 */
int print_bin(unsigned int num)
{
    char str[sizeof(int)*24];
    int i;

    i = 0;

    do{

        str[i] = (num % 2) + '0';
        i++;
        num /= 2;
    }while(num > 0);

    str[i] = '\0';
    reverse(str);

    return print_str(str);
}

/**
 * print_num - desciption
 * @num: int
 * @num: int
 * @num: int
 *
 * Return: int
 */
int print_num(int num, unsigned int unum, int use_unum)
{
    char *str;
    int len;
    if(use_unum)
    {
        str = ui_to_str(unum);
    }
    else
    {
        str = i_to_str(num);
    }

    len = print_str(str);
    free(str);

    return len;
}

/**
 * print_oct - desciption
 * @num: int
 *
 * Return: int
 */
int print_oct(unsigned int num)
{
    char str[sizeof(int)*24];
    int i;

    i = 0;
    do{

            str[i] = (num % 8) + '0';
            num /= 8;
        i++;

    }while(num > 0);

    str[i] = '\0';
    reverse(str);

    return print_str(str);
}

/**
 * print_hex - desciption
 * @num: int
 * @capital: int
 * @is_pointer: int
 *
 * Return: int
 */
int print_hex(unsigned int num,int caps,int is_pointer)
{
    char str[sizeof(int)*24];
    int i;



    i = 0;
    do{


        switch((num % 16)){
            case 15:
                str[i] = 'f';
                break;
            case 14:
                str[i] = 'e';
                break;
            case 13:
                str[i] = 'd';
                break;
            case 12:
                str[i] = 'c';
                break;
            case 11:
                str[i] = 'b';
                break;
            case 10:
                str[i] = 'a';
                break;
            default:
                str[i] = (num % 16) + '0';
                break;

        }

        if((num % 16) > 9 && caps){
            str[i] ^= 32;
        }


        num /= 16;
        i++;

    }while(num > 0);

    if(is_pointer)
    {
        for(; i < 8*2; i++){
            str[i] = '0';
        }
    }


    str[i] = '\0';
    reverse(str);

    return print_str(str);
}


