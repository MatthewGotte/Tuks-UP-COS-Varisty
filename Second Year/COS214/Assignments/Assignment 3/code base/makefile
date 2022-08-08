#main: *.o
#	g++ -o main *.o
#
#*.o: *.h *.cpp
#	g++ -g -c *.cpp
#
#run:
#	./main
#
#clean:
#	rm *.o main
#

OBJS	= Barrier.o Chicane.o Decorator.o FlagObserver.o GravelTrap.o main.o PitStop.o Section.o StartLine.o Straight.o Track.o Turn.o
SOURCE	= Barrier.cpp Chicane.cpp Decorator.cpp FlagObserver.cpp GravelTrap.cpp main.cpp PitStop.cpp Section.cpp StartLine.cpp Straight.cpp Track.cpp Turn.cpp
HEADER	= Barrier.h Chicane.h Decorator.h FlagObserver.h GravelTrap.h Observer.h PitStop.h Section.h StartLine.h Straight.h Track.h Turn.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Barrier.o: Barrier.cpp
	$(CC) $(FLAGS) Barrier.cpp

Chicane.o: Chicane.cpp
	$(CC) $(FLAGS) Chicane.cpp

Decorator.o: Decorator.cpp
	$(CC) $(FLAGS) Decorator.cpp

FlagObserver.o: FlagObserver.cpp
	$(CC) $(FLAGS) FlagObserver.cpp

GravelTrap.o: GravelTrap.cpp
	$(CC) $(FLAGS) GravelTrap.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

PitStop.o: PitStop.cpp
	$(CC) $(FLAGS) PitStop.cpp

Section.o: Section.cpp
	$(CC) $(FLAGS) Section.cpp

StartLine.o: StartLine.cpp
	$(CC) $(FLAGS) StartLine.cpp

Straight.o: Straight.cpp
	$(CC) $(FLAGS) Straight.cpp

Track.o: Track.cpp
	$(CC) $(FLAGS) Track.cpp

Turn.o: Turn.cpp
	$(CC) $(FLAGS) Turn.cpp


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)
