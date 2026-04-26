#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long calcul(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> operands; // 피연산자
    vector<char> operators; // 연산자
    string temp_num = "";
    
    for (char c : expression) {
        if (isdigit(c)) {
            temp_num += c;
        }
        else {
            operands.push_back(stoll(temp_num)); // string to long long
            operators.push_back(c);
            temp_num = "";
        }
    }
    
    if(temp_num != "") {
        operands.push_back(stoll(temp_num));
    }
    
    vector<vector<char>> all_prios = {
        {'*', '+', '-'},
        {'*', '-', '+'},
        {'+', '*', '-'},
        {'+', '-', '*'},
        {'-', '*', '+'},
        {'-', '+', '*'}
    };
    
    long long res = 0;
    long long max_res = 0;
    
    for (vector<char> prio : all_prios) {
        vector<long long> tmp_operands = operands;
        vector<char> tmp_operators = operators;
        
        for (char op : prio) {
            int i = 0;
            while (i < tmp_operators.size()) {
                if (tmp_operators[i] == op) {
                    res = calcul(tmp_operands[i], tmp_operands[i+1], op);
                    tmp_operands[i] = res;
                    
                    tmp_operands.erase(tmp_operands.begin() + i+1);
                    tmp_operators.erase(tmp_operators.begin() + i);
                }
                else {
                    i++;
                }
            }
        }
        max_res = max(max_res, abs(tmp_operands[0]));
    }
    
    answer = max_res;
    return answer;
}