
#include "sql_interface.h"

void SQLInit(Database* database, Info** info, const char* path){

	database->sql_query = (char*) calloc(kQuerySize, sizeof(char));
	database->err_msg = (char*) calloc(kQuerySize, sizeof(char));
	memset(database->sql_query, '\0', kQuerySize);
	memset(database->err_msg, '\0', kQuerySize);

	database->rc = sqlite3_open(path, &database->db);

	if (database->rc != SQLITE_OK) {
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(database->db));
		sqlite3_close(database->db);
	}

	database->sql_query = "SELECT name FROM sqlite_master where type ='table'";
	SQLExecute(database, info);

}

void SQLExecute(Database* database, Info** info){

	database->rc = sqlite3_exec(database->db, database->sql_query, callback, (Info**) info, &database->err_msg);

	if (database->rc != SQLITE_OK ) {
		fprintf(stderr, "Failed to select data\n");
		fprintf(stderr, "SQL error: %s\n", database->err_msg);

		sqlite3_free(database->err_msg);
		sqlite3_close(database->db);
	}

}

void SQLClose(Database *database)
{
	free(database->err_msg);
	free(database->sql_query);
	sqlite3_close(database->db);
}

int callback(void* notused, int argc, char** argv, char** azcolname){

	Info** head = (Info**) notused;

	for(int i = 0; i < argc; ++i){
		InsertList(head, argv[i], azcolname[i]);
	}
	return 0;
}

void InsertList(Info** head, char* argv, char* azcolname){

	Info* node = (Info*) calloc(1, sizeof(Info));

	node->value = (char*) calloc(kMaxInfoSize, sizeof(char));
	node->colname = (char*) calloc(kMaxInfoSize, sizeof(char));

	memset(node->value,'\0', kMaxInfoSize);
	memset(node->colname,'\0', kMaxInfoSize);

	node->next = *head;

	strcpy(node->value, argv);
	strcpy(node->colname, azcolname);

	*head = node;

}

void ClearList(Info** head){

	if(nullptr != *head){
		Info* node = *head;
		Info* next = nullptr;

		while(node){
			next = node->next;
			free(node->value); node->value =nullptr;
			free(node->colname); node->colname = nullptr;
			free(node);
			node = next;
		}
	}
	else return;

}
