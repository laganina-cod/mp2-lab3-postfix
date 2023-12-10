#include "postfix.h"
#include <gtest.h>


TEST(ArithmeticExpression, can_create_expression)
{
  ASSERT_NO_THROW(ArithmeticExpression p());
}
TEST(ArithmeticExpression, can_create_postfix_string) {
	std::string str = { "5+7" };
	ArithmeticExpression p1(str);
	ASSERT_NO_THROW(ArithmeticExpression p2(str));
}
TEST(ArithmeticExpression, created_postfix_is_good) {
	std::string example{"5+7+3"};
	ArithmeticExpression p(example);
	
	EXPECT_EQ("57+3+", p.GetPostfix());
}

TEST(ArithmeticExpression, can_do_postfix1) {

	ArithmeticExpression p("5+(2*4)*8/8");
	EXPECT_EQ("524*8*8/+", p.GetPostfix());
}

TEST(ArithmeticExpression, can_do_postfix2) {

	ArithmeticExpression p("(9/3)*2+5");
	EXPECT_EQ("93/2*5+", p.GetPostfix());
}
TEST(ArithmeticExprssion, can_do_postfix3) {
	ArithmeticExpression p("5-2*(9/3)");
	EXPECT_EQ("5293/*-", p.GetPostfix());
}
TEST(ArithmeticExprssion, can_do_postfix4) {
	ArithmeticExpression p("5+2*(9+3)");
	EXPECT_EQ("5293+*+", p.GetPostfix());
}
TEST(ArithmeticExprssion, can_do_postfix5) {
	ArithmeticExpression p("5+2*(9/3+5+9)");
	EXPECT_EQ("5293/5+9+*+", p.GetPostfix());
}
TEST(ArithmeticExpression, can_do_postfix6) {
	ArithmeticExpression p("5+2*(9+5+9/3)");
	EXPECT_EQ("5295+93/+*+", p.GetPostfix());

}
TEST(ArithmeticExpression, can_do_postfix7) {
	ArithmeticExpression p("5+3*(5*(3-2))");
	EXPECT_EQ("53532-**+", p.GetPostfix());
}
TEST(ArithmeticExpression, can_calculate1) {
	ArithmeticExpression p("5+(2*4)*8/8");
	//map<char, int> op = { {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} };
	double a = p.Calculate();
	EXPECT_EQ(13,a );
}
TEST(ArithmeticExpression, can_calculate2) {
	ArithmeticExpression p("(9/3)*2+5");
	//map<char, int> op = { {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} };
	double a = p.Calculate();
	EXPECT_EQ(11, a);
}
TEST(ArithmeticExpression, can_calculate3) {
	ArithmeticExpression p("5-2*(9/3)");
	//map<char, int> op = { {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} };
	double a = p.Calculate();
	EXPECT_EQ(-1, a);
}
TEST(ArithmeticExpression, can_calculate4) {
	ArithmeticExpression p("5+2*(9+3)");
	//map<char, int> op = { {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} };
	double a = p.Calculate();
	EXPECT_EQ(29, a);
}
TEST(ArithmeticExpression, can_calculate5) {
	ArithmeticExpression p("5+2*(9/3+5+9)");
	//map<char, int> op = { {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} };
	double a = p.Calculate();
	EXPECT_EQ(39, a);
}
TEST(ArithmeticExpression, can_calculate6) {
	ArithmeticExpression p("5+2*(9/3+5+9)");
	//map<char, int> op = { {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} };
	double a = p.Calculate();
	EXPECT_EQ(39, a);
}
TEST(ArithmeticExpression, caan_calculate7) {
	ArithmeticExpression p("5+3*(5*(3-2))");
	//map<char, int> op = { {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9} };
	double a = p.Calculate();
	EXPECT_EQ(20, a);
}
TEST(ArithmeticExpression, icorrect_symbol_throw) {
	ASSERT_ANY_THROW(ArithmeticExpression p("abc"));

}