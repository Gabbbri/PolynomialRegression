

CC = g++
CPPFLAGS = -std=c++11
ODIR = ./obj
SDIR = ./src
LDIR = ./lib   
TDIR = ./test
BIN = ./bin

DEFAULT: build


#Listo tutti i file oggetto 
OBJ_FILES = $(ODIR)/mainLR1.o $(ODIR)/mainLR2.o $(ODIR)/mainPR.o $(ODIR)/LinearRegressionV1.o $(ODIR)/LinearRegressionV2.o $(ODIR)/PolynomialRegression.o

#I file oggetto hanno bisogno della directory $(ODIR)
$(OBJ_FILES): | $(ODIR)

#Lista di tutti gli eseguibili da compilare
LIST1 = TestLR1 TestLR2 TestPR  #andranno in ./bin
LIST2 = LinearRegressionV1 LinearRegressionV2 PolynomialRegression   #andranno in ./lib

#Gli eseguibili hanno bisogno delle directory $(BIN) e $(LDIR)
$(LIST1): | $(BIN)
$(LIST2): | $(LDIR)

#Creo le directory

$(ODIR) $(BIN) $(LDIR):
	@mkdir $@



all: $(LIST1) $(LIST2)


$(ODIR)/mainLR1.o: $(TDIR)/mainLR1.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

$(ODIR)/LinearRegressionV1.o: $(SDIR)/LinearRegressionV1.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@


$(ODIR)/LinearRegressionV2.o: $(SDIR)/LinearRegressionV2.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

$(ODIR)/mainLR2.o: $(TDIR)/mainLR2.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

#forse non è necessario includere qui. Basta farlo nel main
$(ODIR)/PolynomialRegression.o: $(SDIR)/PolynomialRegression.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@    

$(ODIR)/mainPR.o: $(TDIR)/mainPR.cpp
	$(CC) $(CPPFLAGS) -c $< -I ./include -o $@

TestLR1: $(ODIR)/mainLR1.o $(ODIR)/LinearRegressionV1.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^ 
	@echo compiled $(BIN)/$@

TestLR2: $(ODIR)/mainLR2.o $(ODIR)/LinearRegressionV2.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^ 
	@echo compiled $(BIN)/$@

TestPR: $(ODIR)/mainPR.o $(ODIR)/PolynomialRegression.o
	$(CC) $(CPPFLAGS) -o $(BIN)/$@ $^
	@echo compiled $(BIN)/$@

#LinearRegressionV1: $(ODIR)/LinearRegressionV1.o
#	$(CC) $(CPPFLAGS) -o $(LDIR)/$@ $^
#	@echo compiled $(LDIR)/$@

#LinearRegressionV2: $(SDIR)/LinearRegressionV1.cpp
#	$(CC) $(CPPFLAGS) $< -I ./include -o $(LDIR)/$@ $^  ------> Come creo gli .exe della libreria se non contengono un main?
#	@echo compiled $(LDIR)/$@

#PolynomialRegression: $(ODIR)/PolynomialRegression.o
#	$(CC) $(CPPFLAGS) -o $(LDIR)/$@ $^

build: all

clean:
	rm -f ./obj/*.o ./bin/*.exe ./bin/*.gp
	rmdir obj bin




