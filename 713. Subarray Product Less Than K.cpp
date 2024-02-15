class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &v, int k)
    {
        if (k == 0)
            return 0;
        int ans = 0;
        int i, j;
        i = j = 0;
        int mul = 1;
        while (i < v.size())
        {
            j = i;
            int help = 0;
            while ((j < v.size()) && ((mul * v[j]) < k))
            {
                mul *= v[j];
                help++;
                j++;
            }
            i++;
            mul = 1;
            ans += help;
        }
        return ans;
    }
};