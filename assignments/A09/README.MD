## 587 - Erect the Fence
### Delton Hughes
### Description:
You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.

Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.

Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.


### Input Examples: 
Example 1:
Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.

Example 2:
Input: trees = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
Explanation: The fence forms a line that passes through all the trees.

Constraints:
- 1 <= trees.length <= 3000
- trees[i].length == 2
- 0 <= xi, yi <= 100
- All the given positions are unique.


Solution: 
```
/**
 * @param {number[][]} trees
 * @return {number[][]}
 */
function outerTrees(trees) {
    if (trees.length <= 1) return trees;

    // sort the x and y coordinates 
    trees.sort((a, b) => a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]);

    //determine clockwise, counterclockwise, or colinear
    const orientation = (p, q, r) => {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    };

    const hull = [];

    // lower hull
    for (const point of trees) {
        while (hull.length >= 2 && orientation(hull[hull.length - 2], hull[hull.length - 1], point) < 0) {
            hull.pop();
        }
        hull.push(point);
    }

    // upper hull
    const t = hull.length + 1;
    for (let i = trees.length - 1; i >= 0; i--) {
        const point = trees[i];
        while (hull.length >= t && orientation(hull[hull.length - 2], hull[hull.length - 1], point) < 0) {
            hull.pop();
        }
        hull.push(point);
    }

    // get rid of duplicate 
    const uniquePoints = new Set(hull.map(JSON.stringify));
    return Array.from(uniquePoints).map(JSON.parse);
}

```
