## P1046 - Last Stone Weight
### Delton Hughes
### Description:
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

### Input Examples: 
Example 1: 
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2: 
Input: stones = [1]
Output: 1

Constraints:
- 1 <= stones.length <= 30
- 1 <= stones[i] <= 1000



Solution: 
```
#include <vector>
#include <algorithm>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // While there is more than one stone left
        while (stones.size() > 1) {
            // Sort the stones in descending order
            sort(stones.begin(), stones.end(), greater<int>());
            
            // Take the two heaviest stones
            int first = stones[0];
            int second = stones[1];
            
            // Remove them from the list
            stones.erase(stones.begin());
            stones.erase(stones.begin());
            
            // If they are not equal, insert the remainder back
            if (first != second) {
                stones.push_back(first - second);
            }
        }
        
        // If there's one stone left, return its weight, otherwise return 0
        return stones.empty() ? 0 : stones[0];
    }
};
```
