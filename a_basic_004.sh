#! /bin/bash

pop="SMOKE"
echo $pop

filename="woo.txt"  # stored a filename
touch $filename      # make the file
ls -l $filename      # list the content in the file
rm $filename         # removed the file

filesname="woo1 woo2"   # stored two file names
touch $filesname        # touch will seperate them out and create two new files woo1 and woo2
ls -l $filesname        # ls will sperate the name out and list both
rm $filesname           # rm will remove them both

echo $pop, $USER
# SMOKE, joswin
# (Case sensitive)

user_s="$pop, $USER"
echo $user_s
# SMOKE, joswin

user_ss=$pop, $USER
# (ERROR, don't forget quotes")

x = 5
# (ERROR, x=5 is correct)

command1="touch wooBaby.txt"
command2="rm wooBaby.txt"
$command1
echo $command1 executed
ls
$command2
echo $command2 executed
ls

# touch wooBaby.txt executed
# a_basic_004.sh  wooBaby.txt
# rm wooBaby.txt executed
# a_basic_004.sh