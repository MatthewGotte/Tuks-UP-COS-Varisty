OBJS	= Berserker.o BerserkerFactory.o Engineer.o EngineerFactor.o Main.o Medic.o MedicFactory.o Sniper.o SniperFactory.o Soldier.o SoldierFactory.o SoldierMemento.o SoldierState.o SoldierStore.o Zombie.o ZombieMemento.o ZombieState.o ZombieStore.o
SOURCE	= Berserker.cpp BerserkerFactory.cpp Engineer.cpp EngineerFactor.cpp Main.cpp Medic.cpp MedicFactory.cpp Sniper.cpp SniperFactory.cpp Soldier.cpp SoldierFactory.cpp SoldierMemento.cpp SoldierState.cpp SoldierStore.cpp Zombie.cpp ZombieMemento.cpp ZombieState.cpp ZombieStore.cpp
HEADER	= Berserker.h BerserkerFactory.h Engineer.h EngineerFactory.h Medic.h MedicFactory.h Sniper.h SniperFactory.h Soldier.h SoldierFactory.h SoldierMemento.h SoldierState.h SoldierStore.h Zombie.h ZombieMemento.h ZombieState.h ZombieStore.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Berserker.o: Berserker.cpp
	$(CC) $(FLAGS) Berserker.cpp 

BerserkerFactory.o: BerserkerFactory.cpp
	$(CC) $(FLAGS) BerserkerFactory.cpp 

Engineer.o: Engineer.cpp
	$(CC) $(FLAGS) Engineer.cpp 

EngineerFactor.o: EngineerFactor.cpp
	$(CC) $(FLAGS) EngineerFactor.cpp 

Main.o: Main.cpp
	$(CC) $(FLAGS) Main.cpp 

Medic.o: Medic.cpp
	$(CC) $(FLAGS) Medic.cpp 

MedicFactory.o: MedicFactory.cpp
	$(CC) $(FLAGS) MedicFactory.cpp 

Sniper.o: Sniper.cpp
	$(CC) $(FLAGS) Sniper.cpp 

SniperFactory.o: SniperFactory.cpp
	$(CC) $(FLAGS) SniperFactory.cpp 

Soldier.o: Soldier.cpp
	$(CC) $(FLAGS) Soldier.cpp 

SoldierFactory.o: SoldierFactory.cpp
	$(CC) $(FLAGS) SoldierFactory.cpp 

SoldierMemento.o: SoldierMemento.cpp
	$(CC) $(FLAGS) SoldierMemento.cpp 

SoldierState.o: SoldierState.cpp
	$(CC) $(FLAGS) SoldierState.cpp 

SoldierStore.o: SoldierStore.cpp
	$(CC) $(FLAGS) SoldierStore.cpp 

Zombie.o: Zombie.cpp
	$(CC) $(FLAGS) Zombie.cpp 

ZombieMemento.o: ZombieMemento.cpp
	$(CC) $(FLAGS) ZombieMemento.cpp 

ZombieState.o: ZombieState.cpp
	$(CC) $(FLAGS) ZombieState.cpp 

ZombieStore.o: ZombieStore.cpp
	$(CC) $(FLAGS) ZombieStore.cpp 


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)