class Solution {
public:  
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> v;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < n - 1; i++) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0) {
                    v.insert({nums[i], nums[left], nums[right]});
                    left++; right--;

                }
                else if(sum > 0) {
                    right--;
                }
                else left++;
            }
        }
        
        vector<vector<int>> ans;
        for(auto e : v) {
            ans.push_back(e);
        }
        return ans;
    }
};