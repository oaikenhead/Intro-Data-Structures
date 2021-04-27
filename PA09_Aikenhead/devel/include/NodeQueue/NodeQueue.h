/**
 * @brief  CS-202 NodeQueue class Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the NodeQueue class for CS-202.
 */

#ifndef NODEQUEUE_H_
#define NODEQUEUE_H_

#include <DataType/DataType.h>

class Node{
		//allows direct accessing of link and data from class NodeQueue
  	friend class NodeQueue;

	public:
    Node() :
	  	m_next( NULL )
		{
		}

		Node(const DataType & data, Node * next = NULL) :
	  	m_next( next ),
	  	m_data( data )
		{
		}

		Node(const Node & other) :
	  	m_next( other.m_next ),
	  	m_data( other.m_data )
		{
		}

		//gets non-const reference, can be used to modify value of underlying data
  	DataType & data(){
			return m_data;
  	}

		//gets const reference, can be used to access value of underlying data
		const DataType & data() const{
  		return m_data;
  	}

  private:
    Node * m_next;
    DataType m_data;
};

class NodeQueue{
		// (i) operator<<
		friend std::ostream & operator<<(std::ostream & os, const NodeQueue & nodeQueue);
	public:
		// (1) Default Constructor
		NodeQueue();

		// (2) Parametrized Constructor
		NodeQueue(size_t size, const DataType & value);

		// (3) Copy Constructor
		NodeQueue(const NodeQueue & other);

		// (4) Destructor
		~NodeQueue();

		// (5) operator=
		NodeQueue& operator= (const NodeQueue & rhs);

		// (6a) front
		DataType & front();

		// (6b) front
		const DataType & front() const;

		// (7a) back
		DataType & back();

		// (7b) back
		const DataType & back() const;

		// (8) push
		void push(const DataType & value);

		// (9) pop
		void pop();

		// (10) size
		size_t size() const;

		// (11) empty
		bool empty() const;

		// (12) full
		bool full() const;

		// (13) clear
		void clear();

		// (14) serialize
		void serialize(std::ostream & os) const;

	private:
		Node * m_front;
		Node * m_back;
};

#endif//NODEQUEUE_H_
