
#include <iostream>
#define MAX 100001
#define MOD 9901

using namespace std;

int arr[MAX]={0,};

int main(void)
{
    int N;
    cin >> N;
    arr[0]=1;
    arr[1]=3;
    
    for(int i=2;i<=N;i++){
        arr[i] = (arr[i-1]*2 + arr[i-2])%MOD;
    }
    cout << arr[N]%MOD;
    return 0;
}

