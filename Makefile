CC=gcc
SRCDIR=src
INCDIR=inc
BINDIR=bin
BUILDDIR=build
TARGET=$(BINDIR)/indexedStruc
DEP=$(INCDIR)/indexedStruct.h
OBJECTS=$(BUILDDIR)/indexedStruct.o $(BUILDDIR)/main.o
# ARGS=-lcheck -lm -lpthread #for macos
# ARGS=-lcheck -lm -lrt -lpthread -lsubunit #for linux
ARGS=-lcheck -lm -lrt -lpthread #for me

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@
$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(DEP)
	$(CC) -I$(INCDIR) -c $< -o $@



test: $(BINDIR)/api-test
	@echo "api-test..."
$(BINDIR)/api-test: $(BUILDDIR)/api-test.c $(SRCDIR)/ArrayDataStore.c $(DEP)
	$(CC) $(SRCDIR)/ArrayDataStore.c -I$(INCDIR) $(BUILDDIR)/api-test.c $(ARGS) -o $@
$(BUILDDIR)/api-test.c: test/api-test.check
	checkmk $^ > $@


.PHONY: clean

clean:
	@echo "cleaning..."
	rm $(BINDIR)/*
	rm $(BUILDDIR)/*