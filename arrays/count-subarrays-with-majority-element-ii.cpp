class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> count(2 * n + 1, 0);
        int offset = n;
        count[0 + offset] = 1;
        long long ans = 0;
        int prefixSum = 0;
        long long smaller_count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                smaller_count += count[prefixSum + offset];
                prefixSum++;
            } else {
                prefixSum--;
                smaller_count -= count[prefixSum + offset];
            }

            ans += smaller_count;
            count[prefixSum + offset]++;
        }
        return ans;
    }
};
