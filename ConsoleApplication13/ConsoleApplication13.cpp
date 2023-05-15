// ConsoleApplication13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class TBook {
private:
	string Name;
	string Author;
	int Count;
public:
	void setName(string newname) {
		Name = newname;
	}
	void setAuthor(string newauthor) {
		Author = newauthor;
	}
	void setCount(int newcount) {
		Count = newcount;
	}
	string getName() {
		return Name;
	}
	string getAuthor() {
		return Author;
	}
	int getCount() {
		return Count;
	}
};

bool comparewithauthor(TBook book1, TBook book2) {
	return book1.getAuthor() < book2.getAuthor();
}

int main() {
	setlocale(LC_ALL, "ru");
	TBook books[5];
	ifstream fin("book.txt");
	if (!fin) {
		cout << "Не найден!" << endl;
		return 1;
	}

	for (int i = 0; i < 5; i++) {
		string name, author, count_str;

		getline(fin, name);
		getline(fin, author);
		getline(fin, count_str);
		int count = stoi(count_str);

		books[i].setName(name);
		books[i].setAuthor(author);
		books[i].setCount(count);
	}
	fin.close();

	sort(books, books + 5, comparewithauthor);
	for (int i = 0; i < 5; i++) {
		cout << "Name: " << books[i].getName() << endl;
		cout << "Author: " << books[i].getAuthor() << endl;
		cout << "Count: " << books[i].getCount() << endl;
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
