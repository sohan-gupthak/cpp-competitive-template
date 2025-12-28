#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

// Measures and prints the execution time of a scope or function using a RAII-based timer.
struct Timer {
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer() {
        start = std::chrono::steady_clock::now();
    }

    ~Timer() {
        end = std::chrono::steady_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took: " << ms << " ms\n";
    }
};

void Function() {
	Timer t; // use Timer to measure this function's execution time
	
	for (int i = 0; i < 100; i++) {
		cout << i << endl;
	}
}

int main()
{   
    Function();
    
    cin.get();
}
