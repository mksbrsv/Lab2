#ifndef TABLE_RECORD_H
#define TABLE_RECORD_H
#include <utility>

template <class Key, class Value>
class table_record {
public:
	table_record();
	table_record(const Key& key, const Value& value) : m_key(key), m_value(value) { }
	table_record(Key&& key, Value&& value) : m_key(std::forward<Key>(key)), m_value(std::forward<Value>(value))  { }
	Key key();
	Value& value();
private:
	Key m_key;
	Value m_value;
};

template <class Key, class Value>
table_record<Key, Value>::table_record() : m_key(Key()), m_value(Value()) {
}

template <class Key, class Value>
Key table_record<Key, Value>::key() {
	return m_key;
}

template <class Key, class Value>
Value& table_record<Key, Value>::value() {
	return m_value;
}
#endif

