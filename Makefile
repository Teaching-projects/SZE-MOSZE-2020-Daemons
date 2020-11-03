OBJS:=JSON.o Main.o  Hero.o Monster.o
CFLAGS:=-Wall  -Werror -std=c++17
RUN:= g++-10

VLGRND:= valgrind
VLGRNDFLAGS:= --leak-check=full --error-exitcode=1
VLGRNDJSONS:=  ./runMain scenario1.json
CPPRUN:= cppcheck
CPPRUNOBJECTS:=JSON.cpp Main.cpp Unit.cpp  Hero.cpp Monster.cpp
CPPRUNFLAGS:=  --enable=warning --error-exitcode=1
CPPRUNFLAGSFILE:= --enable=performance,style --output-file=performance_and_style_report.txt
DFF:=diff
DFFOBJS:= test/outputs.txt test/good_outputs.txt
#alltest: runMain cppcheck cppcheckfile valgrind diff jsontst generate_outputs
alltest: runMain cppcheck cppcheckfile valgrind diff generate_outputs

runMain:$(OBJS)
	$(RUN) $(CFLAGS) -o runMain $(OBJS)
JSON.o: JSON.cpp JSON.h
	$(RUN) $(CFLAGS) -c JSON.cpp
Main.o: Main.cpp JSON.h Hero.h Monster.h
	$(RUN) $(CFLAGS) -c Main.cpp
Hero.o: Hero.cpp Hero.h JSON.h Monster.h
	$(RUN) $(CFLAGS) -c Hero.cpp
Monster.o: Monster.cpp Monster.h JSON.h Hero.h
	$(RUN) $(CFLAGS) -c Monster.cpp
cppcheck:
	$(CPPRUN) $(CPPRUNOBJECTS)  $(CPPRUNFLAGS)
cppcheckfile:
	$(CPPRUN) $(CPPRUNOBJECTS) $(CPPRUNFLAGSFILE)
valgrind:
	$(VLGRND) $(VLGRNDFLAGS) $(VLGRNDJSONS)
generate_outputs: runMain
	sudo ./test/generate_outputs.sh
diff: generate_outputs
	$(DFF) $(DFFOBJS)
# jsontst:
# 	./test/JsonParser_test
document:
	doxygen doxconf
