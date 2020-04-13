build:	
	g++ bani.cpp -o p1
	g++ gard.cpp -o p2
	g++ bomboane.cpp -o p3
	g++ sala.cpp -o p4
	
run-p1:
	./p1

run-p2:
	./p2

run-p3:
	./p3

run-p4:
	./p4

clean:
	rm -rf p1 p2 p3 p4
