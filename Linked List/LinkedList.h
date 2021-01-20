#pragma once
#include <iostream>
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
	List_Node<T>* current;
	size_t size;

public:
	Linked_List<T>(T datum);

	List_Node<T>* get_head();
	List_Node<T>* get_current();
	bool add_node(T datum);
	size_t get_size();
	void print_list();

};


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
Linked_List<T>::Linked_List<T>(T datum) {
	this->head = new List_Node<T>(datum);
	this->current = head;
	this->size = 1;
}

TEMPLATE
bool Linked_List<T>::add_node(T datum)
{
	try {
		if (this->size == 1)
			this->head->next = new List_Node<T>(datum);
		else
			this->current->next = new List_Node<T>(datum);
		this->size += 1;
		return true;
	}

	catch (...) {
		std::cout << "Error was thrown" << std::endl;
		return false;
	}
}

TEMPLATE
void Linked_List<T>::print_list()
{
	List_Node<T>* ptr = this->head;
	for (int i = 0; i <= size; i++)
	{
		if (ptr != nullptr) {
			std::cout << "Node " << i << " data: " << ptr->data << std::endl;
			ptr = ptr->next;
		}
	}
}