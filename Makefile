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
    UNAME_S:=$(shell uname) 
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

# DLIB=libMathFunc$(DEXT) 
# #build program 
# all: dynamicbuild 
# #build with Static Library 
# staticbuild: liba mathMain.c 
#     $(CC) $(CFLAGS) -o mathProgramStatic$(EXT) mathMain.c $(STATICB) 

# #build with Dynamic Library 
# dynamicbuild: $(DLIB) mathMain.c 
#     $(CC) -o mathProgramDynamic$(EXT) mathMain.c $(DLIB) 

# #build all object files 
# objects: mathMain.o mathFunc.o  
# #build static libraries 
# liba: libMathFunc.a 
# #build dynamiclibraries 
# #windows/mac 
# libd: libMathFunc$(DEXT) 
# #linux 
# libso: 
# #OBJECTS 
# mathMain.o: mathMain.c 
#     $(CC) -c mathMain.c -o mathMain.o 
# mathFunc.o: mathFunc.c 
#     $(CC) -c mathFunc.c -o mathFunc.o 

# #ARCHIVE 
# libMathFunc.a: mathFunc.o 
#     ar $(ARFLAGS) libMathFunc.a mathFunc.o 

# #DYNAMIC LIBRARIES/SHARED OBJECT 
# libMathFunc$(DEXT): mathFunc.o 
#     $(CC) $(DYLIB) -o libMathFunc$(DEXT) mathFunc.o 
# clean: 
#     $(DELETE) *.o *.a *.so *$(DEXT) *$(EXT)