#pragma once
#include <iostream>
template <class T>
struct TNode{
	T val;
	TNode *pNext;
};
template <class T>
class TQueue {
	TNode<T> *pFirst, *pLast;
public:
	//�����������
	TQueue() {
		pFirst = pLast = NULL;
	}
	//����������
	~TQueue() {
		TNode<T> *tmp = pFirst;
		while (pFirst != NULL) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
		pLast = NULL;
	}
	//����������� �����������
	TQueue(const TQueue<T>& q) {
		TNode<T> *tmp = q.pFirst;
		if (tmp == NULL)
			pFirst = pLast = tmp;
		while (tmp != NULL) {
			Push(tmp->val);
			tmp = tmp->pNext;
		}
		delete tmp;
	}
	//������ ������
	int GetSize() {
		TNode<T> *p = pFirst;
		int k = 0;
		while (p != NULL) {
			k++;
			p = p->pNext;
		}
		return k;
	}
	//������
	int GetHead() {
		return 0;
	}
	//������������ ������
	int GetMaxSize() {
		return 10000;
	}
	//�������� ������������
	TQueue<T> operator=(const TQueue<T>& q) {
		if (this != &q) {
			if (!IsEmpty())
				Clear();
			else {
				TNode<T> *tmp = q.pFirst;
				if (tmp == NULL)
					pFirst = tmp;
				while (tmp != NULL) {
					Push(tmp->val);
					tmp = tmp->pNext;
				}
				delete tmp;
			}
		}
		return *this;
	}
	//��������� �� �������
	bool IsEmpty()const {
		return (pFirst == NULL);
	}
	//��������� �� �������
	bool IsFull()const {
		TNode<T> *tmp;
		tmp = new TNode<T>;
		if (tmp == NULL)
			return 1;
		else {
			delete tmp;
			return 0;
		}
	}
	//�������� �������
	void Push(T a) {
		if (IsFull())
			throw - 1;
		else {
			TNode<T> *tmp = new TNode<T>;
			tmp->val = a;
			tmp->pNext = NULL;
			if (pLast != NULL) {
				pLast->pNext = tmp;
				pLast = tmp;
			}
			else
				pFirst = pLast = tmp;
		}
	}
	//������ �������
	T Pop() {
		if (IsEmpty())
			throw - 1;
		else{
			T tmp = pFirst->val;
			TNode<T> *p = pFirst;
			pFirst = pFirst->pNext;
			delete p;
			return tmp;
		}
	}
	//����������, ��� � ������
	T Front() {
		if (IsEmpty())
			throw - 1;
		else
			return pFirst->val;
	}
	//����������, ��� � �����
	T Back() {
		if (IsEmpty())
			throw - 1;
		else
			return pLast->val;
	}
	//�������� �������
	void Clear() {
		TNode<T> *tmp = pFirst;
		while (pFirst != NULL){
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
		pLast = NULL;
	}
};
