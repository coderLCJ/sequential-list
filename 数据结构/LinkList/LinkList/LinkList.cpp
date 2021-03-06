// LinkList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<ctime>
using namespace std;

namespace ds
{
	struct LinkListNode
	{
		int key;
		LinkListNode *next;
	};

	class LinkList
	{
	private:
		LinkListNode * head;
	public:
		LinkList();
		void insertSort(int);
		void merge(LinkList &);
		void print();
	};

	LinkList::LinkList()
	{
		head = new LinkListNode;
		head->next = nullptr;
	}

	void LinkList::insertSort(int tmpKey)
	{
		LinkListNode *p = new LinkListNode;
		p->key = tmpKey;
		p->next = nullptr;
		LinkListNode *pre = nullptr, *cur = head->next;
		while (cur != nullptr)
		{
			if (cur->key >= tmpKey)
				break;
			pre = cur;
			cur = cur->next;
		}
		if (nullptr == pre)
		{
			p->next = head->next;
			head->next = p;
		}
		else
		{
			pre->next = p;
			p->next = cur;
		}
	}

	void LinkList::merge(LinkList &tempSList)
	{
		LinkListNode *p, *q, *com;
		com = head;
		p = head->next;
		q = tempSList.head->next;
		while (p != nullptr && q != nullptr)
		{
			if (p->key<q->key)
			{
				com->next = p;
				p = p->next;
			}
			else
			{
				com->next = q;
				q = q->next;
			}
			com = com->next;
		}
		if (q != nullptr)
			com->next = q;
		if (p != nullptr)
			com->next = p;
	}

	void LinkList::print()
	{
		LinkListNode *p = head->next;
		while (p != nullptr)
		{
			cout << p->key << "  ";
			p = p->next;
		}
		cout << endl;
	}

	int mergeSort(LinkList tArray[], int tLeft, int tRight)
	{
		if (tLeft == tRight)
			return tLeft;
		int mid = (tLeft + tRight) >> 1;
		int l = mergeSort(tArray, tLeft, mid);
		int r = mergeSort(tArray, mid + 1, tRight);
		tArray[l].merge(tArray[r]);
		return l;
	}
}


int main()
{
	int n = 10, i, j = 0;
	ds::LinkList *mySList = new ds::LinkList[n];
	while (j<n)
	{
		i = 0;
		while (i++<n)
		{
			mySList[j].insertSort(rand() % 100);
		}
		mySList[j].print();
		j++;
	}
	mergeSort(mySList, 0, 9);
	mySList[0].print();
	system("PAUSE");
	return 0;
}