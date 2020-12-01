OBJS:=JSON.o Main.o  Hero.o Monster.o Map.o Game.o
CFLAGS:=-Wall  -Werror -std=c++17
RUN:= g++-9

VLGRND:= valgrind
VLGRNDFLAGS:= --error-exitcode=1
VLGRNDJSONS:=  ./runMain scenario2.json < test/maptest.txt
CPPRUN:= cppcheck
CPPRUNOBJECTS:=JSON.cpp Main.cpp Unit.cpp  Hero.cpp Monster.cpp Map.cpp Game.cpp
CPPRUNFLAGS:=  --enable=warning --error-exitcode=1
CPPRUNFLAGSFILE:= --enable=performance,style --output-file=performance_and_style_report.txt
DFF:=diff
DFFOBJS:= test/outputs.txt test/good_outputs.txt
DFRM := rm test/outputs.txt
alltest: runMain cppcheck cppcheckfile valgrind diff jsontst generate_outputs

runMain:$(OBJS)
	$(RUN) $(CFLAGS) -o runMain $(OBJS)
JSON.o: JSON.cpp JSON.h
	$(RUN) $(CFLAGS) -c JSON.cpp
Markedmap.o: Map.cpp Map.h Markedmap.h Markedmap.cpp 
	$(RUN) $(CFLAGS) -c Markedmap.cpp
Main.o: Main.cpp JSON.h Hero.h Monster.h Game.h Markedmap.h
	$(RUN) $(CFLAGS) -c Main.cpp
Hero.o: Hero.cpp Hero.h JSON.h Monster.h
	$(RUN) $(CFLAGS) -c Hero.cpp
Monster.o: Monster.cpp Monster.h JSON.h Hero.h
	$(RUN) $(CFLAGS) -c Monster.cpp
Map.o: Map.cpp Map.h
	$(RUN) $(CFLAGS) -c Map.cpp
Game.o: Game.cpp Game.h Map.h Hero.h Monster.h
	$(RUN) $(CFLAGS) -c Game.cpp


cppcheck:
	$(CPPRUN) $(CPPRUNOBJECTS)  $(CPPRUNFLAGS)
cppcheckfile:
	$(CPPRUN) $(CPPRUNOBJECTS) $(CPPRUNFLAGSFILE)
valgrind:
	$(VLGRND) $(VLGRNDFLAGS) $(VLGRNDJSONS)
generate_outputs: runMain
	./test/generate_outputs.sh
diff: generate_outputs
	$(DFF) $(DFFOBJS)
	$(DFRM)
jsontst:
	./test/JsonParser_test
document:
	doxygen doxconf
