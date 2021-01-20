#include "LinkedList.h"

int main()
{
	Linked_List<int> link_list(12);
	link_list.add_node(13);
	link_list.print_list();
	return 0;
}