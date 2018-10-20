#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int zhi;
    int xi;
    struct node* next;
}Node,*Pnode;

Pnode read();
void print(Pnode L);        //打印指数和系数
Pnode sum(Pnode L1,Pnode L2);
Pnode multiply(Pnode L1,Pnode L2);



int main()
{
    Pnode L1,L2,Lsum,Lmu;
    L1=read();
    L2=read();
    //print(L1);
    //print(L2);
    Lmu = multiply(L1,L2);
    Lsum = sum(L1,L2);
    print(Lmu);
    print(Lsum);
    return 0;
}




Pnode read()
{
    Pnode head,last,p;


    int cnt ,i=0;
    scanf("%d",&cnt);
    head = (Pnode)malloc(sizeof(Node));
    last = head;
    last->next = NULL;
    for(i=0;i<cnt;i++)
    {
        p = (Pnode)malloc(sizeof(Node));
        scanf("%d",&p->xi);
        scanf("%d",&p->zhi);
        last->next = p;
        last = p;
    }
    last->next = NULL;
    return head;
}


void print(Pnode L)
{


    if(L->next == NULL)
    {
        printf("0 0");
    }
    else
    {

    int biaozhi = 1;
    Pnode p;
    p = L->next;
    while(p!=NULL)
    {
        if(biaozhi)
        {
            biaozhi = 0;
            printf("%d %d",p->xi,p->zhi);
        }
       else
        {
            printf(" %d %d",p->xi,p->zhi);
        }

        p = p->next;

    }

    }

    printf("\n");
}

Pnode sum(Pnode L1,Pnode L2)
{
    Pnode p,q,head,last,L;
    p = L1->next;
    q = L2->next;
    head = (Pnode)malloc(sizeof(Node));
    last = head;
    last->next = NULL;
    while(p!=NULL&&q!=NULL)
    {
        if(p->zhi>q->zhi)
        {
            Pnode zhong;
            zhong = p->next;
            last->next = p;
            last =p;
            p = zhong;

        }
        else if(q->zhi>p->zhi)
        {
            Pnode zh;
            zh = q->next;
            last->next = q;
            last =q;
            q = zh;

        }
        else
        {
            if(p->xi+q->xi == 0)
            {
                last->next = NULL;
                p = p->next;
                q = q->next;
            }
            else
            {
                L = (Pnode)malloc(sizeof(Node));
                L->xi = p->xi+q->xi;
                L->zhi = p->zhi;
                last->next = L;
                last= L;
                //L->next = NULL;
                p = p->next;
                q = q->next;
            }

        }

    }


    while(p != NULL)
    {
        last ->next = p;
        last =p;
        p = p->next;

    }
    while(q != NULL)
    {
        last ->next = q;
        last =q;
        q = q->next;
    }


    return head;



}

Pnode multiply(Pnode L1,Pnode L2)
{

    Pnode head ,last,L,k1,t;
    head = (Pnode)malloc(sizeof(Node));
    last = head;
    last->next = NULL;
    Pnode p,q;
    int x,z;
    q = L2->next;


    p = L1->next;
    while(p)
    {
    L = (Pnode)malloc(sizeof(Node));
    L->xi = (p->xi)*(q->xi);
    L->zhi = (q->zhi)+(p->zhi);
    last->next = L;
    last = L;
    last->next = NULL;
    p = p->next;
    }

    q = q->next;
    while(q)
    {

        p = L1->next;
        k1 = head;
        while(p)
        {

            x = (p->xi)*(q->xi);
            z = (q->zhi)+(p->zhi);
            while(k1->next && z<(k1->next->zhi))
            {
                k1 = k1->next;
            }

            if(k1->next&&k1->next->zhi == z)
            {
                if(k1->next->xi + x!=0)
                     k1->next->xi = k1->next->xi + x;
                else
                {
                    t = k1->next;
                    k1->next = t->next;
                    free(t);
                }
            }

            else
            {
                L = (Pnode)malloc(sizeof(Node));
                L->xi = x;
                L->zhi =z;
                L->next = k1->next;
                k1->next = L;
                k1 = k1->next;
            }


        p = p->next;
        }
        q = q->next;

    }




    return head;
}






