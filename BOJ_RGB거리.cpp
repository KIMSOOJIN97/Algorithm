#include <iostream>
#define MAX 1000

using namespace std;

int N;
int arr[MAX][3];
int DP[MAX][3]={0,};

int _min(int a, int b)
{
    if(a<b) return a;
    return b;
}

int main(void)
{
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++)    cin >> arr[i][j];
    }
    
    DP[0][0]= arr[0][0];
    DP[0][1]= arr[0][1];
    DP[0][2]= arr[0][2];
    
    for(int i=1;i<N;i++){
        
        DP[i][0] = _min(DP[i-1][1] , DP[i-1][2]) + arr[i][0];
        DP[i][1] = _min(DP[i-1][0] , DP[i-1][2]) + arr[i][1];
        DP[i][2] = _min(DP[i-1][0] , DP[i-1][1]) + arr[i][2];
    }
    
    cout <<_min(DP[N-1][0] ,_min(DP[N-1][1] , DP[N-1][2]));
    return 0;
}

