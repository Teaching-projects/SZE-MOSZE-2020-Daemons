OBJS:=JSON.o Main.o  Hero.o Monster.o Map.o
CFLAGS:=-Wall  -Werror -std=c++17
RUN:= g++-10

VLGRND:= valgrind
VLGRNDFLAGS:= --leak-check=full --error-exitcode=1
VLGRNDJSONS:=  ./runMain scenario1.json
CPPRUN:= cppcheck
CPPRUNOBJECTS:=JSON.cpp Main.cpp Unit.cpp  Hero.cpp Monster.cpp Map.cpp
CPPRUNFLAGS:=  --enable=warning --error-exitcode=1
CPPRUNFLAGSFILE:= --enable=performance,style --output-file=performance_and_style_report.txt
DFF:=diff
DFFOBJS:= test/outputs.txt test/good_outputs.txt
DFRM := rm test/outputs.txt
alltest: runMain cppcheck cppcheckfile valgrind diff jsontst generate_outputs

runMain:$(OBJS)
	$(RUN) $(CFLAGS) -o runMain $(OBJS)
JSON.o: JSON.cpp JSON.h Damage.h
	$(RUN) $(CFLAGS) -c JSON.cpp
Main.o: Main.cpp JSON.h Hero.h Monster.h Damage.h
	$(RUN) $(CFLAGS) -c Main.cpp
Hero.o: Hero.cpp Hero.h JSON.h Monster.h Damage.h
	$(RUN) $(CFLAGS) -c Hero.cpp
Monster.o: Monster.cpp Monster.h JSON.h Hero.h Damage.h
	$(RUN) $(CFLAGS) -c Monster.cpp
Map.o: Map.cpp Map.h
	$(RUN) $(CFLAGS) -c Map.cpp

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
