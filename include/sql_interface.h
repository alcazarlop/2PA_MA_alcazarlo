
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

/** @brief Open the database
 * 
 * Contains the different options necessary for open
 * a SQL database
 * 
 * @param The database to manage
 * @param The struct that will contain the information of the database
 * @param The path to the database to consult
 */ 
void SQLInit(Database* database, Info** info, const char* path);

/** @brief Executes a query to the database
 * 
 * Contains the SQL functions necessary to execute a query to a databse
 * 
 * @param The database to query
 * @param The struct that will contain the information of the database
 */ 
void SQLExecute(Database* database, Info** info);

/** @brief Close a opened database
 * 
 * @param The database to close
 */ 
void SQLClose(Database* database);

/** @brief The SQL callback to the database
 * 
 * For more info look into the sqlite3.h
 */ 
int callback(void* notused, int argc, char** argv, char** azcolname);

/** @brief Insert information into the Info struct
 * 
 * The functions inserts the information consulted
 * in the dabase, into a info list.
 * 
 * @param The head of the info list
 * @param The value stored in the database
 * @param The name of stored value in the database
 */ 
void InsertList(Info** head, char* argv, char* azcolname);

/** @brief Empty the info struct
 * 
 * @param The info list to empty
 */ 
void ClearList(Info** head);

#endif // __SQL_INTERFACE_H__

