# Makefile 1
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# List of source files
SRCS = ChangeItem.cpp ChangeRequest.cpp Requester.cpp ProductRelease.cpp Product.cpp ReportControl.cpp Utility.cpp UserInterface.cpp ScenarioControl.cpp errors.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

# Output executable name
EXEC = td
# Default target
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up the compiled files
clean:
	rm -f $(OBJS) $(EXEC)
