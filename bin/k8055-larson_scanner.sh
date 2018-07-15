#!/bin/bash

while [ 6 -gt 2 ]; do
 k8055-write_digital 1 0 0 0 0 0 0 0
 k8055-write_digital 0 1 0 0 0 0 0 0
 k8055-write_digital 0 0 1 0 0 0 0 0
 k8055-write_digital 0 0 0 1 0 0 0 0
 k8055-write_digital 0 0 0 0 1 0 0 0
 k8055-write_digital 0 0 0 0 0 1 0 0
 k8055-write_digital 0 0 0 0 0 0 1 0
 k8055-write_digital 0 0 0 0 0 0 0 1
 k8055-write_digital 0 0 0 0 0 0 0 1
 k8055-write_digital 0 0 0 0 0 0 1 0
 k8055-write_digital 0 0 0 0 0 1 0 0
 k8055-write_digital 0 0 0 0 1 0 0 0
 k8055-write_digital 0 0 0 1 0 0 0 0
 k8055-write_digital 0 0 1 0 0 0 0 0
 k8055-write_digital 0 1 0 0 0 0 0 0
 k8055-write_digital 1 0 0 0 0 0 0 0
done
