GCC = g++

PROGRAM = yamrec 

CPPFLAGS = -g 

OBJDIR = obj

SRCDIR = src

SRC = mpm_recgen.cpp \
      data_entry.cpp \
      program_handler.cpp \
      prompt.cpp

OBJ = $(OBJDIR)/mpm_recgen.o $(OBJDIR)/data_entry.o $(OBJDIR)/program_handler.o $(OBJDIR)/prompt.o

$(PROGRAM): $(OBJ) 
	$(GCC) $(CPPFLAGS) -o $(PROGRAM) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(GCC) -c $< -o $@

