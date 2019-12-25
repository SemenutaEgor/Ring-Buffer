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
	//конструктор
	TQueue() {
		pFirst = pLast = NULL;
	}
	//деструктор
	~TQueue() {
		TNode<T> *tmp = pFirst;
		while (pFirst != NULL) {
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
		pLast = NULL;
	}
	//конструктор копирования
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
	//узнать размер
	int GetSize() {
		TNode<T> *p = pFirst;
		int k = 0;
		while (p != NULL) {
			k++;
			p = p->pNext;
		}
		return k;
	}
	//начало
	int GetHead() {
		return 0;
	}
	//максимальный размер
	int GetMaxSize() {
		return 10000;
	}
	//оператор присваивания
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
	//проверить на пустоту
	bool IsEmpty()const {
		return (pFirst == NULL);
	}
	//проверить на полноту
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
	//добавить элемент
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
	//извлчь элемент
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
	//посмотреть, что в начале
	T Front() {
		if (IsEmpty())
			throw - 1;
		else
			return pFirst->val;
	}
	//посмотреть, что в конце
	T Back() {
		if (IsEmpty())
			throw - 1;
		else
			return pLast->val;
	}
	//очистить очередь
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
