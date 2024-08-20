class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int ans = 0, i = 0, cnt = 0,j = 0;  
        while(i < v.size()){
            if(v[i] == 0){
                cnt++;
                if(cnt > k){
                    while(cnt != k){
                        if(v[j] == 0)break;
                        j++;
                    }
                    cnt = k;
                    j++;
                } 
            }    
            ans = max(ans,(i - j + 1));
            i++;
        } 
        return ans;
    }
};