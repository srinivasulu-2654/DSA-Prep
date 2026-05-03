class Solution {
public:
    bool rotateString(string s, string goal) {
        
        string temp = s + s;
        int tempsz = temp.size();
        int m = s.size();
        int n = goal.size();
        if(m!=n) return false;
        int i=0,j=0;
        while(i<tempsz && j<n)
        {
            if(temp[i]==goal[j])
            {
                i++;
                j++;
            }
            else{
                i = i-j+1; // in goal how many we have traversed wrongly
                j=0;

            }
        }

        return j == n;
    }
};
