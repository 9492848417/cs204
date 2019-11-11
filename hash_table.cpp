#include<iostream>
#include <list>
using namespace std;

class Hash
{
    int block;
    list<int> *table;
public:
    Hash(int b);
    void insertItem(int key);
    void deleteItem(int key);
    void Search(int key);
    int hashFunction(int key) {
        return key%block;
    }

    void displayHash();
};

Hash::Hash(int b)
{
    this->block = b;
    table = new list<int>[block];
}

void Hash::Search(int key){
    int index=hashFunction(key);
    list <int> :: iterator i;
       for (i = table[index].begin();
           i != table[index].end(); i++) {
            if (*i == key)
            break;}
      if (i != table[index].end())
       cout << key << " found\n";
      else cout << key << " not found\n";
    }

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_front(key);
}

void Hash::deleteItem(int key)
{

  int index = hashFunction(key);
  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == key)
      break;
  }

  if (i != table[index].end())
    table[index].erase(i);
}


void Hash::displayHash() {
  for (int i = 0; i < block; i++) {
    cout << i;
   for (auto x : table[i])
     cout << " --> " << x;
    cout << '\n';
  }
}


int main()
{

  int a[] = {15,37,43,76,60,84};
  int n = sizeof(a)/sizeof(a[0]);
  Hash h(7);

  for (int i = 0; i < n; i++)
    h.insertItem(a[i]);
  h.deleteItem(43);
  h.displayHash();
  h.Search(76);
  h.Search(46);
  return 0;
}
