const int N = 1e5 + 1;
long long s[N];

class Solution {
public:
    static long long maxProfit(vector<int>& p, vector<int>& a, int k) {
        int n = p.size(), h = k / 2;
        memset(s, 0, sizeof(long long) * (n + 1));

        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + 1LL * a[i] * p[i];
        }

        long long m = reduce(p.begin() + h, p.begin() + k, 0LL);
        long long ans = max(s[n], m + s[n] - s[k]);

        for (int i = 1; i + k <= n; i++) {
            m += p[i + k - 1] - p[i + h - 1];
            ans = max(ans, m + s[n] - s[i + k] + s[i]);
        }
        return ans;
    }
};
