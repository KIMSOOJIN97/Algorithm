#include <iostream>
#define MAX 16


using namespace std;

int T[MAX];
int P[MAX];
int DP[MAX]={0,};

int max(int num1 ,int num2)
{
    if(num1 > num2) return num1;
    return num2;
}

int main(void)
{
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)    scanf("%d %d",&T[i], &P[i]);
    
    if(T[N-1] == 1)    DP[N-1]=P[N-1];
    
    for(int i=N-2 ;i>=0; i--)   {
        
        if(i + T[i] <= N)   DP[i] = max(DP[i+1], P[i]+DP[i + T[i]]);
        else    DP[i] = DP[i+1];
    }
    cout << DP[0];
    return 0;
    
}

