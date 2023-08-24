#! /bin/bash

echo Enter 3 names :
read -a names       # Tell the script to read an array
echo ${names[0]}
echo "NAMES : ${names[0]}, ${names[1]}, ${names[2]}"
# Enter 3 names :
# Joswin Mileex Pop
# Joswin
# NAMES : Joswin, Mileex, Pop

echo Enter subject :
read         # By defalut the input goes into built in variable REPLY
echo Selected subject is $REPLY
# Enter subject :
# MATHS
# Selected subject is MATHS
