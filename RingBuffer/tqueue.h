//tqueue.h
#ifndef _tqueue_h
#define _tqueue_h

template <class T>
class TQueue {

	T* mas;
	int MaxSize;
	int Head, Tail;
	int CurrSize;
public:

	//constructor
	TQueue(int _size = 5) {
		MaxSize = _size;
		mas = new T[MaxSize];
		Head = 0;
		Tail = -1;
		CurrSize = 0;
	}

	//destructor 
	~TQueue() {
		delete[] mas;
	}

	//copy cinstructor
	TQueue(const TQueue<T>& q) {
		MaxSize = q.MaxSize;
		Head = q.Head;
		Tail = q.Tail;
		CurrSize = q.CurrSize;
		mas = new T[MaxSize];
		if (Head <= Tail) {
			for (int i = Head; i <= Tail; i++)
				mas[i] = q.mas[i];
		}
		else {
			for (int i = Head; i < MaxSize; i++)
				mas[i] = q.mas[i];
			for (int i = 0; i <= Tail; i++)
				mas[i] = q.mas[i];
		}
	}

	//assignment operator
	TQueue<T> operator=(const TQueue<T> &q) {
		if (this != &q) {
			if (MaxSize != q.MaxSize) {
				MaxSize = q.MaxSize;
				delete[] mas;
				mas = new T[MaxSize];
			}
			Head = q.Head;
			Tail = q.Tail;
			CurrSize = q.CurrSize;
			if (Head <= Tail) {
				for (int i = Head; i <= Tail; i++)
					mas[i] = q.mas[i];
			}
			else {
				for (int i = Head; i < MaxSize; i++)
					mas[i] = q.mas[i];
				for (int i = 0; i <= Tail; i++)
					mas[i] = q.mas[i];
			}
		}
		return *this;
	}

	//check if full or empty
	bool IsEmpty() const {
		return (!CurrSize);
	}
	bool IsFull() const {
		return (CurrSize == MaxSize);
	}

	//insert into queue the queue
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

	//extract from queue
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

	//see what's firsi
	T Front() {
		if (IsEmpty()) throw - 1;
		else
			return mas[Head];
	}

	//see what's last
	T Back() {
		if (IsEmpty()) throw - 1;
		else
			return mas[Tail];
	}

	//get the furst element int the queue
	int GetHead() {
		return Head;
	}

	//get max size of queue
	int GetMaxSize() {
		return MaxSize;
	}

	//get size of queue
	int GetSize() {
		return CurrSize;
	}
};
#endif
