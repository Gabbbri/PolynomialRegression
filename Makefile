#*********************************
#Makefile solo sulla prima versione
#Vedi "Dependency Tree V1
#*********************************

CC = g++
CPPFLAGS = -std=c++11
ODIR = ./obj
SDIR = ./src/V1
BIN = ./bin

DEFAULT: build


#Listo tutti i file oggetto 
OBJ_FILES = $(ODIR)/main.o $(ODIR)/LinearRegressionV1.o

#I file oggetto hanno bisogno della directory $(ODIR)
$(OBJ_FILES): | $(ODIR)

#Lista di tutti gli eseguibili da compilare
LIST = LinearRegressionV1

#L'eseguibile ha bisogno della directory $(BIN)
$(LIST): | $(BIN)

#Creo le directory

$(ODIR) $(BIN):
	@mkdir $@

#Ho 3 target: LinearRegressionV1.exe, main.o, LinearRegressionV1.o

all: LinearRegressionV1

#ATTENTO AI PATH!!!



$(ODIR)/main.o: $(SDIR)/main.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

$(ODIR)/LinearRegressionV1.o: $(SDIR)/LinearRegressionV1.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

LinearRegressionV1: $(ODIR)/main.o $(ODIR)/LinearRegressionV1.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^ 
	@echo compiled $(BIN)/$@

build: all

clean:
	rm -f ./obj/*.o ./bin/*.exe
	rmdir obj bin




