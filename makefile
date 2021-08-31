CC=g++
CFLAGS=-I$(INCDIR)
RM=rm -rf
MKDIR=mkdir -p

DIRS=$(OBJDIR) $(OBJSDIR) $(BINDIR)
SRCDIR=./src
INCDIR=./inc
OBJDIR=./obj
OBJSDIR=./obj/cards
BINDIR=./bin

SRC=$(shell find $(SRCDIR) -type f -name "*.cpp")
INC=$(shell find $(INCDIR) -type f \( -name "*.h" -o -name "*.hpp" \))
OBJ=$(patsubst ./src/%.cpp,./obj/%.o,$(SRC))
BIN=$(BINDIR)/game

all: $(DIRS) $(BIN)

.PHONY: $(BIN)
$(BIN): $(SRC) $(INC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	$(MKDIR) $@

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) $(BIN)
	$(RM) $(DIRS)
