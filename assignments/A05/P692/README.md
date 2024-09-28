## P692 - Top K Frequent Words
### Delton Hughes
### Description:
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

### Input Examples: 
Example 1: 
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2: 
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

Constraints:
- 1 <= words.length <= 500
- 1 <= words[i].length <= 10
- words[i] consists of lowercase English letters.
- k is in the range [1, The number of unique words[i]]


Solution: 
```
class Solution {
public:
     vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> m;
        vector<pair<int, string>> v;
        pair <int, string> p;
        vector<string> res;
        
        sort(words.begin(), words.end());
        
        for(int i=0; i<words.size(); i++)
        {
            if(m.find(words[i]) == m.end())
            {
                m[words[i]] = 1;
            }
            else
            {
                m[words[i]] += 1;
            }
        }
        
        for(int i=words.size()-1; i>=0; i--)
        {
            // cout << words[i] << " ";
            if(m[words[i]] != -1)
            {
                p = make_pair(m[words[i]], words[i]);
                v.push_back(p);
                m[words[i]] = -1;
            }
        }
        
        sort(v.begin(), v.end());
        vector<string> tmp;
        for(int i=v.size()-1; i>=0; i--)
        {
            if(tmp.size() == 0)
            {
                tmp.push_back(v[i].second);
            }
            else
            {
                if(v[i+1].first == v[i].first)
                {
                    tmp.push_back(v[i].second);
                }
                else
                {
                    sort(tmp.begin(), tmp.end());
                    for(int j=0; j<tmp.size(); j++)
                    {
                        res.push_back(tmp[j]);
                    }
                    tmp.clear();
                    tmp.push_back(v[i].second);
                }
            }
            if(k == 0) break;
        }
        
        if(tmp.size() != 0)
        {
            sort(tmp.begin(), tmp.end());
            for(int j=0; j<tmp.size(); j++)
            {
                res.push_back(tmp[j]);
            }
        }
        
        int size = res.size();
        for(int i=0; i<(size-k); i++) res.pop_back();
        
        return res;
    }
};
            
```
