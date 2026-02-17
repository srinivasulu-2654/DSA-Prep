https://www.geeksforgeeks.org/problems/equal-0-1-and-23208/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// Here this problem can not be able to do by sliding window and all becuase 
// we have to calculate equal number of 0's, 1's and 2's
// so this is like prefixSum

 long long getSubstringWithEqual012(string str) {
        // code here
        int n = str.size();
        long long cnt = 0;
        int z0 = 0, z1 = 0, z2 = 0;
        unordered_map<string,int>mp;
        
        mp["0#0"] = 1;  // here if we are adding the basic because when we take the string str = "012" then it will give wrong answer if we won't take like this
        
        for(int i=0;i<n;i++)
        {
            if(str[i]=='0')
            {
                z0++;
            }
            else if(str[i]=='1')
            {
                z1++;
            }
            else if(str[i]=='2')
            {
                z2++;
            }
            
            string key = to_string(z1-z0) + "#" + to_string(z2-z1);
            
            if(mp.find(key) != mp.end())
            {
                cnt += mp[key];
                mp[key]++;
            }
            else{
                mp[key] = 1;
            }
        }
        
        return cnt;
    }
