#include <stdio.h>
#include <stdlib.h>

//添加内核链表头文件 
#include "list.h"

//设计节点存放数据 
struct node
{
    int data;  
    //添加内核链表
    struct list_head list;
};

//插入节点 
void  InsertNode(struct list_head *head,int data)
{
    //新建节点 
    struct node *xnew = malloc(sizeof( struct node )); 
    xnew->data = data; 

    //插入
    list_add_tail(&xnew->list,head);
}

//遍历节点 
void Show_List(struct list_head *head)
{
    struct node *pos = NULL;
    list_for_each_entry(pos,head,list)
    {
        printf("pos->data=%d\n",pos->data);
    }

    printf("________________\n");
}

//查找节点 
 struct node *Find_Node(struct list_head *head,int data)
 {
    struct node *pos = NULL;
    list_for_each_entry(pos,head,list)
    {
        if(pos->data == data)
        {
            printf("找到节点 %d\n",pos->data);
            //返回节点 
            return pos;
        }
    }

    return NULL; //没找到节点
 }

//修改节点 
void  Change_Node(struct list_head *head,int o_data,int n_data)
{
     //1.查找节点 
    struct node *pos=Find_Node(head,o_data);  
    if(pos != NULL)
    {
        pos->data = n_data; 
        printf("修改节点成功\n");
    }

    return ;
}


//删除节点 
void Del_Node(struct list_head *head,int d_data)
{
    struct node *pos=NULL; //指向要删除的节点 
    struct node *n=NULL;  //指向要删除节点的下一个节点
    list_for_each_entry_safe(pos,n,head,list)
    {
        //判断是否为要删除节点
        if(pos->data == d_data)
        {
            //删除 
            list_del(&pos->list); 

            //释放
            free(pos);
        }
    }
}

//获取链表的节点个数 
int  Get_len(struct list_head *head)
{
   int len=0; 
   struct list_head *pos=NULL;
   list_for_each(pos,head)
   {
    len++; 
   }

     return len;
}


//链表排序 
void Sort_List(struct list_head *head)
{

    for(int i=0;i<Get_len(head);i++)
    {
        //前一个节点与后一个节点比较，大则交换
        struct list_head *pos=NULL;  //指向前一个节点
        struct list_head *n=NULL;    //指向后一个节点
        for(pos = (head)->next, n = pos->next; n != (head);pos = n, n = pos->next)
        {
            //手动取出数据 
            struct node *p1 = list_entry(pos,struct node,list);
            struct node *n1 = list_entry(n,struct node,list);


            if(p1->data > n1->data)
            {
                //交换 
                int  tmp = p1->data; 
                p1->data = n1->data;
                n1->data = tmp;
            }
        }
    }
}


//顺序插入 
void Sort_Insert(struct list_head *head,int data)
{
   //1.新建节点 
   struct node *xnew = malloc(sizeof(struct node)); 
          xnew->data = data; 

    //判断是否无节点 
    if(list_empty(head))
    {
         //直接插入
         list_add_tail(&xnew->list,head);
         return ;
    }

    //获取第一个节点的数据
    struct node *first = list_entry(head->next,struct node,list);
    //判断是否比一个节点小
    if(first->data > data) //插入该节点的前面
    {
        list_add(&xnew->list,head); 
        return ; 
    }

    //判断是否需要插入中间  
    struct list_head *pos=NULL;  //指向前一个节点
    struct list_head *n=NULL;    //指向后一个节点
    for(pos = (head)->next, n = pos->next; n != (head);pos = n, n = pos->next)
    {
        //手动取出数据 
        struct node *p1 = list_entry(pos,struct node,list); //前一个数据
        struct node *n1 = list_entry(n,struct node,list);   //后一个数据


        if(p1->data < data && n1->data > data)  //判断是否在两个数据的中间插入 
        {
             //插入n1 的前面 
             list_inser_loc(n,&xnew->list);
             return ;
        }
    }

    //处理最后一个数据 
    list_add_tail(&xnew->list,head);

    return ;
}

//内核链表逆序 
void List_Reverse(struct list_head *head)
{
    struct list_head *pos = head->next;
    for(int i=0;i<Get_len(head)-1;i++)
    {
         //尾取，尾插 
         list_move(pos->next,head);
    }

}



int main()
{
      //创建头节点
      struct list_head *head = malloc(sizeof(struct list_head)); 
      //初始化头节点 
      INIT_LIST_HEAD(head);


     //插入节点
     Sort_Insert(head,14);
     Sort_Insert(head,557);
     Sort_Insert(head,4564);
     Sort_Insert(head,540);
     Sort_Insert(head,546);


     Show_List(head);

    List_Reverse(head);

    Show_List(head);
}