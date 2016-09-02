/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

/*
1 - 10
2 - 11 20
3 - 12 21 30
4 - 13 22 31 40
5 - 14 23 32 41 50
6 - 15 24 33 42 51 60
7 - 16 25 34 43 52 61 70
8 - 17 26 35 44 53 62 71 80
9 - 18 27 36 45 54 63 72 81 90
    19 28 37 46 55 64 73 82 91
       29 38 47 56 65 74 83 92
          39 48 57 66 75 84 93
             49 58 67 76 85 94
                59 68 77 86 95
                   69 78 87 96
                      79 88 97
                         89 98
                            99
*/ 
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        int ret = num % 9;
        if (ret == 0 ) ret = 9;
        return ret;
    }
};
