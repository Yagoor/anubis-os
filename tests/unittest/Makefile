SUBDIRS = 	os/sys/add 	\
			os/sys/sub 	\
			os/sys/pt 	\

.PHONY: all clean run

all clean run check:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir -f Makefile $@; \
	done