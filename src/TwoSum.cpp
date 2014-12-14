class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //sort(numbers.begin(), numbers.end());
        int n = numbers.size();
        
        vector<int> ans;
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (numbers[i] + numbers[j] == target) {
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                    return ans;
                }
        return ans;
    }
};
