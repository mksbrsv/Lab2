#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include "table.h"

template<class Key>
int hash(const Key& key) {}

template <class Key, class Value> class hash_table : public table<Key, Value> {
public:
  hash_table(int size = 25);
};

template <class Key, class Value>
hash_table<Key, Value>::hash_table(int size) : table<Key, Value>(size) {}





#endif
