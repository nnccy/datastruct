#include <stdio.h>
#include <stdlib.h>


struct  duoxiangshi{


int xishu;
int zhishu;


};



int main()
{

    struct duoxiangshi a[10] ={{1,2},{3,4}};



    printf("%d %d",a[1].xishu,a[0].zhishu);
    return 0;
}









