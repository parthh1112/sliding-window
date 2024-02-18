int lenOfLongSubarr(int v[], int n, int k)
{
    int ans = 0;
    unordered_map<int, int> u;
    u[0] = -1;
    int psum = 0;
    for (int i = 0; i < n; i++)
    {
        psum += v[i];
        if (u.find(psum - k) != u.end())
        { // element found
            ans = max(ans, i - u[psum - k]);
        }
        u[psum]++;
    }
    return ans;
}