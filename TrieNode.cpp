#include "TrieNode.h"

TrieNode* getNewNode(void) // ¬озвращает новый узел с пустыми детьми
{
    // ¬ыдел€ем пам€ть по новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void insert(TrieNode* root, string key) //¬ставка
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        // вычисл€ем индекс в алфите через смещение отнситьельно первой буквы
        int index = key[i] - 'a';

        // если указатель пустрой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;

}

bool isEmpty(TrieNode* root) // ¬охвращает true если root имеет лист, иначе false 
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;

}


void getArrayNode(struct TrieNode* root, string currPrefix) // ‘ормирует варианты дополнени€ текста по его части
{
    if (root->isEndOfWord)
        cout << currPrefix << endl;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            char child = 'a' + i;
            getArrayNode(root->children[i], currPrefix + child);
        }
}

int dysplayTextArrayNode(TrieNode* root, const string key) // ¬ыводит возможные варианты дополнени€ текста по его части
{
    struct TrieNode* node = root;
    
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    if (isEmpty(node)) {
        cout << key << endl;
        return -1;
    }

    getArrayNode(node, key);
    return 1;
}
