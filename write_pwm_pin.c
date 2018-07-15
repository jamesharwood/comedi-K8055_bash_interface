#include <stdio.h>	
#include <stdlib.h>
#include <comedilib.h>
#include <string.h>

int subdev = 1;		
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
	
	// send values from command line
	int pin = -1;
	int data0 = 0;
	int ch = -2;
	while(argc--){
		ch++;
		if(ch > -1){
			if(strRes == NULL){
				sscanf(argv[ch+1],"%d", &data0);
				if(ch+1 == 1){
					// store pin number
					pin = data0-1;
				}	
				if(ch+1 == 2){
					// write value to pin
					retval = comedi_data_write(it, subdev, pin, range, aref, data0);
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
				}
			}else{
				// first arg was comedi device, so skip first arg
				if(ch+1 != 1){
					sscanf(argv[ch+1],"%d", &data0);
					if(ch+1 == 2){
						// store pin number
						pin = data0-1;
					}	
					if(ch+1 == 3){
						// write value to pin
						retval = comedi_data_write(it, subdev, pin, range, aref, data0);
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
					}					
				}	
			}
		}
	}
	return 0;

}

