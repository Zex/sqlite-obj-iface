/*
 * demo-0.c
 *
 * Author: Zex <top_zlynch@yahoo.com>
 *
 * A Demo of SQLite C interfaces
 *
 * Copyright (c) by Zex Li <top_zlynch@yahoo.com>, Hytera Communications Co., Ltd.
 *
 */
#include "basic.h"

const char* usage = "\n\
demo-0 [operation]\n\n\
operation:\n\
c <table name>   create table with table name\n\
l                show all databases\n\
i <table name> <number value> <name value> <color value>\n\
                 insert colorm to table\n\
s <table name>   select all from table\n\
st <table name>  show talbe infomation\n\
p                read available pragma\n\
\n";

int create_table(sqlite3* db, char* tb_name)
{
	char *sql = (char*)sqlite3_malloc(MAX_SQL_LENGTH);

	if (!sql) {
		perror("errmsg:");
		return OPERATION_FAILED;
	}
	sprintf(sql, "\
	create table %s (               \
	number integer primary key autoincrement,\
	name   text,                    \
	color  text 					\
	);", tb_name);

	if (sqlite3_exec(db, sql, general_cb, 0, 0)) {
		prerr(db);
		sqlite3_free(sql);
		return OPERATION_FAILED;
	}

	sqlite3_free(sql);
	return OPERATION_SUCCESS;
}

int insert_to_table(sqlite3* db, char* tb_name,
	 int number, char* name, char* color)
{
	char *sql = (char*)sqlite3_malloc(MAX_SQL_LENGTH);

	if (!sql) {
		perror("errmsg:");
		return OPERATION_FAILED;
	}

	sprintf(sql, "\
	insert into %s (name, color) \
	values ('%s', '%s');                 \
	", tb_name, name, color);
	
	if (sqlite3_exec(db, sql, general_cb, 0, 0)) {
		prerr(db);
		sqlite3_free(sql);
		return OPERATION_FAILED;
	}

	sqlite3_free(sql);
	return OPERATION_SUCCESS;
}

int list_all_from_table(sqlite3* db, char* tb_name)
{
	char *sql = (char*)sqlite3_malloc(MAX_SQL_LENGTH);

	if (!sql) {
		perror("errmsg:");
		return OPERATION_FAILED;
	}
	sprintf(sql, "\
	select * from %s; \
	", tb_name);
	
	if (sqlite3_exec(db, sql, general_cb, 0, 0)) {
		prerr(db);
		sqlite3_free(sql);
		return OPERATION_FAILED;
	}

	sqlite3_free(sql);
	return OPERATION_FAILED;
}

int show_table_info(sqlite3* db, char* tb_name)
{
	char *sql = (char*)sqlite3_malloc(MAX_SQL_LENGTH);

	if (!sql) {
		perror("errmsg:");
		return OPERATION_FAILED;
	}
	sprintf(sql, "\
	pragma table_info(%s)\
	", tb_name);
	
	if (sqlite3_exec(db, sql, general_cb, 0, 0)) {
		prerr(db);
		sqlite3_free(sql);
		return OPERATION_FAILED;
	}

	sqlite3_free(sql);
	return OPERATION_FAILED;
}
int list_all_database(sqlite3* db)
{
	char *sql = (char*)sqlite3_malloc(MAX_SQL_LENGTH);

	if (!sql) {
		perror("errmsg:");
		return OPERATION_FAILED;
	}
	sprintf(sql, "\
	pragma database_list \
	");
	
	if (sqlite3_exec(db, sql, general_cb, 0, 0)) {
		prerr(db);
		sqlite3_free(sql);
		return OPERATION_FAILED;
	}

	sqlite3_free(sql);
	return OPERATION_SUCCESS;
}

int show_all_by_name(sqlite3* db, char* tb_name, char* name)
{
	char *sql = (char*)sqlite3_malloc(MAX_SQL_LENGTH);

	if (!sql) {
		perror("errmsg:");
		return OPERATION_FAILED;
	}
	sprintf(sql, "\
	create virtual table using fts3(id, mame); \
	select * from %s where name match '%s'; \
	", tb_name, name);
	
	if (sqlite3_exec(db, sql, general_cb, 0, 0)) {
		prerr(db);
		sqlite3_free(sql);
		return OPERATION_FAILED;
	}

	sqlite3_free(sql);
	return OPERATION_SUCCESS;
}

int show_pragma(sqlite3* db, char* pragma_name)
{
	char *sql = (char*)sqlite3_malloc(MAX_SQL_LENGTH);

	if (!sql) {
		perror("errmsg:");
		return OPERATION_FAILED;
	}
	sprintf(sql, "pragma %s", pragma_name);
	
	if (sqlite3_exec(db, sql, general_cb, 0, 0)) {
		prerr(db);
		sqlite3_free(sql);
		return OPERATION_FAILED;
	}

	sqlite3_free(sql);
	return OPERATION_SUCCESS;
}

int show_all_pragma(sqlite3* db)
{
	int i = 0;

	while (pragmas[i]) {
		printf("----%s----\n", pragmas[i]);
		show_pragma(db, pragmas[i++]);
	}

	return OPERATION_SUCCESS;
}

int main(int argc, char *argv[])
{
	sqlite3* db;

	if ((2 > argc)) {
		prusage;
		return OPERATION_FAILED;
	}

	if (sqlite3_open(db_name, &db)) {
		prerr(db);
		sqlite3_close(db);
		return OPERATION_FAILED;
	}

	printf("thread mode: %d\n\n", sqlite3_threadsafe());

	switch (argv[1][0]) {
	case 'c':
		if (3 > argc) {
			prusage;
			break;
		}
		create_table(db, argv[2]);
		break;
	case 'i':
		if (6 > argc) {
			prusage;
			break;
		}
		insert_to_table(db, argv[2], atoi(argv[3]), argv[4], argv[5]);
		break;
	case 's':
		if (3 > argc) {
			prusage;
			break;
		}
		if ('t' == argv[1][1])
			show_table_info(db, argv[2]);
		else
			list_all_from_table(db, argv[2]);
		break;
	case 'l':
		list_all_database(db);
		break;
	case 'm':
		if (4 > argc) {
			prusage;
			break;
		}
		show_all_by_name(db, argv[2], argv[3]);
		break;
	case 'p':
		show_all_pragma(db);
		break;
	default:
		prusage;
	}

	if (sqlite3_close(db))
		prerr(db);

	return 0;
}
