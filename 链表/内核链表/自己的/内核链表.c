#include<stdio.h>
#include<stdlib.h>
//设计内核链表的节点

struct list_head
{
    struct list_head *next,*prev;
};

//创建内核链表节点
struct list_head *CreateKernelListNode()
{
    struct list_head *node = malloc(sizeof(struct list_head));
    node->next = node;
    node->prev = node;
    return node;
}

//插入节点

//尾插
//struct list_head *node 要插入的节点
void tail_add_node(struct list_head *head,struct list_head *node)
{

    node->prev = head->prev;
    node->next = head;

    node->prev->next = node;
    node->next =node;
}

//头插
void Top_insert(struct list_head *head,struct list_head *node)
{
    node->next = head->next; 
    node->prev = head; 
    head->next->prev = node; 
    head->next = node;
}


//删除节点
void del_node(struct list_head *head,struct list_head *node)
{
            node->prev->next = node->next; 
            node->next->prev = node->prev; 
            node->next =NULL; 
            node->prev =NULL; 
            free(node);
}


//遍历链表
void list_for_each(struct list_head *head)
{
    struct list_head *pos = head->next;
    for(pos;pos != head;pos=pos->next)
    {
        printf("%p\n",pos);
    }

    printf("_________________\n");
}
int main()
{
    struct list_head *head = malloc(sizeof(struct list_head)); 
    head->next = head; 
    head->prev = head;

    tail_add_node(head,CreateKernelListNode()); 
    tail_add_node(head,CreateKernelListNode());
    
    list_for_each(head);

}
