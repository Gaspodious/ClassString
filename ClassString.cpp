#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
	int size;
	char* data;
public:
	//Конструкторы по умолчанию.
	MyString() {
		size = 0;
		data = nullptr;
	}
	MyString(const char* data) {
		size = strlen(data);
		this->data = new char[size + 1];
		for (int i = 0; i < size; ++i) {
			this->data[i] = data[i];
		}
		this->data[size] = '\0';
	}
	//Конструктор копирования.
	MyString(const MyString& second) {
		size = second.size;
		data = new char[size + 1];
		for (int i = 0; i < size; ++i) {
			data[i] = second.data[i];
		}
		data[size] = '\0';
	}
	//Конструктор переноса.
	MyString(MyString&& second) {
		size = second.size;
		data = second.data;
		second.data = nullptr;
	}
	//Деструктор.
	~MyString() {
		delete[] data;
	}
	//Перегрузка операторов.
	MyString& operator = (const MyString& second) {
		if (data != nullptr) {
			delete[] data;
		}
		size = second.size;
		data = new char[size + 1];
		for (int i = 0; i < size; ++i) {
			data[i] = second.data[i];
		}
		data[size] = '\0';
		return *this;
	}
	MyString operator + (const MyString& second) {
		MyString first;
		first.size = size + second.size;
		first.data = new char[first.size + 1];
		int i = 0;
		for (; i < size; ++i) {
			first.data[i] = data[i];
		}
		for (int j = 0; j < second.size; ++j, ++i) {
			first.data[i] = second.data[j];
		}
		first.data[first.size] = '\0';
		return first;
	}
	bool operator == (const MyString& second) { return data == second.data; }
	bool operator != (const MyString& second) { return data != second.data; }
	bool operator <= (const MyString& second) { return data <= second.data; }
	bool operator >= (const MyString& second) { return data >= second.data; }
	bool operator > (const MyString& second) { return data > second.data; }
	bool operator < (const MyString& second) { return data < second.data; }
	char& operator [] (const int& index) { return data[index]; }
	//Размер строки.
	int Size() { return size; }
	int Lenght() { return size; }
	//Вывод на экран.
	void Print() {
		if (data != nullptr) {
			for (int i = 0; i < strlen(data); ++i) {
				cout << data[i];
			}
		}
	}
};

int main() {
	MyString s;
	return 0;
}
