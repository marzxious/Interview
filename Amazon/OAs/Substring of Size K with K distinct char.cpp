/*
Given a string s and an int k, return all unique substrings of s of size k with k distinct characters.

Example 1:
Input: s = "abcabc", k = 3
Output: ["abc", "bca", "cab"]
Example 2:
Input: s = "abacab", k = 3
Output: ["bac", "cab"]
Example 3:
Input: s = "awaglknagawunagwkwagl", k = 4
Output: ["wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag"]
Explanation: 
Substrings in order are: "wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag", "wagl" 
"wagl" is repeated twice, but is included in the output once.

Solution

Time Complexity : O(N)
Space Complexity : O(k)

The algorithm employs sliding window methodology, while the sliding window moves, we constantly check # of occurrence of each character by a hashmap with key = character and value = occurrence.  Size of hashmap tells us # of distinct character in the current window. 

Two pointer l & r are used to record the location of current sliding window, when window size == k, and counter.size() == k, current substring is valid. 
When window size > k , we slide the left boundary until window size == k, each time we move left boundary, we update the hashmap counter of it's occurrence. If occurrence = 0, we erase this character from hashmap.  
To prevent duplicate word, we use a hashset to store substring result.

*/

class Solution {
public:

	vector<string> KDistinct(string str, int k)
	{
		unordered_map<char, int>  counter;
		unordered_set<string>  uniquestr;
		int l = 0;

		vector<string> res;

		for (int r = 0; r < str.length(); r++)
		{
			char c = str[r];
			counter[c]++;
			while (r-l+1 > k)
			{
				counter[str[l]]--;
				if (counter[str[l]] == 0) counter.erase(str[l]);
				l++;
			}

			if (counter.size() == k)
				uniquestr.insert(str.substr(l, r - l + 1));
		}

		for (auto str : uniquestr)
			res.push_back(str);

		return  res;
	}
};
