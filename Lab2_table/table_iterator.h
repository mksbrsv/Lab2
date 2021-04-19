#ifndef TABLE_ITERATOR_H
#define TABLE_ITERATOR_H
#include "table_record.h"

template<class Key, class Value> class table_management;

template <class Key, class Value>
class table_iterator {
	friend table_management<Key, Value>;
public:
	table_iterator(const table_iterator& it);
	table_iterator& operator=(const table_iterator& it);
	~table_iterator();
	bool operator!=(const table_iterator& it);
	bool operator==(const table_iterator& it);
	table_record<Key, Value>& operator*() const;
	table_record<Key, Value>* operator->() const;
	table_iterator& operator++();
private:
	table_iterator(table_record<Key, Value>* it);
	table_record<Key, Value>* m_curr;

};

template <class Key, class Value>
table_iterator<Key, Value>::table_iterator(const table_iterator& it) : m_curr(it.m_curr) { }

template <class Key, class Value>
table_iterator<Key, Value>& table_iterator<Key, Value>::operator=(const table_iterator& it) {
	m_curr = it.m_curr;
	return *this;
}

template <class Key, class Value>
table_iterator<Key, Value>::~table_iterator() {
	delete m_curr;
}

template <class Key, class Value>
bool table_iterator<Key, Value>::operator!=(const table_iterator& it) {
	return m_curr != it.m_curr;
}

template <class Key, class Value>
bool table_iterator<Key, Value>::operator==(const table_iterator& it) {
	return m_curr == it.m_curr;
}

template <class Key, class Value>
table_record<Key, Value>& table_iterator<Key, Value>::operator*() const {
	return *m_curr;
}

template <class Key, class Value>
table_record<Key, Value>* table_iterator<Key, Value>::operator->() const {
	return m_curr;
}

template <class Key, class Value>
table_iterator<Key, Value>& table_iterator<Key, Value>::operator++() {
	++m_curr;
	return *this;
}

template <class Key, class Value>
table_iterator<Key, Value>::table_iterator(table_record<Key, Value>* it) : m_curr(it) { }
#endif 

