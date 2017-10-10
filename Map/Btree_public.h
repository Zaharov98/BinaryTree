#include <list>
#pragma once

template <class KEY, class VAL>
void Tree<KEY, VAL>::insert(KEY key, VAL value)
{
	if (t_size == 0) {
		Node<KEY, VAL>* temp = new Node<KEY, VAL>;
		temp->key = key;
		temp->value = value;
		temp->rigth = nullptr;
		temp->left = nullptr;

		crone = temp;
		t_size++;
	}
	else {
		push(crone, key, value);
		t_size++;
	}
}


template <class KEY, class VAL>
std::list<std::tuple<KEY, VAL>> Tree<KEY, VAL>::in_order_items()
{
	std::list<std::tuple<KEY, VAL>> items(t_size);

	if (t_size != 0) {
		in_order(crone, std::ref(items));
	}
	else {
		return items;
	}
}