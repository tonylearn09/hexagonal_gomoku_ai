# Configuration:
CC = g++
CFLAGS = -g -O2 -std=c++11

SOURCES = Gomoku.cpp MinimaxPolicy.cpp RandomPolicy.cpp TdLearner.cpp
OBJECTS = Gomoku.o MinimaxPolicy.o RandomPolicy.o play.o 
TRAIN_OBJECTS = Gomoku.o MinimaxPolicy.o RandomPolicy.o TdLearner.o train.o
PLAYER13_OBJECTS = Gomoku.o MinimaxPolicy.o player13.o
TARGET = gomoku_ai
TRAIN_TARGET = train_agent
PLAYER13_TARGET = player13

# Buid rule
all : $(TARGET) $(TRAIN_TARGET) $(PLAYER13_TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(TRAIN_TARGET) : $(TRAIN_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(PLAYER13_TARGET) : $(PLAYER13_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

Gomoku.o : Gomoku.h Gomoku.cpp
	$(CC) $(CFLAGS) -c Gomoku.cpp
MinimaxPolicy.o : MinimaxPolicy.h MinimaxPolicy.cpp
	$(CC) $(CFLAGS) -c MinimaxPolicy.cpp
RandomPolicy.o : RandomPolicy.h RandomPolicy.cpp
	$(CC) $(CFLAGS) -c RandomPolicy.cpp
play.o : play.cpp
	$(CC) $(CFLAGS) -c play.cpp

TdLearner.o : TdLearner.h TdLearner.cpp
	$(CC) $(CFLAGS) -c TdLearner.cpp
train.o : train.cpp
	$(CC) $(CFLAGS) -c train.cpp

player13.o : player13.cpp
	$(CC) $(CFLAGS) -w -c player13.cpp


# Phony means not a "real" target, it doesn't build anything
# The phony target "clean" is used to remove all compiled object files.
.PHONY: clean
clean:
	@rm -f $(TARGET) $(OBJECTS) $(TRAIN_TARGET) $(TRAIN_OBJECTS) $(PLAYER13_TARGET) $(PLAYER13_OBJECTS)

