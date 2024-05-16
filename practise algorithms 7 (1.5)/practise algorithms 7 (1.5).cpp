#include <iostream>
#include <string>
#include <random>
#include <map>
#include "Node.h"
#include "List.h"

// Первое задание
List getL(List L1, List L2) {
	List L;
	
	// Создаем частотный словарь
	std::map<std::string, int> freqDict;

	Node* L1Node = L1.first;
	Node* L2Node = L2.first;
	while (L1Node->next && L2Node->next) {
		if (freqDict.find(L1Node->val) == freqDict.end()) freqDict[L1Node->val] = 1;
		else freqDict[L1Node->val]++;

		if (freqDict.find(L2Node->val) == freqDict.end()) freqDict[L2Node->val] = 1;
		else freqDict[L2Node->val]++;

		L1Node = L1Node->next;
		L2Node = L2Node->next;
	}

	// Заполняем List L
	for (auto& item : freqDict) {
		L.pushBack(item.first);
	}

	return L;
}

// Второе задание
void removeEvenPositions(List* L1) {
	Node* runner = L1->first;

	while (runner) {
		Node* newNext = runner->next->next;
		delete runner->next;
		runner->next = newNext;

		runner = runner->next;
	}
}

// Третье задание
void insertSumsAfterPairs(List* L2) {
	Node* runner1 = L2->first;
	Node* runner2 = L2->first->next;

	while (runner1 && runner2) {
		Node* newNode = new Node(runner1->val + runner2->val);
		runner1 = runner2->next;
		runner2->next = newNode; 
		newNode->next = runner1;
		if (runner1) runner2 = runner1->next;
	}
}


int main()
{
	srand(time(0));

	// По условию даны два линейных однонаправленных списка L1 и L2
	// Сформирую эти списки. Пусть в каждом будет по 10 строковых переменных
	List L1;
	List L2;

	for (int i = 0; i < 10; i++) {
		while (true) {
			std::string newVal1 = std::to_string(rand() % 10);
			if (!L1.find(newVal1)) {
				L1.pushBack(newVal1); 
				break;
			}
		}
		while (true) {
			std::string newVal2 = std::to_string(rand() % 30);
			if (!L2.find(newVal2)) {
				L2.pushBack(newVal2); 
				break;
			}
		}
	}

	L1.print();
	L2.print();

	// Получаем List L (1 задание)
	List L = getL(L1, L2);
	L.print();

	// Удаляем из L1 все узлы на четных позициях (2 задание)
	removeEvenPositions(&L1);
	L1.print();

	// Вставляем в L2 после каждой пар узлов усел с суммой их значений
	insertSumsAfterPairs(&L2);
	L2.print();

	return 0;
}
