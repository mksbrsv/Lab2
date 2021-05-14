#ifndef TABLE_H
#define TABLE_H
#include "table_management.h"
#include <fstream>
#include <string>
#include "track.h"

template <class Key, class Value>
class table : public table_management<Key, Value> {
  using table_management<Key, Value>::m_count;
  using table_management<Key, Value>::m_table;
  using table_management<Key, Value>::m_size;
  using table_management<Key, Value>::m_current_position;

public:
  table(size_t size = 25);
  table_iterator<Key, Value> find(const Key &key) override;
  void insert(const Key &key, const Value &value) override;
  void push_back(const Value &value) override;
  void remove(const Key &key) override;
  void pop() override;

  virtual void load(std::string &&filename);
  virtual void save(std::string &&filename);
};

template <class Key, class Value>
table<Key, Value>::table(size_t size) : table_management<Key, Value>(size) {}

template <class Key, class Value>
table_iterator<Key, Value> table<Key, Value>::find(const Key &key) {
  m_current_position = this->end();
  for (auto it = this->begin(); it != this->end(); ++it) {
    if (it->key() == key) {
      m_current_position = it;
      break;
    }
  }
  return m_current_position;
}

template <class Key, class Value>
void table<Key, Value>::insert(const Key &key, const Value &value) {
  table_record<Key, Value> push(key, value);
  if (m_count < m_size) {
    ++m_count;
    m_table[m_count] = push;
  } else {
    ++m_count;
    auto new_size = m_size * 2;
    auto *new_tab = new table_record<Key, Value>[new_size];
    for (int i = 0; i < m_size; i++) {
      new_tab[i] = m_table[i];
    }
    m_size = new_size;
    m_table = new_tab;
    m_table[m_count] = push;
  }
}

template <class Key, class Value>
void table<Key, Value>::push_back(const Value &value) {
  table_record<Key, Value> push(m_count + 1, value);
  if (m_size != m_count)
    m_table[m_count == 0 ? m_count : m_count + 1] = push;
  ++m_count;
}

template <class Key, class Value>
void table<Key, Value>::remove(const Key &key) {
  int i = 0;
  for (; i < m_count; i++) {
    if (m_table[i].key() == key) {
      break;
    }
  }
  if (i + 1 != m_count) {
    std::swap(m_table[i], m_table[m_count]);
    pop();
  }
}

template <class Key, class Value> void table<Key, Value>::pop() { --m_count; }

template <class Key, class Value>
void table<Key, Value>::load(std::string&& filename) {
  using std::move;
  std::ifstream file(filename);
  std::string specs;
  if (file.is_open()) {
    while (std::getline(file, specs)) {
      std::string key = specs.substr(0, specs.find(" "));
      specs.erase(0, key.length() + 1);
      std::string name = specs.substr(0, specs.find(" "));
      specs.erase(0, name.length() + 1);
      std::string poster = specs.substr(0, specs.find(" "));
      std::string music = specs.substr(specs.find_last_of(" ") + 1, specs.length());
      track temp(move(name), move(poster), move(music));
      insert(std::stoi(key), temp);
    }
  }
    
}

template <class Key, class Value>
void table<Key, Value>::save(std::string &&filename) {
  std::ofstream file(filename);
  for (auto it = this->begin(); it != this->end(); ++it) {
    file << *it;
  }
}
#endif
