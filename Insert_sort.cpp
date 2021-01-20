#include <iostream>

using namespace std;

int main()
{
    int N,M;
    int arr[100]={0,};
    cin >> N;
    for(int i=0;i<N;i++)    cin >> arr[i];
    cin >> M;
    
    for(int i=1;i<=M;i++){
        int tmp = arr[i];
        for(int j=i;j>0;j—){
            if(arr[j-1] > tmp ){
                arr[j] = arr[j-1];
                if(j==1)    {
                    arr[j-1]=tmp;
                    break;
                }
            }
            else{
                arr[j] =tmp;
                break;
            }
        }
    }
    
    for(int i=0;i<N;i++)    cout << arr[i] << " ";
    return 0;
}
