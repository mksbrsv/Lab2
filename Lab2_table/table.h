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
	void pop() override;

	void load(std::string& filename);
	void save(std::string& filename);

};

template <class Key, class Value>
table<Key, Value>::table(size_t size) : table_management<Key, Value>(size) {
}

template <class Key, class Value>
table_iterator<Key, Value> table<Key, Value>::find(const Key& key) {
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
void table<Key, Value>::insert(const Key& key, const Value& value) {
	table_record<Key, Value> push(key, value);
	if (m_count < m_size) {
		++m_count;
		m_table[m_count] = push;
	}
	else {
		++m_count;
		auto new_size = m_size * 2;
		auto* new_tab = new table_record<Key, Value>[new_size];
		for(int i = 0; i < m_size; i++) {
			new_tab[i] = m_table[i];
		}
		m_size = new_size;
		m_table = new_tab;
		m_table[m_count] = push;
	}
}

template <class Key, class Value>
void table<Key, Value>::push_back(const Value& value) {
	table_record<Key, Value> push(m_count + 1, value);
	++m_count;
	if (m_size != m_count)
		m_table[m_count == 0 ? m_count : m_count + 1] = push;

}

template <class Key, class Value>
void table<Key, Value>::remove(const Key& key) {
}

template <class Key, class Value>
void table<Key, Value>::pop() {
	--m_count;
}

template <class Key, class Value>
void table<Key, Value>::load(std::string& filename) {
}

template <class Key, class Value>
void table<Key, Value>::save(std::string& filename) {
}
#endif
