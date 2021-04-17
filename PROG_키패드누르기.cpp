#include <string>
#include <vector>

using namespace std;

struct pos{
    int x,y;
};

pos left = {3,0};
pos right = {3,2};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    for(int i=0;i<numbers.size();i++)
    {
        int num = numbers[i];
        
        if(num == 1 || num == 4 || num == 7)
        {
            answer += "L";
            left = {num/3,0};
        }
        else if(num == 3 || num == 6 || num == 9)
        {
            answer += "R";
            right = { num/3-1 , 2};
        }
        else
        {
            int x = num/3;
            int y = 1;
            if(num == 0)    x = 3;
            
            int ldis = abs(x-left.x) + abs(y-left.y);
            int rdis = abs(x-right.x) + abs(y-right.y);
            
            if(rdis < ldis)
            {
                answer += "R";
                right = {x,y};
            }
            else if(rdis > ldis )
            {
                answer += "L";
                left = {x,y};
            }    
            else
            {
                if(hand.compare("right") == 0)
                {
                    answer += "R";
                    right = {x,y};
                }
                else
                {
                    answer += "L";
                    left = {x,y};
                }
            }
        }
    }
    return answer;
}
