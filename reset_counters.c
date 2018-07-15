#include <stdio.h>	
#include <stdlib.h>
#include <comedilib.h>

int subdev = 4;		
int range = 0;		
int aref = AREF_GROUND;	

int main(int argc,char *argv[])
{
	// open/set up comedi stuff
	comedi_t *it;
	lsampl_t data;
	int retval;
	it = comedi_open("/dev/comedi0");
	if(it == NULL) {
		//comedi_perror("comedi_open");
		fprintf(stderr, "ERROR: libcomedi error opening device.\n");
		return 1;
	}
	
	// send values from command line
	int data0 = 0;
	int ch = -2;
	while(argc--){
		ch++;
		if(ch > -1){
			sscanf(argv[ch+1],"%d", &data0);
			retval = comedi_data_write(it, subdev, ch, range, aref, data0);
			if(retval < 0) {
				//comedi_perror("comedi_data_write");
				fprintf(stderr, "ERROR: libcomedi error reading from device.\n");
				return 1;
			}
		}
	}
	return 0;

}

