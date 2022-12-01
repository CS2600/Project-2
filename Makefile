CC=gcc
CFLAGS=-Wall 
#with Windows use mingw32-make instead of make 
ifeq ($(OS), Windows_NT) 
    ARFLAGS=-rc 
    DYLIB=-fPIC --shared 
    DELETE=del 
    STATICB=-L. -lmathFunc 
    EXT=.exe 
    DEXT=.dll 
else
    UNAME_S := $(shell uname -s)
    $(info $(UNAME_S))
    ifeq ($(UNAME_S), Darwin) 
        $(info $(UNAME_S))
        ARFLAGS=rcs 
        DYLIB=-dynamiclib -fPIC 
        DELETE=rm
        STATICB=libMathFunc.a 
        EXT=.out 
        DEXT=.dylib 
    endif 
endif 
all: program

main.o: main.c
	$(CC) -c main.c -o main.o
Fees.o: Fees.c
	$(CC) -c Fees.c -o Fees.o
FeesCalculator.o: FeesCalculator.c
	$(CC) -c FeesCalculator.c -o FeesCalculator.o
Tests.o: Tests.c
	$(CC) -c Tests.c -o Tests.o

test: Tests.c Fees.c FeesCalculator.c
	$(CC) -o Test$(EXT) Tests.c Fees.c FeesCalculator.c ./unity/src/unity.c
program: main.c Fees.c FeesCalculator.c
	$(CC) -o main$(EXT) main.c Fees.c FeesCalculator.c 

clean: 
	$(DELETE) *.o *.a *.so *$(DEXT) *$(EXT) 