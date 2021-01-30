#include <iostream>
#define MAX 100001

using namespace std;

int _max(int num1 , int num2)
{
    if(num1 > num2) return num1;
    return num2;
}

int main(void)
{
    int T;
    scanf("%d",&T);
    
    for(int k=0;k<T;k++){
        int N;
        cin >> N;
        
        int arr[2][MAX]={0,};
        int DP[2][MAX]={0,};

        for(int i=0;i<2;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        DP[0][0]= arr[0][0];
        DP[0][1]= arr[0][1];
        
        for(int i=1;i<N;i++){
            DP[0][i] = DP[1][i-1] + arr[0][i];
            DP[1][i] = DP[0][i-1] + arr[1][i];
        }
        printf("%d\n",_max(DP[0][N-1] , DP[1][N-1]));
    }
    return 0;
}

