#include <stdio.h>	
#include <comedilib.h>
#include <string.h>

int subdev = 4;		
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

	// get values
	int results[1];
	for (int lc=0; lc < 2; lc++){
		retval = comedi_data_read(it, subdev, lc, range, aref, &data);
		if(retval < 0) {
			//comedi_perror("comedi_data_write");
			fprintf(stderr, "ERROR: libcomedi error reading from ");
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

	// print results
	printf("%d", results[0]);
	printf(" ");
	printf("%d\n", results[1]);

	return 0;
}

