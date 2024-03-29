////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Prashant Gandhi - All rights are reserved
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PRASHANT_MILKYWAY_BINARY_SEARCH_TREE_bINARY_TREE_NODE_H
#define PRASHANT_MILKYWAY_BINARY_SEARCH_TREE_bINARY_TREE_NODE_H

////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <type_traits>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Namespace(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Prashant
{
namespace Milkyway
{
namespace BinarySearchTree
{

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief Node class.
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename NType>
class BinaryTreeNode
{
public:
   static_assert((std::is_integral<NType>::value || std::is_floating_point<NType>::value),
                  "Only integral or floating point data types are allowed for BST");

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // @brief The parameterized constructor.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   explicit BinaryTreeNode(NType const cNodeValue)
      : mRightNode(nullptr)
      , mLeftNode(nullptr)
      , mNodeValue(cNodeValue)
   {
      // Intentionally left empty.
   }
   
   /////////////////////////////////////////////////////////////////////////////////////////////////
   // @brief Rule of five.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   ~BinaryTreeNode(void)
   {
      if (mRightNode != nullptr)
      {
         delete mRightNode;
      }

      if (mLeftNode != nullptr)
      {
         delete mLeftNode;
      }
   }

   BinaryTreeNode(void) = delete;

   BinaryTreeNode(BinaryTreeNode<NType> const&) = delete;
   BinaryTreeNode<NType>& operator=(BinaryTreeNode<NType> const&) = delete;

   BinaryTreeNode(BinaryTreeNode<NType>&&) noexcept = delete;
   BinaryTreeNode<NType>& operator=(BinaryTreeNode<NType>&&) noexcept = delete;

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // @brief Right and left node pointers.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   BinaryTreeNode<NType> *mRightNode;
   BinaryTreeNode<NType> *mLeftNode;

   /////////////////////////////////////////////////////////////////////////////////////////////////
   // @brief Node value.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   NType mNodeValue;
};

} // namespace BinarySearchTree
} // namespace Milkyway
} // namespace Prashant

#endif // PRASHANT_MILKYWAY_BINARY_SEARCH_TREE_bINARY_TREE_NODE_H
