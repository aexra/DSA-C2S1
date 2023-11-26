#include "Lab6.h"

List<int> Lab6::getRandList(size_t size, int begin, int end)
{
	List<int> lst;
	HRND rnd = Random::GetInstance();
	for (int i = 0; i < size; i++)
	{
		lst.push(rnd->randi(begin, end));
	}
	return lst;
}
Queue<int> Lab6::getRandQueue(size_t size, int begin, int end)
{
	Queue<int> lst;
	HRND rnd = Random::GetInstance();
	for (int i = 0; i < size; i++)
	{
		lst.push(rnd->randi(begin, end));
	}
	return lst;
}

void Lab6::t1()
{
	Queue<int> q1 = getRandQueue(3, 1, 10);
	Queue<int> q2 = getRandQueue(3, 1, 10);
	cout << "Queue 1: " << q1;
	cout << "Queue 2: " << q2;
	cout << "\n��������� ����������� ���������..." << endl;
	q2 += q1;
	cout << "Queue 2: " << q2;
	cout << "\n������ ����� ������ � �����:" << endl << "������: " << q2.__GetHeadPtr__() << endl << "�����: " << q2.__GetTailPtr__();
}

void Lab6::t2()
{
	List<int> lst = getRandList(4, 1, 8); lst.cout();
	lst.swap(0, lst.find(lst.min())); lst.cout();
}

template <class T>
Queue<T>::Queue() {}

template<class T>
void Queue<T>::cout(ostream& os)
{
	os << this->toString() << endl;
}

template<class T>
size_t Queue<T>::count()
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
string Queue<T>::toString()
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
void Queue<T>::push(T value)
{
	if (!this->head)
	{
		this->head = new Node(value);
		this->tail = this->head;
		return;
	}

	this->tail->next = new Node(value);
	this->tail = this->tail->next;
}

template<class T>
T Queue<T>::pop()
{
	if (!this->head)
	{
		error("������������Exception");
		exit(-1);
	}
	if (this->head == this->tail) this->tail = nullptr;
	T data = this->head->value;
	Node* oldhead = this->head;
	this->head = this->head->next;
	delete oldhead;
	return data;
}

template<class T>
void Queue<T>::operator+=(const Queue<T>& _Right)
{
	Node* tmp = _Right.head;
	while (tmp)
	{
		this->push(tmp->value);
		tmp = tmp->next;
	}
}

template <class T>
List<T>::List() {}

template<class T>
void List<T>::cout(ostream& os)
{
	os << this->toString() << endl;
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
			error("������� � ����� �������� �� ������!\n\n");
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
	if (x == y) return;

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

	// ����� ������
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

	error("������� � ����� ��������� �� ������!\n\n");
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
			error("������� � ����� �������� �� ������!\n\n");
			exit(-1);
			//throw out_of_range("kekw");
			//return 0;
		}
		tmp = tmp->next;
		j++;
	}

	return tmp->value;
}