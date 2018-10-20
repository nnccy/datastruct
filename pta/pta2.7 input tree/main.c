#include <stdio.h>
#include <stdlib.h>
#define Null -1
typedef struct treenode
{

    int left;
    int right;

}Tree;

typedef struct Node
{
    int data;
    struct Node* next;
}*queue,lqueue;

typedef struct Qnode
{
    struct Node* front;
    struct Node* rear;
} *linkqueue;


struct Qnode creatqueue()
{
    struct Qnode q;
    q.front = q.rear= (queue)malloc(sizeof(lqueue));
    if(!(q.rear))
    printf("gege");
    q.front->next = NULL;

    return q;
}
void insert(linkqueue q,int a)
{
    queue p;
    p = (queue)malloc(sizeof(lqueue));
    p->data = a;
    p->next =NULL;
    q->rear->next = p;
    q->rear = p;      //在这步之前，front和rear共用一块地址
    //之后，q的地址改变

}


int iskong(linkqueue q)
{

    if (q->front == q->rear)
    {
       return Null;

    }
    else
        return 1;
}






int delete (linkqueue q)
{
    int a;

    queue p;
    if (q->front == q->rear)
    {
       return Null;

    }
    else
    {
        p = q->front->next;
        a = p->data;
        q->front->next = p->next;
        if(q->rear == p)
        {
            q->rear = q->front;
        }

        free(p);
    }


    return a;

}

int build(Tree t[])
{
    int root;
    int cnt ,i ;
    scanf("%d",&cnt);
    char l,r;
    getchar();
    int check[cnt];
    for(i=0;i<cnt;i++)
        check[i] = 0;
    if (cnt == 0)
        return Null;
    for(i = 0;i<cnt;i++)
    {
        scanf("%c %c",&l,&r);
        getchar();
        if(l != '-')
        {
            t[i].left = l - '0';
            check[t[i].left] = 1;

        }
        else
        {
            t[i].left = Null;
        }
        if(r != '-')
        {
            t[i].right= r - '0';
            check[t[i].right] = 1;

        }
        else
        {
            t[i].right = Null;
        }

    }

    for(i=0;i<cnt;i++)
    {



        //printf("%d",check[i]);
        if(check[i] == 0)
        {
            root = i;
            break;
        }

    }


    return root;
}

void printyezi(Tree t[],int root)
{
    int biaozhi = 1;
    if (root == Null)
        return;
    struct Qnode q;
     q = creatqueue();
     insert(&q,root);
    while(iskong(&q)!=Null)
    {
        root = delete (&q) ;
        if(biaozhi)
        {
           if(t[root].left == Null && t[root].right == Null)
           {
               printf("%d",root);
               biaozhi = 0;
           }

        }
    else
    {
        if(t[root].left == Null && t[root].right == Null)
        printf(" %d",root);
    }

    if(t[root].left!= Null)
        insert(&q,t[root].left);
    if(t[root].right != Null)
        insert(&q,t[root].right);

    }
}









int main()
{
    Tree tt[10];
    int root;
    root = build(tt);
    printyezi(tt,root);

    //printf("%d",root);
    return 0;
}
