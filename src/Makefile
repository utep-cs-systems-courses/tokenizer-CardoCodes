OBJS= tokenizer.o GUI.o
#target
all: tokenizer

#file dependenices
tokenizer.o: tokenizer.h
history.o: history.h
GUI.o: tokenizer.h history.h

tokenizer: $(OBJS)

#delete files
clean: rm -f test *.o *~ *#
