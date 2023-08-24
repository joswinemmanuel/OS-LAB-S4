echo Enter the limit
read n

a=0
b=1

echo The first $n fibonacci numbers :
for((i=1; i<=n; i++))
do
	c=$((a+b))
	echo $a
	a=$b
	b=$c
done
