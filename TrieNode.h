#pragma once
#include <iostream>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, если ключ €вл€етс€ концом слова
	bool isEndOfWord;
};

TrieNode* getNewNode(void); // ¬озвращает новый узел с пустыми детьми
void insert(TrieNode* root, string key); //¬ставка

bool isEmpty(TrieNode* root); // ¬охвращает true если root имеет лист, иначе false 


void getArrayNode(TrieNode* root, string curren_key); // ‘ормирует варианты дополнени€ текста по его части

int dysplayTextArrayNode(TrieNode* root, string key); // ¬ыводит возможные варианты дополнени€ текста по его части


