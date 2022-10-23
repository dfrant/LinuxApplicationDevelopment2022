#include <stdio.h>
#include <stdlib.h>

void help() {
        printf("Use ./range [N,[M,[S]]]\n");
	printf("./range N -> [0, 1, … N-1]\n");
	printf("./range N M -> [M, M+1, … N-1]\n");
	printf("./range N M S -> [M, M+S, M+2S, … N-1]\n");
	
}


int main(int argc, char** argv) {
	int n = 0;
	int start = 0, m = 0;
	int s = 1;
	
	switch (argc) {
		case 4: 
			s = atoi(argv[3]);
		case 3:
			start = m = atoi(argv[1]);
			n = atoi(argv[2]);
			break;
		case 2:
			n = atoi(argv[1]);
			break;
		default: 
			help();
			break;
	}

	for(m; m < n; m += s) {
		printf("%d\n", m);
        }


	return 0;
}
