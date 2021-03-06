//#include "stdafx.h"

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class MyException:public exception{
	// собственные поля для информации об ошибке
	string _msg;
public:
	/* тут конструктор/ы */
	
	/*перегрузка функции what*/
	const char* what() const noexcept{
		// тут возвращаем сообщение об ошибке
	}
};
	
class ListException: public MyException{
	/* тут могут быть свои поля, конструкторы, методы */
};
class StackEmptyException: public ListException{
	/* тут могут быть свои поля, конструкторы, методы */
};

class Node{
	Node *_next;	
public:
    Node():_next(nullptr){}    
	Node* getNext(){
		return _next;
	}
	// Здесь определяем виртуальные функции, которые могут быть использованы в классе List
	virtual void print()=0;
};

class Data
{
protected:
	double _data;
	
public:
	Data(double value = 0): _data(value) {}
	double getData() { return _data; }
	void setData(double value) { _data = value; }	
};

class DataNode: public Data, public Node{
public:
    DataNode(double data):Data(data){}
    // или как-то так
    DataNode(double data, Node *next):Data(data), Node(next){}
	virtual void print(){
		cout<<"Data: "<<this->getData();
	}
};

//класс списка оперирует объектами класса Node
class List{
	Node *_head;
	
public:
	List(){}
	void add(Node& data){
		//.. добавление элемента в список
		// метод принимает ссылку типа Node, но в функции main мы передаем тип DataNode
		_head = &data;
	}
	void print(){
		Node *cur = _head;

		while (cur != NULL) {
			cur->print();
			cur = cur->getNext();
		}
		
		cout << endl;
	}
};

// Однонаправленный стек
class Stack: public List{

public:
	Node* pop(){
	
	//Если стек пуст, выбрасываем исключение
	throw StackEmptyException("Сообщение об ошибке");
		
	}
	void push(Node* ){}
}


int main()
{
	List list;
	DataNode d1(3.2);
	list.add(d1);
	list.print();
	
	Stack st;
	st.push(d1);
	try{
		st.pop();
		st.pop();
	}
	catch(StackEmptyException& e){
		// что-то делаем
		cout<<e.what();
	}
	catch(MyException &e){
		// что-то делаем
	}
	catch(std::exception &e){
		// что-то делаем		
	}

	char c; cin >> c;
    return 0;
}

