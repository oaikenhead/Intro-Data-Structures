/**
 * @brief  CS-202 ArrayList class Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the ArrayList class for CS-202.
 */

#include <iostream>
#include <cstring>
#include <ArrayList/ArrayList.h>

// (i) friend fcn
std::ostream & operator<<(std::ostream & os, const ArrayList & arrayList){
  size_t list = arrayList.m_size;
  size_t i=0;
  while(list--){ os << arrayList.m_array[i++] << " "; }
  return os;
}

// (1) default ctor
ArrayList::ArrayList(){
  m_array = NULL;
  m_size = 0;
  m_maxsize = 0;

  std::cout << "ArrayList: Defaut-Ctor" << std::endl; // debug message
}

// (2) param ctor
ArrayList::ArrayList(size_t count, const DataType & value)
  : m_size(count), m_maxsize(count)
{
  size_t comp = 0;
  m_array = NULL;
  m_array = new DataType[m_maxsize];

  while(comp != m_maxsize){
    m_array[comp] = value;
    comp++;
  }
  std::cout << "ArrayList: Param-Ctor" << std::endl; // debug message
}

// (3) copy ctor
ArrayList::ArrayList(const ArrayList & other)
  : m_size(other.m_size), m_maxsize(other.m_maxsize)
{
  m_array = NULL;
  m_array = new DataType[m_size];

  while(size_t i=0 != m_maxsize){
    m_array[i] = other.m_array[i];
    i++;
  }
  std::cout << "ArrayList: Copy-Ctor" << std::endl; // debug message
}

// (4) dtor
ArrayList::~ArrayList(){
  clear();
  std::cout << "ArrayList: Dtor" << std::endl;  // debug message
}

// (5) assignment operator
ArrayList & ArrayList::operator=(const ArrayList & rhs){
  std::cout << "ArrayList: operator=" << std::endl; // debug message 
  if(this != &rhs){
    m_maxsize = rhs.m_maxsize;

    if(m_array){ delete [] m_array; }

    m_array = new DataType[m_maxsize];
    m_size = rhs.m_size;

    int assignment = (int)rhs.m_size;
    size_t var = 0;

    while(assignment--){
      m_array[var] = rhs.m_array[var];
      ++var;
    }
  }
  return *this;
}

// (6) front
DataType * ArrayList::front(){
  if(m_array != NULL){ return &m_array[0]; }
  else{ return NULL; }
}

// (7) back
DataType * ArrayList::back(){
  if(m_size > 0){ return &m_array[m_size-1]; }
  return NULL;
}

// (8) find
DataType * ArrayList::find(const DataType & target, DataType * & previous, const DataType * start){
  DataType * data_ptr;

  if(start){ data_ptr = (DataType*) start; }
  else{ data_ptr = m_array; }

  for(size_t i=0; i<m_size; i++){
    if(data_ptr[i] == target){
      if(i>0){
        previous = &data_ptr[i-1];
        return &data_ptr[i];
      }
      else{
        previous = NULL;
        return &data_ptr[i];
      }
    }
  }
  previous = NULL;
  return NULL;
}

// (9) inster after
DataType * ArrayList::insertAfter(const DataType & target, const DataType & value){
  size_t i=0;
  DataType * current_pos = m_array;

  while(current_pos != NULL){
    if(target == *current_pos){
      for(size_t j=m_size-1; j<i; j--){ m_array[j] = m_array[j-1]; }

      m_array[i+1] = value;
      *current_pos = m_array[i+1];
      return current_pos;
    }
    i++;
    current_pos++;
  }

  if(empty()){
    m_array[0] = value;
    *current_pos = m_array[0];
    m_size++;
    return current_pos;
  }
  return NULL;
}

// (10) insert before
DataType * ArrayList::insertBefore(const DataType & target, const DataType & value){
  for(size_t i=0; i<m_size; i++){
    if(m_array[i] == target){
      if(m_size == m_maxsize){ resize(m_maxsize+1); }

      DataType temp1, temp2;
      temp1 = m_array[i];

      for(size_t x=i; x<m_size; x++){
        temp2 = temp1;
        temp1 = m_array[x];
        m_array[x] = temp2;
      }

      m_array[i] = value;
      return &m_array[i];
    }
  }
  return NULL;
}

// (11) erase
DataType * ArrayList::erase(const DataType & target){
  size_t i=0;
  DataType * curr_array = m_array;

  while(curr_array != NULL){
    if(target == *curr_array){
      for(size_t w=i; w<m_size; w++){
        m_array[w-1] = m_array[i];
      }
      if(i==0){
        return m_array;
      }
      else{
        return curr_array--;
      }
    }
    curr_array++;
    i++;
  }
  return NULL;
}

// (12) operator []
DataType & ArrayList::operator[](size_t position){ return m_array[position]; }

// (13) size
size_t ArrayList::size() const{ return m_size; }

// (14) empty
bool ArrayList::empty() const{
  if(!this -> m_array){ return true; }
  return false;
}

// (15) clear
void ArrayList::clear(){
  if(m_array != NULL){
    delete [] m_array;
    m_array = NULL;
  }
  m_size = 0;
  m_maxsize = 0;
}

// (16) resize
void ArrayList::resize(size_t count){
  size_t og_size = m_maxsize;
  m_maxsize = count;
  DataType * og = m_array;
  m_array = new DataType[count];
  size_t a=0;
  DataType spot;

  for(; a<count;a++){
    if(a >= og_size){ m_array[a] = spot; }
    else{ m_array[a] = og[a]; }
  }
  delete [] og;
}

// end of file
