Approach 1:

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();
        if(m!=n) return false;
        for(int cnt=1;cnt<=m;cnt++)
        {
            rotate(begin(s),begin(s)+1,end(s));
            if(s==goal) return true;
        }
        return false;
        
    }
};

Approach 2 :
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();
        if(m!=n) return false;
        if((s+s).find(goal) != string :: npos)
        {
            return true;
        }
        return false;
    }
};
