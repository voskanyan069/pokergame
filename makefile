CC=g++
CFLAGS=-I$(INCDIR) -g -std=c++17
RM=rm -rf
MKDIR=mkdir -p

DIRS=$(OBJDIR) $(OBJSDIR) $(BINDIR)
SRCDIR=./src
INCDIR=./inc
OBJDIR=./obj
OBJSDIR=$(OBJDIR)/cards \
		$(OBJDIR)/table \
		$(OBJDIR)/players \
		$(OBJDIR)/config \
		$(OBJDIR)/log
BINDIR=./bin

SRC=$(shell find $(SRCDIR) -type f -name "*.cpp")
INC=$(shell find $(INCDIR) -type f \( -name "*.h" -o -name "*.hpp" \))
OBJ=$(patsubst ./src/%.cpp,./obj/%.o,$(SRC))
BIN=$(BINDIR)/poker

all: tags $(DIRS) $(BIN) run

$(BIN): $(SRC) $(INC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	$(BIN)

.PHONY: tags
tags:
	ctags -R

$(DIRS):
	$(MKDIR) $@

.PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) $(BIN)
	$(RM) $(DIRS)
	$(RM) tags
