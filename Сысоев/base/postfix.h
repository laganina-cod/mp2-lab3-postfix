#ifndef __POSTFIX_H__
#define __POSTFIX_H__
#pragma once
#include <string>
#include "stack.h"
#include <map>
#include<vector>
#include <exception>
using namespace std;

class ArithmeticExpression
{
  std::string infix;
  std::string postfix;
  vector<char> lexems;
  map<char, int> priorities;
  map <char, double> operands;
  void Parse();
  
public:
    void ToPostfix();
  ArithmeticExpression()
  {
      infix = { "a + b" };
     
      priorities = { {'*',1},{'/',1},{'+',2},{'-',2},{'&',3}};
    postfix = { "ab+" };
    Parse();
  }
  ArithmeticExpression(const std::string& _infix) {
     size_t in_size = _infix.size();
     infix = _infix;
     for (size_t i = 0; i < in_size; i++) {
         int a = (infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '0') || (infix[i] == '1') || (infix[i] == '2') || (infix[i] == '3') || (infix[i] == '4') || (infix[i] == '5') || (infix[i] == '6') || (infix[i] == '7') || (infix[i] == '8') || (infix[i] == '9') || (infix[i] == ')') || (infix[i] == '('));
        if (a == 0) {
             throw std::exception("incorrect symbol");
         }
    }
      priorities = { {'*',1},{'/',1},{'+',2},{'-',2},{'&',3} };
      ToPostfix();
      Parse();
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  vector<char> Getoperands() { return lexems; };
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
