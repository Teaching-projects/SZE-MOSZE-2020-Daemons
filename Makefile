OBJS:=JSON.o Main.o  Hero.o Monster.o Map.o Game.o MarkedMap.o ObserverSVGRenderer.o ObserverTextRenderer.o TextRenderer.o HeroTextRenderer.o CharacterSVGRenderer.o
CFLAGS:=-Wall  -Werror -std=c++17
RUN:= g++-9

VLGRND:= valgrind
VLGRNDFLAGS:= --error-exitcode=1
VLGRNDJSONS:=  ./runMain preparedgame.json < test/maptest.txt
CPPRUN:= cppcheck
CPPRUNOBJECTS:=JSON.cpp Main.cpp Unit.cpp  Hero.cpp Monster.cpp Map.cpp Game.cpp MarkedMap.cpp ObserverSVGRenderer.cpp ObserverTextRenderer.cpp TextRenderer.cpp HeroTextRenderer.cpp CharacterSVGRenderer.cpp
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
MarkedMap.o: Map.cpp Map.h MarkedMap.h MarkedMap.cpp  
	$(RUN) $(CFLAGS) -c MarkedMap.cpp
Main.o: Main.cpp JSON.h Hero.h Monster.h Game.h MarkedMap.h
	$(RUN) $(CFLAGS) -c Main.cpp
Hero.o: Hero.cpp Hero.h JSON.h Monster.h
	$(RUN) $(CFLAGS) -c Hero.cpp
Monster.o: Monster.cpp Monster.h JSON.h Hero.h
	$(RUN) $(CFLAGS) -c Monster.cpp
Map.o: Map.cpp Map.h
	$(RUN) $(CFLAGS) -c Map.cpp
Game.o: Game.cpp Game.h Map.h Hero.h Monster.h
	$(RUN) $(CFLAGS) -c Game.cpp
ObserverSVGRenderer.o: ObserverSVGRenderer.h Renderer.h
	$(RUN) $(CFLAGS) -c ObserverSVGRenderer.cpp

ObserverTextRenderer.o: ObserverTextRenderer.h Renderer.h
	$(RUN) $(CFLAGS) -c ObserverTextRenderer.cpp

TextRenderer.o: TextRenderer.h Renderer.h
	$(RUN) $(CFLAGS) -c TextRenderer.cpp

HeroTextRenderer.o: HeroTextRenderer.h Renderer.h
	$(RUN) $(CFLAGS) -c HeroTextRenderer.cpp

CharacterSVGRenderer.o: CharacterSVGRenderer.h Renderer.h
	$(RUN) $(CFLAGS) -c CharacterSVGRenderer.cpp


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
