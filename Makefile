#
# Makefile
#
# Author: Zex <top_zlynch@yahoo.com>
#
# Copyright (c) by Zex Li <top_zlynch@yahoo.com>, Hytera Communications Co., Ltd.
#
#
LIBS = sqlite3
SRCS = basic.h basic.c

CFLAGS = $(LIBS:%=-l%)

%:%.c
	gcc $(SRCS) $< $(CFLAGS) -o $@

clean:
	rm -f $(shell find . -executable -type f)
