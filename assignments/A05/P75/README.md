## P75 - Sort Colors
### Delton Hughes
### Description:
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



### Input Examples: 
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2: 
Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:
- n == nums.length
- 1 <= n <= 300
- nums[i] is either 0, 1, or 2.


Solution: 
```
class Solution {
public:
 /*
 | Explanation: 
 |  Iterate of array count the number of 0,1,2's and 
 |  fill in new array with ordered list.
 |
 */
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Read the array and count the numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                count0++;
            else if (nums[i] == 1)
                count1++;
            else if (nums[i] == 2)
                count2++;
        }
        
        // replaces indices of array with numbers
        int filling = 0;

        // Fill in 0s
        for(int i = 0; i<count0; i++){
            nums[filling++] = 0; 
        }

        // Fill in 1s
        for(int i = 0; i < count1; i++){
            nums[filling++] = 1;
        }

        // Fill in 2s
        for(int i = 0; i < count2; i++){
            nums[filling++] = 2; 
        }

    }
};
```
