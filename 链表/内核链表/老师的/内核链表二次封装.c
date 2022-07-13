#include <stdio.h>
#include <stdlib.h>

//记得添加内核链表头文件 
#include "list.h"  //使用当前目录的头文件 

//定义一个结构体，包含内核链表 
struct node
{
 struct list_head list;  //定义要定义在最前，因为这样小结构体的地址与大的一致！！ 
 int data;
};

//插入数据 
void inset_data(struct list_head *head,int data)
{
    //分配空间 
    struct node *xnew = malloc(sizeof(struct node)); 

    //初始化 
    xnew->data = data;  

    //调用内核链表的插入接口 
    list_add_tail(&xnew->list,head); 
}

//遍历链表
void Show_List(struct list_head *head)
{
   struct list_head *pos = head; 

   for(pos=head->next;pos!=head;pos=pos->next)
   {
        //通过小结构体与大结构体地址一样的特点 
        struct node *msg = (struct node *)pos;   //把小结构体的地址转换为 大结构体 

        printf("msg->data=%d\n",msg->data);
   }

   printf("______________\n");
}

//删除节点 
void Del_node(struct list_head *head,int del_data)
{

 struct list_head *pos = head; 

   for(pos=head->next;pos!=head;pos=pos->next)
   {
        //通过小结构体与大结构体地址一样的特点 
        struct node *msg = (struct node *)pos;   //把小结构体的地址转换为 大结构体 

        if(msg->data == del_data)
        {
            printf("找到需要删除的数据=%d\n",msg->data);

            //调用内核链表的删除接口
            list_del(pos);
            
            //释放空间 
            free(msg); 

            return ;
        }
       

   }


}



int main()
{
    //创建头节点 
    struct list_head *head  =   malloc(sizeof(struct list_head)); 

    //初始化头节点 
    INIT_LIST_HEAD(head);

    //插入数据 
    inset_data(head,10);
    inset_data(head,20);
    inset_data(head,30);
    inset_data(head,40);

    Show_List(head);

    Del_node(head,20);
    
     Show_List(head);
}