/**
 * @brief  CS-202 Main Source File Implementation
 * @author Olliver Aikenhead
 *
 * This file is the the implementation of the project main source file
 */

#include <iostream>
#include <ArrayList/ArrayList.h>
#include <NodeList/NodeList.h>

using namespace std;

int main(){

  // (1) testing default ctor
  cout << "\n" <<
          "////////////////////////////////\n" <<
          "/////   Constructor Tests  /////\n" <<
          "////////////////////////////////" << endl;

  cout << "\nTesting Default Ctor" << endl;
  ArrayList al_default;
  cout << al_default;

  NodeList nl_default;
  cout << nl_default;


  // (2) testing param ctor
  cout << "Testing Parametrized Ctor" << endl;
  DataType testV1(44, 100.75);
  DataType testV2(77, 200.5);

  ArrayList al_param(1, testV1);
  cout << "Value = " << al_param << endl;

  NodeList nl_param(1, testV2);
  cout << "Value = " << nl_param << endl;


  // (3) testing copy ctor
  cout << "Testing Copy Ctor" << endl;

  DataType copyData1(testV1);
  DataType copyData2(testV2);

  cout << copyData1 << endl;
  cout << copyData2 << endl;

  // (4) testing dtor
  DataType emptySet(0,0.0);

  cout << endl << "Testing Dtor by initializing values then deleting them" << endl;

  ArrayList * arrayTest_ptr = new ArrayList(1, emptySet);
  NodeList * nodeTest_ptr = new NodeList(2, emptySet);

  delete arrayTest_ptr;
  arrayTest_ptr = NULL;
  delete nodeTest_ptr;
  nodeTest_ptr = NULL;

  // (5) testing assignment operator
  cout << "\n" <<
          "//////////////////////////////\n" <<
          "/////   Operator Tests   /////\n" <<
          "//////////////////////////////" << endl;

  DataType testV3(33, 50.25);
  cout << endl << "Testing Assignment Operator=" << endl;

  ArrayList al_assignment(2, testV3);
  cout << "ArrayList before assignment = " << al_assignment << endl;
  al_assignment = al_param;
  cout << "ArrayList after assignment = "<< al_assignment << endl;

  NodeList nl_assignment(2, testV3);
  cout << "NodeList before assignment = " << nl_assignment;
  nl_assignment = nl_param;
  cout << "NodeList after assignment = " << nl_assignment << endl;

  cout <<
          "//////////////////////////////\n" <<
          "/////   Function Tests   /////\n" <<
          "//////////////////////////////" << endl << endl;

  // (6) front function test
  cout << "Testing Front Function" << endl;
  cout << *al_param.front() << endl;

  NodeList nl_front = nl_param;
  Node * show_front = nl_front.front();
  if(show_front != NULL){ cout << "Front Exists" << endl; }
  else{ cout << "Front Does not Exist" << endl; }

  // (7) back function test
  cout << endl << "Testing Back Function" << endl;
  cout << *al_param.back() << endl;

  NodeList nl_back = nl_param;
  Node * show_back = nl_back.back();
  if(show_back != NULL){ cout << "Back Exists" << endl; }
  else{ cout << "Back Does Not Exist" << endl; }


  // (8) find function test
  cout << endl << "Testing Find Function" << endl;
  DataType * previous_data = NULL;
  DataType * al_find = al_param.find(testV1, previous_data);
  cout << *al_find << endl;

  Node * previous_node = NULL;
  Node * locate = nl_assignment.find(testV3, previous_node);
  if(locate != NULL){ cout << "Located" << endl; }
  else{ cout << "Could not Locate" << endl; }

  // (9) insert after
  cout << endl << "Testing Insert After" << endl;


  // (10) insert before
  cout << endl << "Testing Insert Before" << endl;
  DataType al_before_test(1,34.5);
  al_param.insertBefore(al_before_test, testV1);
  cout << al_param << endl;

  // (11) erase
  cout << endl << "Testing Erase Function" << endl;

  // (12) operator[]
  cout << endl << "Testing operator[] Function" << endl;
  cout << "Value in arraylist array: " << al_param[2] << endl;

  // (13) size
  cout << endl << "Testing size function" << endl;
  cout << al_param.size() << endl;
  cout << nl_param.size() << endl;

  // (14) empty
  cout << endl << "Testing Empty Function" << endl;

  if(al_param.empty()){ cout << "ArrayList empty" << endl; }
  else{ cout << "ArrayList is not empty" << endl; }

  if(nl_param.empty()){ cout << "NodeList is empty" << endl; }
  else{ cout << "NodeList is not empty" << endl; }

  // (15) clear
  cout << endl << "Testing Clear Function" << endl;
  NodeList nl_clear(nl_param);
  if(nl_clear.size() > 0){
    nl_clear.clear();
  }

  cout << "\n" <<
          "/////////////////////////////////\n" <<
          "/////   Destructor Output   /////\n" <<
          "/////////////////////////////////" << endl << endl;


  return 0;
}
// end of file 
