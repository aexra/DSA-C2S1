#include "Lab6.h"

void Lab6::t1()
{
	List<int>* lst = new List<int>();
	cout << lst->count();
}

void Lab6::t2()
{
}

template <class T>
List<T>::List() {}

template<class T>
void List<T>::push(T value)
{

}

template<class T>
void List<T>::remove(size_t i)
{

}

template<class T>
size_t List<T>::count()
{
	size_t k = 0;
	Node* tmp = this->head;
	while (tmp)
	{
		k++;
		tmp = tmp->next;
	}
	return k;
}

template<class T>
T List<T>::operator[](size_t i)
{

}
