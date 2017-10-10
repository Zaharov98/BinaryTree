#include <iterator>

#ifndef MY_DNS
#define MY_DNS

/* my piesant container
with basic functions
like in STL std::List
but without iterators */


template <class TYPE>
class List { 
// my guerrillian container: List
private:

	template <class TYPE>
	struct Node
	{ // node of List container
		TYPE value;
		Node* previos;
		Node* next;
	};


	class Nil { 
	// singleton private Null
	public:
		
		static void* instance() {
			static Nil nil;
			static void* nill_ptr = &nil;
			return nill_ptr;
		}
	
	private:

		Nil() { }
		~Nil() { }

		Nil(Nil const& temp) = delete;
		Nil operator=(Nil const& temp) = delete;
	};
	

public:

	class iterator {
	// List iterator objt, compatible with STL algorithm functions 
	public:

		typedef iterator self_type;
		typedef TYPE value_type;
		typedef TYPE& reference;
		typedef TYPE* pointer;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef int difference_type;

		explicit iterator() { }
		explicit iterator(Node<value_type>* node_ptr) : current_node(node_ptr) { }
		self_type operator=(self_type& other_it) noexcept {
			current_node = reinterpret_cast<self_type*>(&other_it)->current_node;
		}
		
		const self_type& operator ++ () noexcept { 
			current_node = current_node->next;
			return *this;
		}
		const self_type& operator -- () noexcept {
			current_node = current_node->previos;
			return *this;
		}
		const reference operator * () noexcept {
			return static_cast<reference>((*current_node).value);
		}

		bool operator == (self_type& comp) noexcept {
			return current_node == reinterpret_cast<self_type*>(&comp)->current_node;
		}
		bool operator != (self_type& comp) noexcept {
			return current_node != reinterpret_cast<self_type*>(&comp)->current_node;
		}

		friend Node<TYPE>* iter_node(typename List<TYPE>::iterator&);

	private:

		Node<value_type>* current_node; 
	};


private:

	int l_size = 0;
	Node<TYPE>* begin_ptr;
	Node<TYPE>* end_ptr;


	friend Node<TYPE>* iter_node(typename List<TYPE>::iterator& it) {
		Node<TYPE>* node_ptr = it.current_node;
		return node_ptr;
	}
	

public:

	List() { }

	void push_back(TYPE);
	void push_front(TYPE);
	void insert(typename List<TYPE>::iterator&, TYPE);
	void erase(typename List<TYPE>::iterator&);
	void erase(typename List<TYPE>::iterator&, typename List<TYPE>::iterator&);
	TYPE pop_back();
	TYPE pop_front();
	TYPE back();
	TYPE front();
	typename List<TYPE>::iterator begin();
	typename List<TYPE>::iterator end();
	int size();
	bool empty();
};


#include "List_public.h"


#endif
