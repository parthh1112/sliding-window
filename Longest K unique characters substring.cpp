
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