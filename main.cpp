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

		cout << "������� �������. ��� ������ �� ��������� �������� q" << endl;
		cin >> oper;

		if (oper == "q") break; /// ������� ���������� ���������

		cout << "�������������� ��� ��������: " << oper << ": " << endl;

		int comp = dysplayTextArrayNode(root, oper);


		if (comp == -1)
			cout << "������ ����� � ���� ��������� �� �������" << endl;

		else if (comp == 0)
			cout << "������ � ���� ��������� �� �������" << endl;

	}


	return 0;
}