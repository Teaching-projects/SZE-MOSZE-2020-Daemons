OBJS:=JsonParser.o Main.o Unit.o Control.o
CLFLAGS:=-Wall -std=c++17
RUN:= g++
VLGRND:= valgrind
VLGRNDFLAGS:= --leak-check=full --error-exitcode=1
VLGRNDJSONS:=  ./runMain test/units/unit1.json test/units/unit2.json
CPPRUN:= cppcheck
CPPRUNOBJECTS:=JsonParser.cpp Main.cpp Unit.cpp Control.cpp
CPPRUNFLAGS:=  --enable=warning --error-exitcode=1
CPPRUNFLAGSFILE:= --enable=performance,style --output-file=performance_and_style_report.txt
DFF:=diff
DFFOBJS:= test/outputs.txt test/good_outputs.txt
JSONTST:= ./test/JsonParser_test
OUTPTS:= ./test/generate_outputs.sh
DCMNT:= doxygen doxconf
alltest: runMain cppcheck cppcheckfile valgrind diff jsontst generate_outputs

runMain:$(OBJS)
	$(RUN) $(CFLAGS) -o runMain $(OBJS)
JsonParser.o: JsonParser.cpp
	$(RUN) $(CFLAGS) -c JsonParser.cpp
Main.o: Main.cpp
	$(RUN) $(CFLAGS) -c Main.cpp
Unit.o: Unit.cpp
	$(RUN) $(CFLAGS) -c Unit.cpp
Control.o: Control.cpp
	$(RUN) $(CFLAGS) -c Control.cpp
cppcheck: 
	$(CPPRUN) $(CPPRUNOBJECTS)  $(CPPRUNFLAGS)
cppcheckfile:
	$(CPPRUN) $(CPPRUNOBJECTS) $(CPPRUNFLAGSFILE)
valgrind:
	$(VLGRND) $(VLGRNDFLAGS) $(VLGRNDJSONS)
generate_outputs: runMain
	$(OUTPTS)
diff: generate_outputs 
	$(DFF) $(DFFOBJS)
jsontst:
	$(JSONTST)
document:
	$(DCMNT)



