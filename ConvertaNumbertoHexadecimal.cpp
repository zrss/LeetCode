class Solution {
public:
	string toHex(int num) {
	    if (num == 0)
	        return "0";
	        
		stack<int> digits;
		unsigned int unum = num;
		while (unum) {
			digits.push(unum & 15);
			unum >>= 4;
		}

		stringstream ss;
		while (!digits.empty()) {
			int digit = digits.top();
			digits.pop();
			if (digit > 9) {
				char ch = (char)(digit + 87);
				ss << ch;
			}
			else {
				ss << digit;
			}
		}

		return ss.str();
	}
};