https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        /* main formula is if num % den == 0 then directly return the quoitent
        if in case not: 
            rem = num % den
            dig = rem / den
            new rem = rem % den
        this is completely normal division like how we will put 0.012 like we borrow right same like that only

        */

        if(numerator==0) return "0";

        string res = "";

        // if(numerator < 0 || denominator < 0) res += "-";
        // instead for this we can use XOR (^) T ^ T = f, T ^ F = T

        if(numerator < 0 ^ denominator < 0) res += "-";

        long long num = llabs(numerator);
        long long den = llabs(denominator);

        long long intergerPart = num/den;

        res += to_string(intergerPart);

        long long rem = num % den;

        if(rem == 0) return res; // here integer part completed now starts fraction part

        res += "."; // already appended "0."

       unordered_map<long long,int>mp;

       while(rem != 0)
       {

            if(mp.find(rem) != mp.end())
            {
                res.insert(mp[rem],"(");
                res += ")";
                break;
            }
          
          mp[rem] = res.size(); // we should from where we have to insert the bracket

          rem = rem * 10;

          long long digit = rem / den;
          res += to_string(digit);
          rem = rem % den;
       }

       return res;
        
    }
};
