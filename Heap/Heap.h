#pragma once
#define TEMPLATE template <typename T>

TEMPLATE
class hNode {
protected:
	T data;
	hNode* left;
	hNode* right;

public:
	hNode() {
		this->data;
		this->left;
		this->right;
	}

	hNode() {
		this->data = 0;
		this->left = nullptr;
		this->right = nullptr;
	}
	hNode(T datum) {
		this->data = datum;
	}
	hNode(T datum, T lesser, T greater) {
		this->data = datum;
		if (greater > lesser) {
			this->left = new hNode(lesser);
			this->right = new hNode(greater);
		}
		else {
			this->left = new hNode(greater);
			this->right = new hNode(lesser);
		}
	}
};

TEMPLATE
class Heap {
protected:
	hNode* head;
	hNode* current;

public:
	Heap() {
		this->head = new hNode<T>;
		this->current = head;
	}

	Heap(T datum) {
		this->head = new hNode<T>(datum);
		this->current = head;
	}

	Heap(std::array<T, int n> arr) {
		//THERES A SPECIFIC WAY AN ARRAY CAN BE ARRANGED TO BUILD A HEAP EASILY
		//WILL HAVE TO RESEARCH THAT SINCE I DON'T REMEMBER IT FROM DATA STRUCTURES CLASS
		std::sort(arr.begin, arr.end);
		T* ptr = arr;
	}
};