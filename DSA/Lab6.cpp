#include "Lab6.h"

void Lab6::t1()
{
	
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
	size_t j = 0;
	Node* prev = nullptr;
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
		prev = tmp;
		tmp = tmp->next;
		j++;
	}

	if (prev) prev->next = tmp->next;
	delete tmp;
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
size_t List<T>::find(T value)
{
	size_t i = 0;
	Node* tmp = this->head;

	while (tmp)
	{
		if (tmp->value == value)
		{
			return i;
		}
		i++;
		tmp = tmp->next;
	}

	error("Элемент с таким значением не найден!\n\n");
	exit(-1);
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
