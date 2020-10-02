#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#include<iostream>
typedef struct tagStudent{
    char chName[20];
    int nAge;
    int nStuNum;
    int nScore;
}Student;

typedef struct tagNode{
    Student stu;
    struct tagNode* next;
}Node;
void inputStudent();
void printStudent();
void saveStudent();
void readStudent();
void countStudent();
void findStudent();
void modifyStudent();
void deleteStudent();
#endif
