## P451 - Sort Characters By Frequency
### Delton Hughes
### Description:
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

### Input Examples: 
Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2: 
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

Constraints:
- 1 <= s.length <= 5 * 105
- s consists of uppercase and lowercase English letters and digits.


Solution: 
```
/**
 * @param {string} s
 * @return {string}
 */
function frequencySort(s) {
  let frequencyMap = {};
  for (let char of s) {
    if (frequencyMap[char]) { //if in the map increment
      frequencyMap[char]++;
    } else {
      frequencyMap[char] = 1; // otherwise make one (first seen)
    }
  }

  //get frequencyMap and sort in descending order based on its key value
  let sortedChars = Object.keys(frequencyMap).sort((a, b) => {
    return frequencyMap[b] - frequencyMap[a]; //comparison
  });

  let result = '';
  //repeat the character based on its key value
  for (let char of sortedChars) {
    
    result += char.repeat(frequencyMap[char]);
  }

  return result;
}


```
