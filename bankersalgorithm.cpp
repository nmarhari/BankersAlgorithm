// Nassim Marhari
// Banker's Algorithm Example
// bankersalgorithm.cpp

#include <iostream>
#include <fstream>

const int proc = 5;
const int res = 3;

void input(int[]);

int main() {

	int data[((res*proc)+(res*proc)+res)];
	input(data);
	
	for (int j = 0; j < 33; ++j) { std::cout << data[j]; }
	
	return 0;
	

}

void input(int data[]) {
	// retrieve input
	std::ifstream input;
	input.open ("input.txt");
	if (!input.is_open()) { 
		std::cerr << "Error opening input file.\n";
		exit(0);
	}
	
	int i = 0, tmp;
	while ( input >> tmp) {
		data[i] = tmp;
		++i;
	}
}
