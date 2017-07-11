#include "stringplus.h"
#include <iostream>
int main(int argc, char** args) {
	StringP MyStr = "I am douglas";
	MyStr.DeleteSubString(0, 2);
	MyStr.InsertString("2333 ", 0);
	MyStr.DeleteCharAt(0);
	MyStr.InsertCharAt(0,'2');
	MyStr.ReplaceSubString("3444", 0);
	MyStr = "2333";
	MyStr += 2333;
	
	std::cout << MyStr.ToCharArray() << std::endl;
	system("pause");
	return 0;
}