#ifndef TABLE_RECORD_H
#define TABLE_RECORD_H
#include <utility>
#include <iostream>

template <class Key, class Value>
class table_record {
public:
	table_record() : m_key(Key()), m_value(Value()) { }
	table_record(const Key& key, const Value& value) : m_key(key), m_value(value) { }
	table_record(Key&& key, Value&& value) : m_key(std::forward<Key>(key)), m_value(std::forward<Value>(value))  { }
	bool operator>(const table_record<Key, Value>& table_record) {
		return m_key > table_record.m_key;
	}
	friend std::ostream& operator<<(std::ostream& out, const table_record<Key, Value>& table_record) {
		out << table_record.m_key << " " << table_record.m_value << std::endl;
		return out;
	}
	Key key() { return m_key; }
	Value& value() { return m_value; }
private:
	Key m_key;
	Value m_value;
};
#endif

