#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>

#include <initializer_list>

template <typename T>
class List;

template <typename T>
struct ListNode {
  T         value = T{};
  ListNode* prev = nullptr;
  ListNode* next = nullptr;
};


//TODO: Implementierung der Methoden des Iterators 
//      (nach Vorlesung STL-1 am 09. Juni) (Aufgabe 3.12)
template <typename T>
struct ListIterator {
  using Self              = ListIterator<T>;
  using value_type        = T;
  using pointer           = T*;
  using reference         = T&;
  using difference_type   = ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;

  ListIterator(ListNode<T>* node):
  node{node}
  {}

  /* DESCRIPTION  operator*() */
  T&  operator*()  const {
    if(nullptr == node) {
      throw "Iterator does not point to valid node";
    }

    //TODO: remaining implementation of derefenciation of 
    //      iterator using operator* (Aufgabe 3.12 - Teil 1)

  } //call *it

  /* DESCRIPTION  operator->() */
  T* operator->() const {
    if(nullptr == node) {
      throw "Iterator does not point to valid node";
    }

    //TODO: remaining implementation of derefenciation of 
    //      iterator using operator-> (Aufgabe 3.12 - Teil 2)
  }  //call it->method() or it->member


  /* PREINCREMENT, call: ++it, advances one element forward */
  ListIterator<T>& operator++() {
    if(nullptr == node) {
      throw "Iterator does not point to valid node";
    }

    //TODO: Implement Postincrement-Operation for Iterator
    //      (Aufgabe 3.12 - Teil 3)
    
  }

  /* POSTINCREMENT (signature distinguishes the iterators), 
                    call:  it++, advances one element forward*/
  ListIterator<T> operator++(int) {
    if(nullptr == node) {
      throw "Iterator does not point to valid node";
    }

    //TODO: Implement Postincrement-Operation for Iterator
    //      (Aufgabe 3.12 - Teil 4)

  }


  /* ... */
  bool operator==(ListIterator<T> const& x) const {
    //TODO: Implement Equality-Operation for Iterator
    //      (Aufgabe 3.12 - Teil 5)
    // Iterators should be the same if they refer to the same node
    return false;
  } // call it: == it

  /* ... */
  bool operator!=(ListIterator<T> const& x) const {
    //TODO: Implement Inequality-Operation for Iterator  
    //      (Aufgabe 3.12 - Teil 6)
    // Reuse operator==
    return false;
  } // call it: != it

  /* Advances Iterator */
  ListIterator<T> next() const {
    if (nullptr != node) {
      return ListIterator{node->next};
    } else {
      return ListIterator{nullptr};
    }
  }


  ListNode <T>* node = nullptr;
};



template <typename T>
class List {
  public:

    //friend declarations for testing the members   
    template <typename TEST_TYPE>
    friend size_t get_size(List<TEST_TYPE> const& list_to_test);
    template <typename TEST_TYPE>
    friend ListNode<TEST_TYPE>* get_first_pointer(List<TEST_TYPE> const& list_to_test);
    template <typename TEST_TYPE>
    friend ListNode<TEST_TYPE>* get_last_pointer(List<TEST_TYPE> const& list_to_test);

    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    // TODO: do not forget about the initialiser list! (Aufgabe 3.2)
    /* ... */
    List(): 
      size_{0},
      first_{nullptr},
      last_{nullptr}
    {}

    // test and implement:
    //TODO: Copy-Konstruktor using Deep-Copy semantics (Aufgabe 3.5)

    List(List <T> const& list):
    size_{0},
    first_{nullptr},
    last_{nullptr}
    {
      auto tmp_node= list.first_;

      while (tmp_node->next != nullptr){
        push_back(tmp_node);
        tmp_node = tmp_node->next;
      }
    }


  List(List<T>&& list):
     size_(list.size()),
     first_(list.first_),
     last_(list.last_)
   {
     list.size = 0;
     list.first_ = nullptr;
     list.last_ = nullptr;
   }

    //TODO: Initializer-List Konstruktor (3.10 - Teil 1)
    /* ... */
    // test and implement:
    List(std::initializer_list<T> ini_list) {
      //not implemented yet
    }

    /* ... */
    // test and implement:
    //TODO: (unifying) Assignment operator (Aufgabe 3.6)
    List& operator=(List rhs)
      { 
        (rhs);
        return *this;
      }

    /* ... */
    // test and implement:

    bool operator==(List const& rhs) const
    {
      //TODO: operator== (Aufgabe 3.8)
      if (size_ == rhs.size_)
      {
        auto rhs_node = rhs.first_;
        auto node     = first_;
        
        while(node.next != nullptr)
        {
          if (rhs_node.value == node.value)
          {
            rhs_node  = rhs_node.next;
            node.next = node.next;    
          } 
          else
          {
           return false;
          }
        }
      } 
      else
      {
        return false;
      }
      
    }

    bool operator!=(List const& rhs) const
    {
      //TODO: operator!= (Aufgabe 3.8)
      // make use of operator==
      if (this == rhs)
      {
        return false;
      }
      else
      {
        return true;
      }
      
    }

    /* ... */
    ~List() {
      //TODO: Implement via clear-Method (Aufgabe 3.4)
      // clear();
    } //can not really be tested

    /* ... */
    ListIterator<T> begin() const
    {
      //TODO: begin-Method returning an Iterator to the 
      //      first element in the List (Aufgabe 3.11)
      return ListIterator<T>(first_);
    }

    /* ... */
    ListIterator<T> end() const
    {
      //TODO: end-Method returning an Iterator to element after (!) 
      //      the last element in the List (Aufgabe 3.11)
      return ListIterator<T>(last_);
    }

    /* ... */ 
    // test and implement:
    //TODO: clear()-Method (Aufgabe 3.4)
    void clear(){
      if(empty())
      {
        throw "List is already empty";
      } 
      else
      {
        // (*first_).next.next != nullptr ??
        while ((*first_).next != nullptr)
        {
          pop_front();
        }
      }

    }

    /* ... */
    //TODO: member function insert (Aufgabe 3.13)

    /* ... */
    //TODO: member function insert (Aufgabe 3.14)

    /* ... */

    //TODO: member function reverse (Aufgabe 3.7 - Teil 1)
    // Question: auto oder explizite Liste initialisieren?
    void reverse()
    {
      // auto node = first_;
      // auto tmp_node = nullptr;
      ListNode<T>* node     = first_;
      ListNode<T>* tmp_node = nullptr;

      while(node != nullptr){
       tmp_node = node -> next;
       node -> next = node -> prev;
       node -> rpev = tmp_node;

       if (tmp_node == nullptr)
       {
         last_  = first_;
         first_ = node;
       } 
      node = tmp_node;
      }
    }


    /* ... */
    void push_front(T const& element) {
      // TODO: push_front-method (Aufgabe 3.3)
      ListNode <T>* node = new ListNode <T> {element, nullptr, nullptr};
      if (!empty())
      {
        // 
        first_ -> prev = node;
        node -> next = first_;
      } 
      else 
      {
        last_ = node;
      }

      first_ = node;
      ++size_;
    }

    /* ... */
    void push_back(T const& element) {
      ListNode <T>* node = new ListNode <T> {element, nullptr, nullptr};
      // TODO: push_back-method (Aufgabe 3.3)
      if (!empty()){
        last_ -> next = node;
        node  -> prev = last_;
      }
      else 
      {
        first_ = node;
      }

      last_ = node;
      ++size_;
    }

    /* ... */
    void pop_front() {
      // TODO delete hinzufügen
      if(empty()) {
        throw "List is empty";
      } 
      else
      {
        if(size() == 1)
        {
          first_ = last_ = nullptr;
          --size_;
          //  Ist sowas sinnvoll? 
          // delete this;
        } 
        else if(size() > 1) 
        {
          first_ = (*first_).next;
          (*first_).prev = nullptr;
          --size_;
          // delete this;
        }
      }
      // TODO: remainder of pop_front-method (Aufgabe 3.3)
    }

    /* ... */
    void pop_back() {
      // TODO delete hinzufügen
      if(empty()) {
        throw "List is empty";
      } else 
        { 
          if (size() == 1)
            {
             first_ = last_ = nullptr;
             --size_; 
              // delete this;
            } 
            else if(size() > 1) 
            {
              last_ = (*last_).prev;
              (*last_).next = nullptr;  
              --size_;
              // delete this;
            } 
      }
    }

    /* ... */
    T& front() {
      if(empty()) {
        throw "List is empty";
      }

      // TODO: remainder of front-method (Aufgabe 3.3)
    }

    /* ... */
    T& back() {
      if(empty()) {
        throw "List is empty";
      }

      // TODO: remainder of back-method (Aufgabe 3.3)
    }

    /* ... */
    bool empty() const {

      // TODO: empty-method (Aufgabe 3.2)
      if (size_ == 0)
      {
        return true;
      } else {
        return false;
      }
    };


    std::size_t size() const{
      // TODO: size-method (Aufgabe 3.2)      
      return size_;
    };


  // list members
  private: 
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
  };

/* ... */
//TODO: Freie Funktion reverse 
//(Aufgabe 3.7 - Teil 2, benutzt Member-Funktion reverse)
template <typename T> List<T> reverse (List<T> const& list)
{
  List<T> rev_list(list);
  rev_list.reverse();
  return rev_list;
}

/* ... */
//TODO: Freie Funktion operator+ (3.10 - Teil 2)


#endif // # define BUW_LIST_HPP
