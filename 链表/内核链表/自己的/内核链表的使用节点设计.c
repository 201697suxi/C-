#include<stdio.h>
#include"list.h"
#include<stdlib.h>


struct node//大结构体用户数据
{
    struct list_head list;//小结构体内核链表,这里不用指针类型因为字节分配原则
    int data;
};


//获取链表节点的个数
void Get_len(struct list_head *head)
{
    struct list_head *pos = head->next;

    for(pos;pos!=head;pos =pos->next)
    {
        //取数据  利用结构体的空间大小 分配规律，得到大结构体的首地址
        struct node *msg = (struct node *)pos;

        printf("pos = %p msg->data = %d\n",pos,msg->data);
    }
    printf("————————————————————————");
}

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

    xnew =malloc(sizeof(struct node));
    xnew->data = 200;
    list_add_tail(&xnew->list,head);

    xnew =malloc(sizeof(struct node));
    xnew->data = 300;
    list_add_tail(&xnew->list,head);

    //遍历数据
    Get_len(head);
    
}