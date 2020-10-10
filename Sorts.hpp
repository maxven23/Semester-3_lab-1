#include "Headers.hpp"
#include <ctime>


template <class T>

class ISorter {
public:

	virtual void Sort(ArraySequence<T>* input) = 0;

protected:
	void Swap(ArraySequence<T>* seq, int index1, int index2)
	{
		T item = seq->Get(index1);
		seq->Set(index1, seq->Get(index2));
		seq->Set(index2, item);
	}
};


template <class T>
// Пузырьковая сортировка
class bubbleSorter : ISorter<T> 
{
public:
	int iterations = 0;
	int comparisons = 0;

	void Sort(ArraySequence<T>* arr) override {

		for (int i = 0; i < arr->GetSize(); i++) {
			for (int j = 0; j < arr->GetSize() - i - 1; j++) {
				if (arr->Get(j) > arr->Get(j + 1)) {

					this->Swap(arr, j, j + 1);
					++iterations;

				}
				++comparisons;
			}
		}
	}
};


template <class T>
// Быстрая сортировка
class quickSorter : ISorter<T>
{
public:
	int iterations;
	int comparisons = 0;

	void Sort(ArraySequence<T>* arr) override {
		quickSort(arr, 0, arr->GetSize() - 1);
	}

	void quickSort(ArraySequence<T>* arr, int left, int right) {

		int i = left, j = right;

		T middle = arr->Get((left + right) / 2);

		while (i <= j) {
			while (arr->Get(i) < middle) {
				comparisons++;
				i++;
			}
			while (arr->Get(j) > middle) {
				comparisons++;
				j--;
			}
			if (i <= j) {

				this->Swap(arr, i, j);
				iterations++;

				i++;
				j--;
			}
		};

		// Рекурсивный вызов
		if (left < j)
			quickSort(arr, left, j);
		if (i < right)
			quickSort(arr, i, right);

	}
};


template <class T>
// Сортировка вставками
class insertSorter : ISorter<T> 
{
public:
	int iterations = 0;
	int comparisons = 0;

	void Sort(ArraySequence<T>* arr) override {

		T temp;

		for (int i = 0; i < arr->GetSize() - 1; i++)
		{
			int key = i + 1;
			temp = arr->Get(key);
			for (int j = i + 1; j > 0; j--)
			{
				++comparisons;
				if (temp < arr->Get(j - 1))
				{
					arr->Set(j, arr->Get(j - 1));
					key = j - 1;
					++iterations;
				}
			}
			arr->Set(key, temp);
		}
	}
};


template <class T>
// Сортировка простым выбором
class selectSorter : ISorter<T> 
{
public:
	int iterations = 0;
	int comparisons = 0;

	void Sort(ArraySequence<T>* arr) override {

		for (int startIndex = 0; startIndex < arr->GetSize(); ++startIndex) {

			int smallestIndex = startIndex;

			for (int currentIndex = startIndex + 1; currentIndex < arr->GetSize(); ++currentIndex) {

				if (arr->Get(currentIndex) < arr->Get(smallestIndex)) {
					++comparisons;
					smallestIndex = currentIndex;
				}
			}

			this->Swap(arr, startIndex, smallestIndex);
			++iterations;
		}
	}
};


template <class T>
// Сотрировка Шелла
class shellSorter : ISorter<T>
{
public:
	int iterations = 0;
	int comparisons = 0;

	void Sort(ArraySequence<T>* arr) override {

		int step, i, j;
		//T tmp;

		// Выбор шага
		for (step = arr->GetSize() / 2; step > 0; step /= 2)
			// Перечисление элементов, которые сортируются на определённом шаге
			for (i = step; i < arr->GetSize(); i++) {
				// Перестановка элементов внутри подмассива, пока i-тый не будет отсортирован
				++comparisons;
				for (j = i - step; j >= 0 && (arr->Get(j) > arr->Get(j + step)); j -= step, ++comparisons)
				{

					this->Swap(arr, j, j + step);
					++iterations;

				}
			}
	}
};


template <typename T> 
void shuffle(ArraySequence<T>* arr) {

	srand(time(NULL));

	for (int i = 0; i < arr->GetSize(); ++i) {
		T tmp = arr->Get(i);
		int r = rand() % arr->GetSize();
		arr->Set(i, arr->Get(r));
		arr->Set(r, tmp);
	}

	cout << "----------------------------------Shuffled Array----------------------------------" << endl << endl;

	cout << "[";
	for (int i = 0; i < arr->GetSize() - 1; ++i) {
		cout << arr->Get(i) << ",  ";
	}
	cout << arr->Get(arr->GetSize() - 1) << "]" << endl << endl;

	cout << "----------------------------------------------------------------------------------" << endl;
};