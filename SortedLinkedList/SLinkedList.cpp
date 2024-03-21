#include "SLinkedList.h"
#include <iostream>
using namespace std;


template<class T>

SLinkedList<T>::SLinkedList()
{
	Head = nullptr;
	Tail = nullptr;
	size = 0;
}
template<class T>

SLinkedList<T>::~SLinkedList()
{
	Node<T>* it1 = Head;
	Node<T>* it2 = Head;
	for (int i = 0;i < size;i++)
	{
		it2 = it2->Next;
		delete it1;
		it1 = it2;
	}
	size = 0;
}
template<class T>

void SLinkedList<T>::insert(T val)
{
	Node<T>* tmp = new Node<T>;
	tmp->value = val;
	tmp->Next = nullptr;
	tmp->Prev = nullptr;
	if (size == 0)
	{
		Head = Tail = tmp;
	}
	else
	{
		Node<T>* it = Head;
		for (int i = 0;i < size;i++,it = it->Next)
		{
			if (it->value > val)
				break;
		}
		if (it != nullptr && it == Head)
		{
			tmp->Next = Head;
			Head->Prev = tmp;
			Head = tmp;
		}
		else if (it != nullptr)
		{
			tmp->Prev = it->Prev;
			tmp->Next = it;
			it->Prev->Next = tmp;
			it->Prev = tmp;
		}
		else
		{
			Tail->Next = tmp;
			tmp->Prev = Tail;
			Tail = tmp;
		}
	}
	size++;
}
template<class T>

T SLinkedList<T>::getMin()
{
	return Head->value;
}

template<class T>

void SLinkedList<T>::merge( SLinkedList<T> & list)
{
	for (Node<T>* it = list.Head;it != nullptr;it = it->Next)
	{
		insert(it->value);
	}
	
}

template<class T>

SLinkedList<T>& SLinkedList<T>::intersection(SLinkedList<T> &list)
{
	SLinkedList<T>* NewList = new SLinkedList<T>;
	SLinkedList<T> tmplist = list.getcopy();
	for (Node<T>* it = Head; it != nullptr; it = it->Next)
	{
		if (tmplist.size > 0)
		{
			for (Node<T>* it2 = tmplist.Head;it2 != nullptr; it2 = it2->Next)
			{
				if (it->value == it2->value)
				{
					(*NewList).insert(it->value);
					tmplist.Delete(it2);
					break;
				}
			}
		}
		else
			break;
	}
	return *NewList;
}

template<class T>
void SLinkedList<T>::Delete(Node<T>* tmp)
{
	if (size == 1)
	{
		Head = nullptr;
		Tail = nullptr;
	}
	else if (tmp == Head)
	{
		Head = tmp->Next;
		Head->Prev = nullptr;
		
	}
	else if (tmp == Tail)
	{
		Tail = tmp->Prev;
		Tail->Next = nullptr;
		
	}
	else
	{
		tmp->Prev->Next = tmp->Next;
		tmp->Next->Prev = tmp->Prev;
		
	}
	delete tmp;
	size--;
}

template<class T>


void SLinkedList<T>::printlist()
{
	for (Node<T>* it = Head; it != nullptr;it = it->Next)
	{
		cout << it->value << " ";
	}
	cout << "\n";
}

template<class T>

SLinkedList<T>& SLinkedList<T>::getcopy()
{
	SLinkedList<T>* tmplist = new SLinkedList<T>;
	for (Node<T>* it = Head;it != nullptr;it = it->Next)
	{
		(*tmplist).insert(it->value);
	}
	return *tmplist;
}
