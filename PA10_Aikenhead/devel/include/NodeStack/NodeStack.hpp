/**
 * @brief  CS-202 NodeStack class Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the NodeStack class for CS-202.
 */

 #ifndef NODESTACK_H_
 #define NODESTACK_H_

 #include <iostream>

 template <typename T>
 class NodeStack;

 template <typename T>
 class Node{
 		friend class NodeStack<T>;

 	public:
 		Node() :
 	  	m_next( NULL )
 		{
 		}

 		Node(const T & data, Node<T>* next = NULL) :
 			m_next( next ),
 			m_data( data )
 		{
 		}

 		Node(const Node<T> & other) :
 			m_next( other.m_next ),
 			m_data( other.m_data )
 		{
 		}

 		T & data(){
 			return m_data;
 		}

 		const T & data() const{
 			return m_data;
 		}

 	private:
 		Node<T>* m_next;
 		T m_data;
 };

 template <typename T>
 class NodeStack{

 	template <typename U>
 	friend std::ostream & operator<<(std::ostream & os, const NodeStack<U> & NodeStack);

 	public:
 		// (1) default ctor
 		NodeStack(){
 			m_top = NULL;
 		}

 		// (2) param ctor
 		NodeStack(size_t count, const T & value){
 			m_top = new Node<T>(value);
 			Node<T> * rhs = m_top;

 			for(size_t i=1; i < count; i++){
 				rhs -> m_next = new Node<T>(value);
 				rhs = rhs -> m_next;
 			}
 		}

 		// (3) copy ctor
 		NodeStack(const NodeStack & other){
 			Node<T> * curr_val;
 			size_t check = other.size();
 			m_top = NULL;

 			while(check){
 				curr_val = other.m_top;
 				for(size_t i=0; i < check-1; i++){
 					curr_val = curr_val -> m_next;
 				}

 				push(curr_val -> data());
 				check--;
 			}
 		}

 		// (4) dtor
 		~NodeStack(){

 		}

 		// (5) operator=
 		NodeStack & operator=(const NodeStack & rhs){
 			if(this != &rhs){
 				// clear whatever is there
 				clear();

 				Node<T> * curr_val;
 				size_t check = rhs.size();
 				m_top = NULL;

 				while(check){
 					curr_val = rhs.m_top;
 					for(int i=0; i < check - 1; i++){
 						curr_val = curr_val -> m_next;
 					}

 					push(curr_val -> data());
 					check--;
 				}
 			}
 			return *this;
 		}

 		// (6) top
 		T & top(){
 			return m_top -> data();
 		}

 		const T & top() const{
 			return m_top -> data();
 		}

 		// (7) push
 		void push(const T & value){
 			if(empty()){
 				m_top = new Node<T>(value);
 			}
 			else{
 				m_top = new Node<T>(value, m_top);
 			}
 		}

 		// (8) pop
 		void pop(){
 			// if this is not empty pop off the value on top
 			if(!empty()){
 				Node<T> * curr_val = m_top;
 				m_top = m_top -> m_next;
 				delete curr_val;
 			}
 		}

 		// (9) size
 		size_t size() const{
 			// setting current value
 			Node<T> * curr_val = m_top;
 			size_t check = 0;

 			// while on the current value check increases and moves the value
 			while(curr_val){
 				check++;
 				curr_val = curr_val -> m_next;
 			}
 			// returning how many times check moved
 			return check;
 		}

 		// (10) empty
 		bool empty() const{
 			return m_top == NULL;
 		}

 		// (11) full
 		bool full() const{
 			return false;
 		}

 		// (12) clear
 		void clear(){
 			// setting top to current value
 			Node<T> * curr_val = m_top;

 			while(curr_val){
 				// taking off the top of the set of values and moving next
 				pop();
 				curr_val = curr_val -> m_next;
 			}
 		}

 		// (13) serialize
 		void serialize(std::ostream & os) const{
 			// creating pointer that points to top
 			Node<T> * curr_val = m_top;
 			size_t i = size() - 1;

 			while(curr_val){
 				os << curr_val -> data();

 				if(curr_val -> m_next){
 					os << std::endl;
 				}

 				// moving the current value
 				curr_val = curr_val -> m_next;
 				i--;
 			}
 		}

 	private:
 		Node<T> * m_top;

 };

 template <typename T>
 std::ostream & operator<<(std::ostream & os, const NodeStack<T> & nodeStack){
 	nodeStack.serialize(os);
 	return os;
 }

 #endif//NODESTACK_H_
