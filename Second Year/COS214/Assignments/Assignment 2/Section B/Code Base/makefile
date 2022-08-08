#main:
#	g++ -g -c *.cpp
#	g++ -o main *.o
#
#run: main
#	./main
#
#clean:
#	rm -f *.o main


OBJS	= AttackPlayStyle.o CardState.o DefendPlayStyle.o main.o NoCardState.o PlayStyle.o PossessionPlayStyle.o RedCardState.o SoccerPlayer.o YellowCardState.o
SOURCE	= AttackPlayStyle.cpp CardState.cpp DefendPlayStyle.cpp main.cpp NoCardState.cpp PlayStyle.cpp PossessionPlayStyle.cpp RedCardState.cpp SoccerPlayer.cpp YellowCardState.cpp
HEADER	= AttackPlayStyle.h CardState.h DefendPlayStyle.h NoCardState.h PlayStyle.h PossessionPlayStyle.h RedCardState.h SoccerPlayer.h YellowCardState.h
OUT	= main.out
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

AttackPlayStyle.o: AttackPlayStyle.cpp
	$(CC) $(FLAGS) AttackPlayStyle.cpp

CardState.o: CardState.cpp
	$(CC) $(FLAGS) CardState.cpp

DefendPlayStyle.o: DefendPlayStyle.cpp
	$(CC) $(FLAGS) DefendPlayStyle.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

NoCardState.o: NoCardState.cpp
	$(CC) $(FLAGS) NoCardState.cpp

PlayStyle.o: PlayStyle.cpp
	$(CC) $(FLAGS) PlayStyle.cpp

PossessionPlayStyle.o: PossessionPlayStyle.cpp
	$(CC) $(FLAGS) PossessionPlayStyle.cpp

RedCardState.o: RedCardState.cpp
	$(CC) $(FLAGS) RedCardState.cpp

SoccerPlayer.o: SoccerPlayer.cpp
	$(CC) $(FLAGS) SoccerPlayer.cpp

YellowCardState.o: YellowCardState.cpp
	$(CC) $(FLAGS) YellowCardState.cpp


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)