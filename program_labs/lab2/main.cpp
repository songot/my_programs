#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <stdlib.h> /* atoi */
#include "DLL.h"

int main ()
{	
	// Node's copy-constructor =;
	/*var3::Node * temp = new var3::Node;	
	temp->set();	
	var3::Node newNode;
	newNode = *temp;
	newNode.print();
	*/
	
	// DLL's copy-constructor =;
	/*var3::DLL origin;
	origin.load();
	var3::DLL newDLL;
	newDLL.load();
	newDLL = origin;
	newDLL.print();*/
	
	// DLL- and Node- methods: +, -
	/*var3::DLL classList;
	var3::Node studentA;
	
	classList.load();
	studentA.set();
	
	//L+a
	classList + studentA;
	classList.print();
	std::cout << std::endl;
	
	//L-a
	classList - studentA;
	classList.print();
	std::cout << std::endl;	
	
	//friend a+L
	studentA + classList;
	classList.print();
	std::cout << std::endl;

	//friend a-L
	studentA - classList;
	classList.print();
	std::cout << std::endl;
	*/

	//DLL[]
	/*var3::DLL classList;
	int id = 0;
	
	classList.load();
	std::cin >> id;
       	
	classList[id].print();*/
	
	//DLL>, DLL<, DLL==
	/*var3::DLL classList;
	int grade = 0;
	
	classList.load();
	std::cin >> grade;

	var3::DLL newDLL = classList == grade;
	newDLL.print();*/
	
	// Node, DLL cin >>, Node, DLL cout <<
	// DLL fin >>, DLL fout <<
	var3::DLL newClass;
	var3::Node newStudent;
	int n = 0;

	std::cin >> n;

	// Node cin >>, cout <<;
	for (int i = 0; i < n; i++)
	{
		std::cin >> newStudent;
		std::cout << newStudent << std::endl;
	}
	
	// DLL cin >>, cout <<
	/*for (int i = 0; i < n; i++)
	{
		std::cin >> newClass;
	}
	std::cout << newClass << std::endl;*/
	
	// DLL fin >>, DLL fout <<

	return 0;

}
