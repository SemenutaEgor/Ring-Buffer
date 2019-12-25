#pragma once
template <class T>
class TQueue {
	T* mas;
	int MaxSize;
	int Head, Tail;
	int CurrSize;                // Текущий размер очереди
public:
	//Конструктор
	TQueue(int _size = 5) {      
		MaxSize = _size;
		mas = new T[MaxSize];
		Head = 0;
		Tail = -1;
		CurrSize = 0;
	}
	//Деструктор 
	~TQueue() {              
		delete [] mas;
	}
	//Конструктор копирования
	TQueue(const TQueue<T>& q) {
		MaxSize = q.MaxSize;
		Head = q.Head;
		Tail = q.Tail;
		CurrSize = q.CurrSize;
		mas = new T[MaxSize];
		if (Head <= Tail){
			for (int i = Head; i <= Tail; i++)
				mas[i] = q.mas[i];
		}
		else{
			for (int i = Head; i < MaxSize; i++)
							mas[i] = q.mas[i];
			for (int i = 0; i <= Tail; i++)
				mas[i] = q.mas[i];
		}
	}
	//Оператор присваивания
	TQueue<T> operator=(const TQueue<T> &q) {
		if (this != &q){
			if (MaxSize != q.MaxSize){
				MaxSize = q.MaxSize;
				delete [] mas;
				mas = new T[MaxSize];
			}
			Head = q.Head;
			Tail = q.Tail;
			CurrSize = q.CurrSize;
			if (Head <= Tail){
				for (int i = Head; i <= Tail; i++)
					mas[i] = q.mas[i];
			}
			else{
				for (int i = Head; i < MaxSize; i++)
					mas[i] = q.mas[i];
				for (int i = 0; i <= Tail; i++)
					mas[i] = q.mas[i];
			}
		}
		return *this;
	}
	//Проверить пустая или полная
	bool IsEmpty() const {
		return (!CurrSize);
	}
	bool IsFull() const {
		return (CurrSize == MaxSize);
	}
	//Положить в очередь
	void Push(T a) {
		if (IsFull()) throw - 1;
		else {
			if (Tail != MaxSize - 1) {
				Tail++;
				mas[Tail] = a;
			}
			else {
				Tail = 0;
				mas[Tail] = a;
			}
			CurrSize++;
		}
	}
	//Извлечь элемент из очереди
	T Pop() {
		if (IsEmpty()) throw - 1;
		int pos = Head;
		if (Head != MaxSize - 1)
			Head++;
		else
			Head = 0;
		CurrSize--;
		return mas[pos];
	}
	//Посмотреть, кто первый
	 T Front() {
		if (IsEmpty()) throw - 1;
		else
			return mas[Head];
	}
	//Посмотреть, кто последний
	 T Back() {
		if (IsEmpty()) throw - 1;
		else
			return mas[Tail];
	}
	int GetHead(){
		 return Head;
	}
	int GetMaxSize() {
		return MaxSize;
	}
	int GetSize() {
		return CurrSize;
	}
};

