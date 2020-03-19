#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

class Student
{
	private:
		// данные
		char * _lastName;
		char * _name; 
		char * _sex;
		char * _grade;
		char * _birthday; 
		char * _address;
	public:
		// поиск по фамилии
		//void search_by_last_name    (char *_lastName);
		// фильтр по классу
		//void filter_by_grade        (char *_grade);
		// методы для доступа к данным get-set
		char * getLastName	();
		char * getName		();
		char * getSex		();
		char * getGrade		();
		char * getBirthday	();
		char * getAddress	();
		void setLastName	(char * lastName);
		void setName		(char * name);	
		void setSex		(char * sex);
		void setGrade		(char * grade);	
		void setBirthday	(char * birthday);	
		void setAddress		(char * address);
		void setLastName();
		void setName();
		void setSex();
		void setGrade();
		void setBirthday();
		void setAddress();
		// print-метод
		void print		();
		// конструктор		
		Student (char *& lastName, char *& name,\
			 char *& sex,      char *& grade,\
			 char *& birthday, char *& address);
		// пустой конструктор
		Student();
		// деструктор
		~Student();
};


char * Student::getLastName	()	
{	return _lastName;	}
char * Student::getName		()	
{	return _name;		}
char * Student::getSex		()	
{	return _sex;		}
char * Student::getGrade	()	
{	return _grade;		}
char * Student::getBirthday	()	
{	return _birthday;	}
char * Student::getAddress	()	
{	return _address;	}

void Student::setLastName	(	char * lastName	)	
{	_lastName	=	lastName;	}
void Student::setName		(	char * name	)	
{	_name		=	name;		}
void Student::setSex		(	char * sex	)	
{	_sex		=	sex;		}
void Student::setGrade		(	char * grade	)	
{	_grade		=	grade;		}
void Student::setBirthday	(	char * birthday	)	
{	_birthday	= 	birthday;	}
void Student::setAddress	(	char * address	)	
{	_address	=	address;	}

void Student::setLastName()
{
	_lastName = new char[50];
	std::cin >> _lastName;
}
void Student::setName()
{
	_name = new char[50];
	std::cin >> _name;

}
void Student::setSex()
{
	_sex = new char[50];
	std::cin >> _sex;

}
void Student::setGrade()
{
	_grade = new char[50];
	std::cin >> _grade;

}
void Student::setBirthday()
{
	_birthday = new char[50];
	std::cin >> _birthday;
}
void Student::setAddress()
{
	_address = new char[50];
	std::cin >> _address;

}
void Student::print()
{
	std::cout << _lastName << \
	      " " << _name     << \
	      " " << _sex      << \
	      " " << _grade    << \
	      " " << _birthday << \
	      " " << _address  << \
	std::endl;
}

Student::Student(char *& lastName, char *& name,\
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

Student::Student(): _lastName(0), _name(0), _sex(0),\
			    _grade(0), _birthday(0),\
					 _address(0){};

Student::~Student()
{
	std::cout << "Student destructor is working" << std::endl;
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



class Node
{
	public:
		Student *_data;
		Node * next;
		Node * prev;
		//Node();
		//Node(Student & data);
		//int Compare(Node * & Node1, Node * & Node2);
		//void sort(const Node * list, int & quantity);
		~Node();
};

/*Node::Node()
{
	// конструктор без параметров - по умолчанию создаём
	// пустое поле data
	std::cout << "Node constructor 0" << std::endl;
	Student data;
	_data=data;
	next=0;
	prev=0;
}

Node::Node(Student & data)
{
	std::cout << "Node constructor 1" << std::endl;
	_data=data;
	next=0;
	prev=0;
}*/

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
	const char * lastName1 = Node1._data->getLastName();
	const char * lastName2 = Node2._data->getLastName();
	int i = 0;
	return mystrcmp(lastName1, lastName2);
}

/*void Node::sort(const Node * list, int & quantity)
{
	// calling qsort function to sort the array
	// with the help of Comparator
	qsort(list, quantity, sizeof(const Node *), Compare);
}*/

Node::~Node()
{
	std::cout << "Node destructor is working" << std::endl;
	/*if(next!=0)
	{
		delete next;
		next=0;
	}
	if(prev!=0)
	{
		delete prev;
		prev=0;
	}*/
	//delete next;
	//delete prev;
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

class DLL
{
	private:
		//Node * _list;
		int _quantity;
		//int _capacity;
		Node * Head;
		Node * Tail;
	public:
		// создание пустого списка
		DLL();
		int getQuantity();
		void load();
		void save();
		// создание пустого списка с capacity
		//DLL(int & capacity);
		// создание списка на основе массива
		//DLL(Node * list, int & quantity);
		// добавление элемента
		void change(int & number,  Options & option);
		void push(Student & newStudent);
		void print();
		void remove (char & item);
		void remove(int & number);
		// поиск по фамилии
		//DLL search_by_last_name(char * lastName);
		// фильтр по классу
		//DLL filter_by_grade(char * grade);
		//деструктор
		~DLL();
};

DLL::DLL():Head(0),Tail(0),_quantity(0){};

int DLL::getQuantity(){return _quantity;}

void DLL::load()
{
	char *line = new char[50];
	std::if
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
			
			temp->_data->setLastName();
			temp->_data->setName();
			temp->_data->setSex();
			temp->_data->setGrade();
			temp->_data->setBirthday();
			temp->_data->setAddress();

			push(*(temp->_data));
			delete temp;
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

			temp->_data->setLastName();
			
			push(*(temp->_data));
			delete temp;
			break;
		case name:
			temp->_data->setName();
			break;
		case sex:
			temp->_data->setSex();
			break;
		case grade:
			temp->_data->setGrade();
			break;
		case birthday:
			temp->_data->setBirthday();
			break;
		case address:
			temp->_data->setAddress();
			break;
		default:
			std::cout << "void DLL::change: error" << std::endl;
			break;
	}		
}

void DLL::push(Student & newStudent)
{
	_quantity++;
	std::cout << "Pushing new item" << std::endl;
	Node * temp = new Node;
	temp->next = 0;
	temp->_data = &newStudent; 
	if (Head!=0)
	{
		Node * bogie = Head;
		
		while(Compare(*temp, *bogie)>=0 && bogie!=Tail)
		{
			bogie=bogie->next;	
		}

		if (bogie==Tail && Compare(*temp, *bogie)>=0)
		{
			temp->prev=Tail;
			Tail->next=temp;
			Tail=temp;
		}
		else if (bogie==Head && Compare(*temp, *bogie)<0)
		{
			temp->next=Head;
			temp->prev=0;
			Head->prev=temp;
			Head=temp;
		}
		else if (bogie!=Head && Compare(*temp, *bogie)<0)
		{
			temp->prev=bogie->prev;
			temp->next=bogie;
			bogie->prev=temp;
			temp->prev->next=temp;
		}
		else if (bogie==Head && Compare(*temp, *bogie)>=0)
		{
			// это случай, в котором начальный список состоит из одного элемента
			temp->prev=Head;
			Head->next=temp;
			Tail=temp;
		}
		else if (Compare(*temp, *bogie)<0 && bogie!=Head && bogie!=Tail)
		{
			temp->next=bogie;
			temp->prev=bogie->prev;
			bogie->prev=temp;
			temp->prev->next=temp;
		}
		else
		{
			std::cout << "Abnormal result" << std::endl;
		}
	}
	else
	{
		// начальный список пуст
		temp->prev=0;
		Head=temp;
		Tail=temp;
	}
}

void DLL::print()
{
	Node * temp = Head;
	while(temp!=0)
	{
		temp->_data->print();
		temp=temp->next;
	}
}

void DLL::remove(char & item)
{
	_quantity--;
	if (item=='a' && Head!=Tail)
	{
		Node * temp = Head;
		Head = Head->next;
		Head->prev = 0;
		temp->next = 0;
		delete temp;
	}
	else if (item=='z' && Head!=Tail)
	{
		Node * temp = Tail;
		Tail = Tail->prev;
		Tail->next=0;
		temp->prev = 0;
		delete temp;
	}
	else if ((item == 'z' || item == 'a') && Head==Tail)
	{
		Node * temp = Head;
		delete temp;
	}
	else
	{
		std::cout << "error" << std::endl;
	}
}

void DLL::remove(int & number)
{
	// 0<number<=_quantity
	Node * temp=Head;
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
		temp=0;
		Tail=0;
		Head=0;
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
	int n;
	int number;
	DLL MyClass;
	Student * data;	

	std::cin >> n;
	data = new Student[n];
	
	for (int i = 0; i<n; i++)
	{
		data[i].setLastName();
		data[i].setName();
		data[i].setSex();
		data[i].setGrade();
		data[i].setBirthday();
		data[i].setAddress();
		MyClass.push(data[i]);
	}
	MyClass.print();
				
	std::cin >> number;
	MyClass.remove(number);

	
	
	if (MyClass.getQuantity()>0) MyClass.print();
	else std::cout << "DLL is empty" << std::endl;
	
	int t = 1;
	Options option = name;

	MyClass.change(t, option);

	if (MyClass.getQuantity()>0) MyClass.print();
	else std::cout << "DLL is empty" << std::endl;

	delete[] data;
	return 0;
}
