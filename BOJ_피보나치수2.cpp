#include <iostream>
#define MAX 91
using namespace std;
long long int arr[MAX]={0,};
int main(void)
{
    int N;
    scanf("%d",&N);
    arr[0] =0;
    arr[1] =1;
    for(int i=2;i<=N;i++)   arr[i] = arr[i-1]+arr[i-2];
    cout << arr[N];
    return 0;
}


