////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Prashant Gandhi - All rights are reserved
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "gtest/gtest.h"
#include "gmock/gmock.h"

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
TEST_F(ListTest, Given_AListObjWithNoElement_When_IsEmptyIsCalled_Then_TrueIsReturned)
{
   // Given - A List object with no element,
   List<uint32_t> test_list{};

   // When - is_empty() is called,
   // Then - True is returned
   EXPECT_TRUE(test_list.is_empty());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest, Given_AListObjWithElements_When_IsEmptyIsCalled_Then_FalseIsReturned)
{
   // Given - A List object with no element,
   List<uint32_t> test_list{ 1U, 2U, 3U };

   // When - is_empty() is called,
   // Then - False is returned
   EXPECT_FALSE(test_list.is_empty());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest, Given_AListObjWithNoElement_When_SizeIsCalled_Then_ZeroIsReturned)
{
   // Given - A List object with no element,
   List<std::string> test_list{};

   // When - size() is called,
   // Then - Zero is returned
   EXPECT_EQ(test_list.size(), 0U);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest, Given_AListObjWithElements_When_SizeIsCalled_Then_ExpectedSizeIsReturned)
{
   // Given - A List object with no element,
   List<std::string> test_list{ std::string("First"), std::string("Sec"), std::string("Third") };

   // When - size() is called,
   // Then - Expected size is returned
   EXPECT_EQ(test_list.size(), 3U);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest, Given_AListObj_When_AnElementIsPushedAtBack_Then_AnElementIsAddedAtCorrectLocation)
{
   // Given - A List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - An element is pushed at back,
   int const new_element{ 70 };
   test_list.push_back( new_element );
   auto const back_element = test_list.back();

   // Then - An Element is added at correct location.
   EXPECT_FALSE(test_list.is_empty());
   EXPECT_THAT(test_list.back(), Eq(new_element));
   EXPECT_EQ(test_list.size(), 4U);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest, Given_AListObj_When_AnElementIsPushedAtBeginning_Then_AnElementIsAddedAtCorrectLocation)
{
   // Given - A List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - An element is pushed at the beginning,
   int const new_element{ 70 };
   test_list.push_front( new_element );
   auto const back_element = test_list.back();

   // Then - An Element is added at correct location.
   EXPECT_FALSE(test_list.is_empty());
   EXPECT_THAT(test_list.front(), Eq(new_element));
   EXPECT_EQ(test_list.size(), 4U);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest, Given_ANonEmptyList_When_ExistingElementIsSearched_Then_TrueIsReturned)
{
   // Given - A non-empty List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - An existing element is searched,
   // Then - True is returned.
   EXPECT_TRUE(test_list.find(98));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest, Given_ANonEmptyList_When_NonExistingElementIsSearched_Then_TrueIsReturned)
{
   // Given - A non-empty List,
   List<int32_t> test_list{ 78, 98, 547 };

   // When - A non existing element is searched,
   // Then - False is returned.
   EXPECT_FALSE(test_list.find(100));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
TEST_F(ListTest, Given_ANonEmptyList_When_ClearIsCalled_Then_AllElementsShouldBeRemoved)
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
TEST_F(ListTest, Given_ANonEmptyList_When_ExistingElementIsRemoved_Then_ElementShouldNotBePresentInList)
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

} // namespace MilkyWay
} // namespace Prashant
