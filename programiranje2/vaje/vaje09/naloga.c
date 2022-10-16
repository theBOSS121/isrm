
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student **studentje, int stStudentov, int vpisna)
{
    for (int i = 0; i < stStudentov; i++)
    {
        if (studentje[i]->vpisna == vpisna)
            return i;
    }

    return -1;
}

int poisciPO(Student *student, char *predmet)
{
    for (int i = 0; i < student->stPO; i++)
    {
        if (strcmp(student->po[i].predmet, predmet) == 0)
            return i;
    }

    return -1;
}

// typedef struct _PO {   // par predmet-ocena
//     char predmet[4];   // oznaka predmeta
//     int ocena;         // ocena pri tem predmetu
// } PO;

// typedef struct _Student {   // podatki o "studentu
//     int vpisna;   // vpisna "stevilka
//     PO* po;       // kazalec na za"cetek tabele parov predmet-ocena
//     int stPO;     // "stevilo parov predmet-ocena
// } Student;

int dodaj(Student **studentje, int stStudentov, int vpisna, char *predmet, int ocena)
{
    int iStudenta = poisciStudenta(studentje, stStudentov, vpisna);

    if (iStudenta != -1)
    {
        int iPredmeta = poisciPO(studentje[iStudenta], predmet);
        if (iPredmeta != -1)
        {
            studentje[iStudenta]->po[iPredmeta].ocena = ocena;
        }
        else
        {
            studentje[iStudenta]->po[studentje[iStudenta]->stPO].ocena = ocena;
            strcpy(studentje[iStudenta]->po[studentje[iStudenta]->stPO].predmet, predmet);
            studentje[iStudenta]->stPO++;
        }
    }
    else
    {
        studentje[stStudentov] = (Student *)malloc(sizeof(Student));
        studentje[stStudentov]->vpisna = vpisna;
        studentje[stStudentov]->stPO = 1;
        studentje[stStudentov]->po = (PO *)malloc(10 * sizeof(PO));
        studentje[stStudentov]->po[0].ocena = ocena;
        strcpy(studentje[stStudentov]->po[0].predmet, predmet);

        stStudentov++;
    }
    return stStudentov;
}

int main()
{
    

    return 0;
}
