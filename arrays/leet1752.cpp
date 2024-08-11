// 1752. Check if Array Is Sorted and Rotated

#include <iostream>
#include <vector>

class Solution {
public:
    bool check(std::vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            // std::cout <<nums[i]<<","<< nums[(i + 1) % n]<<"\n";
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
                // If there is more than one rotation point, return false
                if (count > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {3, 4, 5, 1, 2};
    std::vector<int> nums2 = {2, 1, 3, 4};

    if (sol.check(nums1)) {
        std::cout << "The array {3, 4, 5, 1, 2} is a rotated sorted array." << std::endl;
    } else {
        std::cout << "The array {3, 4, 5, 1, 2} is not a rotated sorted array." << std::endl;
    }

    if (sol.check(nums2)) {
        std::cout << "The array {2, 1, 3, 4} is a rotated sorted array." << std::endl;
    } else {
        std::cout << "The array {2, 1, 3, 4} is not a rotated sorted array." << std::endl;
    }

    return 0;
}
