#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
      int rel = 0;
      for (int i = 2; i < n; ++i) {
        int up = sqrt(i);
        bool prime = true;
        for (int j = 2; prime && j <= up; ++j) {
          if (!(i % j))
            prime = false;
        }
        if (prime) {
          ++rel;
        }
      }
      return rel;
    }
};

int main(int argc, char const *argv[])
{
  Solution solution;
  cout << solution.countPrimes(20) << endl;
  return 0;
}
