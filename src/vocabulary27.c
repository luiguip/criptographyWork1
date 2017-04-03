#include"desafio.h"

#define ASCII 65
#define VOCABULARYSIZE 27
#define SPACE 32

void vocabulary27(char* fileEntryName, char* fileOutName, int n){
	int i, c;
	FILE* fileEntry, *fileOut;
	double frequency[VOCABULARYSIZE];
	double probability[VOCABULARYSIZE];
	double counter, entrophy;
	fileEntry = fopen( fileEntryName, "r");
	fileOut = fopen(fileOutName, "w+");
	counter=0;
	entrophy=0;

	for(i=0;i<VOCABULARYSIZE;i++){
		frequency[i]=0;
	}

	c = toupper(fgetc(fileEntry));
	if(n==-1){
		while(c!=EOF){
			if(c<ASCII+VOCABULARYSIZE && c>=ASCII){
				frequency[c-ASCII]++;
				counter++;
			}
			else if(c==SPACE){
				frequency[VOCABULARYSIZE-1]++;
				counter++;
			}
			c = toupper(fgetc(fileEntry));
		}
	}
	else{
		for(i=0;i<n;i++){
			if(c<ASCII+VOCABULARYSIZE && c>=ASCII){
				frequency[c-ASCII]++;
				counter++;
			}
			else if(c==SPACE){
				frequency[VOCABULARYSIZE-1]++;
				counter++;
			}
			c = toupper(fgetc(fileEntry));
		}
	}
	fputs("Percentages:\n", fileOut);
	for(i=0;i<VOCABULARYSIZE;i++){
		i==VOCABULARYSIZE-1?fputc(SPACE,fileOut):fputc(i+ASCII,fileOut);
		fputs(" : ", fileOut);
		probability[i] = frequency[i]/counter;
		fprintf(fileOut,"%g",probability[i]*100);
		fputs(" \%\n",fileOut);
		if(frequency[i]!=0){
			entrophy+=probability[i]*log10(1/probability[i])/log10(2);
		}
	}
	fputs("Entrophy:\nH = ", fileOut);
	fprintf(fileOut, "%g", entrophy);
	fclose(fileOut);
	fclose(fileEntry);
}
