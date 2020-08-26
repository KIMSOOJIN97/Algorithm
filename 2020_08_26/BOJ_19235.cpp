#include <iostream>

using namespace std;


int red[4][4]={0,};
int green[6][4]={0,};
int blue[4][6]={0,};
int score=0;
int t,x,y;


int check_blue()
{
    int cnt =0;
    int flag=0;
    int tmp[4][6]={0,};
    
    for(int i=0;i<6;i++){
        
        cnt =0;
        
        for(int j=0;j<4;j++){
            if(blue[j][i])  cnt++;
        }
        if(cnt == 4) {
            flag=1;
            for(int k=0;k<4;k++)    blue[k][i]=0;
            score++;
        }
    }
    
    if(flag ==0)    return 1;
    
    for(int k=0;k<4;k++){
        int idx = 5;
        for(int j=5;j>=0;j--){
            if(blue[k][j]==1){
                tmp[k][idx]=1;
                idx--;
            }
        }
    }
    
    for(int k=0;k<4;k++){
        for(int j=0;j<6;j++)
            blue[k][j] = tmp[k][j];
    }
    
    return 0;
    
}

int check_green()
{
    int cnt =0;
    int flag=0;
    int tmp[6][4]={0,};
    
    for(int i=5;i>=0;i--){
        cnt =0;
        
        for(int j=0;j<4;j++){
            if(green[i][j])  cnt++;
        }
        
        if(cnt == 4) {
            for(int k=0;k<4;k++)    green[i][k]=0;

            flag=1;
            score++;
        }
    }
    
    if(flag ==0)    return 1;
    
    for(int k=0;k<4;k++){
        int idx = 5;
        for(int j=5;j>=0;j--){
            if(green[j][k]==1){
                tmp[idx][k]=1;
                idx--;
            }
        }
    }
    
    for(int k=0;k<6;k++){
        for(int j=0;j<4;j++)
            green[k][j]=tmp[k][j];
    }

    return 0;
}


void col()
{
    for(int i=5;i>0;i--){
        for(int j=0;j<4;j++)
            blue[j][i]=blue[j][i-1];
    }
}

void row()
{
    for(int i=5;i>0;i--){
        for(int j=0;j<4;j++)
            blue[j][i]=blue[j][i-1];
    }
}

int push_blue()
{
    int cnt =0;
    for(int i=1;i>=0;i--){
        int flag =0;
        for(int j=0;j<4;j++){
            if(blue[j][i]){
                flag =1;
            }
        }
        if(flag) {
            col();
            cnt++;
        }
    }
    if(cnt ==0 )    return 1;
    
    for(int i=1;i>=0;i--){
        for(int j=0;j<4;j++){
            blue[j][i]=0;
        }
    }
    return 0;
}

int push_green()
{
    int cnt =0;
    for(int i=1;i>=0;i--){
        int flag =0;
        for(int j=0;j<4;j++){
            if(green[i][j]){
                flag =1;
            }
        }
        if(flag) {
            row();
            cnt++;
        }
    }
    if(cnt ==0) return 1;
    
    for(int i=1;i>=0;i--){
        for(int j=0;j<4;j++){
            green[i][j]=0;
        }
    }
    return 0;
}

int mv_blue(int idx)
{
    
    for(int i=0;i<6;i++){
        if(blue[idx][i])    return i-1;
    }
    
    return 5;
}

int mv_green(int idx)
{
    
    for(int i=0;i<6;i++){
        if(green[i][idx])    return i-1;
    }
    
    return 5;
}

void move()
{
    int idx, idx1 , idx2;
    
    if( t == 1){
        idx1 = mv_blue(x);
        blue[x][idx1] = 1;
        
        idx1 = mv_green(y);
        green[idx1][y]=1;
    }
    else if(t==2){
        
        idx1 = mv_blue(x);
        blue[x][idx1] = 1;
        blue[x][idx1-1] =1;
        
        idx1 = mv_green(y);
        idx2 = mv_green(y+1);
        
        idx = idx1 >= idx2 ? idx2 : idx1;
        
        green[idx][y]=1;
        green[idx][y+1]=1;

    }
    else{
        
        idx1 = mv_blue(x);
        idx2 = mv_blue(x+1);
        
        idx = idx1 >= idx2 ? idx2 : idx1;
        
        blue[x][idx] =1;
        blue[x+1][idx] =1;
        
        idx = mv_green(y);
        green[idx][y]=1;
        green[idx-1][y]=1;

    }

}

int main(void)
{
    int N;
    cin >> N ;
    
    for(int i=0;i<N;i++){
        
        cin >> t >> x >> y;
        
        move();
        
        
        int ch1=0;
        int ch2=0;
        int ch3=0;
        int ch4=0;
        while((ch1 && ch2 && ch3 && ch4 ) == 0){
            
            ch1 = check_blue();
            ch2 = check_green();
        
        
            ch3 = push_blue();
            ch4 = push_green();


        }
    }
    
    int num =0;
    
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            num += blue[i][j];
            num+=green[j][i];
        }
        
    }
    cout << score << "\n" ;
    cout << num;
    return 0;
}

