#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    int cnt,a,i = 0;
    List p1,last,head;
    scanf("%d",&cnt);
    head = (List) malloc(sizeof(struct Node));
    head ->Next = NULL;

    last = head;
    while(i<cnt)
    {
        p1 = (List)malloc(sizeof(struct Node));
        scanf("%d",&a);
        last->Next = p1;
        p1->Data = a;
        last = p1;
        last->Next = NULL;

        i++;
    }

    return head;
}




void Print( List L )
{
    List p;
    p = L->Next;
    if(L->Next == NULL)
        printf("\nNULL");
    else
    {
        while(p != NULL)
        {
            printf("%d ",p->Data);
            p=p->Next;

        }

    }
}


List Merge( List L1, List L2 )
{
    List p,q,head,last;
    p = L1->Next;
    q = L2->Next;
    head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    last = head;
    while(p!=NULL&&q!=NULL)
    {
        if(p->Data < q->Data)
        {
            L1->Next = p->Next;
            last->Next = p;
            last = p;
            last->Next = NULL;
            p = L1->Next;
        }
        else
        {
            L2->Next = q->Next;
            last->Next = q;
            last = q;
            last->Next = NULL;
            q = L2->Next;
        }

    }
    while(p!=NULL)
    {
        L1->Next = p->Next;
        last->Next = p;
        last = p;
        last->Next = NULL;
        p = L1->Next;
    }
    while(q!=NULL)
    {
        L2->Next = q->Next;
        last->Next = q;
        last = q;
        last->Next = NULL;
        q = L2->Next;
    }

    return head;

}
