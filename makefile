compile:
	g++ Clementine.cpp Loan.cpp Register.cpp Retirement.cpp -Wall -o Clementine.out
run:
	./Clementine.out
clean:
	rm *.out
