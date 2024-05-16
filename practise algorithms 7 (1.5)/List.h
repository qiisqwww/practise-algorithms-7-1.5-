#include <string>
#include "Node.h"

struct List
{
	// ����
	Node* first;
	Node* last;

	// �����������
	List();
	
	// ������� ������ 
	bool isEmpty();
	void pushBack(std::string val);
	void print();
	Node* find(std::string _val);
	void remove(std::string _val);
	void removeFirst();
	void removeLast();
};