//Hamza Ilyas
//hi3zk
//3.10.18
//hashTable.h

#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<fstream>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define MAXROWS 500
#define MAXCOLS 500

class hashTable {
  
 public:
  hashTable(int line);
  unsigned int hash(string key); //return an index number representing where to store
  void insert (string key);
  bool contains (string key);
  void resize (unsigned int k);
  bool checkprime (unsigned int p);
  int getNextPrime (unsigned int n);
  vector<list<string> > theHash;
  int tableSize;

  static const unsigned int n = 31;
};

#endif
