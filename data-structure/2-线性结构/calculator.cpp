#include <iostream>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

// 运算符优先级
int precedence(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  if (op == '^') return 3;
  return 0;
}

// 中缀表达式转后缀表达式
string intoPostExp(string exp) {
  string res;
  stack<char> op;

  // 清除多余空格
  exp.erase(remove(begin(exp), end(exp), ' '), end(exp));

  for (int i = 0; i < exp.size(); i++) {
    if (exp[i] == '(') { // 左括号：入栈
      op.push(exp[i]);
    } else if (exp[i] == ')') { // 右括号：出栈并拼接，直到遇到左括号
      while (op.top() != '(') {
        res.push_back(op.top());
        op.pop();
      }
      op.pop(); // 左括号出栈不拼接
    } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') { // 运算符
      // 优先级小于等于栈顶运算符时，出栈并拼接，直到该运算符优先级大于栈顶运算符才入栈
      while (!op.empty() && precedence(exp[i]) <= precedence(op.top())) {
        res.push_back(op.top());
        op.pop();
      }
      op.push(exp[i]);
    } else { // 运算数：直接拼接
      res.push_back(exp[i]);
    }
  }

  // 处理完毕后，将栈中存留的运算符一并出栈并拼接
  while (!op.empty()) {
    res.push_back(op.top());
    op.pop();
  }

  return res;
}

// 后缀表达式求值
int calculatePostExp(string postExp) {
  stack<int> nums;

  for (int i = 0; i < postExp.size(); i++) {
    // 获取运算数
    int num = postExp[i] - '0';

    // 运算数入栈
    if (num >= 0 && num <= 9) nums.push(num);
    else {
      int rth = nums.top();
      nums.pop();
      int lth = nums.top();
      nums.pop();

      // 根据运算符计算，并将结果入栈
      if (postExp[i] == '+') {
        nums.push(lth + rth);
      }
      if (postExp[i] == '-') {
        nums.push(lth - rth);
      }
      if (postExp[i] == '*') {
        nums.push(lth * rth);
      }
      if (postExp[i] == '/') {
        nums.push(lth / rth);
      }
      if (postExp[i] == '^') {
        nums.push(pow(lth, rth));
      }
    }
  }

  // 返回结果
  return nums.top();
}

int main() {
  cout << "calculate: " << endl;
  string exp;
  getline(cin, exp);

  string postExp = intoPostExp(exp);
  cout << postExp << endl;

  int res = calculatePostExp(postExp);
  cout << res << endl;
}
