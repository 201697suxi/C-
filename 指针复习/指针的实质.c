#include<stdio.h>
int main()
{
    int date[3] = {123,456,789};


    short *q = date;


    printf("q[0]=%d\n",q[0]);
    printf("*(q+1)=%d\n",*(q+1));//一模一样的含义
    printf("q[2]=%d\n",q[2]);
    printf("q[3]=%d\n",q[3]);
    return 0;
}
