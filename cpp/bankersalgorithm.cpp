// Nassim Marhari
// Banker's Algorithm Example
// bankersalgorithm.cpp

#include <iostream>
#include <fstream>
#include <string>

const int proc = 5;		// number of processes, 5 for this example
const int res = 3;		// number of resources, 3 for this example

void input(int[]);		// function to take in input

int main() {

	int data[((res*proc)+(res*proc)+res)];	// array based on number of processes and resources
	input(data);	// take input from text
	
	// Allocation Matrix
	int alloc[proc][res] = { { data[0],  data[1],  data[2]  },	// Process 0
				 { data[3],  data[4],  data[5]  },	// Process 1
				 { data[6],  data[7],  data[8]  },	// Process 2
				 { data[9],  data[10], data[11] },	// Process 3
				 { data[12], data[13], data[14] } };	// Process 4
	
	// Max Matrix
	int max[proc][res] = { { data[15], data[16], data[17] },	// Process 0
			       { data[18], data[19], data[20] },	// Process 1
			       { data[21], data[22], data[23] },	// Process 2
			       { data[24], data[25], data[26] },	// Process 3
			       { data[27], data[28], data[29] } };	// Process 4
			       
	// Available Resources
	int avail[res] = { data[30], data[31], data[32] };	// Resource A, B, C
	
	// Resource need matrix
	int need[proc][res];	
	for (int i = 0; i < proc; ++i) {	// #proc rows, #res columns
		for (int j = 0; j < res; ++j) {
			need[i][j] = max[i][j] - alloc[i][j];	// max - alloc = need
		}
	}
	
	// Calculate safe state
	bool f[proc] = {0}, found = 0;	// is finished[#proc], bool found unsafe state
	int safe[proc], i, j, k, index = 0;	// safeorder[#proc], iterators, index
	for (i = 0; i < proc; ++i) {
		
		for (j = 0; j < proc; ++j) {
		
			if (f[j] == 0) {	// if process is not finished:
			
				found = 0;	// found unsafe state = 0
				for (k = 0; k < res; ++k) {
					if (need[j][k] > avail[k]) {	// if need > available, unsafe
						found = 1;	// found unsafe state
						break;
					}
				}
						
				if (found == 0) {	// if no unsafe state has been found yet:
				
					safe[index++] = j;	// safe order[i] = current process
					for (int l = 0; l < res; ++l) {
						avail[l] += alloc[j][l];
					}		// add resource to list of available resources
					f[j] = 1;	// process (#) is finished
					
				}
			}	
		}
	}
	found = 1;
	
	for (int i = 0; i < proc; ++i) {
		if (f[i] == 0) {	// if not finished...
			found = 0;	// it is deadlocked, so it is unsafe
			std::cout << "The system is not in a safe state.\n";
			exit(1);
			break;
		}
	}	
	
	if (found == true) {
		std::cout << "The system is in a safe state. The proper sequence is: ";
		for (int i = 0; i < proc; ++i) {
			std::cout << "P";
			std::cout << safe[i] << " ";
		}
		std::cout << "\n";
	}
	
	return 0;
	

}

void input(int data[]) {

	// get file name
	std::string userinput;
	std::cout << "Input file name: ";
	std::cin >> userinput;
	// retrieve input
	std::ifstream input;
	input.open (userinput);	// open input file that was defined
	if (!input.is_open()) { 	// if the file can not be opened...
		std::cerr << "Error opening input file.\n";
		exit(2);
	}
	
	int i = 0, tmp;
	while ( input >> tmp) {	// enter numbers into data array
		data[i] = tmp;
		++i;
	}
}
