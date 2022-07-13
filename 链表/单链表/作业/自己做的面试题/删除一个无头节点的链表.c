#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int data;
    struct  node *next;
};

//创建节点函数 
struct  node*CreateNode(int data)
{
    struct  node  *new_node = malloc(sizeof( struct  node )); 
    new_node->data = data; 
    new_node->next = NULL;

    return  new_node;
}

//插入数据 
struct  node *InsertNode(struct  node *head,int data)
{
    //1.创建节点 
    struct  node *new_node = CreateNode(data); 

    if(head == NULL) //无头节点
    {
        return new_node;
    }

    //2.插入 
    new_node->next = head->next; 
    head->next = new_node; 

    return new_node; 

}
//头插节点
void Top_Insert(struct  node *head,struct  node *new_node)
{
    //2.插入 
    new_node->next = head->next; 
    head->next = new_node; 
}

//遍历节点 
void TraverseNodes(struct  node *head)
{
   struct  node *pos = head; 

   while (pos!=NULL)
   {
      printf("%d\n",pos->data);
      pos = pos->next;
   }
   printf("_____________________\n");
}

//求链表长度函数 
int Get_Length(struct  node *head)
{
    int len =0;
    struct  node *pos = head->next;
    for(;pos!=NULL;pos=pos->next)
    {
         len++;
    }
    return len;
}


//无头链表中的一个非头节点前插入一个节点

// struct node *InsertNode(struct node *node,int add_data,int find_data)
// {
//     struct  node *pos = node;  
//     struct  node *prev= node; //前驱指针

//     struct node *new_Node = CreateNode(add_data);//创建新节点
    
//     //处理当插入的是头的时候
//     if (find_data == node->data)
//     {
//         printf("无法插入头节点");
//         return node;
//     }
//     while (pos)
//     {       
//     //两个节点之间插入
//     if (pos->data ==find_data)
//         {
//             prev->next =add_data;
//             new_Node->next = pos;
//             return new_Node;
//         }
//         prev = pos;
//         pos = pos->next;
//     }
// }



//删除一个无头链表的非尾节点 
struct  node *Del_node(struct  node *node,int del_data)
{       
      struct  node *top =   node;

      struct  node *pos = node;  
      struct  node *prev= node; 

       //处理第一个节点 
       if(node->data == del_data)
       {    
             //保存第二个节点的地址 
             top = node->next;
             //断线
             node->next = NULL; 
             //释放节点
             free(node); 
             //返回新的第一个节点
             return top;
       }

       //遍历节点 找到需要删除的节点
        while (pos != NULL)
        {
            if(pos->data == del_data)
            {
                //判断是否为尾部节点 
                if(pos->next == NULL)
                {
                    printf("尾部节点不删除\n");
                    return top;
                }


                //连线 
                prev->next = pos->next; 

                pos->next = NULL; 

                free(pos); 
                return top;
            }

            prev = pos; //记录前一个位置
            pos  = pos->next; //往后移动
        }
}



int main()
{
    //记录第一个节点的地址 
    struct  node *pos  =  InsertNode(NULL,100);
  
    InsertNode(pos,200);
    InsertNode(pos,300);
    InsertNode(pos,400);

   //从第一个节点开始遍历
    TraverseNodes(pos);

    //删除第一个 节点 
   pos=Del_node(pos,100); 

   TraverseNodes(pos);

    pos=Del_node(pos,200); 
    TraverseNodes(pos);
    
}
