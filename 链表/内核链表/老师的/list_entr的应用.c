#include <stdio.h>
#include <stdlib.h>

//记得添加内核链表头文件 
#include "list.h"  //使用当前目录的头文件 

//定义一个节点，包含一个内核链表 
struct  node 
{
    int data; //用于存放数据  
    struct list_head list;
};


//创建节点
struct node *CreateNode(int data)
{
    struct node *new_node = malloc(sizeof(struct node));

    //初始化
    new_node->data = data;
    return new_node;
}


//添加节点尾插
void new_nodeTotail(struct node *head,int data)
{
    struct node *newNode = CreateNode(data);

    list_add_tail(&newNode->list,head); 
}

//添加节点头插
void new_nodeTohead(struct node *head,int data)
{
    struct node *newNode = CreateNode(data);
    list_add(&newNode->list,head);
}


//查找节点
struct node *Find_node(struct list_head *head,int Find_data)
{
    struct node *pos;
    list_entry(pos,struct node,list);
    {
        if (pos->data == Find_data)
        {
            printf("查找到当前节点的数据为 = %d\n");
        }
    }
}

//删除节点
void dele_Node(struct list_head *head,int dele_data)
{
    struct node *pos;

    while (1)
    {
        pos = Find_node(head,dele_data);
        if(pos == NULL)
        {
            return ;
        }
        list_del(&pos->list);
        free(pos);
    }
    
}
//修改节点

struct node* ModifyNodeData(struct  node *head,int old_data,int new_data)
{

    struct  node *pos = Find_node(head,old_data);

    if(pos != NULL)
    {
        pos->data = new_data;
    }
    return pos;
}


//遍历输出
void TraversePrintf(struct list_head *head)
{
    struct node *pos;
    list_for_each_entry(pos,head,list);
    {
        printf("%d\n",pos->data);
    }
}  

int main()
{
    struct node *head = malloc(sizeof(struct node));
    //创建
    INIT_LIST_HEAD(head);

    //尾插
    new_nodeTotail(head,10);
    TraversePrintf(head);


}