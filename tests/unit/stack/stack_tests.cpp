////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Prashant Gandhi - All rights are reserved
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "milky_way/stack/stack.h"

#include <cstdint>
#include <string>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Namespace(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Prashant
{
namespace MilkyWay
{

using ::testing::Eq;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Test Fixture
////////////////////////////////////////////////////////////////////////////////////////////////////
class StackTest : public testing::Test
{
   // Intentionally left empty.
};

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(StackTest, Given_AnEmptyContainer_When_IsEmptyIsCalled_Then_TrueIsReturned)
{
   // Given - An empty container,
   Stack<int32_t> stack{};

   // When - is_empty() is called,
   // Then - True is returned.
   EXPECT_TRUE(stack.is_empty());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(StackTest, Given_ANonEmptyContainer_When_IsEmptyIsCalled_Then_FalseIsReturned)
{
   // Given - A non-empty container,
   Stack<int32_t> stack{ 45, 75824, 58745, 544 };

   // When - is_empty() is called,
   // Then - False is returned.
   EXPECT_FALSE(stack.is_empty());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(StackTest, Given_ANonEmptyContainer_When_SizeIsCalled_Then_NumberOfElementsAreReturned)
{
   // Given - A non-empty container,
   Stack<std::string> stack{ "This", "is", "test", "string" };

   // When - size() is called,
   // Then - Number of elements are returned.
   EXPECT_THAT(stack.size(), Eq(4U));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(StackTest, Given_AContainer_When_NewElementIsPushed_Then_NumberOfElementsShouldBeUpdated)
{
   // Given - A container,
   Stack<uint32_t> stack{ 1U, 78U, 98U, 100U };

   // When - New element is pushed,
   stack.push(uint32_t{ 700U });

   // Then - Number of elements should be updated.
   EXPECT_THAT(stack.size(), Eq(5U));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(StackTest, Given_AContainer_When_TopIsCalled_Then_LastPushedElementShouldBeReturned)
{
   // Given - A container,
   Stack<uint8_t> stack{ 'p', 'w', 'q' };

   // When - top() is called,
   uint8_t const top_element{ 'c' };
   stack.push(top_element);

   // Then - Last pushed element should be returned.
   EXPECT_THAT(stack.top(), Eq(top_element));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(StackTest, Given_AContainer_When_PopIsCalled_Then_LastPushedElementShouldBeRemoved)
{
   // Given - A container,
   Stack<int8_t> stack{ 1, -2, 4, -8 };

   // When - pop() is called,
   stack.pop();

   // Then - Last pushed element should be removed.
   EXPECT_EQ(stack.top(), int8_t{ 4 });
}

}  // namespace MilkyWay
}  // namespace Prashant
