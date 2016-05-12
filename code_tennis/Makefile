a.out: teama.o teamb.o
	g++ teama.o teamb.o

teama.o: teama.cc
	g++ -c teama.cc

teamb.o: teamb.s
	as -mfpu=neon -o teamb.o teamb.s
