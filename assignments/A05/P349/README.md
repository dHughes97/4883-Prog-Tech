## P349 - Intersection of Two Arrays
### Delton Hughes
### Description:
Given two integer arrays nums1 and nums2, return an array of their 
intersection
. Each element in the result must be unique and you may return the result in any order.



### Input Examples: 
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2: 
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:
- 1 <= nums1.length, nums2.length <= 1000
- 0 <= nums1[i], nums2[i] <= 1000


Solution: 
```
class Solution {
public:

set<int> readIntersection(
    set<int>& firstSet, set<int>& secondSet) {
    set<int>temp;
    //Runs through both sets and uses count to check if 
    //there are any related numbers and if so put them in temp
    for (auto itr = firstSet.begin(); itr != firstSet.end(); itr++)
    {
      for (auto itr = secondSet.begin(); itr != secondSet.end(); itr++)
      {
       //if first set data is in my set 
       //and the 2nd set data is in my set
        if (firstSet.count(*itr) != 0 && secondSet.count(*itr) != 0){
         //put the data that is true in temp set
          temp.insert(*itr);
         }
      }
    }
    return temp;
}
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //convert the vector to a set
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        
        //get the intersection of the two sets and set it to a result
        set<int> resultSet = readIntersection(set1, set2);

        // convert back to a vector
        vector<int> result(resultSet.begin(), resultSet.end());
        
        return result;
    }
};      
```
