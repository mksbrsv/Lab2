#ifndef TABLE_ALLOCATOR_H
#define TABLE_ALLOCATOR_H

template <class T>
class table_allocator {
public:
	T* allocate(size_t size);
	void deallocate(T* array);
};
#endif 

template<class T>
T* table_allocator<T>::allocate(size_t size) {
	T* result = new T[size]();
}

template<class T>
void table_allocator<T>::deallocate(T* array) {
	delete[] array;
}

