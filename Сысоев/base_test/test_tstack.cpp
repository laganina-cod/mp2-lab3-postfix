#include "stack.h"
#include <gtest.h>
TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> st());
}

TEST(TStack, can_create_stzck_with_positive_size)
{
	ASSERT_NO_THROW(
		TStack<int> st(6));

}

TEST(TStack, throws_when_create_stack_with_negative_lengh)
{
	ASSERT_ANY_THROW(TStack<int> st(-1));
	ASSERT_ANY_THROW(TStack<int> st(0));
}

TEST(TStack, can_get_size)
{
	TStack<int> st(5);
	EXPECT_EQ(5, st.size());
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> st(5);

	ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, can_push_element_when_is_not_full)
{
	TStack<int> st(5);
	ASSERT_NO_THROW(st.push(1));
	ASSERT_NO_THROW(st.push(2));

}

TEST(TStack, can_top_when_isnot_empty)
{
	TStack<int> st(5);
	st.push(1);
	st.push(2);
	EXPECT_EQ(2, st.top());
}

TEST(TStack, can_cltop_when_isnot_empty)
{
	TStack<int> st(5);
	st.push(1);
	st.push(2);
	st.cltop();
	EXPECT_EQ(1, st.top());
}

TEST(TStack, is_empty_is_correct)
{
	TStack<int> st(5);
	EXPECT_EQ(1, st.isEmpty());
	st.push(1);
	st.cltop();
	EXPECT_EQ(1, st.isEmpty());
}

TEST(TStack, can_not_top_element_when_is_empty)
{
	TStack<int> st(5);
	ASSERT_ANY_THROW(st.top());

}

TEST(TStack, can_not_cltop_when_is_empty)
{
	TStack<int> st(5);
	ASSERT_ANY_THROW(st.top());
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> st(5);
	st.push(1);
	st.push(2);
	TStack<int> st1(st);
	EXPECT_EQ(2, st1.top());
	st1.cltop();
	EXPECT_EQ(1, st1.top());
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> st(5);
	TStack<int> st1(st);
	st.push(3);
	ASSERT_ANY_THROW(st1.top());
}

TEST(TStack, is_full_is_correct)
{
	TStack<int> st(4);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	EXPECT_EQ(1, st.isFull());
}

TEST(TStack, can_push_element_when_is_full)
{
	TStack<int> st(4);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(9);
	st.push(5);
	EXPECT_EQ(5, st.top());
}

TEST(TStack, resized_stack_is_equal_to_source_one)
{
	TStack<int> st(4);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.cltop();
	EXPECT_EQ(4, st.top());
	st.cltop();
	EXPECT_EQ(3, st.top());
}

TEST(TStack, can_assign_stack)
{
	TStack<int> st(4);
	TStack<int> st1(5);
	ASSERT_NO_THROW(st1 = st);
}
TEST(TStack, assigned_stack_is_equal_to_source_one)
{
	TStack<int> st(4);
	TStack<int> st1(5);
	st.push(2);
	st.push(3);
	st.push(4);
	st1 = st;
	EXPECT_EQ(4, st1.top());
	st1.cltop();
	EXPECT_EQ(3, st1.top());
}