/*
 * basic.c
 *
 * Author: Zex <top_zlynch@yahoo.com>
 *
 * Basic for demo of SQLite C interfaces
 *
 * Copyright (c) by Zex Li <top_zlynch@yahoo.com>, Hytera Communications Co., Ltd.
 *
 */
#include "basic.h"


int general_cb(void* reserve, int argc, char** argv, char** colname)
{
	int i;

	for (i = 0; i < argc; i++) 
		printf("%s: %s\n", colname[i], argv[i]);
	printf("\n");

	return 0;
}
/*
 * Author: Zex <top_zlynch@yahoo.com>
 *
 * Basic for demo of SQLite C interfaces
 *
 * Copyright (c) by Zex Li <top_zlynch@yahoo.com>, Hytera Communications Co., Ltd.
 *
 */
#include "basic.h"


int general_cb(void* reserve, int argc, char** argv, char** colname)
{
	int i;

	for (i = 0; i < argc; i++) 
		printf("%s: %s\n", colname[i], argv[i]);
	printf("\n");

	return 0;
}
