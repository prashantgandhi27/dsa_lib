////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Prashant Gandhi - All rights are reserved
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include "milky_way/binary_search_tree/binary_search_tree.h"

#include <iostream>

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
// @brief Binary Search Tree class implementation.
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
BinarySearchTree<ElementType>::BinarySearchTree(void)
   : mRoot(nullptr)
{
   // Intentionally left empty.
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
BinarySearchTree<ElementType>::~BinarySearchTree(void)
{
   // TODO: destroyTree() call.
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
BinaryTreeNode<ElementType>*
BinarySearchTree<ElementType>::createNode(ElementType const cValue) const
{
   return new BinaryTreeNode<ElementType>(cValue);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
bool BinarySearchTree<ElementType>::insertNode(BinaryTreeNode<ElementType>* &prNode,
                                               ElementType const cValue)
{
   if (nullptr == prNode)
   {
      prNode = createNode(cValue);
      return true;
   }

   if (cValue == prNode->mNodeValue)
   {
      // Duplication is not allowed.
      return false;
   }

   return (cValue > prNode->mNodeValue)
          ? insertNode(prNode->mRightNode, cValue)
          : insertNode(prNode->mLeftNode, cValue);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
void BinarySearchTree<ElementType>::preOrderTraversal(BinaryTreeNode<ElementType>* &r_node) const
{
   if (nullptr != r_node)
   {
      std:cout << r_node->mNodeValue << " ";
      preOrderTraversal(r_node->mLeftNode);
      preOrderTraversal(r_node->mRightNode);
   }

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
void BinarySearchTree<ElementType>::inOrderTraversal(BinaryTreeNode<ElementType>* &r_node) const
{
   if (nullptr != r_node)
   {
      preOrderTraversal(r_node->mLeftNode);
      std:cout << r_node->mNodeValue << " ";
      preOrderTraversal(r_node->mRightNode);
   }

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
void BinarySearchTree<ElementType>::postOrderTraversal(BinaryTreeNode<ElementType>* &r_node) const
{
   if (nullptr != r_node)
   {
      preOrderTraversal(r_node->mLeftNode);
      preOrderTraversal(r_node->mRightNode);
      std:cout << r_node->mNodeValue << " ";
   }

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
void BinarySearchTree<ElementType>::traversal(Binary_search_tree_traversal_t const cTraversalAlgorithm) const
{
   switch (cTraversalAlgorithm)
   {
   case Binary_search_tree_traversal_t::PRE_ORDER_TRAVERSAL:
   {
      preOrderTraversal(mRoot);
      break;
   }

   case Binary_search_tree_traversal_t::IN_ORDER_TRAVERSAL:
   {
      inOrderTraversal(mRoot);
      break;
   }
   
   case Binary_search_tree_traversal_t::POST_ORDER_TRAVERSAL:
   {
      postOrderTraversal(mRoot);
      break;
   }
   
   default:
      preOrderTraversal(mRoot);
      break;
   }

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
bool BinarySearchTree<ElementType>::insertElement(ElementType const cValue)
{
   return insertNode(mRoot, cValue);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
bool BinarySearchTree<ElementType>::removeElement(ElementType const cValue) const
{
   (void)(cValue);
   return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
bool BinarySearchTree<ElementType>::searchElement(ElementType const cValue) const
{
   (void)(cValue);
   return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
uint32_t BinarySearchTree<ElementType>::treeHeight(void) const
{
   return 0U;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
uint32_t BinarySearchTree<ElementType>::totalNodes(void) const
{
   return 0U;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename ElementType>
uint32_t BinarySearchTree<ElementType>::totalLeaves(void) const
{
   return 0U;
}

} // namespace BinarySearchTree
} // namespace Milkyway
} // namespace Prashant
