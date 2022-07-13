#include <stdio.h>
#include <stdlib.h>

//记得添加内核链表头文件 
#include "list.h"  //使用当前目录的头文件 

//定义一个节点，包含一个内核链表 
struct  node 
{
    struct list_head list;
    int data; //用于存放数据  
};


//获取链表节点的个数
void Get_len(struct list_head  *head)
{
   struct list_head  *pos = head->next; 

   for(pos;pos!=head;pos=pos->next)
   {
        //取数据  利用结构体的空间大小 分配规律，得到大结构体的首地址 
        struct node  *msg = (struct node  *)pos;
     
      printf("pos=%p msg->data=%d\n",pos,msg->data);
   }
    printf("——————————————————————\n");
}

//练习： 二次封装内核链表的  插入 和 遍历接口 
int main()
{

    //新建头节点 
    struct list_head *head = malloc(sizeof(struct list_head));

    //初始化头节点  
    INIT_LIST_HEAD(head);


    //插入节点 
    struct node *xnew = malloc(sizeof(struct node));
    xnew->data = 100; 
    list_add_tail(&xnew->list,head);

    xnew = malloc(sizeof(struct node));
    xnew->data = 200; 
    list_add_tail(&xnew->list,head);

    xnew = malloc(sizeof(struct node));
    xnew->data = 300;
    list_add_tail(&xnew->list,head);

   //遍历数据
    Get_len(head);
}