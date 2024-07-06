////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Prashant Gandhi - All rights are reserved
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <array>
#include <cstdint>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "milky_way/list/list.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Namespace(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Prashant
{
namespace MilkyWay
{

using ::testing::Eq;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Test Fixture
////////////////////////////////////////////////////////////////////////////////////////////////////
class ListIteratorTest : public testing::Test
{
protected:
   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Setup function.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void SetUp() override
   {
         for (auto const& element : list_elemets) {
            test_list.push_back(element);
         }
   }

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief TearDown function.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void TearDown() override { test_list.clear(); }

   std::array<uint32_t, 5U> const list_elemets{23U, 87U, 226U, 89347U, 1244U};
   List<uint32_t> test_list{};
};

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListIteratorTest,
   Given_AListIterator_When_BeginIsCalled_Then_IteratorPointingToFirstElementIsReturned)
{
   // Given - A List iterator,
   std::string const first_element = "TEST";
   List<std::string> test_list{first_element, "LIST"};

   // When - Begin() is called,
   auto const it = test_list.begin();

   // Then - An iterator pointing to first element in list is returned.
   EXPECT_EQ(*it, first_element);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListIteratorTest,
   Given_AListIterator_When_ElementsAreCountedUsingForLoop_Then_CountedElementsShouldBeEqualToListSize)
{
   // Given - A List iterator,
   // When - Elements are counted using for loop,
   size_t count{0U};
      for (auto it = test_list.begin(); it != test_list.end(); ++it) {
         ++count;
      }

   // Then - Counted elements should be equal to list size.
   EXPECT_EQ(count, test_list.size());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListIteratorTest,
   Given_AListIterator_When_PostIncrementIsCalled_Then_CorrectResultsAreReturned)
{
   // Given - A List iterator,
   auto it = test_list.begin();
   size_t idx{0U};

      // When - Post-increment is called,
      // Then - Correct results are returned.
      for (auto it = test_list.begin(); it != test_list.end(); it++) {
         EXPECT_EQ(*it, list_elemets[idx]);
         ++idx;
      }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListIteratorTest,
   Given_AListIterator_When_RangBasedForLoopIsCalled_Then_LoopWorksAsExpected)
{
   // Given - A List iterator,
   auto it = test_list.begin();

   // When - Range based for loop is called,
   size_t idx{0U};
      for (auto const& element : test_list) {
         // Then - Loop works as expected.
         EXPECT_EQ(element, list_elemets[idx]);
         ++idx;
      }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListIteratorTest,
   Given_AListIterator_When_IteratorIsUsedToModifyListContent_Then_ListIsUpdated)
{
   // Given - A List iterator,
   auto it = test_list.begin();

   // When - An iterator is used to modify list content,
   uint32_t const updated_value{70U};
   *it = updated_value;

   // Then - List is updated.
   EXPECT_THAT(test_list.front(), Eq(updated_value));
}

}  // namespace MilkyWay
}  // namespace Prashant
