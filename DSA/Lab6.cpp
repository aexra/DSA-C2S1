#include "Lab6.h"

List<int> Lab6::getRandList(size_t size, int begin, int end)
{
	List<int> lst;
	HRND rnd = new Random();
	for (int i = 0; i < size; i++)
	{
		lst.push(rnd->randi(begin, end));
	}
	return lst;
}

void Lab6::t1()
{
	
}

void Lab6::t2()
{
	
}

template <class T>
List<T>::List() {}

template<class T>
void List<T>::cout()
{
	std::cout << this->toString() << endl;
}

template<class T>
string List<T>::toString()
{
	string str = "[ ";
	
	Node* tmp = this->head;
	while (tmp)
	{
		str += to_string(tmp->value) + ", ";
		tmp = tmp->next;
	}

	str += "]";

	return str;
}

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
void List<T>::swap(size_t x, size_t y)
{
	size_t size = this->count();
	if (x >= size || y >= size)
	{
		error("Raised IndexOutOfRangeException");
		exit(-1);
	}

	if (x > y)
	{
		size_t tmpi = y;
		y = x;
		x = tmpi;
	}

	Node* prev1 = x > 0 ? __GetNode__(x - 1) : nullptr;
	Node* node1 = __GetNode__(x);
	Node* next1 = x + 1 != y ? __GetNode__(x + 1) : __GetNode__(x);
	Node* prev2 = y - 1 != x ? __GetNode__(y - 1) : nullptr;
	Node* node2 = __GetNode__(y);
	Node* next2 = y < size - 1 ? __GetNode__(y + 1) : nullptr;

	// общий случай
	if (prev1) prev1->next = node2;
	node1->next = next2;
	if (prev2) prev2->next = node1;
	node2->next = next1;

	if (x == 0) this->head = node2;
}

template<class T>
void List<T>::reverse()
{
	Node* prev = nullptr;
	Node* tmp = this->head;
	Node* realnext = nullptr;
	if (!tmp) return;
	
	while (tmp)
	{
		this->head = tmp;
		realnext = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = realnext;
	}
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
T List<T>::max()
{
	Node* tmp = this->head;
	T maxval = tmp->value;
	while (tmp)
	{
		if (tmp->value > maxval) maxval = tmp->value;
		tmp = tmp->next;
	}
	return maxval;
}

template<class T>
T List<T>::min()
{
	Node* tmp = this->head;
	T minval = tmp->value;
	while (tmp)
	{
		if (tmp->value < minval) minval = tmp->value;
		tmp = tmp->next;
	}
	return minval;
}

template<class T>
T List<T>::sum()
{
	Node* tmp = this->head;
	T sum = 0;
	while (tmp)
	{
		sum += tmp->value;
		tmp = tmp->next;
	}
	return sum;
}

template<class T>
T List<T>::mean()
{
	Node* tmp = this->head;
	T sum = 0;
	size_t count = 0;
	while (tmp)
	{
		sum += tmp->value;
		count++;
		tmp = tmp->next;
	}
	return sum / count;
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
