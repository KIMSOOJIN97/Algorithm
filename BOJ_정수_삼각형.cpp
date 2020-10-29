#include <iostream>
#define MAX 500

using namespace std;

int arr[MAX][MAX]={0,};
int DP[MAX][MAX]={0,};


int _max(int a, int b)
{
    if(a>b) return a;
    return b;
}

int main(void)
{
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++)   cin >> arr[i][j];
    }
    
    DP[0][0]= arr[0][0];
    
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){
            
            if(j==0)    DP[i][j] = DP[i-1][0]+arr[i][j];
            else if(j==i)   DP[i][j] = DP[i-1][j-1]+arr[i][j];
            else    DP[i][j]=_max(DP[i-1][j-1] , DP[i-1][j]) + arr[i][j];
                
        }
    }
    
    int res = 0;
    for(int i=0;i<N;i++){
        if(res < DP[N-1][i])    res = DP[N-1][i];
    }
    cout << res;
    
    return 0;
    
}

