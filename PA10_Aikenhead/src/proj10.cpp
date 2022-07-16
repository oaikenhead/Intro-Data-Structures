/**
 * @brief  CS202 Main Function
 * @author Olliver Aikenhead
 *
 * This file compiles into the main executable
 */

 #include <ArrayStack/ArrayStack.hpp>
 #include <NodeStack/NodeStack.hpp>

 using namespace std;

 int main() {

 	// Default Ctor Tests
 	cout << "\n\t*************************************"
 		 << "\n\t***** ARRAYSTACK FUNCTION TESTS *****"
 		 << "\n\t*************************************"
 		 << endl << endl;
 	cout << "ArrayStack Default-Ctor:" << endl;
 	ArrayStack<int> as_default1;
 	ArrayStack<double> as_default2;
 	cout << as_default1 << endl;
 	cout << as_default2 << endl;

 	// Param Ctor Tests
 	cout << "ArrayStack Parametrized-Ctor:" << endl;
 	ArrayStack<int> as_param1(2, 44);
 	ArrayStack<double> as_param2(2, 77.7);
 	cout << as_param1 << endl;
 	cout << as_param2 << endl << endl;

 	// Copy Ctor Tests
 	cout << "ArrayStack Copy-Ctor:" << endl;
 	ArrayStack<int> as_copy1(as_param1);
 	ArrayStack<double> as_copy2(as_param2);
 	cout << as_copy1 << endl;
 	cout << as_copy2 << endl << endl;

 	// Assignment Operator Tests
 	cout << "ArrayStack Assignment Operator:" << endl;
 	ArrayStack<int> as_ao1(as_param1);
 	ArrayStack<double> as_ao2(as_param2);
 	cout << as_ao1 << endl;
 	cout << as_ao2 << endl << endl;

 	// Push Test
	// pushing 27 on top of as_ao1
	// pushing 33.3 on top of as_ao2
 	cout << "ArrayStack Push:" << endl;
 	as_ao1.push(27);
 	as_ao2.push(33.3);
 	cout << as_ao1 << endl;
 	cout << as_ao2 << endl << endl;

 	// Pop Test
	// popping number from top of stack
 	cout << "ArrayStack Pop:" << endl;
 	as_ao1.pop();
 	as_ao2.pop();
 	cout << as_ao1 << endl;
 	cout << as_ao2 << endl << endl;



 	// NodeStack Testing
 	cout << "\t************************************"
 		 << "\n\t***** NODESTACK FUNCTION TESTS *****"
 		 << "\n\t************************************"
 		 << endl << endl;

 	cout << "NodeStack Default-Ctor:" << endl;
 	NodeStack<int> ns_def1;
 	NodeStack<double> ns_def2;
 	cout << ns_def1 << endl;
 	cout << ns_def2 << endl;

 	// Param Ctor Tests
 	cout << "NodeStack Parametrized-Ctor:" << endl;
 	NodeStack<int> ns_param1(2, 55);
 	NodeStack<double> ns_param2(2, 4.4);
 	cout << ns_param1 << endl;
 	cout << ns_param2 << endl << endl;

 	// Copy Ctor Tests
 	cout << "NodeStack Copy-Ctor:" << endl;
 	NodeStack<int> ns_copy1(ns_param1);
 	NodeStack<double> ns_copy2(ns_param2);
 	cout << ns_copy1 << endl;
 	cout << ns_copy2 << endl << endl;

 	// Assignment Operator Tests
 	cout << "NodeStack Assignment Operator:" << endl;
 	NodeStack<int> ns_ao1(ns_param1);
 	NodeStack<double> ns_ao2(ns_param2);
 	cout << ns_ao1 << endl;
 	cout << ns_ao2 << endl << endl;

 	// Push Tests
 	cout << "NodeStack Push:" << endl;
 	ns_ao1.push(63);
 	ns_ao2.push(88.8);
 	cout << ns_ao1 << endl;
 	cout << ns_ao2 << endl << endl;

 	// Pop Tests
 	cout << "NodeStack Pop:" << endl;
 	ns_ao1.pop();
 	ns_ao2.pop();
 	cout << ns_ao1 << endl;
 	cout << ns_ao2 << endl << endl;

 	cout << "\t*************************************"
 		 << "\n\t*****     TESTING COMPLETED     *****"
 		 << "\n\t*************************************"
 		 << endl << endl;

 	return 0;
 }
