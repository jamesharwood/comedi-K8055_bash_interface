#!/bin/bash

# Turns on OUT1 at 21:30, turns off OUT1 at 05:00

let ondone=0
let offdone=0

while [ 6 -gt 2 ]; do
 # get current hour and minute
 chour=$(date +"%H"| tr -d "\n" | tr -d "\r")
 cminute=$(date +"%M"| tr -d "\n" | tr -d "\r")

 #echo $chour:$cminute

 # check if to turn on
 if [ $chour -eq 21 ]; then
  if [ $cminute -eq 30 ]; then
   if [ $ondone -eq 0 ]; then
    let ondone=1
    let offdone=0
    k8055-write_digital_pin 1 1
    echo -n "Turned OUT1 on at "
    date +"%H:%M"
   fi
  fi
 fi

 # check if to turn off
 if [ $chour -eq 5 ]; then
  if [ $cminute -eq 0 ]; then
   if [ $offdone -eq 0 ]; then
    let ondone=0
    let offdone=1
    k8055-write_digital_pin 1 0
    echo -n "Turned OUT1 off at "
    date +"%H:%M"
   fi
  fi
 fi
done