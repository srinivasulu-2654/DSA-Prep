class Solution {

    public boolean isBalanced(int[] freq)
    {
        int commonFreq = 0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]==0) continue;
            if(commonFreq == 0)
            {
                commonFreq = freq[i];
            }
            else if(freq[i] != commonFreq) return false;
        }

        return true;
    }

    public int longestBalanced(String s) {
        int n = s.length();
        int maxiLen = 0;
        for(int i=0;i<n;i++)
        {
            int[] freq = new int[26];
            for(int j=i;j<n;j++)
            {
                freq[s.charAt(j) - 'a']++;
                if(isBalanced(freq) == true)
                {
                    maxiLen = Math.max(maxiLen,j-i+1);

                }
            }
        }

        return maxiLen;
    }
}
