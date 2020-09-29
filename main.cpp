#include <iostream>
#include "BinaryTree.hpp"

#include "NewMenu.hpp"

using namespace std;


int main(void) {

	srand(time(NULL));

	/*
	int n;
	int iterations;
	int comporations;

	cout << "Input size: " << endl;
	cin >> n;

	ArraySequence<int>* seq = new ArraySequence<int>(n);

	cout << endl << "      Random array: " << endl;
	cout << "[";
	for (int i = 0; i < n - 1; ++i) {

		seq->Set(i, (rand() % 100000) - 15000);
		cout << seq->Get(i) << ",  ";

	}
	
	seq->Set(n - 1, rand() % 100000 - 15000); 

	cout << seq->Get(n - 1) << "]" << endl << endl;

	// Сортировка пузырьком
	
	bubbleSorter<int>* sorter = new bubbleSorter<int>();

	cout << endl << "      bubbleSort: " << endl << endl;
	Timer* timer1 = new Timer();
	sorter->Sort(seq);
	delete timer1;
	iterations = sorter->iterations;
	comporations = sorter->comporations;
	
	output(seq, iterations, comporations);
	coution();

	shuffle(seq);

	// Сортируем вставками
	
	insertSorter<int>* insSorter = new insertSorter<int>();

	cout << endl << "      insertionSort: " << endl << endl;
	Timer* timer2 = new Timer();
	insSorter->Sort(seq);
	delete timer2;
	iterations = insSorter->iterations;
	comporations = insSorter->comporations;
	
	output(seq, iterations, comporations);
	coution();

	shuffle(seq);

	// Сортировка методом простого выбора
	
	chooseSorter<int>* chSorter = new chooseSorter<int>();

	cout << endl << "      simpleChoiceSort: " << endl << endl;
	Timer* timer3 = new Timer();
	chSorter->Sort(seq);
	delete timer3;
	iterations = chSorter->iterations;
	comporations = chSorter->comporations;
	
	output(seq, iterations, comporations);
	coution();

	shuffle(seq);

	// Сортировка Шелла
	
	shellSorter<int>* shSorter = new shellSorter<int>();

	cout << endl << "      ShellSort: " << endl << endl;
	Timer* timer4 = new Timer();
	shSorter->Sort(seq);
	delete timer4;
	iterations = shSorter->iterations;
	comporations = shSorter->comporations;
	
	output(seq, iterations, comporations);
	coution();

	shuffle(seq);

	// Быстрая сортировка
	
	quickSorter<int>* qSorter = new quickSorter<int>();

	cout << endl << "      quickSort: " << endl << endl;
	Timer* timer5 = new Timer();
	qSorter->Sort(seq);
	delete timer5;
	iterations = qSorter->iterations;
	comporations = qSorter->comporations;
	
	output(seq, iterations, comporations);
	coution();
	*/

	NewMenu<double>();

	return 0;
}