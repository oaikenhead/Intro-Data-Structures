/**
 * @brief  CS-202 NodeList class Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the NodeList class for CS-202.
 */

#include <NodeList/NodeList.h>

// (i) friend fcn
std::ostream & operator<<(std::ostream & os, const NodeList & nodeList){
  int size = nodeList.size();
  for(int i=0; i<size; i++){ os << nodeList[i]; }
  os << std::endl;
  return os;
}

// (1) default ctor
NodeList::NodeList(){
  m_head = NULL;
  std::cout << "NodeList: Default-Ctor" << std::endl; // debug message
}

// (2) param ctor
NodeList::NodeList(size_t count, const DataType & value){
  if(count <= 0){ m_head = NULL; }
  else{
    m_head = new Node(value);
    Node * head = m_head;

    while(--count > 0){
      head -> m_next = new Node(value);
      head = head -> m_next;
    }
    head -> m_next = NULL;
  }
  std::cout << "NodeList: Param-Ctor" << std::endl; // debug message
}

// (3) copy ctor
NodeList::NodeList(const NodeList & other){
  *this = other;
  std::cout << "NodeList: Copy-Ctor" << std::endl;  // debug message
}

// (4) dtor
NodeList::~NodeList(){
  clear();
  std::cout << "NodeList: Dtor" << std::endl; // debug message
}

// (5) operator=
NodeList & NodeList::operator=(const NodeList & rhs){
  std::cout << "NodeList: Assignment" << std::endl; // debug message 

  if(this == &rhs){ return *this; }

  Node * ptr = rhs.m_head;
  if(ptr){
    m_head = new Node(*rhs.m_head);
    Node * temp_var = m_head;
    ptr = ptr -> m_next;

    while(ptr){
      temp_var -> m_next = new Node(*ptr);
      temp_var = temp_var -> m_next;
      ptr = ptr -> m_next;
    }
  }
  return *this;
}

// (6) front
Node * NodeList::front(){ return m_head; }

// (7) back
Node * NodeList::back(){
  Node * temp_head = m_head;

  while(temp_head -> m_next != NULL){
    temp_head = temp_head -> m_next;
  }
  return temp_head;
}

// (8) find
Node * NodeList::find(const DataType & target, Node * & previous, const Node * start){
  if(empty()){ return NULL; }

  Node * begin;

  if(start){
    begin = (Node*) start;
  }
  else{
    begin = m_head;
  }

  while(begin && !(begin -> data() == target)){
    previous = begin;
    begin = begin -> m_next;
  }
  return begin;
}

// (9) insert after
Node * NodeList::insertAfter(const DataType & target, const DataType & value){
  Node * prev_state;
  Node * head_ptr = find(target, prev_state);

  if(head_ptr == NULL){ return NULL; }

  else{
    prev_state = new Node(value);
    prev_state -> m_next = head_ptr -> m_next;
    head_ptr -> m_next = prev_state;

    return prev_state;
  }
}

// (10) insert before
Node * NodeList::insertBefore(const DataType & target, const DataType & value){
  Node * prev_state;
  Node * head_ptr = find(target, prev_state);

  if(!head_ptr){ return NULL; }

  else if(head_ptr == m_head){
    m_head = new Node(value);
    m_head -> m_next = head_ptr;
    return m_head;
  }
  else{
    prev_state -> m_next = new Node(value);
    prev_state -> m_next -> m_next = head_ptr;
    return prev_state -> m_next;
  }
}

// (11) erase
Node * NodeList::erase(const DataType & target){
  Node * previous_state;
  Node * node_ptr = find(target, previous_state);

  if(!node_ptr){ return NULL; }

  else{
    previous_state -> m_next = node_ptr -> m_next;
    node_ptr -> m_next = NULL;
    delete node_ptr;
    return previous_state -> m_next;
  }
}

// (12a) operator []
DataType & NodeList::operator[](size_t position){
  Node * node_ptr = m_head;

  while(position-- && node_ptr){
    node_ptr = node_ptr -> m_next;
  }
  return node_ptr -> m_data;
}

// (12b) const operator []
const DataType & NodeList::operator[](size_t position) const{
  Node * node_ptr = m_head;

  while(position-- && node_ptr){
    node_ptr = node_ptr -> m_next;
  }
  return node_ptr -> m_data;
}

// (13) size
size_t NodeList::size() const{
  size_t count = 0;
  Node * node_ptr = m_head;

  while(node_ptr){
    node_ptr = node_ptr -> m_next;
    count++;
  }
  return count;
}

// (14) empty
bool NodeList::empty() const{ return !m_head; }

// (15) clear
void NodeList::clear(){
  if(empty()){ return; }

  Node * node_ptr = m_head;

  while(node_ptr){
    node_ptr = m_head -> m_next;
    delete m_head;
    m_head = node_ptr;
  }
}
