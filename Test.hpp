#include "Headers.hpp"

template <class T>
void printArrTest(ArraySequence<T>* seq) {
	cout << "-----------------------------------Test Array-------------------------------------" << endl;
	cout << endl;
	cout << "[";
	for (int i = 0; i < seq->GetSize() - 1; ++i) {
		cout << seq->Get(i) << ",  ";
	}
	cout << seq->Get(seq->GetSize() - 1) << "]" << endl << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
}


void Test() {

	int SIZE = rand() % 10000 + 1000;

	ArraySequence<int>* arr1 = new ArraySequence<int>(SIZE);

	

	for (int i = 0; i < SIZE; ++i) {

		arr1->Set(i, (rand() % 100000) - 15000);

	}


	printArrTest(arr1);
	
	bubbleSorter<int>* bSorter = new bubbleSorter<int>();
	bSorter->Sort(arr1);

	shuffle<int>(arr1);


	insertSorter<int>* insSorter = new insertSorter<int>();
	insSorter->Sort(arr1);

	shuffle<int>(arr1);


	selectSorter<int>* selSorter = new selectSorter<int>();
	selSorter->Sort(arr1);

	shuffle<int>(arr1);


	shellSorter<int>* shSorter = new shellSorter<int>();
	shSorter->Sort(arr1);

	shuffle<int>(arr1);


	quickSorter<int>* qSorter = new quickSorter<int>();
	qSorter->Sort(arr1);





}