/*
https://leetcode.com/discuss/interview-question/460127/
You work on a team whose job is to understand the most sought after toys for the holiday season. A teammate of yours has built a webcrawler that extracts a list of quotes about toys from different articles. You need to take these quotes and identify which toys are mentioned most frequently. Write an algorithm that identifies the top N toys out of a list of quotes and list of toys.
Your algorithm should output the top N toys mentioned most frequently in the quotes.

The input to the function/method consists of five arguments:
numToys, an integer representing the number of toys
topToys, an integer representing the number of top toys your algorithm needs to return;
toys, a list of strings representing the toys,
numQuotes, an integer representing the number of quotes about toys;
quotes, a list of strings that consists of space-sperated words representing articles about toys



思路: 典型的TopK, 每次用一張hashmap 統計每個單詞在sentence裡面出現的次數 已經出現了只算一次. 最後把單詞與出現頻率丟到heap, 選出top K
考點: corner case的處理, heap的應用

*/


using namespace std;
void printres(vector<string>& strs);

struct sortByFreq
{
	bool  operator ()(const pair<string, int>& lhs, const pair<string, int>& rhs)
	{
		return lhs.second < rhs.second;
	}
};

typedef priority_queue < pair<string, int>, vector<pair<string, int>>, sortByFreq>  MaxHeap;

class Solution
{
public:
	vector<string> topBuzzWord(int numToys, int topToys, vector<string> toys, int numQuotes, vector<string> quotes)
	{
		vector<string> resToys;
		if (topToys == 0 || numQuotes == 0)
			return resToys;

		unordered_map<string, int> toyset;   //key: toy_name, value :  number of occurance
		for (auto toy : toys)
		{
			transform(toy.begin(), toy.end(), toy.begin(), ::tolower);
			toyset[toy] = 0;
		}

		for (auto quote : quotes)
		{
			auto words = splitstr(quote);
			unordered_set<string> seen; //record keyword seen in 'this quote"
			for (auto word : words)
			{
				word = preproc(word);
				if (seen.count(word) == 1) continue;
				if (toyset.count(word) == 0) continue;
				toyset[word]++;
			}
		}

		MaxHeap maxhp;

		for (auto toy : toyset)
			maxhp.push(toy);


		while (topToys > 0 && !maxhp.empty())
		{
			resToys.push_back(maxhp.top().first); maxhp.pop();
			topToys--;
		}

		return resToys;
	}

    //Split string to word by " "
	vector<string> splitstr(string str)
	{
		std::istringstream ss(str);
		string token;
		vector<string> res;
		while (std::getline(ss, token, ' ')) {
			res.push_back(token);
		}
		return res;
	}

	string preproc(string& str)
	{
		transform(str.begin(), str.end(), str.begin(), ::tolower); // To Lower Case by C++ STL
		string res;

		for (auto c :str)
		{
			if (!isalpha(c) || c == ',') break;
			res += c;
		}
		return res;
	}
};
