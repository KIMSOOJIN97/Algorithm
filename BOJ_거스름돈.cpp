#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int cnt =0;
    int arr[6] = {500,100,50,10,5,1};
    scanf("%d",&N);
    
    N = 1000-N;
    for(int i=0;i<6;i++){
        if(N<=0)    break;
        cnt += N/arr[i];
        N = N%arr[i];
    }
    printf("%d",cnt);
    return 0;
}

