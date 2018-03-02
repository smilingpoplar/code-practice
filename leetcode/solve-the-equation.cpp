//
//  solve-the-equation
//  https://leetcode.com/problems/solve-the-equation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        const int N = equation.size();
        int coef = 0, vari = 0;
        int sign = 1;
        int flag = 1; // '='左边系数为正、'='右边系数为负
        for (int i = 0; i < N; ) {
            char c = equation[i];
            if (c == '+') {
                sign = 1;
                i++;
            } else if (c == '-') {
                sign = -1;
                i++;
            } else if (c == '=') {
                flag = -1;
                sign = 1;
                i++;
            } else if (c == 'x') { // 无系数的x
                coef += flag * sign;
                i++;
            } else { // digit
                int start = i;
                while (i < N && isdigit(equation[i])) i++;
                int num = flag * sign * stoi(equation.substr(start, i - start));
                if (i < N && equation[i] == 'x') {
                    coef += num;
                    i++;
                } else {
                    vari += num;                    
                }
            }
        }
        
        if (coef == 0) {
            if (vari == 0) return "Infinite solutions";
            else return "No solution";
        } else {
            return "x=" + to_string(-vari / coef);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
