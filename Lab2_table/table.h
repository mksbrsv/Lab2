#ifndef TABLE_H
#define TABLE_H
#include "table_management.h"

template <class Key, class Value>
class table : public table_management<Key, Value> {
	using table_management<Key, Value>::m_count;
	using table_management<Key, Value>::m_table;
	using table_management<Key, Value>::m_size;
	using table_management<Key, Value>::m_current_position;
public:
	table(size_t size = 25);
	table_iterator<Key, Value> find(const Key& key) override;
	void insert(const Key& key, const Value& value) override;
	void push_back(const Value& value) override;
	void remove(const Key& key) override;

};

template <class Key, class Value>
table<Key, Value>::table(size_t size) : table_management<Key, Value>(size) {
}

template <class Key, class Value>
table_iterator<Key, Value> table<Key, Value>::find(const Key& key) {
	m_current_position = this->end();
	for (auto it = this->begin(); it != this->end(); ++it) {
		if (it->key() == key) 
			m_current_position = it;
	}
		return m_current_position;
}

template <class Key, class Value>
void table<Key, Value>::insert(const Key& key, const Value& value) {
}

template <class Key, class Value>
void table<Key, Value>::push_back(const Value& value) {
	table_record<Key, Value> push(m_count + 1, value);
	if (m_size != m_count)
		m_table[m_count == 0 ? m_count : m_count + 1] = push;
	++m_count;

}

template <class Key, class Value>
void table<Key, Value>::remove(const Key& key) {
}
#endif
