
all-y	+= crit decoder

CC	= gcc
CFLAGS  = -g -Wall

decoder:
	$(Q) $(CC) crit/arch/$(ARCH)/decoder.c -o crit/decoder
.PHONY: decoder

crit/crit: crit/crit-$(PYTHON)
	$(Q) cp $^ $@
crit: crit/crit
.PHONY: crit

clean-crit:
	$(Q) $(RM) crit/crit
	$(Q) $(RM) crit/decoder
.PHONY: clean-crit
clean: clean-crit
mrproper: clean
