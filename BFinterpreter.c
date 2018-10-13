#include <stdio.h>
#include <time.h>

#define PROGRAM_SIZE    404096 //max program size
#define DATA_SIZE       605535
#define OVERFLOW -1
#define UNDERFLOW -2

int interpreter(char* prog){
	
	char* ist; //current istruction
	char* JMP[PROGRAM_SIZE]; //istructions that are beginning of cycles ("[")
	int cr_jmp=0; //index of the next element of JMP
	int count;
	unsigned char data[DATA_SIZE] = {0}; //data space
	unsigned int ptr=0; //pointer that moves along the data space
	
	for(ist=prog;*ist;ist++){
		switch(*ist){
			case '>':
				if(ptr==DATA_SIZE) return OVERFLOW; 
				else ptr++;
				break;

			case '<':
				if(ptr==0) return UNDERFLOW;
				else ptr--;
				break;

			case '+':
				data[ptr]++;
				break;

			case '-':
				data[ptr]--;
				break;

			case '.':
				putchar(data[ptr]);
				break;

			case ',':
				data[ptr] = (unsigned char)getchar();
				break;

			case '[':
				if(data[ptr]){
					JMP[cr_jmp]=ist;
					cr_jmp++;
				} else {
					count = 1;
					for(ist++;count&&*ist;ist++){
						if(*ist == '[') count++;
						if(*ist == ']') count--;
					}
					ist--;
				}
				
				break;

			case ']':
				if(cr_jmp>0)
					if(data[ptr]) ist=JMP[cr_jmp-1];
					else cr_jmp--;
				break;
		}
	}
	return 0;
}


int main(int argc, char **argv){
	
	if (argc != 2 ) {
        fprintf(stderr, "Usage: %s [file_to_interpret]\n", argv[0]);
        return 0;
    }

    printf("\n");
    
    FILE *fp;
    fp = fopen(argv[1],"r");
    int i=0;
    char prog[PROGRAM_SIZE];
    for(; (prog[i]=fgetc(fp))!=EOF;i++);
    prog[i]='\0';

	clock_t startTime = clock();

    int c = interpreter(prog);

    if(c != 0) printf("\nExecuted in %f seconds.\n\n", ((float) clock() - startTime ) / (float)CLOCKS_PER_SEC);
	else printf("Program execution failed, returned %d code", c);

	return 0;
}
    
