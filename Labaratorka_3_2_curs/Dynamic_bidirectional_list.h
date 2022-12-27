#include<iostream>
using namespace std;

template <class T>
class DynamicList
{
private:
	struct Node
	{
		Item data;	// Содержимое узла
		Node* prev;	// Указатель на предыдущий узел
		Node* next;	// Указатель на следующий узел
	};
	
	Node* first;	// Указатель на первый узел списка
	Node* last;	// Указатель на последний узел списка
	int size;

public:
	DynamicList();
	DynamicList(T);
	DynamicList(const DynamicList&);
	~DynamicList();
	typename DynamicList<T>::Node& findElement(int pos, int count) const;
	DynamicList<T>& Add(const T& item, int pos);
	Node& findElement(int pos, int count = up)
	DynamicList& Delete(int pos, int range = 1);
	DynamicList& Delete();
};


template<class T>
DynamicList<T>::DynamicList()
{
	size = 0;
	first = nullptr;
	last = nullptr;
}

template<class T>
DynamicList<T>::DynamicList(T item)
{
	size = 1;
	first = last = new DynamicList<T>::Node;
	first->prev = nullptr;
	first->next = nullptr;
	first->item = item;
}

template<class T>
typename DynamicList<T>::Node& DynamicList<T>::findElement(int pos, int count) const
{

	DynamicList<T>::Node* current;

	if (count == up)
	{
		current = first;
		for (int k = 1; k <= pos; k++)
			current = current->next;
	}
	else
	{
		current = last;
		for (int k = size - 2; k >= pos; k--)
			current = current->prev;
	}

	return *current;
}


template<class T>
DynamicList<T>& DynamicList<T>::Add(const T& item, int pos)
{
	DynamicList<T>::Node* temp = new DynamicList<T>::Node;
	temp->item = item;
	if (pos >= size)
	{
		last = temp;
		temp->next = nullptr;
	}
	else	
	{
		temp->next = &findElement(pos);
		(temp->next)->prev = temp;
	}

	if (pos == 0)
	{
		temp->prev = nullptr;
		first = temp;
	}
	else
		if (size != 0)
		{
			temp->prev = &findElement(pos - 1);
			temp->prev->next = temp;
		}

	size++;	
	return *this;
}

template<class T>
DynamicList<T>::DynamicList(const DynamicList<T>& list)
{
	first = last = nullptr;
	size = 0;

	for (int i = 0; i < list.size; i++)
	{
		Add(ll[i], i);
	}

}

template<class T>
DynamicList<T>& DynamicList<T>::Delete(int pos, int range)
{
	if (pos < 0 || pos >= size)
		std::cout << "Выход за границы массива";
	int tempSize = size;
	for (int i = pos; i < pos + range && i < size; i++, tempSize--)
		delete& findElement(i, down);
	if (tempSize == 0)
		first = last = nullptr;
	else
	{
		if (pos == 0)	
		{
			first = &findElement(pos + range, down);
			first->prev = nullptr;
		}
		else
			if (pos + range >= size)
			{
				last = &findElement(pos - 1);
				last->next = nullptr;
			}
			else				
			{
				findElement(pos - 1).next = &findElement(pos + range, down);
				findElement(pos + range, down).prev = &findElement(pos - 1);
			}

	}
	size = tempSize;

	return *this;
}

template<class T>
DynamicList<T>& DynamicList<T>::Delete()
{
	return Delete(size - 1);
}

template<class T>
DynamicList<T>::~DynamicList()
{
	Delete(0, size);
}