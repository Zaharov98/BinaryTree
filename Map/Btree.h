#include <iostream>
#include <list>
#include <tuple>
#include <functional>
#pragma once


template <class KEY, class VAL>
struct Tree
{
private:
// private fields

	template <class KEY, class VAL>
	struct Node {
	public:
		KEY key;
		VAL value;
		Node* left;
		Node* rigth;
	};

	Node<KEY, VAL>* crone;
	int t_size = 0;


private:
// private methods

	bool left_child_exist(Node<KEY, VAL>* node);
	bool rigth_child_exist(Node<KEY, VAL>* node);
	void push(Node<KEY, VAL>* node, KEY key, VAL value);
	void in_order(Node<KEY, VAL>* node, std::list<std::tuple<KEY, VAL>>& items);

public:
// public methods

	void insert(KEY, VAL);
	std::list<std::tuple<KEY, VAL>> in_order_items();
};

#include "Btree_private.h"
#include "Btree_public.h"