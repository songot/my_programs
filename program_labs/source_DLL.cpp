#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <stdlib.h> /* atoi */
#include <DLL.h>

class Node
{
	private:
		//Student *_data;
		char * _lastName;
		char * _name; 
		char * _sex;
		char * _grade;
		char * _birthday; 
		char * _address;	
	public:
		Node * next;
		Node * prev;
		//Node();
		//Node(Student & data);
		//int Compare(Node * & Node1, Node * & Node2);
		//void sort(const Node * list, int & quantity);
		char * getLastName();
		char * getName();
		char * getSex();
		char * getGrade();
		char * getBirthday();
		char * getAddress();
		void setLastName(char * lastName);
		void setName(char * name);	
		void setSex(char * sex);
		void setGrade(char * grade);	
		void setBirthday(char * birthday);	
		void setAddress(char * address);
		void setLastName();
		void setName();
		void setSex();
		void setGrade();
		void setBirthday();
		void setAddress();
		// print-метод
		void print();
		// Copy
		void copy(Node & origin);
		// конструктор		
		Node (char *& lastName, char *& name,\
			 char *& sex, char *& grade,\
			 char *& birthday, char *& address);
		Node();
		~Node();
};


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

int Compare (char * str1, char * str2)
{
	const char * lastName1 = str1;
	const char * lastName2 = str2;
	return mystrcmp(lastName1, lastName2);
}

enum Options 
{
	item,
	lastName,
	name,
	sex,
	grade,
	birthday,
	address
};

enum Ords
{
	first,
	last
};

enum Ops
{
	greater,
	less,
	greater_or_equal,
	less_or_equal,
	equal
};

class DLL
{
	private:
		int _quantity;
		Node * Head;
		Node * Tail;
	public:
		// создание пустого списка
		DLL();
		DLL (int & quantity);
		int getQuantity();
		Node * getHead();
		Node * getTail();
		void load();
		void save();	
		// изменение элемента
		void change(int & number,  Options & option);
		// добавление элемента
		void push(Node & newStudent);
		// добавление элемента (копирование)
		void cpush(Node & newStudent);
		// печать DLL
		void print();
		// удаление элемента из списка
		void remove (Ords & ord);
		void remove(int & number);
		// поиск по фамилии
		void search_by_last_name(Node * NOT_MY_HEAD, char * lastName);
		// фильтр по классу
		void filter_by_grade(Node * NOT_MY_HEAD, Ops & op, char * grade);
		//деструктор
		~DLL();
};

Node * DLL::getHead(){return Head;}
Node * DLL::getTail(){return Tail;}

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


int main ()
{	
	/*
	int n=0;	

	std::cin >> n;
	
	DLL MyClass(n);

	if (MyClass.getQuantity()>0) MyClass.print();
	else std::cout << "DLL is empty" << std::endl;
	
	int number = 0;

	std::cin >> number;
	MyClass.remove(number);
	
	if (MyClass.getQuantity()>0) MyClass.print();
	else std::cout << "DLL is empty" << std::endl;
	
	int t = 1;
	Options option = item;

	if (MyClass.getQuantity()>0) MyClass.change(t, option);
	else std::cout << "DLL is empty" << std::endl;

	if (MyClass.getQuantity()>0) MyClass.print();
	else std::cout << "DLL is empty" << std::endl;
	*/

	DLL MyClass;
	DLL Re;

	Ops op = greater_or_equal;

	MyClass.load();

	char * grade = new char[50];

	std::cin >> grade;
	
	Node * MyClass_Head = MyClass.getHead();

	//Re.search_by_last_name(MyClass_Head, lastName);
	
	Re.filter_by_grade(MyClass_Head, op, grade);

	//Re.print();
	//std::cout << "HERE WE GO" << std::endl;

	//Node temp(*(MyClass.getHead()));

	//temp.print();

	Re.save();
	
	delete [] grade;
	//char str1[]="Hello Geeks!"; 
	//char str2[] = "GeeksforGeeks"; 
	//char * str3 = new char[40]; 
	//char * str4 = new char[40]; 
	//char str5[] = "GfG";
	//std::cout << "str4 input: "; 
      	//std::cin >> str4;
	//strcpy(str2, str1);
	//strcpy(str3, str4); 
	//std::cout << "pointer on str3: " << &str3 << std::endl;
	//std::cout << "pointer on str4: " << &str4 << std::endl;
	//strcpy(str4, str5); 
	//printf ("str1: %s\nstr2: %s\nstr3: %s\nstr4: %s\n", str1, str2, str3, str4); 

	/*Node * ftry = new Node;
	ftry->setLastName();
	ftry->setName();
	ftry->setSex();
	ftry->setGrade();
	ftry->setBirthday();
	ftry->setAddress();
	
	Node * newtry = new Node;
	
	newtry->copy(*ftry);
	delete ftry;
	
	MyClass.cpush(*newtry);
	delete newtry;
	MyClass.print();*/
	//newtry.print();

	//delete newtry;
	//newtry.copy(ftry);
	
	//newtry.print();




























	return 0;
}
