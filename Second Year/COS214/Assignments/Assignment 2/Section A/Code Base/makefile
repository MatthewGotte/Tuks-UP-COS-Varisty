OBJS	= ArsenalFactory.o ArsenalShirt.o ArsenalSoccerBall.o ChelseaFactory.o ChelseaShirt.o ChelseaSoccerBall.o LiverpoolFactory.o LiverpoolShirt.o LiverpoolSoccerBall.o main.o Merchandise.o MerchandiseFactory.o Shirt.o SoccerBall.o
SOURCE	= ArsenalFactory.cpp ArsenalShirt.cpp ArsenalSoccerBall.cpp ChelseaFactory.cpp ChelseaShirt.cpp ChelseaSoccerBall.cpp LiverpoolFactory.cpp LiverpoolShirt.cpp LiverpoolSoccerBall.cpp main.cpp Merchandise.cpp MerchandiseFactory.cpp Shirt.cpp SoccerBall.cpp
HEADER	= ArsenalFactory.h ArsenalShirt.h ArsenalSoccerBall.h ChelseaFactory.h ChelseaShirt.h ChelseaSoccerBall.h LiverpoolFactory.h LiverpoolShirt.h LiverpoolSoccerBall.h Merchandise.h MerchandiseFactory.h Shirt.h SoccerBall.h
OUT	= main.out
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

ArsenalFactory.o: ArsenalFactory.cpp
	$(CC) $(FLAGS) ArsenalFactory.cpp

ArsenalShirt.o: ArsenalShirt.cpp
	$(CC) $(FLAGS) ArsenalShirt.cpp

ArsenalSoccerBall.o: ArsenalSoccerBall.cpp
	$(CC) $(FLAGS) ArsenalSoccerBall.cpp

ChelseaFactory.o: ChelseaFactory.cpp
	$(CC) $(FLAGS) ChelseaFactory.cpp

ChelseaShirt.o: ChelseaShirt.cpp
	$(CC) $(FLAGS) ChelseaShirt.cpp

ChelseaSoccerBall.o: ChelseaSoccerBall.cpp
	$(CC) $(FLAGS) ChelseaSoccerBall.cpp

LiverpoolFactory.o: LiverpoolFactory.cpp
	$(CC) $(FLAGS) LiverpoolFactory.cpp

LiverpoolShirt.o: LiverpoolShirt.cpp
	$(CC) $(FLAGS) LiverpoolShirt.cpp

LiverpoolSoccerBall.o: LiverpoolSoccerBall.cpp
	$(CC) $(FLAGS) LiverpoolSoccerBall.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

Merchandise.o: Merchandise.cpp
	$(CC) $(FLAGS) Merchandise.cpp

MerchandiseFactory.o: MerchandiseFactory.cpp
	$(CC) $(FLAGS) MerchandiseFactory.cpp

Shirt.o: Shirt.cpp
	$(CC) $(FLAGS) Shirt.cpp

SoccerBall.o: SoccerBall.cpp
	$(CC) $(FLAGS) SoccerBall.cpp

clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)

#main:
#	g++ -c *.cpp
#	g++ -o main *.o
#
#run: main
#	./main
#
#clean:
#	rm -f *.o main
