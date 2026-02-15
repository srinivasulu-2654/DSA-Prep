class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        int sum = 0;
        string res = "";
        while(i>=0 || j>=0)
        {
            sum = carry;
            if(i>=0)
            {
                sum += a[i]-'0';
                i--;
            }
            if(j>=0)
            {
                sum += b[j] - '0';
                j--;
            }

            if(sum%2==0) res.push_back('0');
            else if(sum%2==1) res.push_back('1');
            
            carry = (sum > 1) ? 1 : 0; // else do sum/2;
        }

        if(carry==1) res.push_back('1');
        reverse(res.begin(),res.end());
        return res;

    }
};
