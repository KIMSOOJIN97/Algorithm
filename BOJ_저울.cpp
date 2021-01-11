#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int arr[MAX]={0,};
int N;

int main(void)
{
    cin >> N;
    for(int i=0;i<N;i++)    cin >> arr[i];
    sort(arr,arr+N);
    
    int sum=0;
    
    for(int i=0;i<N;i++){
        if(sum+2<=arr[i]){
            cout << sum+1;
            return 0;
        }
        sum+=arr[i];
    }
    cout << sum+1;
    return 0;
}

