/*

 Time Complexity: 
      O(NLogN) -->sort product (N defines as # of products)
      O(M*N) --> iterate search word prefix (M), for each prefix, search product (N)
Space Complexity : O (1)

Sort algorithm sort string by lexicographically order, therefore, string with similar prefix will be placed next to each other.  We iterate the prefix word from searchWord, for each prefix word, we seek the first three products with matched prefix. 

 **/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        for(int index = 1; index<=searchWord.length(); index++)
        {
            vector<string> suggestion;
            for(int i=0; i<products.size(); i++)
            {
                string product = products[i];
                if(product.substr(0, index) == searchWord.substr(0,index))
                    suggestion.push_back(product);
                if(suggestion.size() == 3)
                    break;
            }
            res.push_back(suggestion);
        }
        return res;        
    }
};
