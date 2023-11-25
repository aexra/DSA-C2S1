#include "Lab6.h"

void Lab6::t1()
{
	List<int> lst = List<int>();
	lst.push(5);
	lst.push(3);
	lst.push(4);
	cout << lst.count();
	cout << endl << lst[5];
}

void Lab6::t2()
{
}

template <class T>
List<T>::List() {}

template<class T>
void List<T>::push(T value)
{
	if (!this->head)
	{
		this->head = new Node(value);
		return;
	}

	Node* tmp = this->head;

	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node(value);
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
	size_t j = 0;
	Node* tmp = this->head;

	while (j != i)
	{
		if (!tmp) 
		{
			error("Элемент с таким индексом не найден!\n\n");
			exit(-1);
			//throw out_of_range("kekw");
			//return 0;
		}
		tmp = tmp->next;
		j++;
	}

	return tmp->value;
}
