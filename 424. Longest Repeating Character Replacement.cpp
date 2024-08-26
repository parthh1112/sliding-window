class Solution {
public:
    int findans(string &s,int &k){
        bool chk = 1;
        int  i = 0,j = 0,n = s.size();
        array<int,26> a;
        int ans = 0;
        while(i < n){
            a[s[i] - 'A'] += 1;
            int maxx = 0;
            for(auto i : a)maxx = max(i,maxx); // O(1) only for 26 chars
            if((i - j) - maxx + 1 > k){
                ans = max(ans,(i - j));chk = 0;
                a[s[j] - 'A'] -= 1;
                j++;
            }
            i++;
        } 
        return (chk) ? n : ans;
    }
    int characterReplacement(string s1, int k) {
        string s2 = s1;
        reverse(s1.begin(),s1.end());
        int ans1 = findans(s1,k);
        int ans2 = findans(s2,k);
        return max(ans1,ans2);
    }
};
