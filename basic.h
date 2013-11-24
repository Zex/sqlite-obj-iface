/*
 * basic.h
 *
 * Author: Zex <top_zlynch@yahoo.com>
 *
 * Basic for demo of SQLite C interfaces
 *
 * Copyright (c) by Zex Li <top_zlynch@yahoo.com>, Hytera Communications Co., Ltd.
 *
 */
#ifndef __BASIC_H__
#define __BASIC_H__

#include <sqlite3.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define OPERATION_FAILED -1
#define OPERATION_SUCCESS 0
#define prerr(db) printf("errmsg: %s\n", sqlite3_errmsg(db))
#define prusage printf(usage)
#define MAX_SQL_LENGTH 1024

static const char* db_name = "demo-0.db";

static char *pragmas[] = {
"pplication_id",
"auto_vacuum",
"automatic_index",
"busy_timeout",
"cache_size",
"cache_spill",
"case_sensitive_like",
"checkpoint_fullfsync",
"collation_list",
"compile_options",
"count_changes",
"data_store_directory",
//"database_list",
"default_cache_size",
"defer_foreign_keys",
"empty_result_callbacks",
"encoding",
"foreign_key_check",
"foreign_key_list",
"foreign_keys",
"freelist_count",
"full_column_names",
"fullfsync",
"ignore_check_constraints",
"incremental_vacuum",
"index_info",
"index_list",
"integrity_check",
"journal_mode",
"journal_size_limit",
"legacy_file_format",
"locking_mode",
"max_page_count",
"mmap_size",
"page_count",
"page_size",
"parser_trace",
"query_only",
"quick_check",
"read_uncommitted",
"recursive_triggers",
"reverse_unordered_selects",
"schema_version",
"secure_delete",
"short_column_names",
"shrink_memory",
"synchronous",
//"table_info",
"temp_store",
"temp_store_directory",
"user_version",
"vdbe_addoptrace",
"vdbe_debug",
"vdbe_listing",
"vdbe_trace",
"wal_autocheckpoint",
"wal_checkpoint",
"writable_schema",
0
};

/* general callback function for sqlite operations */
extern int general_cb(void* reserve, int argc, char** argv, char** colname);

#endif /* __BASIC_H__ */
