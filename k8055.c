#include <stdio.h>	
#include <stdlib.h>

#include "version.h"

int main(int argc,char *argv[])
{
	// just prints list of k8055 programs, their functions and arguments
	printf("\n");	
	printf("All k8055 programs take an optional argument to specify the comedi device file to use\n");
	printf("		/dev/comedi(NUMBER)\n");
	printf("			Defaults to /dev/comedi0 if not specified.\n\n");
	printf("Example bash scripts are in /usr/share/doc/comedi-K8055_bash_interface/examples\n\n");			
	printf("Note that programs to reset counters and set counter debounce times hasn't been implemented yet.\n");
	printf("Version ");
	printf("%4.2f",code_version);
	printf("\n\n");	
	// for k8055_live
	printf("PROGRAM: 	/usr/local/bin/k8055-live\n");
	printf("DESCRIPTION:	Displays a live view of the boards digital inputs, analog inputs and counters.\n");
	printf("\n");
	// for k8055_read_digital
	printf("PROGRAM: 	/usr/local/bin/k8055-read_digital\n");
	printf("DESCRIPTION:	Outputs reading for each digital input seperated by a space.\n");
	printf("		Leftmost character is INP1, rightmost is INP5.\n");
	printf("\n");
	// for k8055_read_analog
	printf("PROGRAM: 	/usr/local/bin/k8055-read_analog\n");
	printf("DESCRIPTION:	Outputs reading for each analog input seperated by a space.\n");
	printf("		ADC range is 0 to 255.\n");
	printf("		Output format is\n");
	printf("			<A1 ADC> <A2 ADC> \n");
	printf("\n");	
	// for k8055_read_counters
	printf("PROGRAM:	/usr/local/bin/k8055-read_counters\n");
	printf("DESCRIPTION:	Outputs counter values seperated by a space.\n");
	printf("		Output format is\n");
	printf("			<COUNTER 1> <COUNTER 2>\n");
	printf("\n");		
	printf("		As of yet, a program to reset the counters and set debounce times hasn't been implemented.\n");	
	printf("\n");		
	// for k8055_write_digital
	printf("PROGRAM:	/usr/local/bin/k8055-write_digital\n");
	printf("DESCRIPTION:	Sets the output states on OUT1 to OUT8 simultaneously, each output can be 0 or 1.\n");
	printf("		Command line format is\n");
	printf("			</dev/comedi(NUMBER)> <OUT1> <OUT2> <OUT3> <OUT4> <OUT5> <OUT6> <OUT7> <OUT8>\n");
	printf("			Examples: /usr/local/bin/k8055-write_digital 1 1 1 1 0 0 0 0\n");
	printf("			          /usr/local/bin/k8055-write_digital /dev/comedi0 1 1 1 1 0 0 0 0\n");
	printf("\n");		
	printf("		An example bash script is at /usr/share/doc/commedi-K8055_bash_interface/examples/k8055-larson_scanner.sh\n");			
	printf("\n");		
	// for k8055_write_pwm
	printf("PROGRAM:	/usr/local/bin/k8055-write_pwm\n");
	printf("DESCRIPTION:	Sets the output states on PWM1 and PWM2 simultaneously, each output can be 0 to 255.\n");
	printf("		Command line format is\n");
	printf("			</dev/comedi(NUMBER)> <PWM1 VALUE> <PWM2 VALUE>\n");
	printf("			Examples: /usr/local/bin/k8055-write_pwm 10 255\n");
	printf("			          /usr/local/bin/k8055-write_pwm /dev/comedi0 10 255\n");
	printf("\n");	
	// for k8055_write_digital_pin
	printf("PROGRAM:	/usr/local/bin/k8055-write_digital_pin\n");
	printf("DESCRIPTION:	Sets the output state on OUT1 to OUT8 individually, each output can be 0 or 1.\n");
	printf("		Command line format is\n");
	printf("			</dev/comedi(NUMBER)> <DIGITAL OUTPUT> <VALUE>\n");
	printf("			Examples: /usr/local/bin/k8055-write_digital_pin 7 1\n");
	printf("			          /usr/local/bin/k8055-write_digital_pin /dev/comedi0 7 1\n");
	printf("\n");
	// for k8055_write_pwm_pin
	printf("PROGRAM:	/usr/local/bin/k8055-write_pwm_pin\n");
	printf("DESCRIPTION:	Sets the output state on either PWM1 or PWM2 individually, each output can be 0 to 255.\n");
	printf("		Command line format is\n");
	printf("			</dev/comedi(NUMBER)> <PWM OUTPUT> <PWM VALUE>\n");
	printf("			Examples: /usr/local/bin/k8055-write_pwm_pin 2 255\n");
	printf("			          /usr/local/bin/k8055-write_pwm_pin /dev/comedi0 2 255\n");
	printf("\n");
	
	return 0;

}

