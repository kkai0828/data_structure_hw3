// CPP program to implement hashing with chaining
// https://www.geeksforgeeks.org/c-program-hashing-chaining/?ref=gcse
#include <iostream>
#include <list>
#include <ctime>
#include <cmath>
using namespace std;

class Hash
{
    int BUCKET; // No. of buckets

    // Pointer to an array containing buckets
    list<int> *table;
public:
    Hash(int V); // Constructor

    // inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    int search (int x);

    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (index)th list
    list <int> :: iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
int Hash::search(int x){
    int index = hashFunction(x);
    list <int> :: iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++) {
        if (*i == x)
            return 1;
    }
    return 0;
}
// Driver program
int main()
{
    srand(time(0));
    int Range = pow(2,30);
    for(int n=10;n<=30;n++ ){
        float T = 0;
        int size = pow(2,n);
        clock_t Startime = clock();
        Hash h(size); // 10000 is count of buckets in hash table
        for(int i=0;i<size;i++){
            int r = rand()%Range;
            h.insertItem(r);
        }
        clock_t Endtime = clock();
        T += (float)(Endtime - Startime)/CLOCKS_PER_SEC;
        cout << " T_insert(n = " << n << ")= " << T << endl; 
        Startime = clock();
        for(int i=0;i<100000;i++){
            int r = rand()%Range;
            h.search(r);
        }
        Endtime = clock();
        T += (float)(Endtime - Startime)/CLOCKS_PER_SEC;
        cout << " T_search(n = " << n << ")= " << T << endl << endl; 
    }

    return 0;
}


