#include <iostream>
#define MAX 1000
using namespace std;

int DP[MAX]={0,};
int N;

int solve(int num)
{
    if(num==1)    return 1;
    else if(num==2)   return 2;
    else if(DP[num] !=0)  return DP[num];
    else{
        DP[num]=(solve(num-1)+solve(num-2))%10007;
        return DP[num];
    }
        
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    DP[1] = 1;
    DP[2] = 2;

    cout << solve(N);
    
}

