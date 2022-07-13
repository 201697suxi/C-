#include<stdio.h>
int main()
{
    int date = 0;
    char b = 0x10;
    char c = 0x2c;
    char d = 0x3b;
    char e = 0x2b;

    char *p = &date;
    *p = e;
    *(p+1) = d;
    *(p+2) = c;
    *(p+3) = b;
    printf("%x\n",date);
    return 0;
}