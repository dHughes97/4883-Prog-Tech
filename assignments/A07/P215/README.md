## P215
 - Kth Largest Element in an Array
### Delton Hughes
### Description:
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

### Input Examples: 
Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4   


Constraints:

- 1 <= k <= nums.length <= 105
- -104 <= nums[i] <= 104

Solution: 
```
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Create a min-heap and take the first k elements, greater<int> keeps smallest at the top
        priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
        
        //iterate the rest of the array
        for (int i = k; i < nums.size(); ++i) {
            // if current is larger than root(smallest in heap)
            if (nums[i] > min_heap.top()) {
                min_heap.pop(); // remove the smallest element
                min_heap.push(nums[i]); // add current into heap
            }
        }
        return min_heap.top(); // the top equals the kth element in array 
    }
};

```
