#pragma once

template <class KEY, class VAL>
bool Tree<KEY, VAL>::left_child_exist(Node<KEY, VAL>* node) {
	return node->left != nullptr;
}


template <class KEY, class VAL>
bool Tree<KEY, VAL>::rigth_child_exist(Node<KEY, VAL>* node) {
	return node->rigth != nullptr;
}


template <class KEY, class VAL>
void Tree<KEY, VAL>::push(Node<KEY, VAL>* node, KEY key, VAL value) {
	
	if (key < node->key) {
		if (left_child_exist(node)) {
			push(node->left, key, value);
		}
		else {
			Node<KEY, VAL>* temp = new Node<KEY, VAL>;
			temp->value = value;
			temp->key = key;
			temp->left = nullptr;
			temp->rigth = nullptr;

			node->left = temp;
		}
	}
	else
		if (key > node->key) {
			if (rigth_child_exist(node)) {
				push(node->rigth, key, value);
			}
			else {
				Node<KEY, VAL>* temp = new Node<KEY, VAL>;
				temp->value = value;
				temp->key = key;
				temp->left = nullptr;
				temp->rigth = nullptr;

				node->rigth = temp;
			}
		}
		else
			if (key == node->key) {
				node->value = value;
			}
}


template <class KEY, class VAL>
void Tree<KEY, VAL>::in_order(Node<KEY, VAL>* node, std::list<std::tuple<KEY, VAL>>& items) {
	
	if (left_child_exist(node)) {
		in_order(node->left, std::ref(items));
	}
	std::cout << node->key << " : " << node->value << '\n';

	auto tup = std::make_tuple(node->key, node->value);
	items.push_back(tup);

	if (rigth_child_exist(node)) {
		in_order(node->rigth, std::ref(items));
	}
}