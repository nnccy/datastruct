

/*********
拼题3.6
******/

#include <stdio.h>
#include <stdlib.h>

#define  Null -1
typedef struct tree
{
    char zhi;
    int left;
    int right;
}Tree;

Tree t1[10];
Tree t2[10];

int build(Tree t[])
{
    int cnt=0,i=0;
    char l,r;
    int root = -1;
    scanf("%d",&cnt);
    getchar();         //屏蔽读取回车信号
    int check[cnt];

     for(i=0;i<cnt;i++)
        check[i]=0;
    if(!cnt)
    return Null;
    for(i = 0;i<cnt;i++)
    {
        scanf("%c %c %c",&t[i].zhi,&l,&r);
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
            t[i].right = r- '0';
            check[t[i].right] = 1;
        }
        else
        {
            t[i].right = Null;
        }


    }
    for(i = 0;i<cnt;i++)
    {
        if(check[i]==0)
        {
            root = i;
            break;
        }

    }

    return root;
}

int istonggou(int r1,int r2)
{

    if((r1==Null)&&(r2==Null))
        return 1;
    if(((r1==Null)&&(r2!=Null))||((r1!=Null)&&(r2==Null)))
        return 0;
    if(t1[r1].zhi != t2[r2].zhi)
        return 0;
    if(t1[r1].left==Null && t2[r2].left == Null)
        return istonggou(t1[r1].right,t2[r2].right);

    if(((t1[r1].left!=Null)&&(t2[r2].left!=Null))&&
       ((t1[t1[r1].left].zhi)==(t2[t2[r2].left].zhi)))
        return (istonggou(t1[r1].left,t2[r2].left))&&
            (istonggou(t1[r1].right,t2[r2].right));
    else
        return (istonggou(t1[r1].left,t2[r2].right))&&
            (istonggou(t1[r1].right,t2[r2].left));



}


int main()
{

    int r1;
    int r2;
    r1 = build(t1);
    r2 = build(t2);

//printf("%d %d",r1,r2);

 if (istonggou(r1,r2) == 0)
 {
     printf("no");
 }
 else
 {
     printf("yes");
 }

 return 0;
}
