#include <iostream>
#include "List.h"
#include "Node.h"

// Конструктор
List::List() : first(nullptr), last(nullptr){}

// Базовые методы
bool List::isEmpty() {
	return first == nullptr;
}

void List::pushBack(std::string _val) {
	Node* pNode = new Node(_val);

	// Если список пустой, то его начало будет совпадать с концом
	if (isEmpty()) {
		first = pNode;
		last = pNode;
		return;
	}

	// Иначе узел добавляется в конец списка
	last->next = pNode;
	last = pNode;
}	

void List::print() {
	if (isEmpty()) return; 

	Node* pNode = first;
	while (pNode) {
		std::cout << pNode->val << " ";
		pNode = pNode->next;
	}

	std::cout << std::endl;
}

Node* List::find(std::string _val) {
	Node* pNode = first;
	while (pNode && pNode->val != _val) pNode = pNode->next;
	return (pNode && pNode->val == _val) ? pNode : nullptr;
}

void List::remove(std::string _val) {
	if (isEmpty()) return;
	
	if (first->val == _val) {
		removeFirst();
		return;
	}
	else if (last->val == _val) {
		removeLast();
		return;
	}

	Node* slow = first;
	Node* fast = first->next;
	while (fast && fast->val != _val) {
		fast = fast->next;
		slow = slow->next;
	}

	if (!fast) {
		std::cout << "This element does not exist" << std::endl;
		return;
	}

	slow->next = fast->next;
	delete fast;
}

void List::removeFirst() {
	Node* temp = first;
	first = first->next;

	delete temp;
}

void List::removeLast() {
	Node* temp = last;

	Node* runner = first;
	while (runner->next->next) runner = runner->next;

	last = runner;
	delete temp;
}
