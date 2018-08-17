//Hamza Ilyas
//hi3zk
//3.10.18
//hashTable.cpp

#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<fstream>
#include<algorithm>

#include "hashTable.h"
using namespace std;

hashTable::hashTable (int line) {
  if (!checkprime(line * 3)) {
    tableSize = getNextPrime(line * 3);
    theHash.resize(tableSize);
  }
  else {
    tableSize = line;
    theHash.resize(tableSize*3);
  }
}
  

unsigned int hashTable:: hash(string key) {
  int hash = 0;
  int index;
  index = key.length();

  for (int i = 0; i < index; i++) {
    int value = (int)key[i];
    hash += value*value*value;
  }

  index = hash % tableSize;
    
  return index;
}

void hashTable:: insert(string key) {
  int index = hash(key)%tableSize;
  theHash.at(index).push_back(key);
  //tableSize++;
}

bool hashTable:: contains(string key) {
  int index = hash(key)%tableSize;
  list<string> pos = theHash.at(index);

  if (find(pos.begin(), pos.end(), key) != (pos.end())) {
    return true;
  }
  else {
    return false;
  }
}

void hashTable:: resize (unsigned int k) {
  theHash.resize(k);
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
  
