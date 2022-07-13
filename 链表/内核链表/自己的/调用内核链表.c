#include<stdio.h>
#include"list.h"
#include<stdlib.h>
int main()
{

    //1.分配头节点内存空间
    struct list_head *head = malloc(sizeof(struct list_head));

    //调用内核链表的头节点
    INIT_LIST_HEAD(head);
    printf("head = %p\n",head);
    printf("head->next = %p\n",head->next);
    printf("head->prev = %p\n",head->prev);


    //尾插
    

}