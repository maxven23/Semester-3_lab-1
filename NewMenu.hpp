#include "Headers.hpp"
#include "Timer.hpp"
#include "Sorts.hpp"
#include "Test.hpp"

void pressAnyButton() {
	cout << "Press any button to continue . . ." << endl;
	system("pause>>VOID");
}

template <class T>
void printArr(ArraySequence<T>* seq) {
	cout << "-----------------------------------Your Array-------------------------------------" << endl;
	cout << endl;
	cout << "[";
	for (int i = 0; i < seq->GetSize() - 1; ++i) {
		cout << seq->Get(i) << ",  ";
	}
	cout << seq->Get(seq->GetSize() - 1) << "]" << endl << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
}

template <class T>
void output(ArraySequence<T>* seq, int iter, int compor) {

	cout << "      Number of elements: " << seq->GetSize() << endl;
	cout << "      Number of iterations: " << iter << endl;
	cout << "      Number of comparisons: " << compor << endl;
	
	cout << endl << "------------------------------(NEW) Sorted Array---------------------------------" << endl << endl;
	cout << "[";
	for (int i = 0; i < seq->GetSize() - 1; ++i) {

		cout << seq->Get(i) << ",  ";

	}
	cout << seq->Get(seq->GetSize() - 1) << "]" << endl << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	
}

void coution() {
	cout << endl;
	cout << endl;
	cout << endl;
}

template <class T>
void manualFill(ArraySequence<T>* arr) {

	T item;

	for (int i = 0; i < arr->GetSize(); i++) {
		system("cls");
		item = { 0 };

		cout << endl;
		cout << "       Enter element #" << i + 1 << ":  ";

		cin >> item;
		arr->Set(i, item);

	}

	printArr(arr);
	cout << endl;

	pressAnyButton();
	
}


// Рандомно заполняется только массив с целыми/вещественными числами (вещ. - ((((double)rand() % 100000) - 15000) / 10000) )
template <class T>
void randomFill(ArraySequence<T>* arr) {

	for (int i = 0; i < arr->GetSize(); ++i) {

		arr->Set(i, (rand() % 100000) - 15000);

	}

	printArr(arr);
	cout << endl;

	pressAnyButton();

}


void selectSortMenu() {
	
	system("cls");
	cout << "--------------select SORT--------------" << endl;
	cout << endl;
	cout << "          1. Bubble Sort" << endl;
	cout << "          2. Insertions Sort" << endl;
	cout << "          3. Simple Selection Sort" << endl;
	cout << "          4. Shell Sort" << endl;
	cout << "          5. Quick Sort" << endl;
	cout << "          " << endl;
	cout << "          6. Print Array" << endl;
	cout << "          7. Shuffle Array" << endl;
	cout << "          " << endl;
	cout << "          0. Exit" << endl;
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;

}

template <class T>
void selectSort(ArraySequence<T>* seq) {
	
	int CHOICE = -1;
	int iterations;
	int comparisons;

	while (true) {
		int CHOICE = -1;
		while (CHOICE == -1) {

			selectSortMenu();
			cout << "      ";
			cin >> CHOICE;
			if (CHOICE < 0 || CHOICE > 9) {
				CHOICE = -1;
			}

		}


		if (CHOICE == 1) {
			system("cls");

			printArr(seq);

			bubbleSorter<T>* sorter = new bubbleSorter<T>();

			cout << endl << "      bubbleSort: " << endl << endl;
			Timer* timer1 = new Timer();
			sorter->Sort(seq);
			delete timer1;
			iterations = sorter->iterations;
			comparisons = sorter->comparisons;

			output(seq, iterations, comparisons);
			coution();

			pressAnyButton();
		}

		else if (CHOICE == 2) {
			system("cls");

			printArr(seq);

			insertSorter<T>* insSorter = new insertSorter<T>();

			cout << endl << "      insertionSort: " << endl << endl;
			Timer* timer2 = new Timer();
			insSorter->Sort(seq);
			delete timer2;
			iterations = insSorter->iterations;
			comparisons = insSorter->comparisons;

			output(seq, iterations, comparisons);
			coution();

			pressAnyButton();
		}

		else if (CHOICE == 3) {
			system("cls");

			printArr(seq);

			selectSorter<T>* selSorter = new selectSorter<T>();

			cout << endl << "      simpleSelectionSort: " << endl << endl;
			Timer* timer3 = new Timer();
			selSorter->Sort(seq);
			delete timer3;
			iterations = selSorter->iterations;
			comparisons = selSorter->comparisons;

			output(seq, iterations, comparisons);
			coution();

			pressAnyButton();
		}

		else if (CHOICE == 4) {
			system("cls");;
			
			printArr(seq);

			shellSorter<T>* shSorter = new shellSorter<T>();

			cout << endl << "      ShellSort: " << endl << endl;
			Timer* timer4 = new Timer();
			shSorter->Sort(seq);
			delete timer4;
			iterations = shSorter->iterations;
			comparisons = shSorter->comparisons;

			output(seq, iterations, comparisons);
			coution();

			pressAnyButton();
		}

		else if (CHOICE == 5) {
			system("cls");

			printArr(seq);

			quickSorter<T>* qSorter = new quickSorter<T>();

			cout << endl << "      quickSort: " << endl << endl;
			Timer* timer5 = new Timer();
			qSorter->Sort(seq);
			delete timer5;
			iterations = qSorter->iterations;
			comparisons = qSorter->comparisons;

			output(seq, iterations, comparisons);
			coution();

			pressAnyButton();
		}

		else if (CHOICE == 6) {
			system("cls");

			printArr(seq);

			pressAnyButton();
		}

		else if (CHOICE == 7) {
			system("cls");

			shuffle(seq);

			pressAnyButton();
		}

		else if (CHOICE == 0) {
			system("cls");
			cout << endl << "      Closing . . ." << endl;
			exit(1);
		}
	}
}

template  <class T>
int creatingMenu(ArraySequence<T>* arr) {
	system("cls");

	bool ON1 = true;
	int FILL = -1;

	while (ON1) {
		system("cls");

		cout << endl;
		cout << "         1. Fill in the array manually" << endl;
		cout << "         2. Fill in the array randomly" << endl;
		cout << endl;
		cout << "         0. Back" << endl;
		cout << endl;
		cout << "-------------------------------------------------" << endl;
		cout << endl;
		cout << "         ";

		cin >> FILL;

		if (FILL < 0 || FILL > 2) {
			FILL = -1;
		}

		else if (FILL == 1) {
			system("cls");

			manualFill<T>(arr);
			ON1 = false;
		}

		else if (FILL == 2) {
			system("cls");

			randomFill<T>(arr);
			ON1 = false;
		}

		else if (FILL == 0) {
			system("cls");

			int BACK = -1;
			return BACK;

		}
	}
	return 0;
}

template <class T>
void StartMenu() {
	bool ON = true;
	int INPUT = -1;


	while (ON) {
		system("cls");

		cout << endl;
		cout << "         1. Create new array" << endl;
		cout << "         2. Make tests" << endl;
		cout << endl;
		cout << "         0. Exit" << endl;
		cout << endl;
		cout << "----------------------------------------" << endl;
		cout << endl;
		cout << "  Input: ";

		cin >> INPUT;

		if (INPUT < 0 || INPUT > 2) {

			INPUT = -1;

		}

		else if (INPUT == 0) {

			system("cls");
			cout << endl;
			cout << "         Closing . . ." << endl;
			exit(1);

		}

		else if (INPUT == 1) {

			int SIZE = -1;

			while (SIZE == -1) {
				system("cls");

				cout << endl;
				cout << "        Enter SIZE of your array:  ";

				cin >> SIZE;

				if (SIZE < 0 || SIZE > MAXINT) {
					SIZE = -1;
				}

				else {

					ArraySequence<T>* arr = new ArraySequence<T>(SIZE);
					int NEXT = creatingMenu<T>(arr);

					if (NEXT == 0) {
						selectSort(arr);
					}

					else {
						delete arr;
						break;
					}
				}
			}
		}
		
		else if (INPUT == 2) {
			Test();
		}
	}
}

template <class T>
void NewMenu() {

	StartMenu<T>();
	
};