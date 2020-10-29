#include <iostream>
#define MAX 90

using namespace std;

long long DP[MAX]={0,};
int N;

int main(void)
{
    cin >> N;
    DP[1] = 1;
    DP[2] = 1;
    
    for(int i=3;i<=N;i++)
    {
        DP[i] = DP[i-1]+DP[i-2];
    }
    cout << DP[N];
    return 0;
    
}


