#include "pch.h"
#include "../queue/stack.h"


TEST(Stack, Empty_stack) {
	Stack<int> stack;
	EXPECT_TRUE( stack.empty() );
	EXPECT_EQ( stack.size(), 0 );
}
TEST( Stack, pushing_to_stack ) {
	Stack<int> stack;
	stack.push( 3 );
	EXPECT_EQ( stack.size(), 1 );
	EXPECT_FALSE( stack.empty() );
	EXPECT_EQ( stack.top(), 3 );

	stack.push( 5 );
	EXPECT_EQ( stack.size(), 2 );
	EXPECT_FALSE( stack.empty() );
	EXPECT_EQ( stack.top(), 5 );
}

TEST( Stack, emplacing_to_stack ) {
	Stack<int> stack;
	stack.emplace( 3 );
	EXPECT_EQ( stack.size(), 1 );
	EXPECT_FALSE( stack.empty() );
	EXPECT_EQ( stack.top(), 3 );

	stack.emplace( 5 );
	EXPECT_EQ( stack.size(), 2 );
	EXPECT_FALSE( stack.empty() );
	EXPECT_EQ( stack.top(), 5 );
}

TEST( Stack, popping_from_stack ) {
	Stack<int> stack;
	stack.pop();
	EXPECT_EQ( stack.size(), 0 );
	EXPECT_TRUE( stack.empty() );
	stack.push( 3 );
	stack.pop();
	stack.pop();
	stack.pop();
	EXPECT_EQ( stack.size(), 0 );
	EXPECT_TRUE( stack.empty() );
}

TEST( Stack, top ) {
	Stack<int> stack;
	EXPECT_EQ( stack.size(), 0 );
	EXPECT_TRUE( stack.empty() );
	try { auto x = stack.top(); }
	catch ( const std::logic_error& exc ) {
		EXPECT_STREQ( exc.what(), "Calling top on empty stack!" );
	}
	stack.emplace( 10 );
	stack.emplace( 20 );
	stack.emplace( 30 );
	EXPECT_EQ( stack.top(), 30 );
	stack.pop();
	EXPECT_EQ( stack.top(), 20 );
	stack.pop();
	EXPECT_EQ( stack.top(), 10 );
	stack.pop();
	EXPECT_EQ( stack.size(), 0 );

}

TEST( Stack, swap ) {
	Stack<int> stack1 {1, 2, 3};
	Stack<int> stack2 {4, 5, 6, 7};
	stack1.swap( stack2 );
	EXPECT_EQ( stack1.size(), 4 );
	EXPECT_EQ( stack2.size(), 3 );

	EXPECT_EQ( stack1.top(), 7 );
	stack1.pop();
	EXPECT_EQ( stack1.top(), 6 );
	stack1.pop();
	EXPECT_EQ( stack1.top(), 5 );
	stack1.pop();
	EXPECT_EQ( stack1.top(), 4 );
	stack1.pop();

	EXPECT_EQ( stack2.top(), 3 );
	stack2.pop();
	EXPECT_EQ( stack2.top(), 2 );
	stack2.pop();
	EXPECT_EQ( stack2.top(), 1 );
	stack2.pop();

	EXPECT_TRUE( stack1.empty() );
	EXPECT_TRUE( stack2.empty() );





}

