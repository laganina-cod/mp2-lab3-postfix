#pragma once
#include "postfix.h"
#include "stack.h"

#include<map>
void ArithmeticExpression::Parse() {
	for (char c : infix) {
		lexems.push_back(c);
	}
}
ArithmeticExpression::ArithmeticExpression(const std::string& _infix) {
	size_t in_size = _infix.size();
	infix = _infix;
	for (size_t i = 0; i < in_size; i++) {
		bool a = (infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '0') || (infix[i] == '1') || (infix[i] == '2') || (infix[i] == '3') || (infix[i] == '4') || (infix[i] == '5') || (infix[i] == '6') || (infix[i] == '7') || (infix[i] == '8') || (infix[i] == '9') || (infix[i] == ')') || (infix[i] == '(');
		if (a == 0) {
			throw std::exception("incorrect symbol");
		}
	}
	priorities = { {'*',1},{'/',1},{'+',2},{'-',2},{'&',3} };
	ToPostfix();
	Parse();
}
	void ArithmeticExpression::ToPostfix()
	{
		Parse();
		TStack<char> st1;
		char stackItem = '&';
		for (char item : lexems) {
			switch (item) {
			case'(':
				st1.push(item);
				stackItem = '&';
				break;
			case')':


				while (st1.top() != '(') {
					postfix += st1.top();
					st1.cltop();

				}
				st1.cltop();
				if (st1.isEmpty() != 1) {
					if (st1.top() != '(') {
						stackItem = st1.top();
					}
					else { stackItem = '&'; }
				}
				else {
					stackItem = '&';
				}
				break;
			case'+':case'-':case'*':case'/':
				while ((priorities[item] >= priorities[stackItem]) && (stackItem != '&')) {

					postfix += st1.top();
					st1.cltop();
					if (st1.isEmpty() != 1) {
						if (st1.top() != '(') { stackItem = st1.top(); }
						else { stackItem = '&'; }
					}
					else { stackItem = '&'; }
				}
				st1.push(item);
				stackItem = item;
				break;
			default:
				postfix += item;
				break;
			}

		}
		while (!st1.isEmpty()) {
			postfix.push_back(st1.top());
			st1.cltop();
		}
	}

double ArithmeticExpression::Calculate()
{
	int size_p = postfix.size();
	TStack<double> st2;
	for (int i = 0; i < size_p;i++) {
		char oper=postfix[i];
		switch (oper) {
		 case'+':case'-':case'*':case'/':
			 double a, b;
			 a = st2.top();
			 st2.cltop();
			 b = st2.top();
			 st2.cltop();
			 if (oper == '+') {
				 b = b+ a;
				 st2.push(b);
			 }
			 if (oper == '-') {
				 b = b - a;
				 st2.push(b);
			 }
			 if (oper == '/') {
				 b = b/ a;
				 st2.push(b);
			 }
			 if (oper == '*') {
				 b = b * a;
				 st2.push(b);
			 }
		     break;
		 default:
			 if (oper == '0') { st2.push(0); }
			 if (oper == '1') { st2.push(1); }
			 if (oper == '2') { st2.push(2); }
			 if (oper == '3') { st2.push(3); }
			 if (oper == '4') { st2.push(4); }
			 if (oper == '5') { st2.push(5); }
			 if (oper == '6') { st2.push(6); }
			 if (oper == '7') { st2.push(7); }
			 if (oper == '8') { st2.push(8); }
			 if (oper == '9') { st2.push(9); }
			 break;
		}
  }
	return st2.top();
} 
