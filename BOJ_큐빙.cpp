#include <iostream>
#include <string>

using namespace std;

int cube[6][3][3]={0,};
char ch1,ch2;

void solve()
{
    int tmp[3];
    
    if(ch1=='U'){
        
        if(ch2=='+'){//시계
            for(int i=0;i<3;i++)    tmp[i] =cube[2][0][i];
            for(int i=0;i<3;i++)    cube[2][0][i] =cube[5][0][i];
            for(int i=0;i<3;i++)    cube[5][0][i] =cube[3][0][2-i];
            for(int i=0;i<3;i++)    cube[3][0][i] =cube[4][0][2-i];
            for(int i=0;i<3;i++)    cube[4][0][i] =tmp[i];
        }
        else{
            
            for(int i=0;i<3;i++)    tmp[i] =cube[2][0][i];
            for(int i=0;i<3;i++)    cube[2][0][i] =cube[4][0][i];
            for(int i=0;i<3;i++)    cube[4][0][i] =cube[3][0][2-i];
            for(int i=0;i<3;i++)    cube[3][0][i] =cube[5][0][2-i];
            for(int i=0;i<3;i++)    cube[4][0][2-i] =tmp[i];
        }
    }
    else if(ch1=='D'){
        
        if(ch2=='-'){//시계
            for(int i=0;i<3;i++)    tmp[i] =cube[2][2][i];
            for(int i=0;i<3;i++)    cube[2][2][i] =cube[4][2][2-i];
            for(int i=0;i<3;i++)    cube[4][2][i] =cube[3][2][i];
            for(int i=0;i<3;i++)    cube[3][2][i] =cube[5][2][i];
            for(int i=0;i<3;i++)    cube[5][2][i] =tmp[2-i];
        }
        else{
            for(int i=0;i<3;i++)    tmp[i] =cube[2][2][i];
            for(int i=0;i<3;i++)    cube[2][2][i] =cube[5][2][2-i];
            for(int i=0;i<3;i++)    cube[5][2][i] =cube[3][2][i];
            for(int i=0;i<3;i++)    cube[3][2][i] =cube[4][2][i];
            for(int i=0;i<3;i++)    cube[4][2][2-i] =tmp[i];
        }
    }
    else if(ch1=='F'){
        
        if(ch2=='+'){//시계
            for(int i=0;i<3;i++)    tmp[i] =cube[5][i][0];
            for(int i=0;i<3;i++)    cube[5][i][0] =cube[0][2][i];
            for(int i=0;i<3;i++)    cube[0][2][i] =cube[4][2-i][2];
            for(int i=0;i<3;i++)    cube[4][i][2] =cube[1][2][i];
            for(int i=0;i<3;i++)    cube[1][2][i] =tmp[2-i];
        }
        else{
            for(int i=0;i<3;i++)    tmp[i] =cube[5][i][0];
            for(int i=0;i<3;i++)    cube[5][i][0] =cube[1][2][2-i];
            for(int i=0;i<3;i++)    cube[1][2][i] =cube[4][i][2];
            for(int i=0;i<3;i++)    cube[4][i][2] =cube[0][2][2-i];
            for(int i=0;i<3;i++)    cube[0][2][i] =tmp[i];
            
        }
    }
    else if(ch1=='B'){
        
        if(ch2=='-'){//시계
            for(int i=0;i<3;i++)    tmp[i] =cube[5][i][2];
            for(int i=0;i<3;i++)    cube[5][i][2] =cube[0][0][i];
            for(int i=0;i<3;i++)    cube[0][0][i] =cube[4][2-i][0];
            for(int i=0;i<3;i++)    cube[4][i][0] =cube[1][0][i];
            for(int i=0;i<3;i++)    cube[1][0][i] =tmp[2-i];
        }
        else{
            for(int i=0;i<3;i++)    tmp[i] =cube[5][i][2];
            for(int i=0;i<3;i++)    cube[5][i][2] =cube[1][0][2-i];
            for(int i=0;i<3;i++)    cube[1][0][i] =cube[4][i][0];
            for(int i=0;i<3;i++)    cube[4][i][0] =cube[0][0][2-i];
            for(int i=0;i<3;i++)    cube[0][0][i] =tmp[i];
            
        }
    }
    else if(ch1=='L'){
        
        if(ch2=='+'){//시계
            for(int i=0;i<3;i++)    tmp[i] =cube[0][i][0];
            for(int i=0;i<3;i++)    cube[0][i][0] =cube[2][2-i][0];
            for(int i=0;i<3;i++)    cube[2][i][0] =cube[1][i][0];
            for(int i=0;i<3;i++)    cube[1][i][0] =cube[3][2-i][0];
            for(int i=0;i<3;i++)    cube[3][i][0] =tmp[i];
        }
        else{//시계
            for(int i=0;i<3;i++)    tmp[i] =cube[0][i][0];
            for(int i=0;i<3;i++)    cube[0][i][0] =cube[3][i][0];
            for(int i=0;i<3;i++)    cube[3][i][0] =cube[1][2-i][0];
            for(int i=0;i<3;i++)    cube[1][i][0] =cube[2][i][0];
            for(int i=0;i<3;i++)    cube[2][i][0] =tmp[2-i];
        }
        
    }
    else if(ch1=='R'){
        
        if(ch2=='-'){//시계
            for(int i=0;i<3;i++)    tmp[i] =cube[0][i][2];
            for(int i=0;i<3;i++)    cube[0][i][2] =cube[2][2-i][2];
            for(int i=0;i<3;i++)    cube[2][i][2] =cube[1][i][2];
            for(int i=0;i<3;i++)    cube[1][i][2] =cube[3][2-i][2];
            for(int i=0;i<3;i++)    cube[3][i][2] =tmp[i];
        }
        else{//시계
            for(int i=0;i<3;i++)    tmp[i] =cube[0][i][2];
            for(int i=0;i<3;i++)    cube[0][i][2] =cube[3][i][2];
            for(int i=0;i<3;i++)    cube[3][i][2] =cube[1][2-i][2];
            for(int i=0;i<3;i++)    cube[1][i][2] =cube[2][i][2];
            for(int i=0;i<3;i++)    cube[2][i][2] =tmp[2-i];
        }
    }

}
void init()
{
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cube[i][j][k]=i;
            }
        }
    }
    

}
int main(void)
{
    int T;
    scanf("%d",&T);
    
    for(int k=0;k<T;k++){
        
        int num;
        scanf("%d",&num);
        init();

        for(int l=0;l<num;l++){
            string tmp;
            cin >> tmp;
            
            ch1 = tmp[0];
            ch2= tmp[1];
            solve();
        }
        for(int i=0;i<3;i++){
            
            for(int j=0;j<3;j++){
                // 흰색은 w, 노란색은 y, 빨간색은 r, 오렌지색은 o, 초록색은 g, 파란색은 b.
                if(cube[0][i][j]==0)    cout << "w";
                else if(cube[0][i][j]==1)    cout << "y";
                else if(cube[0][i][j]==2)    cout << "o";
                else if(cube[0][i][j]==3)    cout << "r";
                else if(cube[0][i][j]==4)    cout << "g";
                else if(cube[0][i][j]==5)    cout << "b";
            }
            cout << endl;
        }

    }
    return 0;
    
}

