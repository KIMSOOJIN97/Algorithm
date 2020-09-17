#include <stdio.h>

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define MAX 2500


int main(void)
{
    int T=0;
    scanf("%d",&T);
    
    for(int k=0;k<T;k++){
        
        int res =0;
        int num[5] ={0,};
        
        
        char croak[MAX];

        scanf("%s",&croak);
        
        for(int i=0;croak[i];i++)
        {
            if(res < num[0] - num[4])   res= num[0]-num[4];
            
            if(croak[i] == 'c'){
                if(num[0] < num[1]) {
                    res = -1;
                    break;
                }
                num[0]++;
            }
            else if(croak[i] == 'r'){
                if(num[1] < num[2]) {
                    res = -1;
                    break;
                }
                num[1]++;
            }
            else if(croak[i] == 'o'){
                if(num[2] < num[3]) {
                    res = -1;
                    break;
                }
                num[2]++;
            }
            else if(croak[i] == 'a'){
                if(num[3] < num[4]) {
                    res = -1;
                    break;
                }
                num[3]++;
            }
            else if(croak[i] == 'k'){
                num[4]++;
            }
        }
        
        if(res == -1)   printf("#%d -1\n",k+1);
        else{
            for(int j=0;j<4;j++){
                if(num[j]!=num[j+1] ) res=-1;
            }
            printf("#%d %d\n",k+1,res);

        }
    }
    return 0;
}

