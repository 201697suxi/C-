#include <stdio.h>
#include <stdlib.h>

//记得添加内核链表头文件 
#include "list.h"  //使用当前目录的头文件 

//定义一个节点，包含一个内核链表 
struct  node 
{
    struct list_head list; //定义在前面，使小结构体的地址与大结构体的地址一致
    int data; //用于存放数据  
};


//插入数据

void inset_data(struct list_head *head,int data)
{
    //分配空间
    struct node *xnew = malloc(sizeof(struct node));//新插入节点的数据

    //新插入的节点初始化
    xnew->data = data;
    
    //调用内核链表的插入接口
    list_add(&xnew->list,head);


}

//遍历链表

void Show_List(struct list_head *head)
{
    //分配遍历指针空间
    struct list_head *pos = head;

    //遍历循环条件
    for(pos=head->next;pos != head; pos = pos->next)
    {
        //利用结构体字节空间分配原则,小结构体的地址与大结构体的地址一样
        struct node *msg = (struct node *)pos;

        printf("msg->data = %d\n", msg->data);

    }
    printf("分割线——————————————————\n");
}

//删除节点
void dele_node(struct list_head *head,int dele_data)
{
    //分配遍历指针的空间
    struct list_head *pos = head;

    //遍历条件
    for(pos = head->next;pos != head; pos = pos->next)
    {
         struct node *msg = (struct node *)pos;

         //遍历到删除条件
        if (msg->data == dele_data)
        {
            printf("找到要删除的接口=%d\n",msg->data);

            //调用内核链表的删除接口
            list_del(pos);

            //记得释放要删除节点的内核链表的空间
                free(msg);

                return  ;
        }
        

    }
}



int main()
{

    //1创建
    struct list_head *head = malloc(sizeof(struct list_head));

    //(1)初始化
    INIT_LIST_HEAD(head);
    //2检测功能

    //(1)插入
    inset_data(head,10);
    inset_data(head,20);
    inset_data(head,30);
    inset_data(head,40);
    Show_List(head);
    //(2)删除
    dele_node(head,20);
    Show_List(head);
    return 0;
}