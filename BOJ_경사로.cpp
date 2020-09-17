#include <iostream>
#define MAX 100

using namespace std;

int N,L;
int map[MAX][MAX]={0,};
int cnt =0;

int comp(int pos , int arr[100])
{
    int tmp;
    
    if ( arr[pos] > arr[pos+1]){
        tmp = pos+1;
        int len=1;
        while(tmp < N-1){
            if(arr[tmp] != arr[tmp+1])  break;
            len++;
            tmp++;
        }
        if(len < L )    return 0;
        else if(tmp == N-1)  return N-1;
        else if((arr[pos]-arr[tmp+1])== 2)   return tmp;
    //    else if(len%L!=0 &&  (arr[pos] == arr[tmp+1]))  return 0;
        else if((len/L) >= 2 &&  (arr[pos] == arr[tmp+1]))  return tmp+1;
        else  return 0;
    }
    else {
        tmp = pos;
        int len =1;
        while(tmp > 0){
            if(arr[tmp] != arr[tmp-1])  break;
            len++;
            tmp--;
        }
        if(len < L )    return 0;
        else    return pos+1;
    }
}

void check(int idx,bool flag)
{
    
    int arr[N];
    
    if(flag)    for(int i=0;i<N;i++)    arr[i] = map[i][idx];
    else    for(int i=0;i<N;i++)    arr[i] = map[idx][i];
    
    int pos =0;
    
    while(pos < N-1 ){
        
        int diff = arr[pos] - arr[pos+1];
        
        if( diff == 0)  pos++;
        else if(diff==1 || diff == -1){
            pos = comp(pos , arr);
            if(pos ==0) return ;
        }
        else    return ;
    }
    
    cnt++;
}

int main(void)
{
    cin >> N >> L;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)    cin >> map[i][j];
    }
    
    for(int i=0;i<N;i++){
        check(i,0); // row
        check(i,1); // col
    }
    
    cout << cnt;
    
    return 0;
}

