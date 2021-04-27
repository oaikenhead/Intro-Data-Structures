/**
 * @brief  CS-202 NodeQueue class Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the NodeQueue class for CS-202.
 */

#include <NodeQueue/NodeQueue.h>

// (1) default ctor
NodeQueue::NodeQueue(){
	m_front = NULL;
	m_back = NULL;

	// debug output
	std::cout << "NodeQueue Default-Ctor" << std::endl;
}

// (2) Parametrized Constructor
NodeQueue::NodeQueue(size_t size, const DataType & value){
	m_front = new Node(value);
	m_back = m_front;

	for(size_t i=1; i < size; i++){
		m_back -> m_next = new Node(value);
		m_back = m_back -> m_next;
	}
}

// (3) Copy Constructor
NodeQueue::NodeQueue(const NodeQueue & other){
	Node * current_arr = other.m_front;
	if(!other.empty()){
		m_front = new Node(other.m_front -> m_data);
		m_back = m_front;
		current_arr = current_arr -> m_next;

		while(current_arr){
			m_back -> m_next = new Node(current_arr -> m_data);
			m_back = m_back -> m_next;
			current_arr = current_arr -> m_next;
		}
	}
}

// (4) Destructor
NodeQueue::~NodeQueue(){
	clear();
}

// (5) operator=
NodeQueue & NodeQueue::operator=(const NodeQueue & rhs){
	if(!empty()){
		clear();
	}

	Node * copy_var = rhs.m_front;

	if(!rhs.empty()){
		m_front = new Node(rhs.m_front -> m_data);
		m_back = m_front;
		copy_var = copy_var -> m_next;

		while(copy_var){
			m_back -> m_next = new Node(copy_var -> m_data);
			m_back = m_back -> m_next;
			copy_var = copy_var -> m_next;
		}
	}
	return *this;
}

// (6a) front
DataType & NodeQueue::front(){
	return m_front -> m_data;
}

// (6b) front const
const DataType & NodeQueue::front() const{
	return m_front -> m_data;
}

// (7a) back
DataType & NodeQueue::back(){
	return m_back -> m_data;
}

// (7b) back const
const DataType & NodeQueue::back() const{
	return m_back -> m_data;
}

// (8) push
void NodeQueue::push(const DataType & value){
	Node * new_node = new Node(value);

	if(empty()){
		m_front = new Node;
		m_back = new Node;
		return;
	}

	m_back -> m_next = new_node;
	m_back = new_node;
}

// (9) pop
void NodeQueue::pop(){
	if(!empty()){
		Node * pop_var = m_front;
		m_front = m_front -> m_next;
		pop_var -> m_next = NULL;
		delete pop_var;
	}
}

// (10) size
size_t NodeQueue::size() const{
	size_t i=0;
	Node * len = m_front;

	while(len){
		len = len -> m_next;
		++i;
	}

	return i;
}

// (11) empty
bool NodeQueue::empty() const{
	if(m_front){
		return false;
	}
	else{
		return true;
	}
}

// (12) full
bool NodeQueue::full() const{
	return false;
}

// (13) clear
void NodeQueue::clear(){
	// while the queue is not empty pop off
	while(!empty()){
		pop();
	}
}

// (14) serialize
void NodeQueue::serialize(std::ostream & os) const{
	Node * current_pos = m_front;
	int i=0;

	while(current_pos){
		os << "NQ" << i << ": " << current_pos -> data();

		if(current_pos -> m_next){
			os << std::endl;
		}

		current_pos = current_pos -> m_next;
		i++;
	}
}

// (i) operator <<
std::ostream & operator<<(std::ostream & os, const NodeQueue & nodeQueue){
	nodeQueue.serialize(os);

	return os;
}
