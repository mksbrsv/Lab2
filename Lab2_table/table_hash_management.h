#ifndef TABLE_HASH_MANAGEMENT_H
#define TABLE_HASH_MANAGEMENT_H

#include "table_organization.h"

template <class T> concept string_hash = requires(T a) {
  a.length();
  a[0];
};

template<string_hash Key>
int hash(const Key& key) {
  unsigned long hash_val = 0;
  int len = key.length();
  for (int i = 0; i < len; i++) {
    hash_val = (hash_val << 3) + key[i];
  }
}


template <class Key, class Value>
class table_hash_management : public table_organization<Key, Value> {
public:
  table_hash_management();
  explicit table_hash_management(int size = 25);

protected:
  table_record<Key, Value>* m_table;
  size_t m_size;
  size_t m_count;


};

#endif
