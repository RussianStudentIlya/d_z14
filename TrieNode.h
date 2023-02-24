#pragma once
#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, ���� ���� �������� ������ �����
	bool isEndOfWord;
};

TrieNode* getNewNode(void); // ���������� ����� ���� � ������� ������
void insert(TrieNode* root, string key); //�������

bool isEmpty(TrieNode* root); // ���������� true ���� root ����� ����, ����� false 


void getArrayNode(TrieNode* root, string curren_key); // ��������� �������� ���������� ������ �� ��� �����

int dysplayTextArrayNode(TrieNode* root, string key); // ������� ��������� �������� ���������� ������ �� ��� �����


