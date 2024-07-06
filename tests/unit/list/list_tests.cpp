////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Prashant Gandhi - All rights are reserved
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "milky_way/list/list.h"

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
// Test Fixture
////////////////////////////////////////////////////////////////////////////////////////////////////
class ListTest : public testing::Test
{
   // Intentionally left empty.
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Tests for APIs:
///   * is_empty()
///   * size()
///   * front()
///   * back()
///   * push_back()
///   * push_front()
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest,
       Given_AListObjWithNoElement_When_IsEmptyIsCalled_Then_TrueIsReturned)
{
   // Given - A List object with no element,
   List<uint32_t> test_list{};

   // When - is_empty() is called,
   // Then - True is returned
   EXPECT_TRUE(test_list.is_empty());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest,
       Given_AListObjWithElements_When_IsEmptyIsCalled_Then_FalseIsReturned)
{
   // Given - A List object with no element,
   List<uint32_t> test_list{ 1U, 2U, 3U };

   // When - is_empty() is called,
   // Then - False is returned
   EXPECT_FALSE(test_list.is_empty());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest,
       Given_AListObjWithNoElement_When_SizeIsCalled_Then_ZeroIsReturned)
{
   // Given - A List object with no element,
   List<std::string> test_list{};

   // When - size() is called,
   // Then - Zero is returned
   EXPECT_EQ(test_list.size(), 0U);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest,
       Given_AListObjWithElements_When_SizeIsCalled_Then_ExpectedSizeIsReturned)
{
   // Given - A List object with no element,
   List<std::string> test_list{ std::string("First"), std::string("Sec"),
                                std::string("Third") };

   // When - size() is called,
   // Then - Expected size is returned
   EXPECT_EQ(test_list.size(), 3U);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_AListObj_When_AnElementIsPushedAtBack_Then_AnElementIsAddedAtCorrectLocation)
{
   // Given - A List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - An element is pushed at back,
   int const new_element{ 70 };
   test_list.push_back(new_element);
   auto const back_element = test_list.back();

   // Then - An Element is added at correct location.
   EXPECT_FALSE(test_list.is_empty());
   EXPECT_THAT(test_list.back(), Eq(new_element));
   EXPECT_EQ(test_list.size(), 4U);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_AListObj_When_AnElementIsPushedAtBeginning_Then_AnElementIsAddedAtCorrectLocation)
{
   // Given - A List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - An element is pushed at the beginning,
   int const new_element{ 70 };
   test_list.push_front(new_element);
   auto const back_element = test_list.back();

   // Then - An Element is added at correct location.
   EXPECT_FALSE(test_list.is_empty());
   EXPECT_THAT(test_list.front(), Eq(new_element));
   EXPECT_EQ(test_list.size(), 4U);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest,
       Given_ANonEmptyList_When_ExistingElementIsSearched_Then_TrueIsReturned)
{
   // Given - A non-empty List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - An existing element is searched,
   // Then - True is returned.
   EXPECT_TRUE(test_list.find(98));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_ANonEmptyList_When_NonExistingElementIsSearched_Then_TrueIsReturned)
{
   // Given - A non-empty List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - A non existing element is searched,
   // Then - False is returned.
   EXPECT_FALSE(test_list.find(100));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest,
       Given_ANonEmptyList_When_ClearIsCalled_Then_AllElementsShouldBeRemoved)
{
   // Given - A non-empty List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - clear() is called,
   test_list.clear();

   // Then - All elements should be removed.
   EXPECT_TRUE(test_list.is_empty());
   EXPECT_EQ(test_list.size(), 0U);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_ANonEmptyList_When_ExistingElementIsRemoved_Then_ElementShouldNotBePresentInList)
{
   // Given - A non-empty List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - An existing element is removed,
   // Then - An element should not be present in list.
   EXPECT_TRUE(test_list.remove(78));
   EXPECT_FALSE(test_list.find(78));
   EXPECT_EQ(test_list.size(), 2U);
   EXPECT_EQ(test_list.front(), 98);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Equality operator test(s)
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_ANonEmptyList_When_ListObjIsComparedWithItselfUsingEqualityOperator_Then_TrueIsReturned)
{
   // Given - A non-empty string,
   List<uint8_t> const test_list{ 4U, 7U, 9U, 78U };

   // When - List object is compared with itself using equality(==) operator,
   // Then - True is returned.
   EXPECT_TRUE((test_list == test_list));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_TwoNonEmptyList_When_ListObjIsComparedWithAnotherListContainingSameElementsEqualityOperator_Then_TrueIsReturned)
{
   // Given - Two non-empty string,
   List<uint8_t> const test_list_1{ 4U, 7U, 9U, 78U };
   List<uint8_t> const test_list_2{ 4U, 7U, 9U, 78U };

   // When - List object is compared with another list containing same elements
   // using equality(==)
   //        operator,
   // Then - True is returned.
   EXPECT_TRUE(test_list_1 == test_list_2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_TwoNonEmptyList_When_ListObjIsComparedWithAnotherListContainingDifferentElementsEqualityOperator_Then_FalseIsReturned)
{
   // Given - Two non-empty string,
   List<uint8_t> const test_list_1{ 4U, 7U, 9U, 78U };
   List<uint8_t> const test_list_2{ 4U, 7U, 9U, 75U };

   // When - List object is compared with another list containing different
   // elements using
   //        equality(==) operator,
   // Then - False is returned.
   EXPECT_FALSE(test_list_1 == test_list_2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Not equal to(!=) operator test(s)
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_ANonEmptyList_When_ListObjIsComparedWithItselfUsingInequalityOperator_Then_FalseIsReturned)
{
   // Given - A non-empty string,
   List<uint8_t> const test_list{ 4U, 7U, 9U, 78U };

   // When - List object is compared with itself using inequality(!=) operator,
   // Then - False is returned.
   EXPECT_FALSE((test_list != test_list));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_TwoNonEmptyList_When_ListObjIsComparedWithAnotherListContainingSameElementsInequalityOperator_Then_FalseIsReturned)
{
   // Given - Two non-empty string,
   List<uint8_t> const test_list_1{ 4U, 7U, 9U, 78U };
   List<uint8_t> const test_list_2{ 4U, 7U, 9U, 78U };

   // When - List object is compared with another list containing same elements
   // using inequality(!=)
   //        operator,
   // Then - False is returned.
   EXPECT_FALSE(test_list_1 != test_list_2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_TwoNonEmptyList_When_ListObjIsComparedWithAnotherListContainingDifferentElementsInequalityOperator_Then_TrueIsReturned)
{
   // Given - Two non-empty string,
   List<uint8_t> const test_list_1{ 4U, 7U, 9U, 78U };
   List<uint8_t> const test_list_2{ 4U, 7U, 9U, 75U };

   // When - List object is compared with another list containing different
   // elements using
   //        inequality(!=) operator,
   // Then - True is returned.
   EXPECT_TRUE(test_list_1 != test_list_2);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Special member functions - Copy Ctor and Copy Assignment tests
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_ANonEmptyList_When_CopyCtorIsUsedToCopyList_Then_CopiedListContainsSameData)
{
   // Given - A non-empty string,
   List<uint8_t> const test_list{ 4U, 7U, 9U, 78U };

   // When - Copy constructor is used to copy list,
   auto const copy_list = test_list;

   // Then - Copied list contains same elements.
   EXPECT_TRUE(copy_list == test_list);
   EXPECT_FALSE(copy_list.is_empty());
   EXPECT_THAT((copy_list.size() == test_list.size()),
               "Size is not equal; Copy failed");
   EXPECT_THAT((copy_list.front() == test_list.front()),
               "Front is not equal; Copy failed");
   EXPECT_THAT((copy_list.back() == test_list.back()),
               "Back is not equal; Copy failed");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_ANonEmptyList_When_CopyAssignmentIsUsedToCopyList_Then_CopiedListContainsSameData)
{
   // Given - A non-empty string,
   List<uint8_t> const test_list{ 4U, 7U, 9U, 78U };

   // When - Copy constructor is used to copy list,
   List<uint8_t> copy_list;
   copy_list = test_list;

   // Then - Copied list contains same elements.
   EXPECT_TRUE(copy_list == test_list);
   EXPECT_FALSE(copy_list.is_empty());
   EXPECT_THAT((copy_list.size() == test_list.size()),
               "Size is not equal; Copy failed");
   EXPECT_THAT((copy_list.front() == test_list.front()),
               "Front is not equal; Copy failed");
   EXPECT_THAT((copy_list.back() == test_list.back()),
               "Back is not equal; Copy failed");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Special member functions - Move Ctor and Move Assignment tests
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_ANonEmptyList_When_MoveCtorIsUsedToMoveList_Then_OriginalListIsMoved)
{
   // Given - A non-empty string,
   List<uint8_t> test_list{ 4U, 7U, 9U, 78U };
   auto const original_list_size  = test_list.size();
   auto const original_list_front = test_list.front();
   auto const original_list_back  = test_list.back();

   // When - Move constructor is used to move list,
   List<uint8_t> move_list(std::move(test_list));

   // Then - Original list is moved.
   EXPECT_TRUE(test_list.is_empty());
   EXPECT_THAT((move_list.size() == original_list_size), "Size mismatch");
   EXPECT_THAT((move_list.front() == original_list_front),
               "Front element mismatch");
   EXPECT_THAT((move_list.back() == original_list_back),
               "Back element mismatch");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(
   ListTest,
   Given_ANonEmptyList_When_MoveAssignmentIsUsedToMoveList_Then_OriginalListIsMoved)
{
   // Given - A non-empty string,
   List<uint8_t> test_list{ 4U, 7U, 9U, 78U };
   auto const original_list_size  = test_list.size();
   auto const original_list_front = test_list.front();
   auto const original_list_back  = test_list.back();

   // When - Move assignment is used to move list,
   List<uint8_t> move_list;
   move_list = std::move(test_list);

   // Then - Original list is moved.
   EXPECT_TRUE(test_list.is_empty());
   EXPECT_THAT((move_list.size() == original_list_size), "Size mismatch");
   EXPECT_THAT((move_list.front() == original_list_front),
               "Front element mismatch");
   EXPECT_THAT((move_list.back() == original_list_back),
               "Back element mismatch");
}

}  // namespace MilkyWay
}  // namespace Prashant
