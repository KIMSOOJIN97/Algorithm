#include <iostream>
#define MAX 1001

using namespace std;

int DP[MAX]={0,};
int N;

int main(void)
{
    scanf("%d", &N);
    
    DP[1] = 1;
    DP[2] = 3;
    
    for(int i=3;i<=N;i++)   DP[i] = (DP[i-1]%10007 + 2*DP[i-2]%10007)%10007;
    
    cout << DP[N];
    return 0;
}

