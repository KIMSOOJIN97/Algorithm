#include <stdio.h>

using namespace std;

int arr[4][8]={0,};

void rotate(int idx ,int dir)
{
    int tmp;
    
    if(dir == 1){//시계
        tmp = arr[idx][7];
        for(int i=6;i>=0;i--)    arr[idx][i+1] = arr[idx][i];
        arr[idx][0]=  tmp;
    }
    else{ // 반시계
        tmp = arr[idx][0];
        for(int i=1;i<=7;i++)    arr[idx][i-1] = arr[idx][i];
        arr[idx][7]=tmp;
    }
}

void solve(int idx , int dir)
{
    int tmp1;
    int tmp2;
    
    if(idx == 0)
    {
        tmp1 = arr[0][2];
        rotate(idx, dir);
        if(tmp1 != arr[1][6]){
            tmp1 = arr[1][2];
            rotate(1,dir*-1);
            if(tmp1 != arr[2][6]){
                tmp1 = arr[2][2];
                rotate(2, dir);
                if(tmp1 != arr[3][6])   rotate(3, dir*-1);
            }
        }
    }
    else if(idx==1){
        tmp1 = arr[1][6];
        tmp2 = arr[1][2];
        rotate(idx,dir);
        if(tmp1 != arr[0][2])   rotate(0,dir*-1);
        if(tmp2 != arr[2][6]){
            tmp2 = arr[2][2];
            rotate(2, dir*-1);
            if(tmp2 != arr[3][6])   rotate(3, dir);
        }
    }
    else if(idx==2){
        tmp1 = arr[2][2];
        tmp2 = arr[2][6];
        rotate(idx,dir);
        if(tmp1 != arr[3][6])   rotate(3, dir*-1);
        if(tmp2 != arr[1][2]){
            tmp2 = arr[1][6];
            rotate(1, dir*-1);
            if(tmp2 != arr[0][2])   rotate(0,dir);
        }
    }
    else{
        tmp1 = arr[3][6];
        rotate(idx,dir);
        if(tmp1 != arr[2][2]){
            tmp1 = arr[2][6];
            rotate(2, dir*-1);
            
            if(tmp1 != arr[1][2]){
                tmp1= arr[1][6];
                rotate(1,dir);
                if(tmp1 != arr[0][2])   rotate(0,dir*-1);
            }
        }
    }
}

int main(void)
{
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++)
            scanf("%1d",&arr[i][j]);
    }
    
    int K;
    scanf("%d",&K);
    
    for(int i=0;i<K;i++){
        int idx , dir;
        
        scanf("%d %d",&idx,&dir);
        solve(idx-1 , dir);
    }
    int sum =0;
    int num=1;
    
    for(int i=0;i<4;i++){
        if(arr[i][0] )  sum += num;
        num*=2;
    }
    printf("%d\n",sum);
    return 0;
}

