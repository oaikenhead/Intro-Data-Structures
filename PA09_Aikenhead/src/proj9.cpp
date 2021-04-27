/**
 * @brief  CS-202 Main Test Driver Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the test driver for project9.
 */

#include <iostream>

#include <DataType/DataType.h>
#include <ArrayQueue/ArrayQueue.h>
#include <NodeQueue/NodeQueue.h>

using namespace std;

int main(){

	// title to show the program has begun running
	cout << "\t******************************************\n"
			 << "\t* TESTING ARRAYQUEUE AND NODEQUEUE CTORS *\n"
			 << "\t******************************************"
			 << endl << endl;

	DataType dt_1(1, 44.01);
	DataType dt_2(2, 77.02);

	// (1) default ctor test
	cout << "Default-Ctor Test for ArrayQueue:" << endl;
	ArrayQueue aq_default;
	cout << aq_default;

	cout << "Default-Ctor Test for NodeQueue:" << endl;
	NodeQueue nq_default;
	cout << nq_default << endl;

	// (2) param ctor test
	cout << "Parametrized-Ctor Test for ArrayQueue:" << endl;
	ArrayQueue aq_param(2, dt_1);
	cout << aq_param << endl;

	cout << "Parametrized-Ctor Test for NodeQueue:" << endl;
	NodeQueue nq_param(2, dt_2);
	cout << nq_param << endl << endl;

	// (3) copy ctor test
	cout << "Copy-Ctor Test for ArrayQueue:" << endl;
	ArrayQueue aq_copy(aq_param);
	cout << aq_copy << endl;

	cout << "Copy-Ctor Test for NodeQueue:" << endl;
	NodeQueue nq_copy(nq_param);
	cout << nq_copy << endl << endl;

	cout << "\t***********************************\n"
			 << "\t* TESTING OPERATORS AND FUNCTIONS *\n"
			 << "\t***********************************"
			 << endl << endl;

	// (5) operator = test
	cout << "Operator = Test for ArrayQueue:" << endl;
	ArrayQueue aq_assignment;
	aq_assignment = aq_param;
	cout << aq_assignment << endl;

	cout << "Operator = Test for NodeQueue:" << endl;
	NodeQueue nq_assignment;
	nq_assignment = nq_param;
	cout << nq_param << endl << endl;

	// (6) front test
	cout << "Front Non Const Test for ArrayQueue:" << endl;
	DataType aq_front = aq_param.front();
	if(aq_param.empty()){
			cout << "The array is empty" << endl;
	}
	cout << aq_front << endl;

	cout << "Front Const Test for ArrayQueue:" << endl;
	const DataType aq_front_cnst = aq_assignment.front();
	cout << aq_front_cnst << endl;

	cout << "Front Non Const Test for NodeQueue:" << endl;
	DataType nq_front = nq_param.front();
	cout << nq_front << endl;

	cout << "Front Const Test for NodeQueue:" << endl;
	const DataType nq_front_cnst = nq_assignment.front();
	cout << nq_front_cnst << endl << endl;

	// (7) back test
	cout << "Back Non Const Test for ArrayQueue:" << endl;
	DataType aq_back = aq_param.back();
	if(aq_param.empty()){
		cout << "The array is empty" << endl;
	}
	cout << aq_back << endl;

	cout << "Back Const Test for ArrayQueue:" << endl;
	const DataType aq_back_cnst = aq_assignment.back();
	cout << aq_back_cnst << endl;

	cout << "Back Non Const Test for NodeQueue:" << endl;
	DataType nq_back = nq_param.back();
	cout << nq_back << endl;

	cout << "Back Const Test for NodeQueue:" << endl;
	const DataType nq_back_cnst = nq_assignment.back();
	cout << nq_back_cnst << endl << endl;

	// (8) push test
	cout << "Push Test for ArrayQueue:" << endl;
	DataType aq_push_data(1, 55.01);
	aq_param.push(aq_push_data);
	cout << aq_param << endl;

	cout << "Push Test for NodeQueue:" << endl;
	DataType nq_push_data(2, 4.02);
	nq_param.push(nq_push_data);
	cout << nq_param << endl << endl;

	// (9) pop test
	cout << "Pop Test for ArrayQueue:" << endl;
	aq_param.pop();
	cout << aq_param << endl;

	cout << "Pop Test for NodeQueue:" << endl;
	nq_param.pop();
	cout << nq_param << endl << endl;

	// (10) size test
	cout << "Size Test for ArrayQueue:" << endl;
	cout << aq_param.size() << endl;

	cout << "Size Test for NodeQueue:" << endl;
	cout << nq_param.size() << endl << endl;

	cout << "\t*********************************\n"
			 << "\t* TESTING COMPLETED EXITING NOW *\n"
			 << "\t*********************************"
			 << endl << endl;

	return 0;
}
