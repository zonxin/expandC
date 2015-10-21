
MAIN:=main.c
OUTDIR:=dest
OUTPUT:=$(OUTDIR)/$(MAIN)
EXEC:=$(OUTDIR)/$(basename $(MAIN)).exe
# diff
DIFF:=diff 
DFLAGS:=-b

T:=a/same
TDIR=testdata/$(T)
TESTDATA=$(wildcard $(TDIR)/test*in.txt)
TESTFAKE=$(subst in.txt,,$(TESTDATA))
TIMETEST=$(wildcard $(TDIR)/time*.txt)
TIMEFAKE=$(subst .txt,,$(TIMETEST))

default:t
.PHONY:default

# generate exec
$(EXEC): $(OUTPUT)
	$(CC) -o $@ $(CFLAGS) $^
# build
.PHONY:build
build:$(OUTPUT)
$(OUTPUT):$(MAIN) clib/a/* clib/b/* clib/data_structure/*
	grunt build:$<:$@

# test 
.PHONY:$(TESTFAKE) t
t: $(TESTFAKE) $(EXEC)
$(TESTFAKE):%:%in.txt %out.txt $(EXEC)
	@echo test data in file \"$<\"
	@./$(EXEC) < $< | $(DIFF) - $(DFLAGS) $(filter %out.txt,$^)
	@echo AC

# time test 
.PHONY:$(TIMEFAKE) tt t
tt: $(TIMEFAKE) $(EXEC)
$(TIMEFAKE):%:%.txt 
	time ./$(EXEC) < $< | tail -3

.PHONY: clean
clean:
	-rm -rf dest
