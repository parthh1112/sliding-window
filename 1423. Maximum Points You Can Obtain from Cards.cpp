class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int ans = 0;
        int l = v.size() - k; // size of sliding window(find the min sum window)
        int mSum = 0;
        for(int i=0;i<l;i++)mSum += v[i]; 
        int s = 0, e = l;
        int mAns = mSum; 
        while(e < v.size()){ 
            mSum -= v[s++];
            mSum += v[e++];
            mAns = min(mAns,mSum);
        } 

        int kk = accumulate(v.begin(),v.end(),0) - mAns;

         
        return kk;
        
    }
};