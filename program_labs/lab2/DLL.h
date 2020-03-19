#ifndef DLL_H
#define DLL_H

#include <iostream>

namespace var3
{
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
			void set();
			// print-метод
			void print();
			// Copy
			void copy(Node & origin);
			void operator=(Node & origin);
			// ==
			bool operator==(Node & nodeB);
			// >>,<<
			friend std::ostream& operator<<(std::ostream& os, const Node&);
			friend std::istream& operator>>(std::istream& is, Node&);
			// конструктор		
			Node (char *& lastName, char *& name,\
				 char *& sex, char *& grade,\
				 char *& birthday, char *& address);
			Node();
			~Node();
	};

	int mystrcmp(const char * a, const char * b);

	int Compare(Node & Node1, Node & Node2);

	int Compare (const char * str1, const char * str2);

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
			void operator=(DLL & origin);
			//+,-
			void operator+(Node & nodeB);
			void operator-(Node & nodeB);
			friend void operator+(Node & nodeA,DLL & dllB);
			friend void operator-(Node & nodeA,DLL & dllB);
			Node & operator[](int & id);
			void load();
			void save();
			friend std::ostream& operator<<(std::ostream& os, const DLL&);
			friend std::istream& operator>>(std::istream& is, DLL&);	
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
			DLL operator>(int & grade);
			DLL operator<(int & grade);
			DLL operator==(int & grade);
			//деструктор
			~DLL();
	};	
}

#endif
