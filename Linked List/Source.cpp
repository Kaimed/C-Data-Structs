#include "LinkedList.h"

int main()
{
	Linked_List<int> link_list(12);
	link_list.add_node(13);
	link_list.add_node(16);
	link_list.add_node(13);
	link_list.add_node(16);
	link_list.print_list();

	int params[5] = {2, 6, 13, 114, 12};
	Linked_List<int> test_list(params);
	test_list.print_list();
	return 0;
}