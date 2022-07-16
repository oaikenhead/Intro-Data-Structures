/**
 * @brief  CS-202 Main Test Driver Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the test driver for project9.
 */

#include <DataType/DataType.h>
#include <ArrayQueue/ArrayQueue.h>
#include <NodeQueue/NodeQueue.h>

using namespace std;

int main(){

	// title to show the program has begun running
	std::cout << "\t******************************************\n"
		      << "\t* TESTING ARRAYQUEUE AND NODEQUEUE CTORS *\n"
		      << "\t******************************************"
		      << std::endl << std::endl;

	DataType dt_1(1, 44.01);
	DataType dt_2(2, 77.02);

	// (1) default ctor test
	std::cout << "Default-Ctor Test for ArrayQueue:" << std::endl;
	ArrayQueue aq_default;
	std::cout << aq_default << std::endl;

	std::cout << "Default-Ctor Test for NodeQueue:" << std::endl;
	NodeQueue nq_default;
	std::cout << nq_default << std::endl;

	// (2) param ctor test
	std::cout << "Parametrized-Ctor Test for ArrayQueue:" << std::endl;
	ArrayQueue aq_param(2, dt_1);
	std::cout << aq_param << std::endl;

	std::cout << "Parametrized-Ctor Test for NodeQueue:" << std::endl;
	NodeQueue nq_param(2, dt_2);
	std::cout << nq_param << std::endl << std::endl;

	// (3) copy ctor test
	std::cout << "Copy-Ctor Test for ArrayQueue:" << std::endl;
	ArrayQueue aq_copy(aq_param);
	std::cout << aq_copy << std::endl;

	std::cout << "Copy-Ctor Test for NodeQueue:" << std::endl;
	NodeQueue nq_copy(nq_param);
	std::cout << nq_copy << std::endl << std::endl;

	std::cout << "\t***********************************\n"
			 << "\t* TESTING OPERATORS AND FUNCTIONS *\n"
			 << "\t***********************************"
			 << std::endl << std::endl;

	// (5) operator = test
	std::cout << "Operator = Test for ArrayQueue:" << std::endl;
	ArrayQueue aq_assignment;
	aq_assignment = aq_param;
	std::cout << aq_assignment << std::endl;

	std::cout << "Operator = Test for NodeQueue:" << std::endl;
	NodeQueue nq_assignment;
	nq_assignment = nq_param;
	std::cout << nq_param << std::endl << std::endl;

	// (6) front test
	std::cout << "Front Non Const Test for ArrayQueue:" << std::endl;
	DataType aq_front = aq_param.front();
	if(aq_param.empty()){
			std::cout << "The array is empty" << std::endl;
	}
	std::cout << aq_front << std::endl;

	std::cout << "Front Const Test for ArrayQueue:" << std::endl;
	const DataType aq_front_cnst = aq_assignment.front();
	std::cout << aq_front_cnst << std::endl;

	std::cout << "Front Non Const Test for NodeQueue:" << std::endl;
	DataType nq_front = nq_param.front();
	std::cout << nq_front << std::endl;

	std::cout << "Front Const Test for NodeQueue:" << std::endl;
	const DataType nq_front_cnst = nq_assignment.front();
	std::cout << nq_front_cnst << std::endl << std::endl;

	// (7) back test
	std::cout << "Back Non Const Test for ArrayQueue:" << std::endl;
	DataType aq_back = aq_param.back();
	if(aq_param.empty()){
		std::cout << "The array is empty" << std::endl;
	}
	std::cout << aq_back << std::endl;

	std::cout << "Back Const Test for ArrayQueue:" << std::endl;
	const DataType aq_back_cnst = aq_assignment.back();
	std::cout << aq_back_cnst << std::endl;

	std::cout << "Back Non Const Test for NodeQueue:" << std::endl;
	DataType nq_back = nq_param.back();
	std::cout << nq_back << std::endl;

	std::cout << "Back Const Test for NodeQueue:" << std::endl;
	const DataType nq_back_cnst = nq_assignment.back();
	std::cout << nq_back_cnst << std::endl << std::endl;

	// (8) push test
	std::cout << "Push Test for ArrayQueue:" << std::endl;
	DataType aq_push_data(1, 55.01);
	aq_param.push(aq_push_data);
	std::cout << aq_param << std::endl;

	std::cout << "Push Test for NodeQueue:" << std::endl;
	DataType nq_push_data(2, 4.02);
	nq_param.push(nq_push_data);
	std::cout << nq_param << std::endl << std::endl;

	// (9) pop test
	std::cout << "Pop Test for ArrayQueue:" << std::endl;
	aq_param.pop();
	std::cout << aq_param << std::endl;

	std::cout << "Pop Test for NodeQueue:" << std::endl;
	nq_param.pop();
	std::cout << nq_param << std::endl << std::endl;

	// (10) size test
	std::cout << "Size Test for ArrayQueue:" << std::endl;
	std::cout << aq_param.size() << std::endl;

	std::cout << "Size Test for NodeQueue:" << std::endl;
	std::cout << nq_param.size() << std::endl << std::endl;

	std::cout << "\t*********************************\n"
			 << "\t* TESTING COMPLETED EXITING NOW *\n"
			 << "\t*********************************"
			 << std::endl << std::endl;

	return 0;
}
