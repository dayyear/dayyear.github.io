
CXX = g++
CXXFLAGS += -std=c++11 -O3 -Wall -fmessage-length=0
LDFLAGS += -static
DEPENDFLAGS += -std=c++11
OBJS = max_num.o max.o
EXE = max.exe

default: $(EXE) depend

$(EXE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

depend:
	-@$(CXX) $(DEPENDFLAGS) -MM $(OBJS:.o=.cpp) > $@ 2> err.log

-include depend

