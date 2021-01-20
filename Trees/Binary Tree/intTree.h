#pragma once
#include "intNode.h"
#include <stack>

class Tree {
protected:
	node* root;

public:
	Tree();
	Tree(node* top);
};

Tree::Tree() {
	root = nullptr;
}

Tree::Tree(node* top) {
	root = top;
}