#include <string>

struct Node
{
	// Поля
	std::string val;
	Node* next;

	// Конструктор
	Node(std::string _val);
};

