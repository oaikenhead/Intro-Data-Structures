/**
 * @brief  CS202 ArrayStack Class Implementation - C++11
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the ArrayStack class for CS-202.
 */

 #ifndef ARRAYSTACK_H_
 #define ARRAYSTACK_H_

 #include <iostream>

 const size_t ARRAY_SIZE = 1000;

 template <typename T>
 class ArrayStack{
 	// (i) operator <<
 	template <typename U>
 	friend std::ostream & operator<<(std::ostream &os, const ArrayStack<U> &arrayStack);
 	
	public:
 		// (1) default ctor
 		ArrayStack(){ m_top = 0; }

 		// (2) param ctor
 		ArrayStack(size_t count, const T &value){
 			m_top = 0;

 			for(size_t i=0; i < count; i++){
 				push(value);
 			}
 		}

 		// (3) copy ctor
 		ArrayStack(const ArrayStack &other) {
 			size_t check = other.size();
 			m_top = 0;

 			for(size_t i=0; i < check; i++) {
 				push(other.m_container[i]);
 			}
 		}

 		// (4) dtor
 		~ArrayStack(){ }

 		// (5) operator =
 		ArrayStack &operator=(const ArrayStack &rhs){
 			if(this != &rhs){
 				// clear data
 				clear();

 				size_t check = rhs.size();

 				for(size_t i=0; i < check; i++){
 					push(rhs.m_container[i]);
 				}
 			}
 			return *this;
 		}

 		// (6) top
 		T &top(){ return m_container[m_top-1]; }

 		const T &top() const{ return m_container[m_top-1]; }

 		// (7) push
 		void push(const T &value){
 			if(!full()){
 				m_container[m_top++] = value;
 			}
 		}

 		// (8) pop
 		void pop(){
 			if(!empty()){
 				m_top--;
 			}
 		}

 		// (9) size
 		size_t size() const{ return m_top; }

 		// (10) empty
 		bool empty() const{ return m_top == 0; }

 		// (11) full
 		bool full() const{ return size() >= ARRAY_SIZE; }

 		// (12) clear
 		void clear(){ m_top = 0; }

 		// (13) serialize
 		void serialize(std::ostream &os) const{
 			size_t c_size = size();

 			for(int i=c_size-1; i >= 0; i--){
 				os << m_container[i];

 				if(i>0){
 					os << std::endl;
 				}
 			}
 		}

 	private:
 		T m_container[ARRAY_SIZE];
 		size_t m_top;
 };

 template <typename U>
 std::ostream & operator<<(std::ostream &os, const ArrayStack<U> &arrayStack){
 	arrayStack.serialize(os);
 	return os;
 }

 #endif//ARRAYSTACK_H_
