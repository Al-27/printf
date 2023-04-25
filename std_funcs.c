#include "std_funcs.h"
/**
 * i_to_str - desciption
 * @num: to be converted
 *
 * Return: char*
 */
char* i_to_str(int num)
{
    char* sNum;
    int i = 0, tmp;

    sNum = malloc(30);
    tmp = (num >= 0);
    num = tmp ? num : num * -1;
    do{

        sNum[i] = num % 10 + '0';
        i++;
        num /= 10;

    }while( num > 0 );

    if(!tmp)
    {

        sNum[i] = '-';
        i++;

    }
    sNum[i] = '\0';
    reverse(sNum);
    return sNum;
}

/**
 * reverse - desciption
 * @s: string to reverse
 *
 */
void reverse(char s[])
{
    int i, j,c;

    for (i = 0, j = str_len(s)-1; j > i; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

}

/**
 * ui_to_str - desciption
 * @num: to be converted
 *
 * Return: char*
 */
char* ui_to_str(unsigned int num)
{
    char* sNum;
    int i = 0, tmp;

    sNum = malloc(30);

    do{

        sNum[i] = num % 10 + '0';
        i++;
        num /= 10;

    }while( num > 0 );

    sNum[i] = '\0';
    reverse(sNum);
    return sNum;
}







