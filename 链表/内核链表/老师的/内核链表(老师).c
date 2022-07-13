#include <stdio.h>
#include <stdlib.h>

//设计内核链表的节点
struct list_head {
	struct list_head *next, *prev;
};

//尾插 
void Tail_add_node(struct list_head *head, struct list_head *node)
{
    node->prev = head->prev; 
    node->next = head; 
    head->prev->next = node; 
    head->prev = node;
}

//头插 
void Top_add_node(struct list_head *head, struct list_head *node)
{
    node->next = head->next; 
    node->prev = head; 
    head->next->prev = node; 
    head->next = node;
}

//新建节点
 struct list_head *creat_node()
 {
    struct list_head *node = malloc(sizeof(struct list_head)); 
    node->next = node; 
    node->prev = node;
    return node;
 }

//删除节点
void del_node(struct list_head *head, struct list_head *node)
{
            node->prev->next = node->next; 
            node->next->prev = node->prev; 
            node->next =NULL; 
            node->prev =NULL; 
            free(node);
}

//遍历节点
void list_for_each(struct list_head *head)
{
    struct list_head *pos = head->next; 
    for(pos;pos!=head;pos=pos->next)
    {
        printf("%p\n",pos);
    }
    printf("__________________\n");
}


int main()
{
    //创建头节点
    struct list_head *head = malloc(sizeof(struct list_head)); 
    head->next = head; 
    head->prev = head;


    //尾插
    Tail_add_node(head,creat_node());
    Tail_add_node(head,creat_node());
    Top_add_node(head,creat_node());
    Top_add_node(head,creat_node());
    Top_add_node(head,creat_node());
    Top_add_node(head,creat_node());
    
    list_for_each(head);

    //删除节点 
    del_node(head,head->next->next->next);

    list_for_each(head);
}