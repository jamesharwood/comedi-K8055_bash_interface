#!/bin/bash

# increment verson number
version=$(cat version | tr -d "\r" | tr -d "\n")
version=$(echo $version + 0.01 | bc | tr -d "\r" | tr -d "\n")
version=$(printf "%4.2f" $version)
echo $version > version
echo "#define code_version $version" > version.h
echo $version

# make
cc write_digital.c -lcomedi -lm -o bin/k8055-write_digital
cc write_pwm.c -lcomedi -lm -o bin/k8055-write_pwm
cc read_digital.c -lcomedi -lm -o bin/k8055-read_digital
cc read_analog.c -lcomedi -lm -o bin/k8055-read_analog
cc read_counters.c -lcomedi -lm -o bin/k8055-read_counters
#cc reset_counters.c -lcomedi -lm -o bin/k8055-reset_counters
cc live.c -lcomedi -lm -o bin/k8055-live
cc write_digital_pin.c -lcomedi -lm -o bin/k8055-write_digital_pin
cc write_pwm_pin.c -lcomedi -lm -o bin/k8055-write_pwm_pin
cc k8055.c -lcomedi -lm -o bin/k8055-help
