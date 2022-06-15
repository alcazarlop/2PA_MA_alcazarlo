
#include "sql_interface.h"
#include <string>

void SQLInit(Database* database, const char* path){

	database->sql_query = (char*) calloc(kQuerySize, sizeof(char));
	database->err_msg = (char*) calloc(kQuerySize, sizeof(char));
	memset(database->sql_query, '\0', kQuerySize);
	memset(database->err_msg, '\0', kQuerySize);

	database->rc = sqlite3_open(path, &database->db);

	if (database->rc != SQLITE_OK) {
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(database->db));
		sqlite3_close(database->db);
	}

	SQLExecute_read(database, "SELECT name FROM sqlite_master where type ='table'");
	sqlite3_close(database->db);
}

void SQLExecute_read(Database* database, char* query){
  database->colname.clear();
  database->value.clear();
	database->rc = sqlite3_exec(database->db, query, read_from_table_callback, (Database*) database, &database->err_msg);
	if (database->rc != SQLITE_OK ) {
		fprintf(stderr, "Failed to select data\n");
		fprintf(stderr, "SQL error: %s\n", database->err_msg);
		sqlite3_free(database->err_msg);
	}

	for(int i = 0; i < database->colname.size(); ++i){
		printf("%s : %s\n",database->colname[i], database->value[i]);
	}
}

void SQLExecute_create(Database* database, char* query){
  database->colname.clear();
  database->value.clear();
	database->rc = sqlite3_exec(database->db, query, NULL, nothing_callback, &database->err_msg);
	if (database->rc != SQLITE_OK ) {
		fprintf(stderr, "Failed to select data\n");
		fprintf(stderr, "SQL error: %s\n", database->err_msg);
		sqlite3_free(database->err_msg);
	}
}

void SQLOpen(Database* database, const char* path){
	database->rc = sqlite3_open(path, &database->db);
	if (database->rc != SQLITE_OK) {
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(database->db));
		sqlite3_close(database->db);
	}
}

void SQLClose(Database *database){
	sqlite3_close(database->db);
}

void SQLExit(Database *database){
	free(database->err_msg);
	free(database->sql_query);
	database->colname.clear();
	database->value.clear();
	sqlite3_close(database->db);
}

int read_from_table_callback(void* notused, int argc, char** argv, char** azcolname){
	Database* temp = (Database*) notused;

	for(int i = 0; i < argc; ++i){
		char* value = (char*)malloc(sizeof(kMaxInfoSize));
		char* colum = (char*)malloc(sizeof(kMaxInfoSize));

		strcpy(value, argv[i]);
		temp->value.push_back(value);

		strcpy(colum, azcolname[i]);
		temp->colname.push_back(colum);
	}

	return 0;
}

int nothing_callback(void* notused, int argc, char** argv, char** azcolname){
	Database* temp = (Database*) notused;
	argc = 0;
	argv = NULL;
	azcolname= NULL;

	return 0;
}

void InsertList(Info** head, int col, char* argv, char* azcolname){

	Info* node = (Info*) calloc(1, sizeof(Info));

	node->columns = col;
	node->value = (char*) calloc(kMaxInfoSize, sizeof(char));
	node->colname = (char*) calloc(kMaxInfoSize, sizeof(char));

	memset(node->value,'\0', kMaxInfoSize);
	memset(node->colname,'\0', kMaxInfoSize);

	node->next = *head;

	strcpy(node->value, argv);
	strcpy(node->colname, azcolname);

	*head = node;

}

void ResetList(Info** head){
if(nullptr != *head){
		Info* node = *head;
		Info* next = nullptr;

		while(node){
			next = node->next;
			free(node->value); node->value = nullptr;
			free(node->colname); node->colname = nullptr;
			node = next;
		}
	}
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
}
