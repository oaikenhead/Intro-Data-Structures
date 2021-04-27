// main driver test file

#include <iostream>
#include <MyString/MyString.h>

int main(){

  std::cout << "\n\tOlliver's Test Driver Program\n" << std::endl;

  // (1)
  std::cout << "Testing Default ctor" << std::endl;
  MyString ms_default;
  std::cout << ms_default << std::endl;

  // (2)
  std::cout << "Testing Parametrized ctor" << std::endl;
  MyString ms_parametrized("MyString parametrized constructor!");
  std::cout << ms_parametrized << std::endl << std::endl;

  // (3)
  std::cout << "Testing Copy ctor" << std::endl;
  MyString ms_copy(ms_parametrized);
  std::cout << ms_copy << std::endl << std::endl;

  // (4)
  std::cout << "Testing dtor" << std::endl;
  {
    MyString ms_destroy("MyString to be destroyed...");
    std::cout << ms_destroy << std::endl << std::endl;
  }

  // (5), (6)
  MyString ms_size_length("Size and length test");
  std::cout << "Testing size()" << std::endl;
  std::cout << ms_size_length.size() << std::endl;
  std::cout << "Testing length()" << std::endl;
  std::cout << ms_size_length.length() << std::endl << std::endl;

  // (7)
  std::cout << "Testing c_str()" << std::endl;
  MyString ms_toCstring("C-String equivalent successfully obtained!");
  std::cout << ms_toCstring.c_str() << std::endl << std::endl;

  // (8)
  std::cout << "Testing operator==()" << std::endl;
  MyString ms_same1("The same"), ms_same2("The same");
  if (ms_same1==ms_same2)
    std::cout << "Same success" << std::endl;

  MyString ms_different("The same (NOT)");
  if (!(ms_same1==ms_different))
    std::cout << "Different success" << std::endl << std::endl;

  // (9)
  std::cout << "Testing operator=()" << std::endl;
  MyString ms_assign("Before assignment");
  std::cout << ms_assign << std::endl;
  ms_assign = MyString("After performing assignment");
  std::cout << ms_assign << std::endl << std::endl;

  // (10)
  std::cout << "Testing operator+" << std::endl;
  MyString ms_append1("The first part");
  MyString ms_append2(" and the second");
  MyString ms_concat = ms_append1+ ms_append2;
  std::cout << ms_concat << std::endl << std::endl;

  // (11)
  std::cout << "Testing operator[]()" << std::endl;
  MyString ms_access("Access successful (NOT)");
  ms_access[17] = 0;
  std::cout << ms_access << std::endl << std::endl;

  // (12)
  std::cout << "Testing operator<<()" << std::endl;
  std::cout << ms_access << std::endl;

  return 0;
}
