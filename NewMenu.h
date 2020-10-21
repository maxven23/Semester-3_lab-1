#include "Headers.h"
#include "Timer.h"
#include "Sorts.h"
#include "Test.h"
#include <vld.h>




template <class T>
void printArr(Sequence<T>* seq) {

	cout << "---------------------------------Your Sequence------------------------------------" << endl;
	cout << endl;
	cout << "[";
	for (int i = 0; i < seq->GetSize() - 1; ++i) {
		cout << seq->Get(i) << ",  ";
	}
	cout << seq->Get(seq->GetSize() - 1) << "]" << endl << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

}

template <class T>
void output(Sequence<T>* seq, int iter, int compor) {

	cout << "      Number of elements: " << seq->GetSize() << endl;
	cout << "      Number of iterations: " << iter << endl;
	cout << "      Number of comparasions: " << compor << endl;

}

template <class T>
void sorterSeq(Sequence<T>* seq) {
	if (seq->GetSize() <= 1000) {

		cout << endl << "-----------------------------(NEW) Sorted Sequence-------------------------------" << endl << endl;
		cout << "[";
		for (int i = 0; i < seq->GetSize() - 1; ++i) {

			cout << seq->Get(i) << ",  ";

		}
		cout << seq->Get(seq->GetSize() - 1) << "]" << endl << endl;
		cout << "----------------------------------------------------------------------------------" << endl;
	}
}

void coution() {
	cout << endl;
	cout << endl;
	cout << endl;
}

template <class T>
void manualFill(Sequence<T>* arr) {

	T item;

	for (int i = 0; i < arr->GetSize(); i++) {
		system("cls");
		item = { 0 };

		cout << endl;
		cout << "       Enter element #" << i + 1 << ":  ";

		cin >> item;
		arr->Set(i, item);

	}

	if (arr->GetSize() <= 1000) {
		printArr(arr);
	}

	cout << endl;

	pressAnyButton();
	
}

template <class T>
void manualFillList(Sequence<T>* seq, int size) {

	T item;

	for (int i = 0; i < size; i++) {
		system("cls");
		item = { 0 };

		cout << endl;
		cout << "       Enter element #" << i + 1 << ":  ";

		cin >> item;
		//seq->Append(item);
		seq->Prepend(item);

	}

	if (size <= 1000) {
		printArr(seq);
	}

	cout << endl;

	pressAnyButton();

}

// Рандомно заполняется только массив с целыми/вещественными числами (вещ. - ((((double)rand() % 100000) - 15000) / 10000) )
template <class T>
void randomFill(Sequence<T>* arr) {

	for (int i = 0; i < arr->GetSize(); ++i) {

		arr->Set(i, i);

	}

	shuffle(arr);

	if (arr->GetSize() <= 1000) {
		printArr(arr);
	}

	cout << endl;

	pressAnyButton();

}

template <class T>
void randomFillList(Sequence<T>* seq, int size) {

	for (int i = 0; i < size; ++i) {

		//seq->Append((rand() % 100000) - 15000);
		seq->Prepend(i);

	}

	if (size <= 1000) {
		printArr(seq);
	}

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
	cout << "          8. Sort compare (Only for ArraySeq (temp))" << endl;
	cout << "          " << endl;
	cout << "          0. Exit" << endl;
	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;

}


template <class T>
void sortComparasion(Sequence<T>* seq, ISorter<T>* sorter1, ISorter<T>* sorter2, string nameSort1, string nameSort2) {
	system("cls");

	ArraySequence<T>* seq_copy = new ArraySequence<T>(seq->GetSize());
	for (int i = 0; i < seq->GetSize(); i++) {
		seq_copy->Set(i, seq->Get(i));
	}

	Timer* timer1 = new Timer();
	sorter1->Sort(seq, bigger);
	double duration1 = timer1->Time();
	delete timer1;

	long long comp1 = sorter1->getComp();
	long long iter1 = sorter1->getIter();


	Timer* timer2 = new Timer();
	sorter2->Sort(seq_copy, bigger);
	double duration2 = timer2->Time();
	delete timer2;

	long long comp2 = sorter2->getComp();
	long long iter2 = sorter2->getIter();

	cout << endl;
	cout << " Number of elements: " << seq->GetSize() << endl;
	cout << endl;
	cout << " " << nameSort1 << endl;
	cout << "   Sorting Time: " << duration1 << " sec" << endl;
	cout << "   Number of Iterations: " << iter1 << endl;
	cout << "   Number of Comparasions: " << comp1 << endl;
	cout << endl;
	cout << "-----------------------" << endl;
	cout << endl;
	cout << "  " << nameSort2 << endl;
	cout << "   Sorting Time: " << duration2 << " sec" << endl;
	cout << "   Number of Iterations: " << iter2 << endl;
	cout << "   Number of Comparasions: " << comp2 << endl;
	cout << endl;

	delete seq_copy;
	pressAnyButton();
}

template <class T>
void selectSort(Sequence<T>* seq) {
	
	int CHOICE = -1;
	int CHOICE1 = -1;
	long long iterations;
	long long comparasions;

	while (true) {
		double duration;
		int CHOICE = -1;
		while (CHOICE == -1) {

			selectSortMenu();
			cout << "Input:  ";
			cin >> CHOICE;
			if (CHOICE < 0 || CHOICE > 9) {
				CHOICE = -1;
			}

		}


		if (CHOICE == 1) {
			CHOICE1 = -1;
			system("cls");

			bubbleSorter<T>* sorter = new bubbleSorter<T>();
			
			while (CHOICE1 == -1) {

				system("cls");

				cout << endl;
				cout << "        Choose order of sorting: " << endl;
				cout << endl;
				cout << "        1. Sort in ascending" << endl;
				cout << "        2. Sort in descending" << endl;
				cout << endl;
				cout << "---------------------------------------" << endl;
				cout << endl;
				cout << "Input:  ";

				cin >> CHOICE1;

				if (CHOICE1 < 1 || CHOICE1 > 2) {
					CHOICE1 = -1;
				}

				else if (CHOICE1 == 1) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					sorter->Sort(seq, bigger);
					duration = timer1->Time();
					delete timer1;

					iterations = sorter->getIter();
					comparasions = sorter->getComp();

					sorterSeq(seq);
					
					cout << endl << "      bubbleSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}

				else if (CHOICE1 == 2) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					sorter->Sort(seq, lower);
					duration = timer1->Time();
					delete timer1;

					iterations = sorter->getIter();
					comparasions = sorter->getComp();

					sorterSeq(seq);

					cout << endl << "      bubbleSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}
			}
			delete sorter;
		}

		else if (CHOICE == 2) {
			CHOICE1 = -1;
			system("cls");

			insertSorter<T>* insSorter = new insertSorter<T>();
			while (CHOICE1 == -1) {

				system("cls");

				cout << endl;
				cout << "        Choose order of sorting: " << endl;
				cout << endl;
				cout << "        1. Sort in ascending" << endl;
				cout << "        2. Sort in descending" << endl;
				cout << endl;
				cout << "---------------------------------------" << endl;
				cout << endl;
				cout << "Input:  ";

				cin >> CHOICE1;

				if (CHOICE1 < 1 || CHOICE1 > 2) {
					CHOICE1 = -1;
				}

				else if (CHOICE1 == 1) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					insSorter->Sort(seq, bigger);
					duration = timer1->Time();
					delete timer1;

					iterations = insSorter->getIter();
					comparasions = insSorter->getComp();

					sorterSeq(seq);
			
					cout << endl << "      insertionSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}

				else if (CHOICE1 == 2) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					insSorter->Sort(seq, lower);
					duration = timer1->Time();
					delete timer1;

					iterations = insSorter->getIter();
					comparasions = insSorter->getComp();

					sorterSeq(seq);

					cout << endl << "      insertionSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}
			}
			delete insSorter;
		}

		else if (CHOICE == 3) {
			system("cls");
			CHOICE1 = -1;

			selectSorter<T>* selSorter = new selectSorter<T>();

			while (CHOICE1 == -1) {

				system("cls");

				cout << endl;
				cout << "        Choose order of sorting: " << endl;
				cout << endl;
				cout << "        1. Sort in ascending" << endl;
				cout << "        2. Sort in descending" << endl;
				cout << endl;
				cout << "---------------------------------------" << endl;
				cout << endl;
				cout << "Input:  ";

				cin >> CHOICE1;

				if (CHOICE1 < 1 || CHOICE1 > 2) {
					CHOICE1 = -1;
				}

				else if (CHOICE1 == 1) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					selSorter->Sort(seq, bigger);
					duration = timer1->Time();
					delete timer1;

					iterations = selSorter->getIter();
					comparasions = selSorter->getComp();

					sorterSeq(seq);

					cout << endl << "      simpleSelectionSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}

				else if (CHOICE1 == 2) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					selSorter->Sort(seq, lower);
					duration = timer1->Time();
					delete timer1;

					iterations = selSorter->getIter();
					comparasions = selSorter->getComp();

					sorterSeq(seq);

					cout << endl << "      simpleSelectionSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}
			}
			delete selSorter;
		}

		else if (CHOICE == 4) {
			system("cls");;
			CHOICE1 = -1;

			shellSorter<T>* shSorter = new shellSorter<T>();

			while (CHOICE1 == -1) {

				system("cls");

				cout << endl;
				cout << "        Choose order of sorting: " << endl;
				cout << endl;
				cout << "        1. Sort in ascending" << endl;
				cout << "        2. Sort in descending" << endl;
				cout << endl;
				cout << "---------------------------------------" << endl;
				cout << endl;
				cout << "Input:  ";

				cin >> CHOICE1;

				if (CHOICE1 < 1 || CHOICE1 > 2) {
					CHOICE1 = -1;
				}

				else if (CHOICE1 == 1) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					shSorter->Sort(seq, bigger);
					duration = timer1->Time();
					delete timer1;

					iterations = shSorter->getIter();
					comparasions = shSorter->getComp();

					sorterSeq(seq);

					cout << endl << "      ShellSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}

				else if (CHOICE1 == 2) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					shSorter->Sort(seq, lower);
					duration = timer1->Time();
					delete timer1;

					iterations = shSorter->getIter();
					comparasions = shSorter->getComp();

					sorterSeq(seq);

					cout << endl << "      ShellSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}
			}
			delete shSorter;
		}

		else if (CHOICE == 5) {
			system("cls");
			CHOICE1 = -1;

			quickSorter<T>* qSorter = new quickSorter<T>();

			while (CHOICE1 == -1) {

				system("cls");

				cout << endl;
				cout << "        Choose order of sorting: " << endl;
				cout << endl;
				cout << "        1. Sort in ascending" << endl;
				cout << "        2. Sort in descending" << endl;
				cout << endl;
				cout << "---------------------------------------" << endl;
				cout << endl;
				cout << "Input:  ";

				cin >> CHOICE1;

				if (CHOICE1 < 1 || CHOICE1 > 2) {
					CHOICE1 = -1;
				}

				else if (CHOICE1 == 1) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					qSorter->Sort(seq, bigger);
					duration = timer1->Time();
					delete timer1;

					iterations = qSorter->getIter();
					comparasions = qSorter->getComp();

					coution();
					sorterSeq(seq);
					coution();

					cout << endl << "      quickSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}

				else if (CHOICE1 == 2) {
					system("cls");

					if (seq->GetSize() <= 1000) {
						printArr(seq);
					}

					Timer* timer1 = new Timer();
					qSorter->Sort(seq, lower);
					duration = timer1->Time();
					delete timer1;

					iterations = qSorter->getIter();
					comparasions = qSorter->getComp();

					coution();
					sorterSeq(seq);
					coution();

					cout << endl << "      quickSort: " << endl << endl;
					cout << "      Duration of sorting: " << duration << "sec" << endl;
					output(seq, iterations, comparasions);
					coution();

					pressAnyButton();
				}
			}
			delete qSorter;
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

		else if (CHOICE == 8) {
			system("cls");
			int First = -1;
			int Second = -1;

			while (First == -1) {
				system("cls");
				cout << "Choose First Sorter: " << endl;
				cout << "---------------------" << endl;
				cout << "1. Bubble Sort" << endl;
				cout << "2. Insertion Sort" << endl;
				cout << "3. Selection Sort" << endl;
				cout << "4. Shell Sort" << endl;
				cout << "5. Quick Sort" << endl;
				cout << "---------------------" << endl;
				cout << "Input:  ";
				cin >> First;

				if (First < 1 || First > 5) {
					First = -1;
				}
			}
			while (Second == -1) {
				system("cls");
				cout << "Choose Second Sorter: " << endl;
				cout << "---------------------" << endl;
				cout << "1. Bubble Sort" << endl;
				cout << "2. Insertion Sort" << endl;
				cout << "3. Selection Sort" << endl;
				cout << "4. Shell Sort" << endl;
				cout << "5. Quick Sort" << endl;
				cout << "---------------------" << endl;
				cout << "Input:  ";
				cin >> Second;

				if (Second < 1 || Second > 5) {
					Second = -1;
				}
			}
			

			if (First == 1) {
				bubbleSorter<int>* sorter1 = new bubbleSorter<int>();
				if (Second == 2) {

					insertSorter<int>* sorter2 = new insertSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Bubble Sorter:", "Insertion Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 3) {
					
					selectSorter<int>* sorter2 = new selectSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Bubble Sorter:", "Selection Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 4) {
					
					shellSorter<int>* sorter2 = new shellSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Bubble Sorter:", "Shell Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 5) {
					
					quickSorter<int>* sorter2 = new quickSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Bubble Sorter:", "Quick Sorter:");
					delete sorter1;
					delete sorter2;
				}
			}
			if (First == 2) {
				insertSorter<int>* sorter1 = new insertSorter<int>();
				if (Second == 1) {

					bubbleSorter<int>* sorter2 = new bubbleSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Insertion Sorter:", "Bubble Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 3) {

					selectSorter<int>* sorter2 = new selectSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Insertion Sorter:", "Selection Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 4) {

					shellSorter<int>* sorter2 = new shellSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Bubble Sorter:", "Shell Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 5) {

					quickSorter<int>* sorter2 = new quickSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Insertion Sorter:", "Quick Sorter:");
					delete sorter1;
					delete sorter2;
				}
			}
			if (First == 3) {
				selectSorter<int>* sorter1 = new selectSorter<int>();
				if (Second == 2) {

					insertSorter<int>* sorter2 = new insertSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Selection Sorter:", "Insertion Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 1) {

					bubbleSorter<int>* sorter2 = new bubbleSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Selection Sorter:", "Bubble Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 4) {

					shellSorter<int>* sorter2 = new shellSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Selection Sorter:", "Shell Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 5) {

					quickSorter<int>* sorter2 = new quickSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Selection Sorter:", "Quick Sorter:");
					delete sorter1;
					delete sorter2;
				}
			}
			if (First == 4) {
				shellSorter<int>* sorter1 = new shellSorter<int>();
				if (Second == 2) {

					insertSorter<int>* sorter2 = new insertSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Shell Sorter:", "Insertion Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 3) {

					selectSorter<int>* sorter2 = new selectSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Shell Sorter:", "Selection Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 1) {

					bubbleSorter<int>* sorter2 = new bubbleSorter<int>();
					sortComparasion(seq, sorter1, sorter2, "Shell Sorter:", "Bubble Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 5) {

					quickSorter<int>* sorter2 = new quickSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Shell Sorter:", "Quick Sorter:");
					delete sorter1;
					delete sorter2;
				}
			}
			if (First == 5) {
				quickSorter<int>* sorter1 = new quickSorter<int>();
				if (Second == 2) {

					insertSorter<int>* sorter2 = new insertSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Quick Sorter:", "Insertion Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 3) {

					selectSorter<int>* sorter2 = new selectSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Quick Sorter:", "Selection Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 4) {

					shellSorter<int>* sorter2 = new shellSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Quick Sorter:", "Shell Sorter:");
					delete sorter1;
					delete sorter2;
				}
				else if (Second == 1) {

					bubbleSorter<int>* sorter2 = new bubbleSorter<int>();
					sortComparasion<int>(seq, sorter1, sorter2, "Quick Sorter:", "Quick Sorter:");
					delete sorter1;
					delete sorter2;
				}
			}
		}

		else if (CHOICE == 0) {

			system("cls");
			break;

		}
	}
}

template  <class T>
int creatingMenu(Sequence<T>* arr) {
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
		cout << "Input:   ";

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
}

template  <class T>
int creatingMenuList(ListSequence<T>* seq, int SIZE) {
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

			manualFillList<T>(seq, SIZE);
			ON1 = false;
		}

		else if (FILL == 2) {
			system("cls");

			randomFillList<T>(seq, SIZE);
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
		cout << "         1. Create new sequence" << endl;
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
			int TYPE_SEQ = -1;
			int SIZE = -1;

			while (SIZE == -1) {
				system("cls");

				cout << endl;
				cout << "        Enter SIZE of your sequence:  ";

				cin >> SIZE;

				if (SIZE < 0 || SIZE > MAXINT) {
					SIZE = -1;
				}

				else {
					while (TYPE_SEQ == -1) {
						system("cls");
						int NEXT = 0;

						cout << endl;
						cout << "        Choose type of your sequence:  " << endl;
						cout << endl;
						cout << "        1. ArraySequence" << endl;
						cout << "        2. ListSequence" << endl;
						cout << endl;
						cout << "        0. Exit" << endl;
						cout << endl;
						cout << "----------------------------------------" << endl;
						cout << endl;

						cout << "Input:  ";
						cin >> TYPE_SEQ;

						if (TYPE_SEQ < 0 || TYPE_SEQ > 2) {
							TYPE_SEQ = -1;
						}

						else if (TYPE_SEQ == 0) {
							system("cls");
							cout << endl;
							cout << "         Closing . . ." << endl;
							exit(1);
						}
						
						else if (TYPE_SEQ == 1) {
							
							ArraySequence<int>* arr = new ArraySequence<int>(SIZE);
							NEXT = creatingMenu<int>(arr);

							if (NEXT == 0) {
								selectSort(arr);
							}

							delete arr;
						}

						else if (TYPE_SEQ == 2) {

							ListSequence<int>* seq = new ListSequence<int>();
							NEXT = creatingMenuList<int>(seq, SIZE);

							if (NEXT == 0) {
								selectSort(seq);
							}

							delete seq;
						}
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