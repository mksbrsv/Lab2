#ifndef TABLE_ORGANIZATION_H
#define TABLE_ORGANIZATION_H
#include "table_iterator.h"

template <class Key, class Value>
class table_organization {
protected:
	using iterator = table_iterator<Key, Value>;
	using const_iterator = table_iterator<const Key, const Value>;
	virtual bool empty() = 0;
	virtual bool full() = 0;
	virtual size_t get_data_count() = 0;
	virtual Key get_key() const = 0;
	virtual Value get_value() const = 0;
	virtual table_iterator<Key, Value> find(const Key& key) = 0;
	virtual void insert(const Key& key, const Value& value) = 0;
	virtual void push_back(const Value& value) = 0;
	virtual void remove(const Key& key) = 0;
	virtual ~table_organization() = default;
	virtual table_iterator<Key, Value> begin() = 0;
	virtual table_iterator<Key, Value> end() = 0;
	//virtual void next() = 0;
};
#endif

