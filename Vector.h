#pragma once
#include "Libraries.h"

class Vector {
private:
	unsigned int size;
public:
	int* IndexOf;
	Vector() { IndexOf = nullptr; size = 0; }
	Vector(const int* index) {
		this->IndexOf = new int[sizeof(index) / sizeof(index[0])];
		size = sizeof(index) / sizeof(index[0]);
	}
	Vector(const unsigned int size) {
		this->IndexOf = new int[size];
		this->size = size;
	}
	unsigned int getSize() {
		return size;
	}
	int* getVector() { return IndexOf; }
	~Vector() {
		if (IndexOf != nullptr) {
			delete[] IndexOf;
			IndexOf = nullptr;
			size = 0;
		}
	}
	bool Empty() {
		if (IndexOf == nullptr && size == 0)
			return true;
		return false;
	}
	void resize(const unsigned int newsize) {
		if (newsize == size)
			return;
		int* temp = new int[newsize];
		if (newsize < size) {
			for (unsigned int i = 0; i < newsize; i++) {
				temp[i] = IndexOf[i];
			}
		}
		else
		{
			for (unsigned int i = 0; i < size; i++) {
				temp[i] = IndexOf[i];
			}
			for (unsigned int i = size; i < newsize; i++) {
				temp[i] = 0;
			}
		}
		delete[] IndexOf;
		IndexOf = new int[newsize];
		for (unsigned int i = 0; i < newsize; i++) {
			IndexOf[i] = temp[i];
		}
		size = newsize;
		return;
	}
	void Display() {
		if (this->IndexOf == nullptr)
			return;
		for (unsigned int i = 0; i < size; i++) {
			cout << IndexOf[i] << " ";
		}
		cout << endl;
	}
	void push_back(const int num) {
		resize(size + 1);
		this->IndexOf[size - 1] = num;
	}
	void push_front(const int num) {
		Vector temp(size + 1);
		for (unsigned int i = 1; i < temp.size; i++) {
			temp.IndexOf[i] = this->IndexOf[i - 1];
		}
		temp.IndexOf[0] = num;
		resize(size + 1);
		for (unsigned int i = 0; i < size; i++) {
			this->IndexOf[i] = temp.IndexOf[i];
		}
	}
	void clear() {
		size = 0;
		delete[] this->IndexOf;
	}
	double MidPositive() {
		if (size == 1 && IndexOf[0]>0)
			return IndexOf[0];
		double mid = 0;
		int count = 0;
		for (unsigned int i = 0; i < size; i++) {
			if (IndexOf[i] > 0) {
				count++;
				mid += IndexOf[i];
			}
		}
		return mid / count;
	}
	bool operator ==(const Vector &another) {
		if (this->IndexOf == nullptr && another.IndexOf == nullptr)
			return true;
		if (this->size == another.size) {
			for (unsigned int i = 0; i < size; i++) {
				if (this->IndexOf[i] != another.IndexOf[i])
					return false;
			}
			return true;
		}
		return false;
	}
	bool operator <(const Vector &another) {
		if (this->size < another.size)
			return true;
		return false;
	}
	bool operator >(const Vector &another) {
		if (this->size > another.size)
			return true;
		return false;
	}
	bool operator <=(const Vector &another) {
		if (this->size <= another.size)
			return true;
		return false;
	}
	bool operator >=(const Vector &another) {
		if (this->size >= another.size)
			return true;
		return false;
	}
	void randomize(const int start, const int end) {
		srand(time(NULL));
		if (IndexOf == nullptr)
			return;
		for (unsigned int i = 0; i < size; i++){
			if (IndexOf[i] == 0)
				IndexOf[i] = rand() % (end -start + 1 ) + start;
		}
		return;
	}
};

