#include <iostream>
#define MAX 10000
using namespace std;

int N,M;
int arr[MAX];


int main(void)
{
    int total=0;

    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)    scanf("%d",&arr[i]);
    
    int start =0 ;
    int end =0;
    int sum =arr[0];
    
    
    while(start <= end && end < N)
    {
        if(sum < M) sum += arr[++end];
        else if( sum > M)
        {
            sum -= arr[start++];
            if( start > end && start <N){
                end=  start;
                sum= arr[start];
            }
        }
        else if (sum == M)
        {
            total++;
            sum += arr[++end];
        }
    }
    
    printf("%d",total);
    return 0;
    
}

