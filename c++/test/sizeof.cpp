#include <iostream>

using std::cout;
using std::endl;

int main()
{
	cout << "int: " << sizeof(int) << "\n"
		 << "float: " << sizeof(float) << "\n"
		 << "short: " << sizeof(short) << "\n"
		 << "void*: " << sizeof(void*) << "\n"
		 << "long: " << sizeof(long) << "\n"
		 << "char: " << sizeof(char) << "\n"
		 << "short int: " << sizeof(short int) << "\n"
		 << "long long: " << sizeof(long long) << "\n"
		 << "double: " << sizeof(double) << "\n"
		 << endl;
	return 0;
}
