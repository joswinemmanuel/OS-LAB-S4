#! /bin/bash

printf "Enter a word : "
read word
printf "The word is %s\n\n" $word
# Enter a word : UNIQUE
# The word is UNIQUE

printf "Enter another word : "
read word2
printf "First word is : %s, Second word is : %s\n" $word $word2
# Enter another word : DIFFERENT
# First word is : UNIQUE, Second word is : DIFFERENT