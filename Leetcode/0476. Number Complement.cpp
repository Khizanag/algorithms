/* Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation. */

class Solution {
public:
	int findComplement(int num) {
		unsigned mask = ~0;
		while((mask & num) != 0) mask <<= 1;
		return ~mask & ~num;
	}
};