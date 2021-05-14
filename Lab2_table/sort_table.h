#ifndef SORT_TABLE_H
#define SORT_TABLE_H
#include "table.h"
#include <algorithm>
template <class Key, class Value> class sort_table : public table<Key, Value> {
  using table_management<Key, Value>::m_count;
  using table_management<Key, Value>::m_table;
  using table_management<Key, Value>::m_size;
  using table_management<Key, Value>::m_current_position;

public:
  sort_table(int size = 25);
  void merge();
  void insertion();
  void quick();
  void insert(const Key &key, const Value &value) override;
  void push_back(const Value &value) override;
  void remove(const Key &key) override;
  void pop() override;

  void load(std::string &&filename) override;
  void save(std::string &&filename) override;

private:
  bool is_sorted = false;
};

template <class Key, class Value>
sort_table<Key, Value>::sort_table(int size) : table<Key, Value>(size) {}

template <class Key, class Value> void sort_table<Key, Value>::merge() {

}

template <class Key, class Value> void sort_table<Key, Value>::insertion() {
  int j = 0;
  for (int i = 1; i < m_count; i++) {
    auto key = m_table[i];
    j = i - 1;
    while (j >= 0 && m_table[j] > key) {
      m_table[j + 1] = m_table[j];
      j = j - 1;
    }
    m_table[j + 1] = key;
  }
  is_sorted = true;
}

template <class Key, class Value> void sort_table<Key, Value>::quick() {
  std::sort(m_table, m_table + m_count,
            [](table_record<Key, Value> it1, table_record<Key, Value> it2) {
              return it1.key() < it2.key();
            });
  is_sorted = true;
}

template <class Key, class Value>
void sort_table<Key, Value>::insert(const Key &key, const Value &value) {
  if (m_count < m_size) {
    m_table[m_count] = table_record<Key, Value>(key, value);
    ++m_count;
  } else {
    ++m_count;
    auto new_size = m_size * 2;
    auto *new_tab = new table_record<Key, Value>[new_size];
    for (int i = 0; i < m_size; i++) {
      new_tab[i] = m_table[i];
    }
    m_size = new_size;
    m_table = new_tab;
    m_table[m_count] = table_record<Key, Value>(key, value);
  }
  if (is_sorted)
    quick();
}

template <class Key, class Value>
void sort_table<Key, Value>::push_back(const Value &value) {
  table_record<Key, Value> push(m_count + 1, value);
  if (m_size != m_count)
    m_table[m_count == 0 ? m_count : m_count + 1] = push;
  ++m_count;
  if (is_sorted)
	quick();
}

template <class Key, class Value>
void sort_table<Key, Value>::remove(const Key &key) {
  int i = 0;
  for (; i < m_count; i++) {
    if (m_table[i].key() == key) {
      break;
    }
  }
  if (i + 1 != m_count) {
    std::swap(m_table[i], m_table[m_count]);
    pop();
    if (is_sorted)
		quick();
  }
}

template <class Key, class Value> void sort_table<Key, Value>::pop() {
  --m_count;
}
template <class Key, class Value>
void sort_table<Key, Value>::load(std::string &&filename) {
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
void sort_table<Key, Value>::save(std::string &&filename) {
  std::ofstream file(filename);
  for (auto it = this->begin(); it != this->end(); ++it) {
    file << *it;
  }
}
#endif
