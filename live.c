#include <stdio.h>
#include <comedilib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "version.h"

int subdev = 2;		
int range = 0;		
int aref = AREF_GROUND;	

int main(int argc,char *argv[])
{
	// open/set up comedi stuff
	comedi_t *it;
	lsampl_t data;
	int retval;
	char *strRes = NULL;
	// check if arg is comedi device
	if(argc > 1){
		strRes = strstr(argv[1],"/dev/comedi");	
		if (strRes != NULL){
			it = comedi_open(argv[1]);	
		}else{
			it = comedi_open("/dev/comedi0");
		}	
	}else{
		it = comedi_open("/dev/comedi0");
	}
	if(it == NULL) {
		//comedi_perror("comedi_open");
		fprintf(stderr, "ERROR: libcomedi error opening ");
		if(strRes == NULL){
			fprintf(stderr, "/dev/comedi0\n");		
		}else{
			fprintf(stderr, argv[1]);	
			fprintf(stderr, "\n");		
		}	
		return 1;
	}
	// check this device is a velleman K8055 board
	char *boardRes = NULL;
	boardRes = strstr(comedi_get_board_name(it),"K8055");
	if(boardRes == NULL){
		fprintf(stderr, "ERROR: ");	
		if(strRes == NULL){
			fprintf(stderr, "/dev/comedi0 ");		
		}else{
			fprintf(stderr, argv[1]);	
			fprintf(stderr, " ");		
		}
		fprintf(stderr, "is not a Velleman K8055 board!\n");	
		return 1;
	}	

	// make text bold and turn off cursor
	//printf("\033[1M"); //bold
	printf("\033[?25l"); //cursor off

	// print basic layout
	printf("\nK8055 ");
	if(strRes == NULL){
		printf("/dev/comedi0");		
	}else{
		printf(argv[1]);			
	}	
	printf("%4.2f",code_version);
	printf(" status:\n\n");
	printf("    DIGITAL INPUTS 1 2 3 4 5\n");
	printf("\n");
	printf("\n");
	printf("    ANALOG INPUTS  1       2\n");
	printf("\n");
	printf("\n");
	printf("    COUNTERS       1       2\n");
	printf("\n");
	printf("\n");

	// main loop to get values and update screen
	int results[5];
	char ui[20];
	while(6 > 5){
		// move cursor up to digital input values line
		printf("\033[1A");
		printf("\033[1A");
		printf("\033[1A");
		printf("\033[1A");
		printf("\033[1A");
		printf("\033[1A");
		printf("\033[1A");
		printf("\033[1A                   ");

		// get digital input values
		subdev = 2;
		for (int lc=0; lc < 5; lc++){
			retval = comedi_data_read(it, subdev, lc, range, aref, &data);
			if(retval < 0) {
				//comedi_perror("comedi_data_write");
				fprintf(stderr, "ERROR: libcomedi error writing to ");
				if(strRes == NULL){
					fprintf(stderr, "/dev/comedi0\n");		
				}else{
					fprintf(stderr, argv[1]);	
					fprintf(stderr, "\n");		
				}	
				return 1;
			}
			results[lc] = data;
		}
		// print digital values
		printf("%d", results[0]);
		printf(" ");
		printf("%d", results[1]);
		printf(" ");
		printf("%d", results[2]);
		printf(" ");
		printf("%d", results[3]);
		printf(" ");
		printf("%d", results[4]);
		printf("       \n");
		
		// move cursor down to analog input values line
		printf("\n");
		printf("\n                   ");
		// get analog input values
		subdev = 0;
		for (int lc=0; lc < 2; lc++){
			retval = comedi_data_read(it, subdev, lc, range, aref, &data);
			if(retval < 0) {
				//comedi_perror("comedi_data_write");
				fprintf(stderr, "ERROR: libcomedi error writing to ");
				if(strRes == NULL){
					fprintf(stderr, "/dev/comedi0\n");		
				}else{
					fprintf(stderr, argv[1]);	
					fprintf(stderr, "\n");		
				}	
				return 1;
			}
			results[lc] = data;
		}
		// print analog values
		printf("                       \n\033[1A                   ");
		printf("%d", results[0]);
		if(results[0] < 100){
			printf(" ");
		}
		if(results[0] < 10){
			printf(" ");
		}
		printf("     ");
		printf("%d", results[1]);
		printf("        \n");

		// move cursor down to counter values line
		printf("\n");
		printf("\n                   ");
		// get counter values
		subdev = 4;
		for (int lc=0; lc < 2; lc++){
			retval = comedi_data_read(it, subdev, lc, range, aref, &data);
			if(retval < 0) {
				//comedi_perror("comedi_data_write");
				fprintf(stderr, "ERROR: libcomedi error writing to ");
				if(strRes == NULL){
					fprintf(stderr, "/dev/comedi0\n");		
				}else{
					fprintf(stderr, argv[1]);	
					fprintf(stderr, "\n");		
				}	
				return 1;
			}
			results[lc] = data;
		}
		// print counter values
		printf("                       \n\033[1A                   ");
		printf("%d", results[0]);
		if(results[0] < 10000){
			printf(" ");
		}
		if(results[0] < 1000){
			printf(" ");
		}
		if(results[0] < 100){
			printf(" ");
		}
		if(results[0] < 10){
			printf(" ");
		}
		printf("   ");
		printf("%d", results[1]);
		printf("       \n");
		printf("       \n");

		// check for user input to quit
		fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
		results[0] = read(0,ui,4);
		if (results[0] > 0){
			//if(ui[0] == 'q'){
				printf("\n\n\033[?25h");
				exit(0);
			//}
		}

	}
	return 0;
}

