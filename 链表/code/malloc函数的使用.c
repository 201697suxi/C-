#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义一个people 结构体 
struct  people
{
    char name[1024];  //姓名 
    int id;  //id
};


int main()
{
     
     //1.分配一个int 类型的堆空间 ,一个int  4 个字节 
    int *p  = malloc(sizeof(int));
    *p = 10086; 
    printf("%d\n",*p);

    //2.分配100 个int 类型的堆空间  ,一个int 4个字节 100 int  400 个字节 
    int *q  = calloc(100,sizeof(int));
 
    
    for(int i=0;i<100;i++)
    {
        q[i] = 100+i;
        printf("%d\n",q[i]);
    }

    //3.分配一块堆空间存放一个  struct  people 结构体类型 
    struct  people *peo = malloc(sizeof(struct  people)*3); 

    peo->id  = 123456; 
    //peo->name = "小明";   //name 是数组名，是一个地址，不能直接赋值
    strcpy(peo->name,"小明");
    printf("id=%d\n",peo->id);
    printf("name=%s\n",peo->name);

    (peo+1)->id = 6666; 
    strcpy((peo+1)->name,"小东");
    printf("id=%d\n", (peo+1)->id);
    printf("name=%s\n",(peo+1)->name);

    (peo+2)->id = 8888; 
    strcpy((peo+2)->name,"小美");
     printf("id=%d\n",(peo+2)->id );
    printf("name=%s\n",(peo+2)->name);

    //释放所有的堆空间  
    free(p);
    free(q); 
    free(peo);

    //练习： 利用 malloc 分配 3 个人物信息， 包含姓名和年龄 ，并往三个人物进行赋值，和输出。 

}