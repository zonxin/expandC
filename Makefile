
MAIN:=main.c
OUTDIR:=dest
OUTPUT:=$(OUTDIR)/$(MAIN)
EXEC:=$(OUTDIR)/$(basename $(MAIN)).exe
# diff
DIFF:=diff 
DFLAGS:=-b

default:t
.PHONY:default

# generate exec
$(EXEC): $(OUTPUT)
	$(CC) -o $@ $^ $(CFLAGS)
# build
.PHONY:build
build:$(OUTPUT)
$(OUTPUT):$(MAIN) clib/a/* clib/b/* clib/data_structure/*
	grunt build:$<:$@

TEMP=_temp
TPAHTFILE=$(TEMP)/testpath.makefile
-include  $(TPAHTFILE)
TDIR:=testdata/a/same
TESTDATA=$(wildcard $(TDIR)/test*in.txt)
TESTFAKE=$(subst in.txt,,$(TESTDATA))
TIMETEST=$(wildcard $(TDIR)/time*.txt)
TIMEFAKE=$(subst .txt,,$(TIMETEST))
# testpath
$(TPAHTFILE):$(MAIN)
	-mkdir $(TEMP)
	sed -n '1s/.*TestFilePath:\(\S*\)\/\?.*$$/override TDIR=\1/gp' $^ > $@
# test 
.PHONY:t $(TESTFAKE)
t: $(TPAHTFILE) $(TESTFAKE) $(EXEC)
$(TESTFAKE):%:%in.txt %out.txt $(EXEC)
	@echo Testing data in file \"$<\"
	@./$(EXEC) < $< > $(TEMP)/out.txt
	@$(DIFF) $(TEMP)/out.txt $(DFLAGS) $(filter %out.txt,$^) > /dev/null || $(DIFF) $(TEMP)/out.txt $(filter %out.txt,$^) -y --left-column
	@echo ...AC

# time test 
.PHONY:$(TIMEFAKE) tt t
tt: $(TIMEFAKE) $(EXEC)
$(TIMEFAKE):%:%.txt 
	time ./$(EXEC) < $< | tail -3

.PHONY: clean
clean:
	-rm -rf $(OUTDIR)
	-rm -rf $(TEMP)
