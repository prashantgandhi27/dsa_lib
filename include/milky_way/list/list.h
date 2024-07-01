////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2024 Prashant Gandhi - All rights are reserved
////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PRASHANT_MILKY_WAY_LIST_LIST_H
#define PRASHANT_MILKY_WAY_LIST_LIST_H

////////////////////////////////////////////////////////////////////////////////////////////////////
// Include(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <initializer_list>
#include <utility>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Namespace(s)
////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Prashant
{
namespace MilkyWay
{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief List class.
////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class List
{
public:
   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Default constructor.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   List() = default;

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Default constructor.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   explicit List(std::initializer_list<T> const &);

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Destructor.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   ~List();

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Pushes the element at the beginning of the list.
   ///
   /// @param[in] rc_element The element that needs to be inserted.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void push_back(T const &rc_element);

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Pushes the element at the end of the list.
   ///
   /// @param[in] rc_element The element that needs to be inserted.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void push_front(T const &rc_element);

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Inserts the provided list of elements.
   ///
   /// @param[in] rc_element The element that needs to be inserted.
   /// @param[in] c_pos      The position where provided element needs to be inserted.
   ///
   /// @note If provided position is greater than the list size, then the provided list of elements
   ///       are inserted at the end.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void insert(T const &rc_element, size_t const c_pos);

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Inserts the provided list of elements.
   ///
   /// @param[in] rc_element The element that needs to be inserted.
   /// @param[in] c_pos      The position where provided element needs to be inserted.
   /// @param[in] c_count    The number of time provided element needs to be inserted.
   ///
   /// @note If provided position is greater than the list size, then the provided list of elements
   ///       are inserted at the end.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void insert(T const &rc_element, size_t const c_pos, size_t const c_count);

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Inserts the provided list of elements.
   ///
   /// @param[in] rc_element_list The list of elements that needs to be inserted.
   /// @param[in] c_pos           The position where provided list of elements need to be inserted.
   ///
   /// @note If provided position is greater than the list size, then the provided list of elements
   ///       are inserted at the end.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void insert(std::initializer_list<T> const &rc_element_list, size_t const c_pos);

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Remove the provided element from the list.
   ///
   /// @param[in] rc_element The element that needs to be removed.
   ///
   /// @return True if element is removed successfully, otherwise false.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   bool remove(T const &rc_element);

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Destroys the list if it is non-empty.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void clear();

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Provides total elements present in the list.
   ///
   /// @return Number of elements present in the list.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   size_t size() const;

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Checks whether or not the list is empty.
   ///
   /// @return True if the list is empty, otherwise false.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   bool is_empty() const;

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Checks whether or not provided element is present in the list.
   ///
   /// @param[in] rc_element The element that needs to be searched.
   ///
   /// @return True if element is found in the list, otherwise false.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   bool find(T const &rc_element) const;

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Gets the first element in the list.
   ///
   /// @return Reference to the first element if list is non-empty, otherwise undefined behaviour.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   T const &front() const;

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @overload T const &front() const
   /////////////////////////////////////////////////////////////////////////////////////////////////
   T &front();

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Gets the last element in the list.
   ///
   /// @return Reference to the last element if list is non-empty, otherwise undefined behaviour.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   T const &back() const;

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @overload T const &back() const
   /////////////////////////////////////////////////////////////////////////////////////////////////
   T &back();

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Prints the list in forward direction.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void print() const;

   /////////////////////////////////////////////////////////////////////////////////////////////////
   /// @brief Prints the list in backward direction.
   /////////////////////////////////////////////////////////////////////////////////////////////////
   void print_reverse() const;

   List(List const &) = default;
   List &operator=(List const &) = default;
   List(List &&) noexcept = default;
   List &operator=(List &&) noexcept = default;
private:
   struct Node
   {
      Node(T const &rc_element)
          : m_node_data{std::move(rc_element)}
      {
         // Intentionally left empty.
      }
      T m_node_data{};
      Node *mp_next_node{nullptr};
      Node *mp_prev_node{nullptr};
   };

   void remove_head_nodes(T const &);
   void remove_tail_nodes(T const &);
   bool remove_middle_nodes(T const &);

   Node *mp_head{nullptr};
   Node *mp_tail{nullptr};
   size_t m_total_nodes{0U};
};

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
List<T>::List(std::initializer_list<T> const &rc_init_list)
{
   for (auto const &element : rc_init_list)
   {
      this->push_back(element);
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
List<T>::~List()
{
   this->clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool List<T>::is_empty() const
{
   return (0U == this->size());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
size_t List<T>::size() const
{
   return this->m_total_nodes;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::push_back(T const &rc_element)
{
   if (this->is_empty()) {
      this->mp_head = new List::Node(rc_element);
      this->mp_tail = this->mp_head;
   } else {
      this->mp_tail->mp_next_node = new List::Node(rc_element);
      this->mp_tail->mp_next_node->mp_prev_node = this->mp_tail;
      this->mp_tail = this->mp_tail->mp_next_node;
   }

   ++this->m_total_nodes;

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::push_front(T const &rc_element)
{
   if (this->is_empty()) {
      this->mp_head = new List::Node(rc_element);
      this->mp_tail = this->mp_head;
   } else {
      List::Node *temp = new List::Node(rc_element);
      temp->mp_next_node = this->mp_head;
      this->mp_head->mp_prev_node = temp;
      this->mp_head = this->mp_head->mp_prev_node;
   }

   ++this->m_total_nodes;

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool List<T>::find(T const &rc_element) const
{
   if (this->is_empty())
   {
      return false;
   }

   bool found{false};
   List::Node *current_node = this->mp_head;
   while (current_node != nullptr)
   {
      if (current_node->m_node_data == rc_element)
      {
         found = true;
      }
      current_node = current_node->mp_next_node;
   }

   return found;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T const &List<T>::front() const
{
   return this->mp_head->m_node_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T &List<T>::front()
{
   return this->mp_head->m_node_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T const &List<T>::back() const
{
   return this->mp_tail->m_node_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
T &List<T>::back()
{
   return this->mp_tail->m_node_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::clear()
{
   if (this->is_empty())
   {
      return;
   }

   List::Node *current_node = this->mp_head;
   while (current_node != nullptr)
   {
      List::Node *temp_node = current_node;
      current_node = current_node->mp_next_node;
      delete temp_node;
      --this->m_total_nodes;
   }

   this->mp_head = nullptr;
   this->mp_tail = nullptr;

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::insert(T const &rc_element, size_t const c_position)
{
   if (c_position > this->size())
   {
      this->push_back(rc_element);
      return;
   }
   else if (c_position == 0U)
   {
      this->push_front(rc_element);
      return;
   }

   List::Node *current_node = this->mp_head;
   for (size_t count{0U}; count < (c_position - 1U); ++count)
   {
      current_node = current_node->mp_next_node;
   }

   List::Node *new_node = new List::Node(rc_element);
   new_node->mp_next_node = current_node->mp_next_node;
   new_node->mp_prev_node = current_node;
   current_node->mp_next_node = new_node;
   current_node = new_node->mp_next_node;
   current_node->mp_prev_node = new_node;

   ++this->m_total_nodes;

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::insert(T const &rc_element, size_t const c_position, size_t const c_count)
{
   if (c_count == 0U)
   {
      return;
   }

   if (c_position > this->size())
   {
      for (size_t count{0U}; count < c_count; ++count)
      {
         this->push_back(rc_element);
      }
      return;
   }
   else if (c_position == 0U)
   {
      for (size_t count{0U}; count < c_count; ++count)
      {
         this->push_front(rc_element);
      }
      return;
   }

   List::Node *current_node = this->mp_head;
   for (size_t count{0U}; count < (c_position - 1U); ++count)
   {
      current_node = current_node->mp_next_node;
   }

   List::Node *new_node = new List::Node(rc_element);
   List::Node *temp_head = new_node;
   List::Node *temp_tail = new_node;
   for (size_t count{1U}; count < c_count; ++count)
   {
      new_node->mp_next_node = new List::Node(rc_element);
      temp_tail = new_node->mp_next_node;
      temp_tail->mp_prev_node = new_node;
      new_node = new_node->mp_next_node;
   }

   temp_tail->mp_next_node = current_node->mp_next_node;
   temp_head->mp_prev_node = current_node;
   current_node->mp_next_node = temp_head;
   current_node = temp_tail->mp_next_node;
   current_node->mp_prev_node = temp_tail;
   this->m_total_nodes += c_count;

   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::insert(std::initializer_list<T> const &rc_element_list, size_t const c_position)
{
   auto current_data_pos{c_position};
   for (auto const &data : rc_element_list)
   {
      this->insert(data, current_data_pos);
      ++current_data_pos;
   }
   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::remove_head_nodes(T const &rc_element)
{
   while ((this->mp_head != nullptr) && (rc_element == this->mp_head->m_node_data))
   {
      List::Node *temp_node = this->mp_head;
      this->mp_head = this->mp_head->mp_next_node;
      if (this->mp_head != nullptr)
      {
         this->mp_head->mp_prev_node = nullptr;
      }
      else
      {
         this->mp_tail = nullptr;
      }
      delete temp_node;
      --this->m_total_nodes;
   }
   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::remove_tail_nodes(T const &rc_element)
{
   while ((this->mp_tail != nullptr) && (rc_element == this->mp_tail->m_node_data))
   {
      List::Node *temp_node = this->mp_tail;
      this->mp_tail = this->mp_tail->mp_prev_node;
      this->mp_tail->mp_next_node = nullptr;
      delete temp_node;
      --this->m_total_nodes;
   }
   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool List<T>::remove_middle_nodes(T const &rc_element)
{
   bool node_deleted{false};
   List::Node *current_node = this->mp_head;
   while (current_node != nullptr)
   {
      if (rc_element == current_node->m_node_data)
      {
         List::Node *prev_node = current_node->mp_prev_node;
         List::Node *next_node = current_node->mp_next_node;
         List::Node *delete_node = current_node;
         prev_node->mp_next_node = current_node->mp_next_node;
         next_node->mp_prev_node = current_node->mp_prev_node;
         current_node = current_node->mp_next_node;
         delete delete_node;

         --this->m_total_nodes;
         node_deleted = true;
      }
      else
      {
         current_node = current_node->mp_next_node;
      }
   }
   return node_deleted;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool List<T>::remove(T const &rc_element)
{
   bool node_removed{false};
   if (this->is_empty())
   {
      return false;
   }
   if (this->size() == 1U)
   {
      if (rc_element == this->mp_head->m_node_data)
      {
         this->clear();
         node_removed = true;
      }
      else
      {
         // NTD.
      }
   }
   else
   {
      // Handle head node deletion.
      if (rc_element == this->mp_head->m_node_data)
      {
         remove_head_nodes(rc_element);
         node_removed = true;
      }
      // Handle tail node deletion.
      if (rc_element == this->mp_tail->m_node_data)
      {
         remove_tail_nodes(rc_element);
         node_removed = true;
      }

      // Handle middle node deletion.
      node_removed |= remove_middle_nodes(rc_element);
   }
   return node_removed;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::print() const
{
   if (this->is_empty())
   {
      std::cout << "Empty list" << std::endl;
      return;
   }
   List::Node const *temp = this->mp_head;
   while (temp != nullptr)
   {
      std::cout << temp->m_node_data << " ";
      temp = temp->mp_next_node;
   }
   std::cout << std::endl;
   return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void List<T>::print_reverse() const
{
   if (this->is_empty())
   {
      std::cout << "Empty list" << std::endl;
      return;
   }
   List::Node const *temp = this->mp_tail;
   while (temp != nullptr)
   {
      std::cout << temp->m_node_data << " ";
      temp = temp->mp_prev_node;
   }
   std::cout << std::endl;
   return;
}

} // namespace MilkyWay
} // namespace Prashant

#endif // PRASHANT_MILKY_WAY_LIST_LIST_H
