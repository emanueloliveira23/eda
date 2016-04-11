/**
* hash.h
*/
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

class HashTable {
  
  struct List {
    int key;
    int info;
    List *next;
  };

  struct HashEntry {
    const int key;
    List *list;
  };

  int realSize;
  HashEntry **table;

public:
  HashTable(const int size);
  ~HashTable();

  int get(const int key) const;
  void insert(const int key, int value);
  bool remove(const int key);

private:
  void init();

};

#endif

/**
* hash.cpp
*/
#include <iostream>

#define hash(v, m) v % m

HashTable::HashTable(int size) 
{
  realSize = size / 2;
  init();
}

HashTable::~HashTable()
{
  for (int i = 0; i < realSize; i++) {
    if (table[i] != NULL) {
      List *list = table[i]->list;
      while (list != NULL) {
        List *next = list->next;
        delete list;
        list = next;
      }
      delete table[i];
    }    
  }
}

int HashTable::get(const int key) const
{
  const int h = hash(key, realSize);
  if (table[h] != NULL) {
    List *list = table[h]->list;
    while (list != NULL) {
      if (list->key == key) {
        return list->info;
      }
      list = list->next;
    }
  } 

  throw key;
}

void HashTable::insert(const int key, int value)
{
  const int h = hash(key, realSize);
  
  if (table[h] == NULL) {
   
    //Cria a lista de entrada 
    List *list = new List();
    list->key = key;
    list->info = value;
    list->next = NULL;

    //Cria a entrada apontado para a lista
    HashEntry *newEntry = new HashEntry();
    newEntry->list = list;
    
    //Atribui a entrada à tabela
    table[h] = newEntry;
  
  } else {
    
    //Cria um novo nó para a lista que já existe no índice h da tabela
    List *newNode = new List();
    newNode->key = key;
    newNode->info = value;
    
    //Atualiza a lista exististente, inserindo o novo nó na cabeça
    HashEntry *entry = table[h];
    newNode->next = entry->list;
    entry->list = newNode;

  }
}

bool HashTable::remove(const int key)
{
  const int h = hash(key, realSize);
  bool ok = false;  
  if (table[h] != NULL) {

    List *ant = NULL;
    List *list = table[h]->list;
    while (list != NULL) {
      if (list->key == key) {
        if (ant == NULL) {
          table[h]->list = list->next;
        } else {
          ant->next = list->next;
        }
        delete list;
        ok = true;
        break;
      }
      ant = list;
      list = list->next;
    }

  }
  return ok;
}

void HashTable::init() 
{
  table = new HashEntry*[realSize];
  for (int i = 0; i < realSize; i++) {
    table[i] = NULL;
  }
}

/**
* main.cpp
*/

int main(int argc, char const *argv[])
{
  HashTable *hashTable = new HashTable(100);
  
  hashTable->insert(10, 5000);
  hashTable->insert(60, 300);
  
  try {  
    
    printf("%d => %d\n", 10, hashTable->get(10));
    printf("%d => %d\n", 60, hashTable->get(60));
    printf("%d => %d\n", 61, hashTable->get(61));
 
  } catch (int key) {
    printf("Key not found: %d\n", key);
  }

  printf("Removing %d ... %s\n", 60, hashTable->remove(60) ? "success" : "failure" );

  try {
    printf("%d => %d\n", 60, hashTable->get(60));
  } catch (int key) {
    printf("Key not found: %d\n", key);
  }

  delete hashTable;
  return 0;
}