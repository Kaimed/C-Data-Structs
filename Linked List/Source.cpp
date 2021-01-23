#include "LinkedList.h"
#include <string>

int main()
{
	Linked_List<int> link_list(12);
	link_list.add_node(13);
	link_list.add_node(16);
	link_list.add_node(13);
	link_list.add_node(16);
	link_list.print_list();

	int params[5] = { 4, 23, 55, 756, 12 };
	size_t param_size = 5;
	Linked_List<int> test_list(params[0]);
	for (int i = 1; i < sizeof(params) / sizeof(int); i++)
	{
		try {
			test_list.add_node(params[i]);
		}
		catch (...) {
			std::cout << "Exception was caught reading int array\n";
			break;
		}
	}
	test_list.print_list();
	test_list.~Linked_List();

	std::string words[3] = { "Kevin","Cole","Corpeny" };
	Linked_List<std::string> string_list(words[0]);
	//std::cout << words->size() << '\t' << sizeof(words) / sizeof(std::string) << std::endl;
	for (int i = 1; i <(sizeof(words)/sizeof(std::string)); i++)
	{
		try {
			string_list.add_node(words[i]);
		} 
		catch (...) {
			std::cout << "Exception Caught....\n";
			break;
		}
	}
	string_list.print_list();
	List_Node<std::string>* found = string_list.find("Kevin");
	std::cout << found->data<<'\n';
	return 0;
}