/**
 * @brief  CS202 Node Class Implementation
 * @author Olliver Aikenhead
 *
 * A templated node implementation, using T for class Template name
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

template <typename T>
class NodeStack;

template <typename T>
class Node{
   friend class NodeStack<T>;

 public:
   Node() :
     m_next(NULL)
   {
   }

   Node(const T &data, Node<T>* next = nullptr) : 
     m_next(next),
     m_data(data)
   {
   }

   Node(const Node<T> &other) :
     m_next(other.m_next),
     m_data(other.m_data)
   {
   }

   T &data(){
     return m_data;
   }

   const T &data() const{
     return m_data;
   }

 private:
   Node<T>* m_next;
   T m_data;
};


#endif//NODE_H_
