#include<iostream>
using namespace std;


template <class T>
class DynamicList
{
private:
	struct Elem
	{
		T data = 0;
		Elem* next, * prev;
	};

	Elem* Head, * Tail;
	int Count;

public:
	DynamicList();
	DynamicList(T _data);
	DynamicList(const DynamicList&);
	~DynamicList();
	void AddHead(T _data);
	void AddTail(T _data);
	void Del(T pos = 0);
	void DelAll();
	void Print();
	void operator+(T _data);
	template <class T> friend ostream& operator<<(ostream& _out, DynamicList<T>& _list);
};

template<class T>
DynamicList<T>::DynamicList()
{
	Head = Tail = NULL;
	Count = 0;
}

template<class T>
DynamicList<T>::DynamicList(T _data)
{
	this->AddHead(_data);
}

template<class T>
DynamicList<T>::DynamicList(const DynamicList<T>& list)
{
	Head = Tail = NULL;
	Count = 0;

	Elem* temp = list.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

template<class T>
DynamicList<T>::~DynamicList()
{
	DelAll();
}

template<class T>
void DynamicList<T>::AddHead(T _data)
{
	Elem* temp = new Elem;
	temp->prev = 0;
	temp->data = _data;
	temp->next = Head;
	if (Head != 0)
		Head->prev = temp;
	if (Count == 0)
		Head = Tail = temp;
	else
		Head = temp;

	Count++;
}

template<class T>
void DynamicList<T>::AddTail(T _data)
{
	Elem* temp = new Elem;
	temp->next = 0;
	temp->data = _data;
	temp->prev = Tail;

	if (Tail != 0)
		Tail->next = temp;

	if (Count == 0)
		Head = Tail = temp;
	else
		Tail = temp;

	Count++;
}

template<class T>
void DynamicList<T>::Del(T pos)
{
	if (pos == 0)
	{
		cout << "Input position: ";
		cin >> pos;
	}
	if (pos < 1 || pos > Count)
	{
		cout << "Incorrect position\n";
		return;
	}

	int i = 1;

	Elem* Del = Head;

	while (i < pos)
	{
		Del = Del->next;
		i++;
	}

	Elem* PrevDel = Del->prev;
	Elem* AfterDel = Del->next;

	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;

	delete Del;

	Count--;
}

template<class T>
void DynamicList<T>::DelAll()
{
	while (Count != 0)
		Del(1);
}


template<class T>
void DynamicList<T>::Print()
{
	if (Count != 0)
	{
		Elem* temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )\n";
	}
}

template<class T>
ostream& operator<<(ostream& _out, DynamicList<T>& _list)
{
	DynamicList<T> temp = _list;

	while (temp.Head != NULL)
	{
		_out << temp.Head->data << " ";
		temp.Head = temp.Head->next;
	}

	return  _out;
}

template<class T>
void DynamicList<T>::operator+(T _data)
{
	this->AddTail(_data);
}