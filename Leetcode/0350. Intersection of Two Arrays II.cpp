/* Given two arrays, write a function to compute their intersection. */

class Solution {
public:
	vector<int> intersect(vector<int>& A, vector<int>& B) {
		unordered_map<int, int> FA, FB; // frequencies
		for(int i : A) FA[i] += 1;
		for(int i : B) FB[i] += 1;
		
		vector<int> v;
		for(auto pr : FA)
		{
			if(FB.count(pr.first))
			{
				for(int i = 0; i < min(pr.second, FB[pr.first]); i+=1)
					v.push_back(pr.first);
			}
		}
		
		return v;
	}
};