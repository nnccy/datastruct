#include <stdio.h>
#include <stdlib.h>
int MaxSubseqSum1( int A[], int N );
int MaxSubseqSum2( int A[], int N );
int MaxSubseqSum3( int List[], int N );
int MaxSubseqSum4 (int List[], int N );
int main()
{

    int a[8] = {-1,3,-2,4,-6,1,6,-1};
    int max = 0;

//   max = MaxSubseqSum1(a,8);
//   max = MaxSubseqSum2(a,8);
    max = MaxSubseqSum3(a,8);
    printf("%d",max);



    return 0;
}



//暴力求解
int MaxSubseqSum1( int A[], int N )
{
    int ThisSum, MaxSum = 0;
    int i, j, k;
    for( i = 0; i < N; i++ )
    {
        for( j = i; j < N; j++ )
        {
            ThisSum = 0;
            for( k = i; k <= j; k++ )
            {
                ThisSum += A[k];
            }

            if( ThisSum > MaxSum )
                MaxSum = ThisSum;

        }
    }
    return MaxSum;
}

//去掉了一个循环
int MaxSubseqSum2( int A[], int N )
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for( i = 0; i < N; i++ )
    {
        ThisSum = 0;
        for( j = i; j < N; j++ )
        {
            ThisSum += A[j];
            if( ThisSum > MaxSum )
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}


//分而治之 ，运用递归
int Max3( int A, int B, int C )
{ /* 返回3个整数中的最大值 */
    //return A > B ? A > C ? A : C : B > C ? B : C;
    if(A>B)
    {
        if(A>C)

            return A;
        else
            return C;
    }
    else
    {
        if(B>C)

            return B;
        else
            return C;
    }


}




int DivideAndConquer( int List[], int left, int right )
{ //分治法求List[left]到List[right]的最大子列和 */
    int MaxLeftSum, MaxRightSum; //存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; //存放跨分界线的结果

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )
    { // 递归的终止条件，子列只有1个数字
        if( List[left] > 0 )
            return List[left];
        else
            return 0;
    }

    //下面是"分"的过程 */
    center = ( left + right ) / 2; //找到中分点
    //递归求得两边子列的最大和
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    // 下面求跨分界线的最大子列和
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- )
    {
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ )
    {
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    }

    printf("%d  %d  %d\n",MaxLeftSum,MaxRightSum,MaxLeftBorderSum + MaxRightBorderSum);
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum3( int List[], int N )
{
    return DivideAndConquer( List, 0, N-1 );
}


//动态规划
int MaxSubseqSum4 (int List[], int N )
{
    int sum = 0,i = 0;
    int maxsum = 0;
    for(i = 0;i < N;i++)
    {
        sum += List[i];
        if(maxsum < sum)
        {
            maxsum = sum;
        }
        if (sum < 0)
            sum = 0;
    }

return maxsum;
}












