#include <iostream>
#define MAX 10000

using namespace std;

int DP[MAX]={0,};
int arr[MAX]={0,};
int N;

int max(int a , int b)
{
    if ( a> b)  return a;
    else return b;
}

int main(void)
{
    cin >> N;
    for(int i=0;i<N;i++)    cin >> arr[i];
    
    DP[0] = arr[0];
    DP[1] = DP[0] + arr[1];
    DP[2] = max(arr[0]+arr[1] , arr[0]+arr[2]);
    
    for(int i=3;i<N;i++){
        DP[i] = max(arr[i]+arr[i-1]+DP[i-3] , arr[i]+DP[i-2]);
        DP[i]=max(DP[i], DP[i-1]);
    }
    cout << DP[N-1];
    return 0;
    
}

