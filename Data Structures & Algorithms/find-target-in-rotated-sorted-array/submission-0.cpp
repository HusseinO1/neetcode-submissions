class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    // 1. Find the pivot (index of the minimum element)
    while (left < right) {
      int mid = left + (right - left) / 2;

      // FIXED: Sign reversed to correctly find the minimum
      if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    
    int pivot = left;
    
    // 2. Decide which sorted half to search
    left = 0;
    right = nums.size() - 1;

    // FIXED: Compare against the last element to determine the chunk
    if (target >= nums[pivot] && target <= nums[right]) {
        left = pivot; // Target is in the right chunk
    } else {
        right = pivot - 1; // Target is in the left chunk
    }

    // 3. Standard binary search on the chosen half
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if(nums[mid] == target) return mid;

      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return -1;
  }
};