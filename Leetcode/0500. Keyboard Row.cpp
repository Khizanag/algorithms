/* Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. */

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector< unordered_set<char> > K = {
			{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'},
			{'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'},
			{'Z', 'X', 'C', 'V', 'B', 'N', 'M'},
		};
		
		vector<string> v;
		for(string &word : words)
		{
			if(word.size() == 0)
				v.push_back(word);
			else {
				int index; 
				for(index = 0; index < 3; index++) 
					if(K[index].count(toupper(word[0]))) 
						break;
				for(int i = 1; i < word.size(); i++)
					if(K[index].count(toupper(word[i])) == 0)
						goto NOT_FOUND;
			}
			v.push_back(word);

			NOT_FOUND:
			continue;
		}
		
		return v;
	}
};