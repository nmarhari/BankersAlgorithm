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
	int avail[res] = { data[30], data[31], data[32] };
	
	// Resource need
	int need[proc][res];
	for (int i = 0; i < proc; ++i) {
		for (int j = 0; j < res; ++j) {
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	
	// Calculate safe state
	bool f[proc] = {0}, found = 0;
	int i = 0, safe[proc];
	while (i < proc) {
		
		for (int j = 0; j < proc; ++j) {
		
			if (f[j] == 0) {
			
				found = 0;
				int k;
				for (k = 0; k < res; ++k) {
					if (need[j][k] > avail[k]) {
						found = 1;
						break;
					}
				}
						
				if (found == 0) {
				
					safe[i++] = j;
					for (int l = 0; l < res; ++l) {
						avail[l] += alloc[j][k];
					}
					f[j] = 1;
					
				}
			}	
		}
	}
	
	if (found == true) {
		std::cout << "The system is not in a safe state.\n";
		exit(1);
	}	
	
	if (found == false) {
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
