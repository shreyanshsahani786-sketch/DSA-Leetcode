class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right<fruits.size(); right++){

// window expand krna 
            mp[fruits[right]]++;

            // shrink if more then two types 

            if(mp.size() > 2) {

             mp[fruits[left]]--;

             if(mp[fruits[left]] == 0)
             mp.erase(fruits[left]);

             left++;
            }
            ans = max(ans,right - left + 1);
        }
        return ans;
        
    }
};