#include "Headers.hpp"
#include "Comp.hpp"


void pressAnyButton() {
	cout << "Press any button to continue . . ." << endl;
	system("pause>>VOID");
}

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
	pressAnyButton();
}


void correctTest(bool CORRECT, string SORT) {
	cout.width(18);
	cout.setf(ios::left);
	cout << SORT;
	cout.width(6);
	if (CORRECT) {
		cout << " is CORRECT" << endl;
	}
	else {
		cout << " is INCORRECT" << endl;
	}
}

template <class T>
void TestSeq(Sequence<T>* arr1, string NAME) {
	system("cls");

	bool bubbleCORRECT = true;
	bool insertCORRECT = true;
	bool selectCORRECT = true;
	bool shellCORRECT = true;
	bool quickCORRECT = true;

	shuffle<int>(arr1);
	
	bubbleCORRECT = true;
	bubbleSorter<int>* bSorter = new bubbleSorter<int>();
	bSorter->Sort(arr1, bigger);

	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != i) {
			bubbleCORRECT = false;
		}
	}

	shuffle<int>(arr1);

	bSorter->Sort(arr1, lower);

	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != 99 - i) {
			bubbleCORRECT = false;
		}
	}
	delete bSorter;
	shuffle<int>(arr1);


	insertCORRECT = true;
	insertSorter<int>* insSorter = new insertSorter<int>();
	insSorter->Sort(arr1, bigger);

	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != i) {
			insertCORRECT = false;
		}
	}
	shuffle<int>(arr1);

	insSorter->Sort(arr1, lower);
	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != 99 - i) {
			insertCORRECT = false;
		}
	}
	delete insSorter;
	shuffle<int>(arr1);


	selectCORRECT = true;
	selectSorter<int>* selSorter = new selectSorter<int>();
	selSorter->Sort(arr1, bigger);

	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != i) {
			selectCORRECT = false;
		}
	}
	shuffle<int>(arr1);

	selSorter->Sort(arr1, lower);
	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != 99 - i) {
			selectCORRECT = false;
		}
	}

	delete selSorter;
	shuffle<int>(arr1);


	shellCORRECT = true;
	shellSorter<int>* shSorter = new shellSorter<int>();
	shSorter->Sort(arr1, bigger);

	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != i) {
			shellCORRECT = false;
		}
	}
	shuffle<int>(arr1);

	shSorter->Sort(arr1, lower);
	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != 99 - i) {
			shellCORRECT = false;
		}
	}

	delete shSorter;
	shuffle<int>(arr1);


	quickCORRECT = true;
	quickSorter<int>* qSorter = new quickSorter<int>();
	qSorter->Sort(arr1, bigger);

	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != i) {
			quickCORRECT = false;
		}
	}
	shuffle<int>(arr1);

	qSorter->Sort(arr1, lower);
	for (int i = 0; i < 100; i++) {
		if (arr1->Get(i) != 99 - i) {
			quickCORRECT = false;
		}
	}

	delete qSorter;
	shuffle<int>(arr1);

	system("cls");
	cout << endl;
	cout << NAME << endl;
	cout << endl;
	cout << "Sort's test results:" << endl;
	cout << endl;
	correctTest(bubbleCORRECT, "bubbleSort");
	correctTest(insertCORRECT, "insertionSort");
	correctTest(selectCORRECT, "selectionSort");
	correctTest(shellCORRECT, "shellSort");
	correctTest(quickCORRECT, "quickSort");

	cout << endl << endl;
	pressAnyButton();
}

void Test() {
	const int SIZE = 100;
	ArraySequence<int>* arr = new ArraySequence<int>(SIZE);

	for (int i = 0; i < SIZE; ++i) {
		arr->Set(i, i);
	}

	TestSeq(arr, "ARRAY TEST:");
	delete arr;

	ListSequence<int>* seq = new ListSequence<int>();

	for (int i = 0; i < SIZE; ++i) {
		seq->Prepend(i);
	}

	TestSeq(seq, "LIST TEST:");
	delete seq;
}