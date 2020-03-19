//#include "stdafx.h"
#include <iostream>

using namespace std;

class Element
{
	//������� �������� ������
private:
	Element* next;
	double field;
public:
	//������ � ���� *next
	Element * getNext() { return next; }
	void setNext(Element* value) { next = value; }

	//������ � ���� � �������� ����������� field

	double getValue() { return field; }
	void setValue(double value) { field = value; }
};

class LinkedList
{
protected:
	//���������� ������� ������ ������
	Element* begin;
	//��� �������� ������ ���������� ���������
	int num;
public:
	int Number() {return num;}

	Element* getBegin() { return begin; }

	LinkedList() 
	{
		//����������� ��� ����������
		begin = NULL;
		num = 0;
	}
	LinkedList(LinkedList& L) 
	{
		//����������� �����, �������� �����������
		begin = new Element;
		num = L.Number();
		//�� ������ - ����� ������ ������������, � ���� ������� ��������� ��������� ����� ������ � ����������� ���������� ����
		begin = L.begin;
	}

	virtual void push(double a)
	{
		//�������� ������� � �����
		Element* cur = begin;
		if(begin==NULL)
		{
			//������ � ������ ���
			num = 1;
			begin = new Element;
			begin->setValue(a);
			begin->setNext(NULL);
			return;
		}
		//���� ��������� ������� - �������� ����������� ����������� ���������
		while(cur->getNext()!=NULL)
		{
			cur = cur->getNext();
		}
		num ++ ;
		//������� ��������
		cur->setNext(new Element);
		cur->getNext()->setValue(a);
		cur->getNext()->setNext(NULL);
	}

	virtual void push_r(double a, Element* current=NULL)
	{
		//�������� ������� � ����� - ����������� ������
		
		if (begin == NULL)
		{
			//������ � ������ ���
			num = 1;
			begin = new Element;
			begin->setValue(a);
			begin->setNext(NULL);
			return;
		}
		//������ �� �������� � ������� - �� ��������� �������� � ������ ������
		if (current == NULL)
			current = begin;

		//��������� �� ��������� ������� �������� - ������� ���� �����. ����� �������� ���������� 
		if (current->getNext() == NULL)
		{
			current->setNext(new Element);
			current->getNext()->setValue(a);
			current->getNext()->setNext(NULL);
			num++;
			return;
		}

		//�� ��������� ���-�� � ������ - ���� ��������� ������� ����������
		push_r(a, current->getNext());
	}
	virtual double pop()
	{
		//�������� ������� � �����
		Element* cur = begin;
		Element* prev = NULL;
		//�������� ���������� ������ 0/1 ���������
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
		//���� ��������� � ������������� �������
		while(cur->getNext()!=NULL)
		{
			prev = cur;
			cur = cur->getNext();
		}
		//��������� ���������
		double res = cur->getValue();
		//������������� ���� ���������
		prev->setNext(NULL);
		//���������� �����
		delete cur;
		num--;
		return res;
	}

	

	~LinkedList()
	{
		//���������� - ������������ ������
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
		//����������
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
		//����������� ������ ������ ������ 
		Element* cur = begin;
		while (cur != NULL)
		{
			cout << cur->getValue() << "\n";
			cur = cur->getNext();
		}
	}

	void print_r(Element* current = NULL)
	{
		//����������� ������ ������ ������ 
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
		//������� �������� �� ��������� value � ������ ����� �� ��������� current
		//���������� ������ ������ insert()
		Element* newElem = new Element;
		newElem->setNext(NULL);
		newElem->setValue(value);
		
		insert(current, newElem);
	}

	void insert(Element* current, Element* newElem)
	{
		//������� �������� newElem � ������ ����� �� ��������� current
		if (current == NULL)
		{
			//���� ���������, ���� ������ �� ������
			if (begin == NULL)
				return;

			current = begin;
			while (current->getNext() != NULL)
			{
				current = current->getNext();
			}

			//��������� ������� ��� ������������ = ��������� ������� ��� current
			newElem->setNext(current->getNext());
			//����� ��������� ������� �� current - ��� newElem
			current->setNext(newElem);
			
			num++;
			return;
		}
		
		//������ �� ������, current!=NULL

		//��������� ������� ��� ������������ = ��������� ������� ��� current
		newElem->setNext(current->getNext());
		//����� ��������� ������� �� current - ��� newElem
		current->setNext(newElem);
		num++;

	}

	void remove(Element* current)
	{
		//�������� ��������
		if (current != NULL)
		{
			//����� ����������
			Element* cur = begin;
			while (cur->getNext() != current)
			{
				cur = cur->getNext();
			}

			//cur - ���������� �������, current->next - ���������

			cur->setNext(current->getNext());
			num--;

			//������������ ������
			delete current;


		}
	}
};

class List
{
protected:
	//������� ������
	double* ptr;
	//���������� ��������� �� ������� ������
	int num;
	//����� ���������� ������
	int capacity;
public:
	int Number() {return num;}
	int Capacity() {return capacity;}
	List(int Capacity) 
	{
		//�������� ������ ��� Capacity ���������, ��������� - 0
		capacity = Capacity;
		ptr = new double[capacity];
		num = 0;
	}
	List() 
	{	//�� ��������� �������� ������ ��� 10 ���������
		capacity = 10;
		ptr = new double[capacity];
		num = 0;
	}
	List(List& L) 
	{
		//����������� �����
		capacity = L.Capacity();
		ptr = new double[capacity];
		num = L.Number();
		for(int i=0;i<num;i++)
		{
			ptr[i] = L[i];
		}
	}
	double& operator[](int i) {return ptr[i];}

	//�������� ����������/���������� �������� ���������������� � ��������
	virtual void push(double a) = 0;
	virtual double pop() = 0;

	~List()
	{
		//����������
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

