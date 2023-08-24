echo "Enter the first number : "
read n1
echo "Enter the second number : "
read n2
echo "1) ADDITION
2) SUBTRACTION
3) MULTIPLICATION
4) DIVISION
Choose the operation : "
read op

case $op in
1) echo THE SUM IS $(($n1+$n2));;
2) echo THE DIFFERENCE IS $(($n1-$n2));;
3) echo THE PRODUCT IS $(($n1*$n2));;
4) echo THE QUOTIENT IS $(($n1/$n2));;
*) echo Wrong choice;;
esac
