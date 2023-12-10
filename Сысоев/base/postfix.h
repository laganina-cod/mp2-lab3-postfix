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
  ArithmeticExpression(const std::string& _infix);
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  vector<char> Getoperands() { return lexems; };
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
