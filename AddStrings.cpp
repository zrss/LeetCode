// 简单的模拟

class Solution {
public:
    string addStrings(string num1, string num2) {
    	int l1 = num1.length();
    	int l2 = num2.length();

    	if (l1 == 0)
    		return num2;

    	if (l2 == 0)
    		return num1;

    	stringstream ss;

    	int c1 = l1 - 1;
    	int c2 = l2 - 1;
    	int in = 0;
    	while (c1 >= 0 && c2 >= 0) {
    		int n1 = num1[c1] - '0';
    		int n2 = num2[c2] - '0';
    		int r = n1 + n2 + in;
    		ss << (r % 10);
    		in = r / 10;
    		--c1;
    		--c2;
    	}

    	while (c1 >= 0) {
    		int n1 = num1[c1] - '0';
    		int r = n1 + in;
    		ss << (r % 10);
    		in = r / 10;
    		--c1;
    	}

    	while (c2 >= 0) {
    		int n2 = num2[c2] - '0';
    		int r = n2 + in;
    		ss << (r % 10);
    		in = r / 10;
    		--c2;
    	}

    	if (in > 0)
    		ss << in;

    	string rel = ss.str();
    	reverse(rel.begin(), rel.end());
    	return rel;
    }
};