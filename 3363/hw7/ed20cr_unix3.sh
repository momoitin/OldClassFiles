#Evan Dunlap ed20cr 4/10/2021

echo "Hello" $1 ", pleased to meet you"

cp ~jayarama/homework/hw7unix.cpp .
cp ~jayarama/homework/sample.out .

g++ hw7unix.cpp -o points.exe

./points.exe > myOutput.txt

echo "Date:"; date

echo "Word Count: "; wc -w myOutput.txt

echo "Differences: "
diff -w sample.out myOutput.txt

mkdir $2

find . -name \*$3 -exec cp {} $2 \;