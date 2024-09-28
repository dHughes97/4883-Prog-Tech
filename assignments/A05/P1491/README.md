## P1491 - Average Salary Excluding the Minimum and Maximum Salary
### Delton Hughes
### Description:
You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

### Input Examples: 
Example 1: 
Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500

Example 2: 
Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000

Constraints:
- 3 <= salary.length <= 100
- 1000 <= salary[i] <= 106
- All the integers of salary are unique.


Solution: 
```
#include <climits>
#include <algorithm>

class Solution {
public:
    double average(vector<int>& salary) {
        int total = 0;
        int min_max_total = 0; 
        //Exclusion of min and max
        int min_salary = INT_MAX;
        int max_salary = INT_MIN;

        // read in the array, find sum, min, max
        for(int i = 0; i < salary.size(); i++){
            total += salary[i];
            min_salary = min(min_salary, salary[i]);   
            max_salary = max(max_salary, salary[i]);
        }

        
        // subtract the min and max from the total 
        min_max_total = min_salary + max_salary; 

        total = total - min_max_total;

        cout << total;
        return (double)total/(salary.size()-2);
    }
};
            
```
