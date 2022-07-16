/**
 * @brief  CS-202 ArrayQueue class Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the ArrayQueue class for CS-202.
 */

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

#include <DataType/DataType.h>

const size_t ARRAY_MAX = 1000;

class ArrayQueue{
		// (i) operator<<
		friend std::ostream &operator<<(std::ostream &os, const ArrayQueue &arrayQueue);

	public:
		// (1) Default Constructor
		ArrayQueue();

		// (2) Parametrized Constructor
		ArrayQueue(size_t count, const DataType &value);

		// (3) Copy Constructor
		ArrayQueue(const ArrayQueue &other);

		// (4) Destructor
		~ArrayQueue();

		// (5) operator=
		ArrayQueue & operator= (const ArrayQueue &rhs);

		// (6a) front
		DataType & front();

		// (6b) front
		const DataType & front() const;

		// (7a) back
		DataType & back();

		// (7b) back
		const DataType & back() const;

		// (8) push
		void push(const DataType &value);

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
		void serialize(std::ostream &os) const;

	private:
		DataType m_array[ARRAY_MAX];
		size_t m_front;
		size_t m_back;
		size_t m_size;
};

#endif//ARRAYQUEUE_H_
