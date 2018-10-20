#include <stdio.h>
#include <stdlib.h>


typedef struct snode
{
char cc;
struct  snode *next;

} *stack ,lstack;

void push(stack top,char s)     //ÈëÕ»
{

    stack p;
    p = (stack)malloc(sizeof(lstack));
    p->cc = s;
    p->next = top->next;
    top -> next = p;

}
char pop(stack top)     //³öÕ»
{

   if(top->next == NULL)
   {
       printf("¶ÑÕ»¿Õ");
       return NULL;
   }

   else
    {
        stack p;
        char a;
        p = top->next;
        a = p->cc;
        top->next = p->next;
        free(p);
        return a;
    }

}

stack create()
{
    stack top;
    top = (stack) malloc(sizeof(lstack));
    top->next = NULL;
    return top;

}

int main()
{
    stack top;
    char b;
    top = create();
    push(top,'f');
    push(top,'c');
    b = pop(top);
    printf("%c",b);
    b = pop(top);
    printf("%c",b);
    return 0;
}

