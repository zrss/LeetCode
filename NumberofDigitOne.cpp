#include <cstdio>
#include <iostream>

using namespace std;

int naiveCountOne(int n) {
    int cnt = 0; // 1 count

    for (int i = 1; i <= n; ++i) {
        int tmp = i;
        while (tmp) {
            if ((tmp % 10) == 1) {
                ++cnt;
            }
            tmp /= 10;
        }
    }

    return cnt;
}

// 从低位到高位，将数划分为两半

// Case 1
// 如529
// 52 9
// 假设9取1，那么根据乘法原理
// [0 - 52]种出现1的情况

// 5 2 9
// [0 - 5] * [0 - 9]种出现1的情况

// 5 29
// [0 - 99]种出现1的情况

// 529 总计出现1的情况有
// 53 + 60 + 100 = 213

// Case 2
// 如516
// 假设6取1
// 52种情况

// 5 1 6
// 1本来就是1，所以需要特殊考虑一下
// [0 - 4] * 10, 高位为5时，只有[0 - 6]情况
// 所以有57种

// 5 16
// [0 - 99]
// 100种
// 52 + 57 + 100 = 209

// Case 3
// 506
// 51种
// [0 - 4] * [0 - 9] = 50种
// 100种
// 51 + 50 + 100 = 201

// Summary
// if (currentDigit == 0)
//     leftPart * pow
// if (currentDigit == 1)
//     leftPart * pow + (rightPart + 1)
// if (currentDigit > 1)
//     (leftPart + 1) * pow

long long int advanceCountOne(int n) {
    long long int cnt = 0; // 1 count
    long long int pow = 1;

    long long int tmp = n; // 遍历每一位
    while (tmp > 0) {
        long long int leftPart = n / (pow * 10);
        long long int digit = tmp % 10;

        if (digit > 1) {
            cnt += (leftPart + 1) * pow;
        }
        else if (digit == 1) {
            cnt += leftPart * pow + ((n % pow) + 1);
        }
        else {
            cnt += leftPart * pow;
        }

        pow *= 10;
        tmp /= 10;
    }
    
    return cnt;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%lld\n", advanceCountOne(1232131));

    return 0;
}