class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = -1;
        int n = colors.size();
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(colors[i] != colors[j])
                {
                    ans = max(ans, abs(j-i));
                }
            }
        }
        return ans;
    }
};