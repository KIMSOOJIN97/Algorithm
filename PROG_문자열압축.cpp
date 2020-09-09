#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    
    int len = s.size();
    int answer = len;
    
    
    for(int i=1;i<len;i++){
        
        string res = "";
        string temp=s.substr(0,i);
        int count=1;
        
        for(int j=i;j<=len;j+=i)
        {
            if(temp==s.substr(j,i))
            {
                count++;
            }
            else{
                
                if(count==1)    res += temp;
                else    res+= (to_string(count)+temp);
                
                count=1;
                temp = s.substr(j,i);
            }
        }
        
        if(len/i != 0)  res += s.substr((len/i) * i);
        if(res.size() < answer )    answer = res.size();
    }
    
    return answer;
}

