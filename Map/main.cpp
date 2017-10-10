#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Btree.h"


using namespace std;


void main()
{
	srand(time(NULL));

	Tree<int, int> map;
	for (int i = 0; i < 10; i++) {
		int key = rand();
		map.insert(key, i);
		cout << "inserted " << key << " : " << i << '\n';
	}

	cout << endl;
	for (tuple<int, int> tup : map.in_order_items()) {
		cout << get<0>(tup) << ' ' << get<1>(tup) << '\n';
	}

	system("pause");
}