class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>&v, int k) {
        vector<int> ans;
        int i,j;i=j=0;
        deque<int> q;
        while((i < v.size()) && (ans.size() < v.size() - k + 1)){
            while((j<v.size()) && (j-i < k)){
                while(q.size() != 0 && q.back() < v[j]) q.pop_back();
                q.push_back(v[j]);
                j++;
            }
            ans.push_back(q.front());
            if(v[i] == q.front())q.pop_front();
            i++;
        }
        return ans;
    }
};