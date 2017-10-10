#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "List.h"


struct UserType
{
private:

	std::string message = "\nuser type ";
	int numb;


public:

	explicit UserType() { }
	explicit UserType(int numb) : numb(numb) { }

	std::string get_message() {
		std::string ret_value = message + std::to_string(numb);

		return ret_value;
	}
}; 


void main()
{
	List<UserType> list;

	srand(time(NULL));
	for (int i = 0; i < 14; i++) {
		UserType temp(i);
		list.push_back(temp);
	}

	for (List<UserType>::iterator it = list.begin(); it != list.end(); ++it) {
		std::cout << (*it).get_message() << ' ';
	}
	std::cout << std::endl;

	UserType temp(14);
	list.insert(list.end(), temp);

	auto it = list.begin();

	for (List<UserType>::iterator it = list.begin(); it != list.end(); ++it) {
		std::cout << (*it).get_message() << ' ';
	}
	std::cout << std::endl;


	/* doesn't work
	for (int numb : list) {
		std::cout << numb << ' ';
	
	std::cout << std::endl;*/

	system("pause");
}