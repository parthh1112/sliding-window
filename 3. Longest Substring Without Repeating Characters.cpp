class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0, j = 0;
        unordered_map<char, int> u;
        for (int i = 0; i < s.size(); i++)
        {
            int r = u.size();
            u[s[i]]++;
            if (r == u.size())
            {
                int c = u[s[i]];
                while (u[s[i]] != c - 1)
                {
                    u[s[j]]--;
                    if (u[s[j]] == 0)
                        u.erase(s[j]);
                    j++;
                }
                continue;
            }
            r = u.size();
            ans = max(ans, r);
        }
        return ans;
    }
};



// or can do this way as well


class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int ans = 0;
        set<char> s;
        int i = 0 , j = 0; 
        while(i < str.size()){
            if(s.find(str[i]) == s.end()){
                s.insert(str[i]);
            }
            else{
                while(s.find(str[i]) != s.end()){
                    s.erase(str[j]);
                    j++;                    
                }  
                s.insert(str[i]);

            } 
            int k = s.size();
            ans = max(ans,k);
            i++;
        }

        return ans;
    }
};