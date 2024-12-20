## P335 - Self Crossing
### Delton Hughes
### Description:
You are given an array of integers distance.

You start at the point (0, 0) on an X-Y plane, and you move distance[0] meters to the north, then distance[1] meters to the west, distance[2] meters to the south, distance[3] meters to the east, and so on. In other words, after each move, your direction changes counter-clockwise.

Return true if your path crosses itself or false if it does not.

### Input Examples: 
Example 1:
<br>
<img src="/profile_images/example1.png" width="200" />
<br>
    Input: distance = [2,1,1,2]
    Output: true
    Explanation: The path crosses itself at the point (0, 1).   
<br> 
Example 2: 
<br>
<img src="/profile_images/example2.png" width="200" />
<br>
    Input: distance = [1,2,3,4]
    Output: false
    Explanation: The path does not cross itself at any point.
<br>
Example 3: 
<br>
<img src="/profile_images/example3.png" width="200" />
<br>
    Input: distance = [1,1,1,2,1]
    Output: true
    Explanation: The path crosses itself at the point (0, 0).
<br>
Constraints:
- 1 <= distance.length <= 105
- 1 <= distance[i] <= 105


Solution: 
```
function isSelfCrossing(distance) {
    const n = distance.length;
    
    for (let i = 3; i < n; i++) {
        // Case 1: Fourth line crosses the first line (lines are in segments)
        if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
            return true;
        }

        // Case 2: Fifth line meets the first line (lines are in segments)
        if (
            i >= 4 &&
            distance[i - 1] === distance[i - 3] &&
            distance[i] + distance[i - 4] >= distance[i - 2]
        ) {
            return true;
        }

        // Case 3: Sixth line crosses the first line (lines are in segments)
        if (
            i >= 5 &&
            distance[i - 2] >= distance[i - 4] &&
            distance[i] + distance[i - 4] >= distance[i - 2] &&
            distance[i - 1] <= distance[i - 3] &&
            distance[i - 1] + distance[i - 5] >= distance[i - 3]
        ) {
            return true;
        }
    }

    return false;
}

```
