// my string source file

#include <iostream>
#include <cstring>
#include <MyString/MyString.h>

// (1) default ctor definition
MyString::MyString(){
  m_size = 0;
  m_buffer = 0;
  buffer_allocate( 0 );
}

// (2) param ctor definition
MyString::MyString(const char * str){
  size_t size = strlen( str );

  try{
    buffer_allocate( size );
    strcpy( m_buffer, str );
  }
  catch(const std::bad_alloc & exc){
    std::cerr << exc.what() << std::endl;
    buffer_deallocate();
  }
}

// (3) copy ctor definition
MyString::MyString(const MyString & other_myStr){
  try{
    buffer_allocate( other_myStr.size() );
    for(size_t i=0; i<other_myStr.size(); i++){
      (*this)[i] = other_myStr[i];
    }
  }

  catch(const std::bad_alloc & exc){
    std::cerr << exc.what() << std::endl;
    buffer_deallocate();
  }
}

// (4) dtor definition
MyString::~MyString(){ this -> buffer_deallocate(); }

// (5) size definition
size_t MyString::size() const{ return m_size; }

// (6) length definition
size_t MyString::length() const{ return m_size - 1; }

// (7) c_str definition
const char * MyString::c_str() const{ return m_buffer; }

// (8) overload binary operator ==
bool MyString::operator==(const MyString & other_myStr) const{
  return strcmp(m_buffer, other_myStr.m_buffer) == 0;
}

// (9) operator =
MyString & MyString::operator=(const MyString & other_myStr){
  this -> buffer_deallocate();

  try{
    this -> buffer_allocate( other_myStr.size() );
    for(size_t i=0; i<other_myStr.size(); i++){
      (*this)[i] = other_myStr[i];
    }
  }

  catch(const std::bad_alloc & exc){
    std::cerr << exc.what() << std::endl;
    this -> buffer_deallocate();
  }

  return *this;
}

// (10) operator + definition
MyString MyString::operator+(const MyString & other_myStr) const{
  size_t buffer = other_myStr.size() + size();
  char * temp_buffer;

  try{
    temp_buffer = new char[buffer];
    size_t i=0;

    for(; i<size(); i++){
      temp_buffer[i] = (*this)[i];
    }
    for(; i<buffer; i++){
      temp_buffer[i] = other_myStr[i-size()];
    }
  }
  catch(std::bad_alloc & exc){
    std::cerr << exc.what() << std::endl;
  }

  return MyString(temp_buffer);
}

// (11a) operator []
char & MyString::operator[](size_t index){ return m_buffer[index]; }

// (11b) operator []
const char & MyString::operator[](size_t index) const{ return m_buffer[index]; }

// (12) operator <<
std::ostream & operator<<(std::ostream & os, const MyString & myStr){
  os << myStr.m_buffer;

  return os;
}

// (13) buffer deallocate
void MyString::buffer_deallocate(){
  if(m_buffer != NULL){
    delete [] m_buffer;
    m_buffer = NULL;
    m_size = 0;
  }
}

// (14) buffer allocate
void MyString::buffer_allocate(size_t size){
  try{
    m_size = size;
    m_buffer = new char[size];
  }
  catch(const std::exception & exc){
    std::cerr << exc.what() << std::endl;
    this -> buffer_deallocate();
  }
}
