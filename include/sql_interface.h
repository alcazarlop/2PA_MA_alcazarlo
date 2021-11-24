
#ifndef __SQL_INTERFACE_H__
#define __SQL_INTERFACE_H__ 1

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned char kQuerySize = 60;
const unsigned char kMaxInfoSize = 16;

struct Database{
	sqlite3 *db;
	int rc;
	char* sql_query;
	char* err_msg;
};

struct Info{
	char* value;
	char* colname;
	Info* next;
};

void SQLInit(Database* database, Info** info, const char* path);
void SQLExecute(Database* database, Info** info);
void SQLClose(Database* database);

int callback(void* notused, int argc, char** argv, char** azcolname);
void InsertList(Info** head, char* argv, char* azcolname);
void ClearList(Info** head);

#endif // __SQL_INTERFACE_H__

