#pragma once
#include <iostream>
class node {
public:
	int data;
	node* left;
	node* right;

	node() {
		data = 69;
		left = nullptr;
		right = nullptr;
	};

	node(int datum) {
		data = datum;
		left = nullptr;
		right = nullptr;
	};

	void newNode(int val, char s) {
		switch (s) {
		case 'l':
			left = new node(val);
			break;
		case 'r':
			right = new node(val);
			break;
		}
	};
	
	/*~node() {
		data = 0;
		delete left;
		delete right;
	}*/

	void setData(int datum) {
		data = datum;
	};

	friend std::ostream &operator<<(std::ostream &output, node &n) {
		output << "Root:\t\t   " <<n.data << '\n';
		if (n.left != nullptr)
			output << "Left child: " << n.left->data<<'\n';
		if (n.right != nullptr)
			output << "Right Child: \t\t" << n.right->data<<'\n';
		return output;
	};

	/*
	friend std::ostream& operator<<(std::ostream& output, node* child) {
		std::cout << '\t' << child->data << '\n';
		return output;
	}
	*/
};

