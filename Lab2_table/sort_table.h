#ifndef SORT_TABLE_H
#define SORT_TABLE_H
#include "table.h"
#include <algorithm>
template<class Key, class Value>
class sort_table : public table<Key, Value> {
	using table_management<Key, Value>::m_count;
	using table_management<Key, Value>::m_table;
	using table_management<Key, Value>::m_size;
	using table_management<Key, Value>::m_current_position;
public:
	sort_table(int size = 25);
	void merge();
	void insertion();
	void quick();

};

template <class Key, class Value>
sort_table<Key, Value>::sort_table(int size) : table<Key, Value>(size) {
}

template <class Key, class Value>
void sort_table<Key, Value>::merge() {
}

template <class Key, class Value>
void sort_table<Key, Value>::insertion() {
	int j = 0;
	for(int i = 1; i < m_count; i++) {
		auto key = m_table[i];
		j = i - 1;
		while (j >= 0 && m_table[j] > key) {
			m_table[j + 1] = m_table[j];
			j = j - 1;
		}
		m_table[j + 1] = key;
	}
}

template <class Key, class Value>
void sort_table<Key, Value>::quick() {
	std::sort(m_table, m_table + m_count, [](table_record<Key, Value> it1, table_record<Key, Value> it2) {
		return it1.key() < it2.key();
	});
}
#endif 

