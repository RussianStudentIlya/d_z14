#include <iostream>
#include <string>
#include "TrieNode.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");

	string arr[] = { "call", "cat", "cult", "run", "rut", "dog", "dot", "dove", "duck", "zebra" };

	TrieNode* root = getNewNode();

	for (string item : arr)
	{
		insert(root, item);
	}


	while (true)
	{
		string oper;

		cout << "Введите префикс. Для выхода из программы выберете q" << endl;
		cin >> oper;

		if (oper == "q") break; /// Условие завершения программы

		cout << "Автодополнения для префикса: " << oper << ": " << endl;

		int comp = dysplayTextArrayNode(root, oper);


		if (comp == -1)
			cout << "Других строк с этим префиксом не найдено" << endl;

		else if (comp == 0)
			cout << "Строка с этим префиксом не найдена" << endl;

	}


	return 0;
}