//#include "stdafx.h" - Для VisualStudio
#include<iostream>

using namespace std;

//объекты этого класса будем хранить в нашем списке
class Data
{
private:
	//непосредственно данные
	int _data;
public:
	//методы для доступа к данным get-set
	int getData() { return _data; }
	void setData(int value) { _data = value; }
	//конструктор
	Data(int value = 0) { _data = value; }
	//но лучше так:
	//Data(int value = 0):_data(value) {cout << "Data constructor"<<endl;}
	void print()
	{
		//вывести содержимое
		cout << "\n"; // или cout << endl;
		cout << this->getData() << endl;//или cout << getData() << endl; или просто cout << _data << endl;	
	}
};

// Реализация списка на массиве
class List
{
protected:
	//список состоит из массива и вспомогательных переменных
	Data * arr;
	//число элементов в списке сейчас
	int count;
	//максимальное число элементов в списке
	int capacity;
public:
	void push(Data D)
	{
		//положить элемент D в список - здесь в конец списка
		if (count<capacity)
		{
			arr[count] = D;
			count++;
		}
	}
	Data pop()
	{
		//извлечь элемент из списка - здесь с начала списка
		if (count > 0)
			return arr[0];
		else
		{
			//что делаем, если в списке ничего нет?			
		}
					
	}
	void print()
	{
		//вывести содержимое списка
		cout << "\n";
		for (int i = 0; i<count; i++)
		{
			cout << arr[i].getData() << "\t";
			//или лучше
			//arr[i].print();
		}
	}
	void print_element(int index)
	{
		//вывести элемент из списка по индексу
		cout << "\n";
		if (index >= 0 && index < count)
			arr[index].print();
		else
			cout << "Wrong index";
	}
	List()
	{
		//конструктор без параметров - по умолчанию создаём список из 10 свободных мест
		cout << "\nList constructor 0";
		arr = new Data[10];
		capacity = 10;
		count = 0;
	}
	List(int Capacity)
	{
		//в этом конструкторе параметр задает объём выделяемой памяти
		cout << "\nList constructor 1";
		arr = new Data[Capacity];
		capacity = Capacity;
		count = 0;
	}

	List(Data* Arr, int Number)
	{
		//создаём список на основе существующего массива - копируем его элементы в список
		cout << "\nList constructor 2";
		arr = new Data[Number];
		capacity = Number;
		count = Number;
		for (int i = 0; i<Number; i++)
		{
			arr[i] = Arr[i];
		}
	}
	List(List& L)
	{
		//конструктор копий
		cout << "\nList copy constructor";
		count = L.count;
		capacity = L.capacity;
		arr = new Data[count];
		for (int i = 0; i<count; i++)
		{
			arr[i] = L[i];
		}
	}
	~List()
	{
		//деструктор
		cout << "\nList destructor is working";
		if (arr != NULL)
			delete[] arr;
		arr = NULL;
		count = 0;
	}
};

int main()
{
	List L(10);
	L.push(Data(1));
	L.push(Data(2));
	L.print();
	Data v = L.pop();
	cout << "\n" << v.getData() << "\n";
	//или
	v.print();
	char c; cin >> c;
    return 0;
}

