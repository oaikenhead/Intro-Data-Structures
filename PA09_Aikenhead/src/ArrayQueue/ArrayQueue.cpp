/**
 * @brief  CS-202 ArrayQueue class Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the ArrayQueue class for CS-202.
 */

#include <ArrayQueue/ArrayQueue.h>

// (1) Default Constructor
ArrayQueue::ArrayQueue() {
	m_front = 0;
	m_back = 0;
	m_size = 0;

	// debug output
	std::cout << "ArrayQueue Default-Ctor" << std::endl;
}

// (2) Parametrized Constructor
ArrayQueue::ArrayQueue(size_t count, const DataType &value) {
	m_front = 0;
	m_back = count;
	m_size = count;

	for(size_t i=0; i<count; i++) {
		m_array[i] = value;
	}
}

// (3) Copy Constructor
ArrayQueue::ArrayQueue(const ArrayQueue & other) {
	m_front = other.m_front;
	m_back = other.m_back;
	m_size = other.m_size;

	for(size_t i=0; i < other.m_size; i++) {
		m_array[i] = other.m_array[i];
	}
}

// (4) Destructor
ArrayQueue::~ArrayQueue() {
	clear();
}

// (5) operator=
ArrayQueue & ArrayQueue::operator=(const ArrayQueue &rhs) {
	if(this != &rhs){
		// empty whatever lhs has
		clear();

		// set rhs values
		m_front = rhs.m_front;
		m_back = rhs.m_back;
		m_size = rhs.m_size;

		for(size_t i=0; i < m_size; i++) {
			m_array[i] = rhs.m_array[i];
		}
	}

	return *this;
}

// (6a) front non const
DataType & ArrayQueue::front() {
	return m_array[m_front];
}

// (6b) front const
const DataType & ArrayQueue::front() const {
	return m_array[m_front];
}

// (7a) back non const
DataType & ArrayQueue::back() {
	return m_array[m_back];
}

// (7b) back const
const DataType & ArrayQueue::back() const {
	return m_array[m_back];
}

// (8) push
void ArrayQueue::push(const DataType & value) {
	m_array[m_back] = value;
	++m_size;
	m_back = (m_back + 1) % ARRAY_MAX;
}

// (9) pop
void ArrayQueue::pop() {
	--m_size;
	m_front = (m_front + 1) % ARRAY_MAX;
}

// (10) size
size_t ArrayQueue::size() const {
	return m_size;
}

// (11) empty
bool ArrayQueue::empty() const {
	if(m_size == 0){
		return false;
	}
	else{
		return true;
	}
}

// (12) full
bool ArrayQueue::full() const {
	if(m_size >= ARRAY_MAX){
		return true;
	}
	else{
		return true;
	}
}

// (13) clear
void ArrayQueue::clear() {
	m_front = 0;
	m_back = 0;
	m_size = 0;
}

// (14) serialize
void ArrayQueue::serialize(std::ostream &os) const {
	for(size_t i=0; i < m_size; i++){
		os << "AQ" << i << ": " << m_array[i + m_front];

		if(i != m_size - 1){
			os << std::endl;
		}
	}
}


// (i) operator <<
std::ostream & operator<<(std::ostream &os, const ArrayQueue &arrayQueue) {
	arrayQueue.serialize(os);
	return os;
}
