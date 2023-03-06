#! /bin/bash

echo "Enter your name : "
read name
echo WELCOME $name
# Enter your name : 
# Mileex
# WELCOME Mileex

echo "Enter names : "
read name1 name2 name3
echo WELCOME $name1, $name2, $name3
# Enter names : 
# POP TATE SHELBY
# WELCOME POP, TATE, SHELBY

# (To have the prompt on the same line)
read -p 'Enter the username : ' un
echo HELLO USER $un
# Enter the username : Joswin
# HELLO USER Joswin

read -p 'Enter the username : ' un
read -sp 'Enter the password : ' pw     # (To make hidden entry in prompt)
echo                                    # (echo ,to echo a blank line, to go to next line)
echo HELLO USER $un
echo Password entered is : $pw

# Enter the username : POP_SMOKE
# Enter the password : 
# HELLO USER POP_SMOKE
# Password entered is : woolife
