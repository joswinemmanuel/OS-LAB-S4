echo Enter the limit :
read n

echo The first $n natural number is :
for((i=1; i<=n; i++))
do
	echo $i
done
