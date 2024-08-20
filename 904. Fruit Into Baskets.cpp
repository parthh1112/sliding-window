
class Solution
{
public:
    int totalFruit(vector<int> &v)
    {
        int ans = 0, i = 0, j = 0, sum = 0;
        unordered_map<int, int> u;
        while (i < v.size())
        {
            u[v[i]]++;
            if (u.size() > 2)
            {
                u[v[j]]--;
                if (u[v[j]] == 0)
                    u.erase(v[j]);
                j++;
            }
            int s = 0;
            for (auto k : u)
                s += k.second; // o(1) => loop is running for only 2 elements
            ans = max(ans, s);
            i++;
        }
        return ans;
    }
};




or 





class Solution {
public:
    int totalFruit(vector<int>& v) {
        int ans = 0, i = 0, j = 0, n = v.size();
        map<int,int> m;
        while(i < n){
            m[v[i]]++;
            if(m.size() > 2){
                int l = i - j;
                while(l-- && m.size() != 2){
                    m[v[j]]--;
                    if(m[v[j]] == 0){ 
                        m.erase(v[j++]);
                        break;
                    }
                    j++;
                }
            } 
            ans = max(ans,i - j + 1); 
            i++;
        }
        return ans;        
    }
};