class Solution
{
public:
    int numberOfSubarrays(vector<int> &v, int k)
    {
        deque<int> q;
        v.push_back(1);
        int i = 0, j = 0, cnt = 0, fans = 0;
        while (i < v.size())
        {
            if (v[i] % 2 == 1)
            {
                cnt++;
                if (cnt == k + 1)
                {
                    int f = q.front(), l = q.back(); 
                    q.pop_front();
                    int ans = ((f - j) * (i - l - 1)) + ((i - j) - (l - f + 1) + 1);
                    fans += ans;
                    cnt--;
                    j = f + 1;
                }
                q.push_back(i);
            }
            i++;
        }
        return fans;
    }
};