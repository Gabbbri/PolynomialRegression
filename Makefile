#*********************************
#Makefile solo sulla prima versione
#Vedi "Dependency Tree V1
#*********************************

CC = g++
CPPFLAGS = -std=c++11
ODIR = ./obj
SDIR = ./src
BIN = ./bin

DEFAULT: build


#Listo tutti i file oggetto 
OBJ_FILES = $(ODIR)/main.o $(ODIR)/LinearRegressionV1.o

#I file oggetto hanno bisogno della directory $(ODIR)
$(OBJ_FILES): | $(ODIR)

#Lista di tutti gli eseguibili da compilare
LIST = LinearRegressionV1 LinearRegressionV2 LinearRegressionV3

#L'eseguibile ha bisogno della directory $(BIN)
$(LIST): | $(BIN)

#Creo le directory

$(ODIR) $(BIN):
	@mkdir $@

#Ho 3 target: LinearRegressionV1.exe, main.o, LinearRegressionV1.o

all: $(LIST)



$(ODIR)/main.o: $(SDIR)/V1/main.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

$(ODIR)/LinearRegressionV1.o: $(SDIR)/V1/LinearRegressionV1.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

$(ODIR)/LinearRegressionV2.o: $(SDIR)/V2/LinearRegressionV2.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

$(ODIR)/main2.o: $(SDIR)/V2/main2.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

$(ODIR)/LinearRegressionV3.o: $(SDIR)/V3/LinearRegressionV3.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

LinearRegressionV1: $(ODIR)/main.o $(ODIR)/LinearRegressionV1.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^ 
	@echo compiled $(BIN)/$@

LinearRegressionV2: $(ODIR)/main2.o $(ODIR)/LinearRegressionV2.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^ 
	@echo compiled $(BIN)/$@

LinearRegressionV3: $(ODIR)/main2.o $(ODIR)/LinearRegressionV3.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^

build: all

clean:
	rm -f ./obj/*.o ./bin/*.exe ./bin/*.gp
	rmdir obj bin




