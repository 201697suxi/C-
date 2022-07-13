#include <stdio.h>

int main()
{

      long long  *p=NULL; 

       long long    *p1=NULL;

       long long    *p2=NULL;

       long long    *p3=NULL;

        long long    *p4=NULL;
        long long    *p5=NULL;
     //设计数据与数据之间的关系 
      
      p = &p1; //利用保存 p1 的地址
      p1 = &p2;
      p2 = &p3;
      p3 =  &p4;
      p4 =  &p5;

      long long   *pos = &p; //指向第一个节点的地址 

     int i=0;
      //遍历链表， 数据与数据之间相互连接以后，就形成了链表。 
     while (pos != NULL)
     {
          pos = *pos; 
          i++; 
     }
     
     printf("链表的结点个数 %d\n",i);
}