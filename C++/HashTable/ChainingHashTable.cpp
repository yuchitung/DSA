#include <iostream>
#include <list>
using namespace std;

class Hash {
    int sizes;
    list<int> *table;

  public:
    Hash(int sizes);
    void insertItem(int value);
    void deleteItem(int value);
    int hashFunction(int value) { return value % sizes; }
    void print();
};

Hash::Hash(int sizes) {
    this->sizes = sizes;
    table = new list<int>[sizes];
}

void Hash::insertItem(int value) {
    int index = hashFunction(value);
    table[index].push_back(value);
}

void Hash::deleteItem(int value) {
    list<int>::iterator i;
    int index = hashFunction(value);
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == value) {
            table[index].erase(i);
            break;
        }
    }
}

void Hash::print() {
    for (int i = 0; i < sizes; i++) {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main() {
    int array[] = {22, 6, 13, 3, 78, 11};
    int numbers = sizeof(array) / sizeof(array[0]);

    Hash hashTable(5);
    cout << "Initialize hash table..." << endl;
    hashTable.print();

    cout << endl << "Insert items" << endl;
    for (int i = 0; i < numbers; i++)
        hashTable.insertItem(array[i]);
    hashTable.print();

    cout << endl << "Delete item:13" << endl;
    hashTable.deleteItem(13);
    hashTable.print();

    return 0;
}