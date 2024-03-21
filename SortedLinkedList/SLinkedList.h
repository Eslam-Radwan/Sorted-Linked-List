#pragma once

template<class T>
class Node
{
public:
	T value;
	Node<T>* Next;
	Node<T>* Prev;
};
template<class T>
class SLinkedList
{
public:
	Node<T>* Head;
	Node<T>* Tail;
	int size;
	void insert(T);
	T getMin(void);
	void merge(SLinkedList<T>&);
	SLinkedList<T>& intersection(SLinkedList<T>&);
	void Delete(Node<T>*);
	void printlist(void);
	SLinkedList<T>& getcopy(void);
	SLinkedList();
	~SLinkedList();
};

