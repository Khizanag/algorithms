/* Given a string, sort it in decreasing order based on the frequency of characters */

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> F;
		for(char c : s)
			F[c]++;
		map<int, vector<char>> DB;
		for(auto &pr : F)
			DB[pr.second].push_back(pr.first);
		string rs = "";
		for(auto &pr : DB)
			for(char c : pr.second)
				for(int i = 0; i < pr.first; i++)
					rs += c;
		reverse(rs.begin(), rs.end());
		return rs;
	}
};