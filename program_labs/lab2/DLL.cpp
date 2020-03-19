#include "DLL.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstring>

namespace var3
{
	char * Node::getLastName(){return _lastName;}
	char * Node::getName(){return _name;}
	char * Node::getSex(){return _sex;}
	char * Node::getGrade(){return _grade;}
	char * Node::getBirthday(){return _birthday;}
	char * Node::getAddress(){return _address;}

	void Node::setLastName(char * lastName)
	{
		/*if (sizeof(_lastName)>sizeof(char)) delete[] _lastName;
		else if (sizeof(_lastName)==sizeof(char)) delete _lastName;*/
		int i;
		_lastName = new char[50];
		for (i=0;lastName[i]!='\0';i++)
		{
			_lastName[i]=lastName[i];
		}
		_lastName[i]='\0';
	}
	void Node::setName(char * name)
	{
		/*if (sizeof(_name)>sizeof(char)) delete[] _name;
		else if (sizeof(_name)==sizeof(char)) delete _name;*/
		int i;
		_name = new char[50];
		for (i=0;name[i]!='\0';i++)
		{
			_name[i]=name[i];
		}
		_name[i]='\0';
	}
	void Node::setSex(char * sex)
	{
		/*if (sizeof(_sex)>sizeof(char)) delete[] _sex;
		else if (sizeof(_sex)==sizeof(char)) delete _sex;*/
		int i;
		_sex = new char[50];
		for (i=0;sex[i]!='\0';i++)
		{
			_sex[i]=sex[i];
		}
		_sex[i]='\0';
	}
	void Node::setGrade(char * grade)
	{
		/*if (sizeof(_grade)>sizeof(char)) delete[] _grade;
		else if (sizeof(_grade)==sizeof(char)) delete _grade;*/
		int i;
		_grade = new char[50];
		for (i=0; grade[i]!='\0';i++)
		{
			_grade[i]=grade[i];
		}
		_grade[i]='\0';
	}
	void Node::setBirthday(char * birthday)
	{
		/*if (sizeof(_birthday)>sizeof(char)) delete[] _birthday;
		else if (sizeof(_birthday)==sizeof(char)) delete _birthday;*/	
		int i;
		_birthday = new char[50];
		for (i=0; birthday[i]!='\0';i++)
		{
			_birthday[i]=birthday[i];
		}
		_birthday[i]='\0';
	}
	void Node::setAddress(char * address)
	{
		/*if (sizeof(_address)>sizeof(char)) delete[] _address;
		else if (sizeof(_address)==sizeof(char)) delete _address;*/
		int i;
		_address=new char[50];
		for (i=0; address[i]!='\0';i++)
		{
			_address[i]=address[i];
		}
		_address[i]='\0';
	}

	void Node::setLastName()
	{
		_lastName = new char[50];
		std::cin >> _lastName;
	}
	void Node::setName()
	{
		_name = new char[50];
		std::cin >> _name;

	}
	void Node::setSex()
	{
		_sex = new char[50];
		std::cin >> _sex;

	}
	void Node::setGrade()
	{
		_grade = new char[50];
		std::cin >> _grade;
	}
	void Node::setBirthday()
	{
		_birthday = new char[50];
		std::cin >> _birthday;
	}
	void Node::setAddress()
	{
		_address = new char[50];
		std::cin >> _address;
	}
	void Node::set()
	{
		setLastName();
		setName();
		setSex();
		setGrade();
		setBirthday();
		setAddress();
	}
	void Node::print()
	{
		std::cout << _lastName << \
		      " " << _name     << \
		      " " << _sex      << \
		      " " << _grade    << \
		      " " << _birthday << \
		      " " << _address  << \
		std::endl;
	}

	void Node::copy(Node & origin)
	{
		//конструктор копий
		
		char * lastName = origin.getLastName(); 
		char * name = origin.getName();
		char * sex = origin.getSex();
		char * grade = origin.getGrade();
		char * birthday = origin.getBirthday();
		char * address = origin.getAddress();

		setLastName(lastName); 

		setName(name); 

		setSex(sex); 

		setGrade(grade); 

		setBirthday(birthday); 

		setAddress(address); 

	}

	void Node::operator=(Node & origin)
	{
		// перегрузка =
		// конструктор копий
		char * lastName = origin.getLastName(); 
		char * name = origin.getName();
		char * sex = origin.getSex();
		char * grade = origin.getGrade();
		char * birthday = origin.getBirthday();
		char * address = origin.getAddress();

		setLastName(lastName); 

		setName(name); 

		setSex(sex); 

		setGrade(grade); 

		setBirthday(birthday); 

		setAddress(address);
	}
	
	bool Node::operator==(Node & nodeB)
	{
		if (!mystrcmp(nodeB.getLastName(),this->getLastName())&&\
		    !mystrcmp(nodeB.getName(),this->getName())&&\
		    !mystrcmp(nodeB.getSex(),this->getSex())&&\
		    !mystrcmp(nodeB.getGrade(),this->getGrade())&&\
		    !mystrcmp(nodeB.getBirthday(),this->getBirthday())&&\
		    !mystrcmp(nodeB.getAddress(),this->getAddress()))
			return true;
		else
			return false;
	}

	std::ostream& operator<<(std::ostream& os, const Node&)
	{
		os << _lastName << \
		      " " << _name     << \
		      " " << _sex      << \
		      " " << _grade    << \
		      " " << _birthday << \
		      " " << _address;
		return os;
	}
	
	std::istream& operator>>(std::istream& is, Node&)
	{
		_lastName = new char[50];
		_name = new char[50];
		_sex = new char[50];
		_grade = new char[50];
		_birthday = new char[50];
		_address = new char[50];_ 
		
		is >> _lastName;
		is >> _name;
		is >> _sex;
		is >> _grade;
		is >> _birthday;
		is >> _address;

		return is;
	}	

	Node::Node(char *& lastName, char *& name,\
			 char *& sex,	 char *& grade,\
			 char *& birthday, char *& address)
	{
		_lastName=lastName;
		_name=name;
		_sex=sex;
		_grade=grade;
		_birthday=birthday;
		_address=address;
	}

	Node::Node(): _lastName(0), _name(0), _sex(0),\
				    _grade(0), _birthday(0),\
						 _address(0){};

	Node::~Node()
	{
		std::cout << "Node destructor is working" << std::endl;
		/*delete[] _lastName;
		std::cout << "help" << std::endl;
		delete[] _name;
		delete[] _sex;
		delete[] _grade;
		delete[] _birthday;
		delete[] _address;*/
		if (_lastName!=0) 
		{
			delete[] _lastName;
			_lastName=0;
		}
		if (_name!=0)
		{
			delete[] _name;
			_name=0;
		}
		if (_sex!=0)
		{
			delete[] _sex;
			_sex=0;
		}
		if (_grade!=0)
		{
			delete[] _grade;
			_grade=0;
		}
		if (_birthday!=0)
		{
			delete[] _birthday;
			_birthday=0;
		}
		if (_address!=0)
		{
			delete[] _address;
			_address=0;
		}
	}

	int mystrcmp(const char * a, const char * b)
	{
		while (* a && * b && * a == * b)
		{
			++a;
			++b;
		}
		return (* a - * b);
	}

	int Compare(Node & Node1, Node & Node2)
	{
		// setting up rules for comparison
		const char * lastName1 = Node1.getLastName();
		const char * lastName2 = Node2.getLastName();
		return mystrcmp(lastName1, lastName2);
	}

	int Compare (const char * str1, const char * str2)
	{
		//const char * lastName1 = str1;
		//const char * lastName2 = str2;
		return mystrcmp(str1, str2);
	}

	Node * DLL::getHead(){return Head;}
	Node * DLL::getTail(){return Tail;}
	void DLL::operator=(DLL & origin)
	{
		if (_quantity)
		{
			int q = _quantity;
			for (int i = 1; i <= q; i++)
			{
				remove(i);
			}
		}
		

		Node * temp = origin.getHead();
		while(temp)
		{
			cpush(*temp);
			temp=temp->next;
		}
	}
	void DLL::operator+(Node & nodeB)
	{
		cpush(nodeB);
	}

	void DLL::operator-(Node & nodeB)
	{
		Node * temp = getHead();
		int id = 1;
		while (temp)
		{
			if (nodeB == *temp)
			{
				remove(id);
				break;
			}
			temp=temp->next;
			id++;
		}	
	}

	void operator+(Node & nodeA, DLL & dllB)
	{
		dllB.cpush(nodeA);
	}

	void operator-(Node & nodeA, DLL & dllB)
	{
		Node * temp = dllB.getHead();
		int id = 1;
		while (temp)
		{
			if (nodeA == *temp)
			{
				dllB.remove(id);
				break;
			}
			temp=temp->next;
			id++;
		}
	}

	Node & DLL::operator[](int & id)
	{
		int t = 0;
		Node * temp = Head;
		if (id >= _quantity)
		{
			std::cout << "Out of DLL-size" << std::endl;
			
			return *Tail;
		}
		while (t!=id)
		{
			t++;
			temp=temp->next;
		}
		return *temp;
	}

	void DLL::filter_by_grade(Node * NOT_MY_HEAD, Ops & op, char * grade)
	{
		Node * temp = NOT_MY_HEAD;
		int input_grade = atoi(grade);
		
		switch(op)
		{
			case greater:
				while (temp)
				{
					int temp_grade = atoi(temp->getGrade());
					
					if (temp_grade > input_grade)
					{
						Node wanted;
						wanted.copy(*temp);
						wanted.print();
						cpush(wanted);
					}
					temp=temp->next;
				}
				break;
			case less:
				while (temp)
				{	
					int temp_grade = atoi(temp->getGrade());

					if (temp_grade < input_grade)
					{
						Node wanted;
						wanted.copy(*temp);
						wanted.print();
						cpush(wanted);
					}
					temp=temp->next;
				}
				break;
			case greater_or_equal:
				while (temp)
				{
					int temp_grade = atoi(temp->getGrade());

					if (temp_grade >= input_grade)
					{
						Node wanted;
						wanted.copy(*temp);
						wanted.print();
						cpush(wanted);
					}
					temp=temp->next;
				}		
				break;
			case less_or_equal:
				while (temp)
				{
					int temp_grade = atoi(temp->getGrade());

					if (temp_grade <= input_grade)
					{
						Node wanted;
						wanted.copy(*temp);
						wanted.print();
						cpush(wanted);
					}
					temp=temp->next;
				}
				break;
			case equal:
				while (temp)
				{
					int temp_grade = atoi(temp->getGrade());

					if (temp_grade == input_grade)
					{
						Node wanted;
						wanted.copy(*temp);
						wanted.print();
						cpush(wanted);
					}
					temp=temp->next;
				}
				break;
			default:
				std::cout << "void filter_by_grade() - error" << std::endl;
				break;
		}
	}

	DLL DLL::operator>(int & grade)
	{
		Node * temp = Head;
		DLL fil_dll;
		while (temp)
		{
			int temp_grade = atoi(temp->getGrade());	
			if (temp_grade > grade)
			{
				Node wanted;
				wanted=*temp;
				fil_dll.cpush(wanted);
			}
			temp=temp->next;
		}
		return fil_dll;
	}

	DLL DLL::operator<(int & grade)
	{
		Node * temp = Head;
		DLL fil_dll;
		while (temp)
		{
			int temp_grade = atoi(temp->getGrade());	
			if (temp_grade < grade)
			{
				Node wanted;
				wanted=*temp;
				fil_dll.cpush(wanted);
			}
			temp=temp->next;
		}
		return fil_dll;
	}

	DLL DLL::operator==(int & grade)
	{
		Node * temp = Head;
		DLL fil_dll;
		while (temp)
		{
			int temp_grade = atoi(temp->getGrade());	
			if (temp_grade == grade)
			{
				Node wanted;
				wanted=*temp;
				fil_dll.cpush(wanted);
			}
			temp=temp->next;
		}
		return fil_dll;
	}

	void DLL::search_by_last_name(Node * NOT_MY_HEAD, char * lastName)
	{
		Node * temp = NOT_MY_HEAD;
			
		while (temp)
		{
			if (!Compare(temp->getLastName(), lastName))
			{
				Node wanted;
				wanted.copy(*temp);
				wanted.print();
				cpush(wanted);
			}		
			temp=temp->next;
		}
	}

	DLL::DLL():Head(0),Tail(0),_quantity(0){};

	DLL::DLL(int & quantity)
	{
		Tail=Head=0;
		_quantity=0;
		for (int i = 0; i<quantity; i++)
		{
			Node * temp = new Node;
			temp->setLastName();
			temp->setName();
			temp->setSex();
			temp->setGrade();
			temp->setBirthday();
			temp->setAddress();
			this->push(*temp);
		}
	}

	int DLL::getQuantity(){return _quantity;}

	void DLL::load()
	{
		char * line = new char[300];
		std::ifstream in ("input.txt");
		Tail=Head=0;
		_quantity=0;

		// Loading
		
		if (in.is_open())
		{
			while(in.getline(line, 300))
			{
				Node * temp=new Node;
				std::stringstream iss(line);

				char * lastName = new char[50];
				char * name = new char[50];
				char * sex = new char[50];
				char * grade = new char[50];
				char * birthday = new char[50];
				char * address = new char[50];

				iss >> lastName;
				iss >> name;
				iss >> sex;
				iss >> grade;
				iss >> birthday;
				iss >> address;

				temp->setLastName(lastName);
				temp->setName(name);
				temp->setSex(sex);
				temp->setGrade(grade);
				temp->setBirthday(birthday);
				temp->setAddress(address);

				this->push(*temp);
			}
		}
		in.close();
	}

	void DLL::save()
	{
		if (_quantity > 0)
		{
			std::ofstream fout;
			Node * temp=Head;
			fout.open("output.txt");
			while(temp)
			{
				fout << temp->getLastName() <<\
				" " << temp->getName() <<\
				" " << temp->getSex() <<\
				" " << temp->getGrade() <<\
				" " << temp->getBirthday() <<\
				" " << temp->getAddress() <<\
				std::endl;
				temp=temp->next;
			}
			fout.close();
		}
		else
		{
			std::cout << "DLL::save - Error. DLL is empty" <<\
			std::endl;
		}
	}

	std::ostream& operator<<(std::ostream& os, const DLL&){}
	
	std::istream& operator>>(std::istream& is, DLL&){}

	void DLL::change(int & number, Options & option)
	{
		// 0<number<=_quantity
		Node * temp;
		if (number == 1) temp = Head;
		else if (number == _quantity) temp = Tail;
		else
		{
			temp=Head;
			for (int i = 1; i<number; i++)
			{
				temp=temp->next;
			}
		}
		switch(option)
		{
			case item:
				if (temp!=Head && temp!=Tail)
				{	
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					temp->next=0;
					temp->prev=0;
				}
				else if (temp==Head && temp!=Tail)
				{
					Head = temp->next;
					Head->prev = 0;
					temp->next = 0;
				}
				else if (temp!=Head && temp==Tail)
				{
					Tail = temp->prev;
					Tail->next = 0;
					temp->prev = 0;
				}
				else if (temp==Head && temp==Tail)
				{
					Head = Tail = 0;
				}
				
				temp->setLastName();
				temp->setName();
				temp->setSex();
				temp->setGrade();
				temp->setBirthday();
				temp->setAddress();

				push(*(temp));
				break;
			case lastName:
				if (temp!=Head && temp!=Tail)
				{	
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					temp->next=0;
					temp->prev=0;
				}
				else if (temp==Head && temp!=Tail)
				{
					Head = temp->next;
					Head->prev = 0;
					temp->next = 0;
				}
				else if (temp!=Head && temp==Tail)
				{
					Tail = temp->prev;
					Tail->next = 0;
					temp->prev = 0;
				}
				else if (temp==Head && temp==Tail)
				{
					Head = Tail = 0;
				}

				temp->setLastName();
				
				push(*(temp));
				break;
			case name:
				temp->setName();
				break;
			case sex:
				temp->setSex();
				break;
			case grade:
				temp->setGrade();
				break;
			case birthday:
				temp->setBirthday();
				break;
			case address:
				temp->setAddress();
				break;
			default:
				std::cout << "void DLL::change: error" << std::endl;
				break;
		}		
	}

	void DLL::cpush(Node & newStudent)
	{
		_quantity++;
		std::cout << "Pushing new item(copy)" << std::endl;
		Node * ptemp = new Node;
		ptemp->copy(newStudent);
		if (!ptemp->next) ptemp->next = 0; 
		if (Head)
		{
			Node * bogie = Head;
			
			while(Compare(*ptemp, *bogie)>=0 && bogie!=Tail)
			{
				bogie=bogie->next;	
			}

			if (bogie==Tail && Compare(*ptemp, *bogie)>=0)
			{
				ptemp->prev=Tail;
				Tail->next=ptemp;
				Tail=ptemp;
			}
			else if (bogie==Head && Compare(*ptemp, *bogie)<0)
			{
				ptemp->next=Head;
				ptemp->prev=0;
				Head->prev=ptemp;
				Head=ptemp;
			}
			else if (bogie!=Head && Compare(*ptemp, *bogie)<0)
			{
				ptemp->prev=bogie->prev;
				ptemp->next=bogie;
				bogie->prev=ptemp;
				ptemp->prev->next=ptemp;
			}
			else if (bogie==Head && Compare(*ptemp, *bogie)>=0)
			{
				// это случай, в котором начальный список состоит из одного элемента
				ptemp->prev=Head;
				Head->next=ptemp;
				Tail=ptemp;
			}
			else if (Compare(*ptemp, *bogie)<0 && bogie!=Head && bogie!=Tail)
			{
				ptemp->next=bogie;
				ptemp->prev=bogie->prev;
				bogie->prev=ptemp;
				ptemp->prev->next=ptemp;
			}
			else
			{
				std::cout << "Abnormal result" << std::endl;
			}
		}
		else
		{
			// начальный список пуст
			if (!ptemp->prev) ptemp->prev=0;
			Head=Tail=ptemp;
		}
		Head->prev = NULL;
		Tail->next = NULL;
	}


	void DLL::push(Node & temp)
	{
		_quantity++;
		std::cout << "Pushing new item" << std::endl;
		Node * ptemp = &temp;
		if (!ptemp->next) ptemp->next = 0; 
		if (Head)
		{
			Node * bogie = Head;
			
			while(Compare(*ptemp, *bogie)>=0 && bogie!=Tail)
			{
				bogie=bogie->next;	
			}

			if (bogie==Tail && Compare(*ptemp, *bogie)>=0)
			{
				ptemp->prev=Tail;
				Tail->next=ptemp;
				Tail=ptemp;
			}
			else if (bogie==Head && Compare(*ptemp, *bogie)<0)
			{
				ptemp->next=Head;
				ptemp->prev=0;
				Head->prev=ptemp;
				Head=ptemp;
			}
			else if (bogie!=Head && Compare(*ptemp, *bogie)<0)
			{
				ptemp->prev=bogie->prev;
				ptemp->next=bogie;
				bogie->prev=ptemp;
				ptemp->prev->next=ptemp;
			}
			else if (bogie==Head && Compare(*ptemp, *bogie)>=0)
			{
				// это случай, в котором начальный список состоит из одного элемента
				ptemp->prev=Head;
				Head->next=ptemp;
				Tail=ptemp;
			}
			else if (Compare(*ptemp, *bogie)<0 && bogie!=Head && bogie!=Tail)
			{
				ptemp->next=bogie;
				ptemp->prev=bogie->prev;
				bogie->prev=ptemp;
				ptemp->prev->next=ptemp;
			}
			else
			{
				std::cout << "Abnormal result" << std::endl;
			}
		}
		else
		{
			// начальный список пуст
			if (!ptemp->prev) ptemp->prev=0;
			Head=Tail=ptemp;
		}
		Head->prev = NULL;
		Tail->next = NULL;
	}

	void DLL::print()
	{
		Node * temp = Head;
		while(temp)
		{
			temp->print();
			temp=temp->next;
		}
	}

	void DLL::remove(Ords & ord)
	{
		_quantity--;
		if (ord==first && Head!=Tail)
		{
			Node * temp = Head;
			Head = Head->next;
			Head->prev = 0;
			temp->next = 0;
			delete temp;
		}
		else if (ord==last && Head!=Tail)
		{
			Node * temp = Tail;
			Tail = Tail->prev;
			Tail->next=0;
			temp->prev = 0;
			delete temp;
		}
		else if ((ord == last || ord == first) && Head==Tail)
		{
			delete Head;
			Head=0;
			Tail=0;
		}
		else
		{
			std::cout << "error" << std::endl;
		}
	}

	void DLL::remove(int & number)
	{
		// 0<number<=_quantity
		Node * temp = Head;
		int i=1;
		_quantity--;
		while (i<number && temp!=Tail)
		{
			temp=temp->next;
			i++;
		}
		if (temp != Head && temp !=Tail)
		{
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			temp->next=0;
			temp->prev=0;
			delete temp;
		}
		else if (temp == Head && temp != Tail)
		{
			Head=temp->next;
			Head->prev=0;
			temp->next=0;
			delete temp;
		}
		else if (temp == Tail && temp != Head)
		{
			Tail=temp->prev;
			Tail->next=0;
			temp->prev=0;
			delete temp;
		}
		else if (temp == Tail && temp == Head)
		{
			delete temp;
			Head=Tail=temp=0;
		}
	}

	DLL::~DLL()
	{
		std::cout << "DLL destructor is working" << std::endl;
		while(Head && _quantity!=0)
		{
			Tail=Head->next;
			delete Head;
			Head=Tail;
		}
		std::cout << " I'm ready!" << std::endl;
	}	
}
