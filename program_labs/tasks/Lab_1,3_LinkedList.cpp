//#include "stdafx.h"
#include <iostream>

using namespace std;

class Element
{
	//элемент связного списка
private:
	Element* next;
	double field;
public:
	//доступ к полю *next
	Element * getNext() { return next; }
	void setNext(Element* value) { next = value; }

	//доступ к полю с хранимой информацией field

	double getValue() { return field; }
	void setValue(double value) { field = value; }
};

class LinkedList
{
protected:
	//достаточно хранить только начало
	Element* begin;
	//для удобства храним количество элементов
	int num;
public:
	int Number() {return num;}

	Element* getBegin() { return begin; }

	LinkedList() 
	{
		//конструктор без параметров
		begin = NULL;
		num = 0;
	}
	LinkedList(LinkedList& L) 
	{
		//конструктор копий, доделать копирование
		begin = new Element;
		num = L.Number();
		//не хорошо - здесь просто присваивание, а надо сделать настоящее выделение новой памяти и копирование информации туда
		begin = L.begin;
	}

	virtual void push(double a)
	{
		//положить элемент в конец
		Element* cur = begin;
		if(begin==NULL)
		{
			//ничего в списке нет
			num = 1;
			begin = new Element;
			begin->setValue(a);
			begin->setNext(NULL);
			return;
		}
		//ищем последний элемент - добавить аналогичную рекурсивную процедуру
		while(cur->getNext()!=NULL)
		{
			cur = cur->getNext();
		}
		num ++ ;
		//вставка элемента
		cur->setNext(new Element);
		cur->getNext()->setValue(a);
		cur->getNext()->setNext(NULL);
	}

	virtual void push_r(double a, Element* current=NULL)
	{
		//положить элемент в конец - рекурсивная версия
		
		if (begin == NULL)
		{
			//ничего в списке нет
			num = 1;
			begin = new Element;
			begin->setValue(a);
			begin->setNext(NULL);
			return;
		}
		//ничего не передано в функцию - по умолчанию начинаем с начала списка
		if (current == NULL)
			current = begin;

		//указатель на следующий элемент свободен - цепляем туда новый. Здесь рекурсия закончится 
		if (current->getNext() == NULL)
		{
			current->setNext(new Element);
			current->getNext()->setValue(a);
			current->getNext()->setNext(NULL);
			num++;
			return;
		}

		//мы находимся где-то в списке - ищем последний элемент рекурсивно
		push_r(a, current->getNext());
	}
	virtual double pop()
	{
		//вытащить элемент с конца
		Element* cur = begin;
		Element* prev = NULL;
		//отдельно рассмотрим случай 0/1 элементов
		if(begin==NULL)
		{
			return -1;
		}
		if(num==1)
		{
			double res = begin->getValue();
			num--;
			return res;
		}
		//ищем последний и предпоследний элемент
		while(cur->getNext()!=NULL)
		{
			prev = cur;
			cur = cur->getNext();
		}
		//сохраняем результат
		double res = cur->getValue();
		//предпоследний стал последним
		prev->setNext(NULL);
		//последнего стёрли
		delete cur;
		num--;
		return res;
	}

	

	~LinkedList()
	{
		//деструктор - освобождение памяти
		num = 0;
		Element* cur = begin;
		if(cur!=NULL)
			cur = cur->getNext();
		while(cur!=NULL)
		{
			Element* prev = cur;
			cur = cur->getNext();
			delete prev;
		}
		if(begin!=NULL)
			delete begin;
	}
	Element* operator[](int i)
	{
		//индексация
		if(i<0 || i>num) return NULL;
		int k = 0;
		Element* cur = begin;
		for(k=0;k<i;k++)
		{
			cur = cur->getNext();
		}
		return cur;
	}

	void print()
	{
		//итеративная версия вывода списка 
		Element* cur = begin;
		while (cur != NULL)
		{
			cout << cur->getValue() << "\n";
			cur = cur->getNext();
		}
	}

	void print_r(Element* current = NULL)
	{
		//рекурсивная версия вывода списка 
		if (current == NULL)
			current = begin;
		if (current != NULL)
		{
			cout << current->getValue() << "\n";
			if (current->getNext() != NULL)
				print_r(current->getNext());
		}

	}

	void insert(Element* current, double value)
	{
		//вставка элемента со значением value в список сразу за элементом current
		//используем другую версию insert()
		Element* newElem = new Element;
		newElem->setNext(NULL);
		newElem->setValue(value);
		
		insert(current, newElem);
	}

	void insert(Element* current, Element* newElem)
	{
		//вставка элемента newElem в список сразу за элементом current
		if (current == NULL)
		{
			//ищем последний, если список не пустой
			if (begin == NULL)
				return;

			current = begin;
			while (current->getNext() != NULL)
			{
				current = current->getNext();
			}

			//следующий элемент для вставляемого = следующий элемент для current
			newElem->setNext(current->getNext());
			//новый следующий элемент за current - это newElem
			current->setNext(newElem);
			
			num++;
			return;
		}
		
		//список не пустой, current!=NULL

		//следующий элемент для вставляемого = следующий элемент для current
		newElem->setNext(current->getNext());
		//новый следующий элемент за current - это newElem
		current->setNext(newElem);
		num++;

	}

	void remove(Element* current)
	{
		//удаление элемента
		if (current != NULL)
		{
			//найдём предыдущий
			Element* cur = begin;
			while (cur->getNext() != current)
			{
				cur = cur->getNext();
			}

			//cur - предыдущий элемент, current->next - следующий

			cur->setNext(current->getNext());
			num--;

			//освобождение памяти
			delete current;


		}
	}
};

class List
{
protected:
	//область памяти
	double* ptr;
	//количество элементов на текущий момент
	int num;
	//объём выделенной памяти
	int capacity;
public:
	int Number() {return num;}
	int Capacity() {return capacity;}
	List(int Capacity) 
	{
		//выделяем память под Capacity элементов, заполнено - 0
		capacity = Capacity;
		ptr = new double[capacity];
		num = 0;
	}
	List() 
	{	//по умолчанию выделяем память под 10 элементов
		capacity = 10;
		ptr = new double[capacity];
		num = 0;
	}
	List(List& L) 
	{
		//конструктор копий
		capacity = L.Capacity();
		ptr = new double[capacity];
		num = L.Number();
		for(int i=0;i<num;i++)
		{
			ptr[i] = L[i];
		}
	}
	double& operator[](int i) {return ptr[i];}

	//операции добавления/извлечения элемента переопределяются в потомках
	virtual void push(double a) = 0;
	virtual double pop() = 0;

	~List()
	{
		//деструктор
		if(ptr!=NULL) delete[] ptr;
	}
};

class Stack: public List
{
public:
	Stack():List(){}
	Stack(int Capacity):List(Capacity) {}

	virtual void push(double a)
	{
		if(num<capacity-1)
		{
			ptr[num] = a;
			num++;
		}
	}

	virtual double pop()
	{
		if(num==0)
			return -1;
		num--;
		return ptr[num];
	}
};

class Queue: public List
{
public:
	Queue():List(){}
	Queue(int Capacity):List(Capacity) {}

	virtual void push(double a)
	{
		if(num<capacity-1)
		{
			ptr[num] = a;
			num++;
		}
	}

	virtual double pop()
	{
		if(num==0)
			return -1;
		double res = ptr[0];
		for(int i=1;i<num;i++)
		{ptr[i-1] = ptr[i];}
		num--;
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	if(1)
	{
		LinkedList L;
		L.push_r(1);L.push_r(2);L.push_r(3);
		int i=0;
		//for(i=0;i<3;i++) cout<<" "<<L[i]->field;
		L.print_r();
		L.remove(L.getBegin()->getNext());
		L.insert(L.getBegin(), 5);
		L.print_r();
		cout<<"\nPop: "<<L.pop()<<"\n ";
		for(i=0;i<L.Number();i++) cout<<" "<<L[i]->getValue();
		cout<<"\n\n";
		Stack S(5);
		S.push(1);S.push(2);S.push(3);
		/*cout<<"\n"<<S[0]<<" "<<S[1]<<" "<<S[2];
		cout<<"\n"<<S.pop();
		cout<<"\n"<<S[0]<<" "<<S[1];*/

		Queue Q(5);
		Q.push(1);Q.push(2);Q.push(3);
		/*cout<<"\n"<<Q[0]<<" "<<Q[1]<<" "<<Q[2];
		cout<<"\n"<<Q.pop();
		cout<<"\n"<<Q[0]<<" "<<Q[1];*/

		List* p = &S;
		cout<<"\n"<<p->pop();

		p = &Q;
		cout<<"\n"<<p->pop();
	}

	/*LinkedList L;
	L.push(1); L.push(2);L.push(3); L.pop();
	int i;
	for(i=0;i<L.Number();i++) cout<<L[i]->field<<"\n";*/
	char c; cin>>c;
	return 0;
}

