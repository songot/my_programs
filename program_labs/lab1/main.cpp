#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <stdlib.h> /* atoi */
#include "DLL.h"

int main ()
{	
	/*filter by the grade (less then)*/
	var3::DLL MyClass1; // - создание пустого списка
	var3::DLL Re1;
	var3::Ops op = var3::less;
	MyClass1.load();
	char * grade = new char[50];
	std::cout << "Grade: ";
	std::cin >> grade;	
	var3::Node * MyClass1_Head = MyClass1.getHead();
	Re1.filter_by_grade(MyClass1_Head, op, grade);	
	Re1.save();
	delete [] grade;
	/**/
	
	/*search by the last name*/
	var3::DLL MyClass2;
	var3::DLL Re2;
	MyClass2.load();
	char * lastName = new char[50];
	std::cout << "Last name: ";
	std::cin >> lastName;
	var3::Node * MyClass2_Head = MyClass2.getHead();
	Re2.search_by_last_name(MyClass2_Head, lastName);
	Re2.print();
	delete [] lastName;	
	/**/	

	/*change an element*/
	var3::DLL MyClass3;
	var3::Options option = var3::item;
	MyClass3.load();
	int id;
	std::cout << "Id: ";
	std::cin >> id;
	MyClass3.change(id, option);
	MyClass3.print();	
	/**/

	/*remove an element*/
	var3::DLL MyClass4;
	MyClass4.load();
	std::cout << "Id: ";
	std::cin >> id;
	MyClass4.remove(id);
	MyClass4.print();
	/**/

	return 0;
}
