#!/bin/bash

while [ 6 -gt 2 ]; do
 adc=$(k8055-read_analog | tr -d "\n" | tr -d "\r")
 error=$(echo $adc | grep -c "." | tr -d "\n" | tr -d "\r")
 if [ $error -gt 0 ]; then
  adc=$(echo $adc | cut -f1 -d" " | tr -d "\n" | tr -d "\r")
  echo "ADC1: $adc"
  k8055-write_pwm_pin 1 $adc
 fi
done
