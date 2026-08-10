class Solution {
public:
    int numberOfSubstrings(string s) {

        unordered_map<char,int> mp;

        int left = 0;
        int right = 0;
        int ans = 0;
        int n = s.size();

        for(int right = 0; right < n; right++) {

            // Expand krenge right ko
            mp[s[right]]++;
            

            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {

                ans = ans + (n - right);

                // Shrink
                mp[s[left]]--;
                left++;
            }
        }

        return ans;
    }
};