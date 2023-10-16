#ifndef TREE_HPP
#define TREE_HPP

#include "../../Sort.h"

/**
* Basic binary tree node structure
*/
struct Node {
	int key;
	struct Node* l, * r;
};

/**
* Creates a new node
* 
* @param Data for the new node
* 
* @return The new node
*/
struct Node* newNode(int n) {
	struct Node* temp = new Node;
	temp->key = n;
	temp->l = temp->r = nullptr;
	return temp;
}

/**
* Inserts a new node into the tree
* 
* @param Node to be inserted
* @param Key value
* 
* @return The inserted node
*/
Node* insert(Node* node, int key) {
	if (node == nullptr) { return newNode(key); }

	if (key < node->key) {
		node->l = insert(node->l, key);
	}
	else if (key > node->key) {
		node->r = insert(node->r, key);
	}

	return node;
}

/*
	Tree Sort class

	Runs a Tree sort
*/
class Tree : public Sort {
public:
	explicit Tree();				// Default Constructor

	explicit Tree(short length);	// Primary Constructor

	/**
	* Runs the sort
	*/
	void run() override;

	/**
	* Checks the sort
	*/
	void check() override;

	/**
	* Converts an array to a binary tree for certain sorts
	*
	* @param head node
	* @param index
	*/
	void sort_tree(Node* root, int& i);
protected:

private:

};

// Default Constructor
Tree::Tree() : Sort() {
	sort_info._sort_name = "Insertion Sorts: Tree Sort";
}

// Primary Constructor
Tree::Tree(short length) : Sort(length) {
	sort_info._sort_name = "Insertion Sorts: Tree Sort";
}

// Runs the sort
void Tree::run() {
	sort_info.init_labels();
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	while (!started) {}

	//sort_info._elapsed_timer.start();

	// Convert to tree
	Node* head = nullptr;
	++sort_info._n_aux_writes;
		
	head = insert(head, arr[0]);
	for (int i = 1; i < len; ++i) {
		head = insert(head, arr[i]);
		++sort_info._n_aux_writes;
	}

	int i = 0;
	sort_tree(head, i);

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Tree::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

// Converts an array to a binary tree for certain sorts
void Tree::sort_tree(Node* root, int& i) {
	if (root != nullptr) {
		++sort_info._n_comparisons;
		sort_tree(root->l, i);

		++sort_info._n_main_writes;
		arr[i++] = root->key;
		swap_a = i;
		swap_b = i;
		usleep(delay);

		++sort_info._n_comparisons;
		sort_tree(root->r, i);
	}
}

#endif // TREE_HPP