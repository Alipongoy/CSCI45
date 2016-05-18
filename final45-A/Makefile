a.out: main.o student_calc.o
	gcc -g main.o student_calc.o

main.o: main.c
	gcc -c -g main.c

student_calc.o: student_calc.s
	gcc -c -g student_calc.s

clean:
	rm a.out *.o
