#pragma once
#ifndef LinkedList_h
#define LinkedList_h
#endif
#include <iostream>
//THINKING THIS WILL HELP WITH THE ARRAY CONSTRUCTOR
#include <array>

#define TEMPLATE template <typename T>

TEMPLATE
class List_Node {
public:
	T data;
	List_Node* next;

	List_Node();
	List_Node(T datum);
};

TEMPLATE
class Linked_List {
protected:
	List_Node<T>* head;
	List_Node<T>* tail;
	List_Node<T>* current;
	size_t size;

public:
	Linked_List<T>();
	Linked_List<T>(T datum);
	Linked_List<T>(T *arr, size_t arrSize);
	~Linked_List<T>();

	List_Node<T>* find(T target);
	List_Node<T>* get_head();
	List_Node<T>* get_current();

	bool append(T datum);
	size_t get_size();
	void print_list();

};

///////////////
//DEFINITIONS//
///////////////


//CONSTRUCTORS
TEMPLATE
List_Node<T>::List_Node<T>() {
	this->data = 0;
	this->next = nullptr;
}

TEMPLATE
List_Node<T>::List_Node<T>(T datum) {
	this->data = datum;
	this->next = nullptr;
}

TEMPLATE
Linked_List<T>::Linked_List<T>()
{
	this->head = new List_Node<T>();
	this->current = head;
	this->tail = head;
	this->head->next = nullptr;
	this->current->next = nullptr;
	this->tail->next = nullptr;
	this->size = 0;
}

TEMPLATE
Linked_List<T>::Linked_List<T>(T datum)
{
	this->head = new List_Node<T>(datum);
	this->current = head;
	this->tail = head;
	this->head->next = nullptr;
	std::cout << this->tail->next << std::endl;
	std::cout << this->head->next << std::endl;
	
	//FAIRLY SURE I CAN JUST IGNORE SETTING THESE SINCE THEY POINT TO HEAD ANYWAY
	//this->current->next = nullptr;
	//this->tail->next = nullptr;
	
	this->size = 1;
}

TEMPLATE
Linked_List<T>::Linked_List<T>(T *arr,size_t arrSize)
{
	this->head = new List_Node<T>(arr[0]);
	List_Node<T>* ptr = head;
	for (int i = 1; i < arrSize; i++)
	{
		ptr->next = new List_Node<T>(arr[i]);
		ptr = ptr->next;
	}
	this->size = arrSize;
	
}

TEMPLATE
Linked_List<T>::~Linked_List()
{
	int i = 0;
	while (i < this->size)
	{
		i++;

		try {
			List_Node<T>* ptr = this->head;
			this->head = this->head->next;
			delete ptr;
		}
		catch (...) {
			std::cout << "Deletion error\n";
			break;
		}
		delete this->current;
		this->size = 0;
	}
}

//GETTERS
TEMPLATE
List_Node<T>* Linked_List<T>::get_head()
{
	return this->head;
}

TEMPLATE
List_Node<T>* Linked_List<T>::get_current()
{
	return this->current;
}

TEMPLATE
size_t Linked_List<T>::get_size()
{
	return this->size;
}

TEMPLATE
bool Linked_List<T>::append(T datum)
{
	try {
		if (this->size == 0) {
			this->head = new List_Node<T>(datum);
			this->current = head;
			this->tail = head;
			this->head->next = nullptr;
		}
		else if (this->size == 1) {
			this->head->next = new List_Node<T>(datum);
			this->tail = head->next;
			this->current = tail;
			this->tail->next = nullptr;
	
		}
		else {
			this->tail->next = new List_Node<T>(datum);
			this->tail = this->tail->next;
			this->tail->next = nullptr;
			this->current = this->tail;
		}
		this->size += 1;
		return true;
	}

	catch (...) {
		std::cout << "Error was thrown" << std::endl;
		return false;
	}
}


TEMPLATE
List_Node<T>* Linked_List<T>::find(T target)
{
	//RETURNS: 
	//	-Node, if element is in list
	//	-nullptr is

	//REPLACED 1/24/21 WITH DO WHILE LOOP
	//while (ptr != nullptr) {
	//	if (ptr->data == target)
	//		return ptr;
	//	ptr = ptr->next;
	//}

	List_Node<T>* ptr = head;
	do {
		if (ptr->data == target) {
			return ptr;
		}
		else {
			ptr = this->head->next;
		}
	} while (ptr != tail);
	return nullptr;
}

TEMPLATE
void Linked_List<T>::print_list()
{
	List_Node<T>* ptr = this->head;
	do {
		std::cout << "Node: " << ptr->data << std::endl;
		ptr = ptr->next;
	} while (ptr != nullptr);

	//REPLACED WITH DO WHILE ON 1/24/21
	//for (int i = 0; i <= size; i++)
	//{
	//	if (ptr != nullptr) {
	//		std::cout << "Node " << i << " data: " << ptr->data << std::endl;
	//		ptr = ptr->next;
	//	}
	//}
}