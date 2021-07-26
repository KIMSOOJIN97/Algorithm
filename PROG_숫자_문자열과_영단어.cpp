#include <string>
#include <vector>

using namespace std;

string ans ="";

int solution(string s) {
    int answer = 0;
    int size = s.size();
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>= 48 && s[i] <= 57) ans += s[i];
        else
        {
            if(s[i]=='z')
            {
                ans+="0";
                i+= 4;
            }
            else if(s[i]=='o'){
                ans+="1";
                i+= 3;
            } 
            else if(s[i]=='e'){
                ans+="8";
                i+= 5;
            }
            else if(s[i]=='n'){
                ans+="9";
                i+= 4;
            }
            else if(s.substr(i,3) == "two"){
                ans+="2";
                i+= 3;
            }
            else if(s.substr(i,5) == "three"){
                ans+="3";
                i+= 5;
            }
            else if(s.substr(i,4) == "four"){
                ans+="4";
                i+= 4;
            }    
            else if(s.substr(i,4) == "five"){
                ans+="5";
                i+= 4;
            }
            else if(s.substr(i,3) == "six"){
                ans+="6";
                i+= 3;
            }
            else if(s.substr(i,5) == "seven"){
                ans+="7";
                i+= 5;
            }
            
            i--;
        }
    }
    answer = stoi(ans);
    return answer;
}
