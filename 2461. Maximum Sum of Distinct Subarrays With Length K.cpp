#define ll long long
class Solution {
public:
    ll maximumSubarraySum(vector<int>& v, int k) { 
        ll int i,sum,ans,j;i=j=sum=ans=0;
        unordered_map<ll int,ll int> m;
        while(i < v.size()){ 
            while((j < v.size()) && ((j-i) < k)){
                sum += v[j];
                m[v[j]]++;
                j++;                
            }
            if(m.size() == k) ans = max(ans,sum);
            if(m[v[i]] == 1) m.erase(v[i]);
            else m[v[i]]--;
            sum -= v[i];  
            i++;
        }
        return ans;
    }
};