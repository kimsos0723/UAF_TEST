all: uaf
	chmod +x ./exploit.sh	
uaf: uaf_test.o	
	ulimit -s unlimited	
	g++ -o uaf uaf_test.o -fno-stack-protector -no-pie -z execstack -z norelro -z execstack
	export MALLOC_CHECK_=0 

uaf_test.o: uaf_test.cpp	
	sudo g++ -c -o uaf_test.o uaf_test.cpp 

clean:
	rm -f uaf_test.o
	export MALLOC_CHECK_=2
	