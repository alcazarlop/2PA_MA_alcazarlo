
#ifndef __SQL_INTERFACE_H__
#define __SQL_INTERFACE_H__ 1

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

const unsigned int kQuerySize = 2048;
const unsigned char kMaxInfoSize = 32;

struct Info{
	char* value;
	char* colname;
	int columns;
	Info* next;
};

struct Database{
	sqlite3 *db;
	int rc;
	char* sql_query;
	char* err_msg;
	std::vector<char*> colname;
	std::vector<char*> value;
};

/** @brief Initialize the database and allocates memory
 * 
 * Contains the different options necessary for open
 * a SQL database
 * 
 * @param The database to manage
 * @param The path to the database to consult
 */ 
void SQLInit(Database* database, const char* path);

/** @brief Executes a query to the database, for read purposes only
 * 
 * Contains the SQL functions necessary to execute a query to a databse
 * 
 * @param The database to query
 * @param The struct that will contain the information of the database
 */ 

void SQLOpen(Database* database, const char* path);
void SQLClose(Database *database);
int nothing_callback(void* notused, int argc, char** argv, char** azcolname);
void SQLExecute_create(Database* database, char* query);

void SQLExecute_read(Database* database, char* query);

/** @brief Close a opened database and free the allocated data
 * 
 * @param The database to close 
 */ 
void SQLExit(Database* database);

/** @brief The SQL callback to the database, for read purposes only.
 * 
 * For more info look into the sqlite3.h
 */ 
int read_from_table_callback(void* notused, int argc, char** argv, char** azcolname);

/** @brief Insert information into the Info struct
 * 
 * The functions inserts the information consulted
 * in the dabase, into a info list.
 * 
 * @param The head of the info list
 * @param The value stored in the database
 * @param The name of stored value in the database
 */ 
void InsertList(Info** head, int col, char* argv, char* azcolname);

/** @brief Empty the info struct
 * 
 * @param The info list to empty
 */ 
void ClearList(Info** head);
void ResetList(Info** head);

#endif // __SQL_INTERFACE_H__

