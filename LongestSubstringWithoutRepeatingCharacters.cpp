// Given a string s, find the length of the longest substring without repeating characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxi=0;
        map<char,int> mp;
        for(int right=0;right<s.length();right++)
        {
            mp[s[right]]++;
            if(mp.size()<right-left+1)
            {
                while(mp.size()<right-left+1)
                {
                    mp[s[left]]--;
                    if(mp[s[left]]==0)
                        mp.erase(s[left]);
                           left++;
                }
            }
            if(mp.size()==right-left+1)
                maxi=max(maxi,right-left+1);
                
        }
        return maxi;
    }
};
