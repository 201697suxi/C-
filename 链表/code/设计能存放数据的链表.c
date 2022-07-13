#include <stdio.h>

struct  node
{
   int date; //存放数据 
   struct  node *p; //存放地址 ，用来把数据链接起来
};


int main()
{
       struct  node a;  //局部变量 
       a.date = 100; 
       a.p = NULL;
       struct  node b;//局部变量 
       b.date = 200;
       b.p    = NULL;  
       struct  node c;//局部变量 
       c.date = 300; 
       c.p  = NULL; 
       struct  node d;//局部变量  
       d.date = 400; 
       d.p = NULL; 

      //打印所有节点的地址 
      printf("&a:%p  &b:%p  &c:%p  &d:%p\n",&a,&b,&c,&d);
       //把 a b  c d  链接起来 
        a.p = &b; 
        b.p = &c; 
        c.p = &d; 
        struct  node *pos = &a; //指向a的首地址 
       // printf("pos=%p pos->p=%p  pos->date=%d\n",pos,pos->p,pos->date);
        while (pos != NULL)
        {
            printf("pos=%p pos->p=%p  pos->date=%d\n",pos,pos->p,pos->date);
            pos  = pos->p; //指向下一个节点的地址 
        }

        //该链表的数据结构，存储在哪里？？ 存储在栈空间
        //练习：把上述链表修改为存储在堆空间！！ 
}