#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType_t;
//设计链表的节点 
typedef struct  node 
{
    int data; //存放数据 
    struct  node *next; //存放下一个节点的首地址 
}Node_t;

//创建链表有首个节点的链表
 Node_t* create_list(ElemType_t inputData)
{
    //1 新建链表的首节点--申请节点结构体(Node_t)内存空间,并且判断是否成功申请内存空间
    Node_t*head = malloc(sizeof(Node_t));
    if(head == NULL)
    {
        printf("申请首节点内存空间失败\n");
        return NULL;//指针类型只能返回空
    }
    //2 初始化
    head->data = inputData;//数据赋值
    head->next = NULL;
    //3 返回这条链表的首节点的地址
    return head;
}

//新建初始化节点
Node_t* Init_Node(ElemType_t date)
{
    Node_t *newNode = malloc(sizeof(Node_t));
    if(newNode == NULL)
    {
        printf("内存申请失败");
        return NULL;
    }
    newNode->data = date;
    newNode->next = NULL;

    return newNode;
}

//插入链表(头插法)
Node_t* InsertNodeTohead(Node_t *head ,ElemType_t date)
{
        Node_t*newNode = Init_Node(date);
        if (newNode == NULL)
        {
            printf("插入失败");
            return head;
        }
        //改变指向
        newNode->next = head;
        //更新首节点
        head = newNode;

        return newNode;
}

//查找
bool FindNodes(Node_t *head,ElemType_t Findate)
{
    //遍历链表的每个节点与Findate比较
    Node_t *p = head;
    while (p)
    {
        if(p->data == Findate)//如果找到了
        break;//退出
        p = p->next;//继续遍历下一个节点
    }
    if(p!=NULL)
    {
        return true;
    }  
     else
     {
        return false;
     }
}

bool Change_nodeToList(Node_t*head,ElemType_t Sourcenode_data,ElemType_t Changedata)
{
    //1 遍历链表 找到你值为surcennode_date的源节点
    Node_t *p = head;
    while (p)
    {
        if(Sourcenode_data == p->data)
        break;
        p = p->next;
    }
    //2 如果没有找到，返回false
    if(p == NULL)
    return false;
    //3 如果找到了，修改数据为Changedate;
    p->data = Changedata;
    return true;
}
void Traver_Nodes(Node_t *head)
{
    //遍历链表
    Node_t *p = head;
    while (p)
    {   
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    //创建并初始化
    Node_t *head = create_list(100);

    //插入（头插法）
    head = InsertNodeTohead(head,200);
    head = InsertNodeTohead(head,300);
    head = InsertNodeTohead(head,400);
    head = InsertNodeTohead(head,500);
    Traver_Nodes(head);
    //查找
    if (FindNodes(head,200))
    {
        printf("找到了\n");
    }
    else{
        printf("没找到\n");
    }
    Change_nodeToList(head,200,300);
    Traver_Nodes(head);
    return 0;
}