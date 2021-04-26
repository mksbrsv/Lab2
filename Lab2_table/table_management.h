#ifndef TABLE_MANAGEMENT_H
#define TABLE_MANAGEMENT_H
#include "table_iterator.h"
#include "table_organization.h"
#include "table_record.h"
template <class Key, class Value>
class table_management : public table_organization<Key, Value> {
	using table_organization<Key, Value>::iterator;
public:
	table_management();
	explicit table_management(size_t size = 25);
	// copy
	table_management(const table_management& manager);
	table_management& operator=(const table_management& manager);
	// move
	table_management(table_management&& manager) noexcept;
	table_management& operator=(table_management&& manager) noexcept;
	~table_management() override;
	bool empty() override;
	bool full() override;
	size_t get_data_count() override;
	Key get_key() const override;
	Value get_value() const override;
	table_iterator<Key, Value> begin() override;
	table_iterator<Key, Value> end() override;
protected:
	table_record<Key, Value>* m_table;
	size_t m_size;
	size_t m_count;
	iterator m_current_position;
};

template <class Key, class Value>
table_management<Key, Value>::table_management() :
	m_table(new table_record<Key, Value>[10]()),
	m_size(10),
	m_count(0) {
}

template <class Key, class Value>
table_management<Key, Value>::table_management(size_t size) :
	m_table(new table_record<Key, Value>[size]),
	m_size(size),
	m_count(0),
	m_current_position(m_table){
}

template <class Key, class Value>
table_management<Key, Value>::table_management(const table_management& manager) :
	m_table(new table_record<Key, Value>[manager.m_size]),
	m_count(manager.m_count),
	m_size(manager.m_size) {
	for (int i = 0; i < m_count; i++) {
		m_table[i] = manager.m_table[i];
	}
}

template <class Key, class Value>
table_management<Key, Value>& table_management<Key, Value>::operator=(const table_management& manager) {
	if (&manager != this) {
		m_count = manager.m_count;
		m_size = manager.m_size;
		m_table = new table_record<Key, Value>[m_size];
		for (int i = 0; i < m_count; i++) {
			m_table[i] = manager.m_table[i];
		}
	}
	return *this;
}

template <class Key, class Value>
table_management<Key, Value>::table_management(table_management&& manager) noexcept :
	m_table(manager.m_table),
	m_count(manager.m_count),
	m_size(manager.m_size),
	m_current_position(manager.m_current_position){
	manager.m_table = nullptr;
	manager.m_count = 0;
	manager.m_size = 0;
	manager.m_current_position = iterator(nullptr);
}

template <class Key, class Value>
table_management<Key, Value>& table_management<Key, Value>::operator=(table_management&& manager) noexcept {
	using std::swap;
	if (&manager != this) {
		swap(m_table, manager.m_table);
		swap(m_count, manager.m_count);
		swap(m_size, manager.m_size);
	}
	return *this;
}

template <class Key, class Value>
table_management<Key, Value>::~table_management() {
	m_count = 0;
	m_size = 0;
	m_current_position = table_iterator<Key, Value>(nullptr);
	delete[] m_table;
}

template <class Key, class Value>
bool table_management<Key, Value>::empty() {
	return m_count == 0;
}

template <class Key, class Value>
bool table_management<Key, Value>::full() {
	return m_size == m_count;

}

template <class Key, class Value>
size_t table_management<Key, Value>::get_data_count() {
	return m_count;
}

template <class Key, class Value>
Key table_management<Key, Value>::get_key() const {
	return m_current_position->key();
}

template <class Key, class Value>
Value table_management<Key, Value>::get_value() const {
	return m_current_position->value();
}

template <class Key, class Value>
table_iterator<Key, Value> table_management<Key, Value>::begin() {
	return iterator(m_table);
}

template <class Key, class Value>
table_iterator<Key, Value> table_management<Key, Value>::end() {
	return iterator(m_table + m_count);
}
#endif

