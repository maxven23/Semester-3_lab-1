
#include <iostream>
#include <chrono>



class Timer {
private:

	std::chrono::steady_clock::time_point startTime;
	std::chrono::steady_clock::time_point endTime;

public:
	
	Timer() {
		startTime = chrono::high_resolution_clock::now();
	}

	~Timer() {
		endTime = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = endTime - startTime;

		cout << "      Duration of sorting: " << duration.count() << "sec" << endl;
	}

};