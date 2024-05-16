#include <iostream>
#include <string>
#include <random>
#include "Node.h"
#include "List.h"


int main()
{
	srand(time(0));

	// По условию даны два линейных однонаправленных списка L1 и L2
	// Сформирую эти списки. Пусть в каждом будет по 10 строковых переменных
	List L1;
	List L2;

	for (int i = 0; i < 10; i++) {
		L1.pushBack(std::to_string(rand() % 100));
		L2.pushBack(std::to_string(rand() % 100));
	}

	L1.print();
	L2.print();

	return 0;
}
