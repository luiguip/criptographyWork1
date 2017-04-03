#include"desafio.h"

#define MODE "-m"
#define INFILE "-f"
#define OUTFILE "-o"
#define HELP "-h"
#define CNUMBER "-n"

int main(int argc, char *argv[]){
	char* fileEntryName, *fileOutName, *mode;
	int i, n;
	n = -1;
	//argv processing

	if(argc==1){
		fprintf(stderr, "No arguments, -h for help");
		exit(EXIT_SUCCESS);
	}
	if(argc>9){
		fprintf(stderr, "Too much arguments, -h for help");
		exit(EXIT_SUCCESS);
	}
	for(i=1;i<argc;i++){
		if(strcmp(argv[i], HELP)==0){
			printf("desafio -m [Z26|Z27|Z256] -f foo.txt -o target (-n \\d*)+\n");
			exit(EXIT_SUCCESS);
		}
		else if(strcmp(argv[i], MODE)==0){
			i++;
			if(i>argc-1){
				fprintf(stderr, "No mode argument, -h for help");
				exit(EXIT_SUCCESS);
			}
			mode = argv[i];
		}
		else if(strcmp(argv[i], INFILE)==0){
			i++;
			if(i>argc-1){
				fprintf(stderr, "No input file argument, -h for help");
				exit(EXIT_SUCCESS);
			}
			fileEntryName= argv[i];
		}
		else if(strcmp(argv[i], OUTFILE)==0){
			i++;
			if(i>argc-1){
				fprintf(stderr, "No output file argument, -h for help");
				exit(EXIT_SUCCESS);
			}
			fileOutName = argv[i];
		}
		else if(strcmp(argv[i], CNUMBER)==0){
			i++;
			if(i>argc-1){
				fprintf(stderr, "No number argument, -h for help");
				exit(EXIT_SUCCESS);
			}
			n = atoi(argv[i]);
		}
		else{
			fprintf(stderr, "Invalid argument. -h for help");
			exit(EXIT_FAILURE);
		}
	}

	//vocabulary selecting

	if(strcmp(mode, "Z26")==0){
		vocabulary26( fileEntryName, fileOutName, n);
	}
	else if(strcmp(mode, "Z27")==0){
		vocabulary27(fileEntryName,fileOutName,n);
	}
	else if(strcmp(mode, "Z256")==0){
		vocabulary256(fileEntryName,fileOutName,n);
	}
	else{
		fprintf(stderr, "Invalid mode");
		exit(EXIT_FAILURE);
	}
	return 0;
}
