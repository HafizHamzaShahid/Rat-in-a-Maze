#pragma once
#include<iostream>
#include"point.h"
#include<time.h>
#include"myconsole.h"
#include"mygraphics.h"
using namespace std;

template<class T>
class Link_List
{
public:
	//////////////////////////Node//////////////////////////////
	class Node
	{
	public:
		friend class Link_List<T>;
		T p;
		Node* next;
		Node()
		{
			next = nullptr;
			p.set(0, 0);
		}
		Node(T a)
		{
			p.set(a.getX(), a.getY());
			next = nullptr;
		}
	};
	Link_List()
	{
		head = nullptr;
		tail = nullptr;
	}
	~Link_List()
	{
		delete head;
		delete tail;
	}
	///////////////////////////////Stack_Base/////////////////////////////////
	class Stack_Base
	{
	private:
		Link_List<T> l1;
		int count;
		int size;
	public:
		Stack_Base()
		{
			count = 0;
			size = 0;
		}
		Stack_Base(int n)
		{
			size = n;
		}
		bool isEmpty()
		{
			if (l1.head == nullptr)
			{
				return true;
			}
			else
				return false;
		}
		bool isFull()
		{
			if (count == size)
			{
				return true;
			}
			else
				return false;
		}
		void Push(T a)
		{
			Node* n = new Node(a);
			if (l1.head == nullptr)
			{
				l1.head = n;
				count++;
			}
			else if (!isFull())
			{
				n->next = l1.head;
				l1.head = n;
				count++;
			}
		}
		T pop()
		{
			if (isEmpty())
			{
				Node* temp = l1.head;
				Node* tmp = l1.head;
				point po(tmp->p.getX(), tmp->p.getY());
				l1.head = l1.head->next;
				delete temp;

				return po;
			}

		}
		T S_Top()
		{
			return l1.head->p;
		}

	};
	///////////////////////////////Quee_Base////////////////////////////////
	class Quee_Base
	{
	private:
		Link_List<T> l2;
		int count;
		int size;
	public:
		Quee_Base()
		{
			count = 0;
			size = 0;
		}
		Quee_Base(int n)
		{
			size = n;
		}
		bool isEmpty()
		{
			if (l2.head == l2.tail)
			{
				return true;
			}
			else
				return false;
		}
		bool isFull()
		{
			if (count == size)
			{
				return true;
			}
			else
				return false;
		}
		void Enquee(T a)
		{
			Node* n = new Node(a);
			if (l2.head == nullptr)
			{
				l2.head = n;
				l2.tail = n;
				count++;
			}
			else if (!isFull())
			{
				l2.tail->next = n;
				l2.tail = n;
				count++;
			}
		}
		T Dequee()
		{
			if (isEmpty())
			{
				Node* temp = l2.head;
				Node* tmp = l2.head;
				point po(tmp->p.getX(), tmp->p.getY());
				l2.head = l2.head->next;
				delete temp;

				return po;
			}
		}
		
		T Q_Top()
		{
			return l2.head->p;
		}

	};
private:
	Node* head;
	Node* tail;
};



