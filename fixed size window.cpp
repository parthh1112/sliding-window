#include <bits/stdc++.h>
using namespace std;
int max_subarray_sum(vector<int> &v, int k)
{
    int ans = INT_MIN;
    int tans = 0;
    for (int i = 0; i < k; i++)
    {
        tans += v[i];
    }
    ans = max(ans, tans);
    for (int i = k; i < v.size(); i++)
    {
        tans += v[i];
        tans -= v[i - k];
        ans = max(ans, tans);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[i] = x;
    }
    int k;
    cin >> k; // window size
    cout << max_subarray_sum(v, k);
    return 0;
}