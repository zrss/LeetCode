class Solution {
public:
	bool validUtf8(vector<int>& data) {
		int len = data.size();
		unsigned int testZero[] = {0x80, 0x20, 0x10, 0x08};
		unsigned int testOnes[] = {0x00, 0xC0, 0xE0, 0xF0};

		bool testFirstByte = true;
		int remainByte = 0;

		for (int i = 0; i < len; ++i) {
			if (testFirstByte) {
				bool match = false;
				for (int j = 0; !match && j < 4; ++j) {
					if ((testZero[j] & data[i]) == 0 && (testOnes[j] & data[i]) == testOnes[j]) {
						remainByte = j;
						match = true;
					}
				}
				if (!match)
					return false;
				testFirstByte = false;
			}
			else {
				bool match = true;
				int j = 0;
				for (; match && i < len && j < remainByte; ++j, ++i) {
					if (!((data[i] & 0xF0) != 0 && (data[i] & 0x40) == 0)) {
						match = false;
					}
				}

				if (!match || j != remainByte)
					return false;

				--i;

				testFirstByte = true;
				remainByte = 0;
			}
		}

		return remainByte == 0;
	}
};

int main() {
	vector<int> data = {235, 140, 4};
	cout << Solution().validUtf8(data) << endl;
	return 0;
}