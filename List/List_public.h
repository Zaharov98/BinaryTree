#pragma once

/*template <class TYPE>
TYPE& List<TYPE>::operator[](int i)
{
	if (i < 0 || i >= l_size) {
		std::exception err("operator [] exception\n");
		throw err;
	}


	if ((i < l_size / 2) && i < l_size) {
		Node<TYPE>* temp = begin_ptr;

		for (int j = 0; j < i; j++) {
			temp = temp->next;
		}

		return temp->value;
	}
	else
		if (i < l_size) {
			Node<TYPE>* temp = end_ptr;

			for (int j = 0; j < l_size - i - 1; j++) {
				temp = temp->previos;
			}

			return temp->value;
		}
}*/


template <class TYPE>
void List<TYPE>::push_back(TYPE value)
{
	if (l_size == 0) {
		Node<TYPE>* temp = new Node<TYPE>;
		temp->value = value;
		temp->next = static_cast<Node<TYPE>*>(Nil::instance());
		temp->previos = static_cast<Node<TYPE>*>(Nil::instance()); //Nill::instance();

		begin_ptr = end_ptr = temp;
		l_size++;
	}
	else
	{
		Node<TYPE>* temp = new Node<TYPE>;
		temp->value = value;
		temp->next = static_cast<Node<TYPE>*>(Nil::instance());
		temp->previos = end_ptr;

		end_ptr->next = temp;
		//end_ptr->previos = end_ptr; mistake in lesson example
		end_ptr = temp;
		l_size++;
	}
}


template <class TYPE>
void List<TYPE>::push_front(TYPE value)
{
	if (l_size == 0) {
		Node<TYPE>* temp = new Node<TYPE>;
		temp->value = value;
		temp->next = static_cast<Node<TYPE>*>(Nil::instance());
		temp->previos = static_cast<Node<TYPE>*>(Nil::instance());

		begin_ptr = end_ptr = temp;
		l_size++;
	}
	else
	{
		Node<TYPE>* temp = new Node<TYPE>;
		temp->value = value;
		temp->next = begin_ptr;
		temp->previos = static_cast<Node<TYPE>*>(Nil::instance());

		begin_ptr->previos = temp;
		begin_ptr = temp;
		l_size++;
	}
}


template <class TYPE>
void List<TYPE>::insert(typename List<TYPE>::iterator &pos, TYPE value)
{
	if (pos == List<TYPE>::begin()) {
		List<TYPE>::push_front(value);
	}
	else
		if (pos == List<TYPE>::end()) {
			List<TYPE>::push_back(value);
		}
		else {
			Node<TYPE>* current = iter_node(pos);

			Node<TYPE>* new_node = new Node<TYPE>;
			new_node->value = value;
			new_node->previos = current->previos;
			new_node->next = current;
			current->previos->next = new_node;
			current->previos = new_node;
		}
}


template <class TYPE>
void List<TYPE>::erase(typename List<TYPE>::iterator& pos)
{
	if (pos == List<TYPE>::begin()) {
		List<TYPE>::pop_front();
	}
	else
		if (pos == List<TYPE>::end()) {
			List<TYPE>::pop_back();
		}
		else {
			Node<TYPE>* current = iter_node(pos);

			current->next->previos = current->previos;
			current->previos->next = current->next;
			delete current;
		}
}


template <class TYPE>
void List<TYPE>::erase(typename List<TYPE>::iterator& left, typename List<TYPE>::iterator& right)
{
	auto it = left;

	Node<TYPE>* left_node = iter_node(left);
	Node<TYPE>* right_node = iter_node(right);
	left_node->next = right_node;
	right_node->previos = left_node;

	while (it != right)
	{
		Node<TYPE>* temp = iter_node(it);
		++it;
		delete temp;
	}

}


template <class TYPE>
TYPE List<TYPE>::pop_back()
{
	Node<TYPE>* temp = end_ptr;

	TYPE return_value = end_ptr->value;

	end_ptr = end_ptr->previos;
	//end_ptr->next = Nill::instace();

	delete temp;
	l_size--;

	return return_value;
}


template <class TYPE>
TYPE List<TYPE>::pop_front()
{
	Node<TYPE>* temp = begin_ptr;

	TYPE return_value = begin_ptr->value;

	begin_ptr = begin_ptr->next;
	begin_ptr->previos = static_cast<Node<TYPE>*>(Nil::instance());

	delete temp;
	l_size--;

	return return_value;
}


template <class TYPE>
TYPE List<TYPE>::back() {
	return end_ptr->value;
}


template <class TYPE>
TYPE List<TYPE>::front() {
	return begin_ptr->value;
}


template <class TYPE>
typename List<TYPE>::iterator List<TYPE>::begin() {
	iterator begin_it(this->begin_ptr);
	return begin_it;
}


template <class TYPE>
typename List<TYPE>::iterator List<TYPE>::end() {
	iterator end_it(end_ptr->next);
	return end_it;
}


template <class TYPE>
int List<TYPE>::size() {
	return l_size;
}


template <class TYPE>
bool List<TYPE>::empty() {
	return l_size == 0;
}
