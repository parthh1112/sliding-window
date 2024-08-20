
class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        unordered_map<char, int> m;
        int ans = -1;
        int i, j;
        i = j = 0;
        while (j < s.size())
        {
            m[s[j]]++;
            if (m.size() < k)
            {
                j++;
            }
            else if (m.size() == k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {
                while (m.size() > k)
                {
                    m[s[i]]--;
                    if (m[s[i]] == 0)
                        m.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};



or 





class Solution{
  public:
    int longestKSubstr(string s, int k) {
        if(k == 26)return s.size();
        bool chk = 1;
        int ans = -1, i = 0, j = 0, n = s.size();
        map<char,int> m;
        while(i < n){
            m[s[i]]++;
            if(m.size() > k){
                chk = 0;
                int l = i - j;
                while(l--){
                    m[s[j]]--;
                    if(m[s[j]] == 0){
                        m.erase(s[j++]);
                        break;
                    }
                    j++;
                }
                
            }
            ans = max(ans,i - j + 1);
            i++;
        }
        if(chk)return -1;
        
        return ans;
    }
};
