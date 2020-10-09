#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<vector>
#include "./function.h"
using namespace std;
vector<Student> Stu;
extern void inputStudent();
extern void printStudent();
extern void saveStudent();
extern void readStudent();
extern void countStudent();
extern void findStudent();
extern void modifyStudent();
extern void deleteStudent();
extern void interface();
int main(){
    system("color 9f");
	system("mode con cols = 74 lines = 25");
    readStudent();
    system("cls");
    while(1){
        interface();
        char ch;
        ch = _getch();
        switch(ch){
            case '1':
                inputStudent();
                break;
            case '2':
                printStudent();
                break;
            case '3':
                saveStudent();
                break;
            case '4':
                readStudent();
                break;
            case '5':
                countStudent();
                break;
            case '6': 
                findStudent();                
                break;
            case '7':
                modifyStudent();
                break;
            case '8':
                deleteStudent();
                break;
            case '0':
                saveStudent();
                cout << "ByeBye!";
                return 0;
            default:
                system("cls");
                cout << "Input Error! Please Try Again!" << endl;
                break;
        }
    }
    return 0;
}
