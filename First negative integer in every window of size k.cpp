#define ll long long 
vector<ll> printFirstNegativeInteger(ll int v[],ll int n, ll int k) { 
    vector<ll> ans; 
    int i = 0,j = 0;
    int s = n - k + 1;
    queue<ll int> q;
    while(i < n && ans.size() < s){
        while((j < n) && ((j-i) < k)){
            if(v[j] < 0)q.push(v[j]);
            j++;
        }
        if((q.size() == 0)) ans.push_back(0);
        else ans.push_back(q.front());
        if(v[i] == q.front()) q.pop();
        i++;
    } 
    return ans;
}