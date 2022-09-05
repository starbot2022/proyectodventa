#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caracteres.h"
#include "tabdb.h"
#include <time.h>

void crete_ID(char *ID)
{

        time_t rawtime;
        struct tm *info;
        time(&rawtime);

        info = localtime(&rawtime);

        strftime(ID, 20, "%y%m%H%I%M%S%p", info);
}

int new_client(char *ID, char *nombre, char *apellido, char *identificacion, char *phone, char *TdP)
{

        char client[500];
        sprintf(client, "%s\t%s\t%s\t%s\t%s\t%s", ID, nombre, apellido, identificacion, phone, TdP);

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        add_line_file(fp, client);

        fclose(fp);
}

int delete_client(int row)
{

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        delete_line_file(fp, row);

        fclose(fp);

        return 0;
}

int modify_name_clients(int row, char *nombre)
{

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        modify_col_file(fp, row, 1, nombre);
        fclose(fp);
        return 0;
}

int modify_lastname_clients(int row, char *apellido)
{

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        modify_col_file(fp, row, 2, apellido);
        fclose(fp);
        return 0;
}

int modify_dni_clients(int row, char *identificacion)

{
        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        modify_col_file(fp, row, 3, identificacion);

        fclose(fp);
        return 0;
}

int modify_phone_clients(int row, char *phone)
{

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        modify_col_file(fp, row, 4, phone);

        fclose(fp);
        return 0;
}

int modify_JoN_clients(int row, int TdP)
{

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        modify_col_file(fp, row, 5, TdP);

        fclose(fp);
        return 0;
}

int get_name_clients(int row, char *name)
{

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        read_col_file(fp, row, 1, name);
        fclose(fp);
        return 0;
}

int get_latname_clients(int row, char *apellido)
{

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        read_col_file(fp, row, 2, apellido);
        fclose(fp);
        return 0;
}

int get_dni_clients(int row, char *identificacion)
{
        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        read_col_file(fp, row, 3, identificacion);
        fclose(fp);
        return 0;
}

int get_phone_clients(int row, char *phone)
{

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        read_col_file(fp, row, 4, phone);
        fclose(fp);
        return 0;
}

int get_TdP_clients(int row, char *TdP)
{

        FILE *fp;

        fp = fopen("./clientes.txt", "r+");
        if (fp == NULL)
                return -1;

        read_col_file(fp, row, 5, TdP);
        fclose(fp);
        return 0;
}

int main()
{

        char nombre[100];
        char apellido[100];
        char identificacion[20];
        int phone[20];
        char TdP[20];

        printf("introduzca el nombre: ");
        gets(nombre);

        printf("introduzca el apellido: ");
        gets(apellido);

        printf("introduzca identificacion: ");
        gets(identificacion);

        printf("introduzca phone: ");
        gets(phone);

        printf("introduzca TdP");
        gets(TdP);

        char ID[20];

        crete_ID(ID);

        new_client(ID, nombre, apellido, identificacion, phone, TdP);

        return 0;
}