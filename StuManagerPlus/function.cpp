#include "function.h"
extern vector<Student> Stu;
void interface(){
    cout << "--------Welcome To The Student Manager!--------" << endl;
    cout << "\t\tPlease Select The Function: " << endl;
    cout << "\t\t1. Input Student Information!" << endl;
    cout << "\t\t2. Print Student Information!" << endl;
    cout << "\t\t3. Save Student Information!" << endl;
    cout << "\t\t4. Read Student Information!" << endl;
    cout << "\t\t5. Count Student Information!" << endl;
    cout << "\t\t6. Find Student Information!" << endl;
    cout << "\t\t7. Modify Student Information!" << endl;
    cout << "\t\t8. Delete Student Information!" << endl;
    cout << "\t\t0. Exit System!" << endl;
    cout << "[fangxing]$:";
}
void inputStudent(){
    system("cls");
    Student st;
    cout << "Please Input Stu Information: StuName, StuNum, Age, Score\n";
    cin >> st.chName >> st.nAge >> st.nStuNum >> st.nScore;
    Stu.push_back(st);
    cout << "Input Successful!\n";    
}

void printStudent(){
    system("cls");
    vector<Student>::iterator it;
    for(it = Stu.begin(); it != Stu.end(); it++){
        cout << it -> chName << ' ' << it -> nAge << ' ' << it -> nStuNum << ' ' << it -> nScore << endl;
    }
    cout << "Print Successful!\n";
}

void saveStudent(){
    system("cls");
    FILE *fp;
    fp = fopen("./stuinfo.data", "w");
    if(fp == NULL){
        cout << "Open File Failed!\n";
        return ;
    }
    vector<Student>::iterator it;
    for(it = Stu.begin(); it != Stu.end(); it++){
       fprintf(fp, "%s %d %d %d\n", it -> chName, it -> nAge, it -> nStuNum, it -> nScore);
    }
    cout << "Save Successful!" << endl;
    fclose(fp);
}

void readStudent(){
    system("cls");
    Stu.clear();
    FILE* fp;
    fp = fopen("./stuinfo.data", "r");
    if(fp == NULL){
        cout << "Open sutinfo.data Failed!\n";
        return ;
    }
    Student st;
    while(!feof(fp)){
        fscanf(fp, "%s %d %d %d\n", &st.chName, &st.nAge, &st.nStuNum, &st.nScore);
        Stu.push_back(st);
    }
    cout << "Read stuinfo.data Successful!\n";
    fclose(fp);
}

void countStudent(){
    system("cls");
    cout << "Num Of Student Is: " << Stu.size() << endl;
}

void findStudent(){
    system("cls");
    cout << "Please Input Stu NUM:\n";
    int nStuNum;
    cin >> nStuNum;
    vector<Student>::iterator it;
    for(it = Stu.begin(); it != Stu.end(); it++){
       if(it -> nStuNum == nStuNum){
           cout << it -> chName << ' ' << it -> nAge << ' ' << it -> nStuNum << ' ' << it -> nScore << endl;
           break;
       }
    }
    if(it == Stu.end())
        cout << "Can't Find!\n";
}

void modifyStudent(){
    system("cls");
    cout << "Before Modify! Please Input Stu NUM:\n";
    int nStuNum;
    cin >> nStuNum;
    vector<Student>::iterator it;
    for(it = Stu.begin(); it != Stu.end(); it++){
       if(it -> nStuNum == nStuNum){
           cout << "Input The New Stu Info:\n";
           cin >> it -> chName >> it -> nAge >> it -> nStuNum >> it -> nScore;
           break;
       }
    }
    if(it == Stu.end())
        cout << "Can't Find!\n";
}

void deleteStudent(){
     system("cls");
    cout << "Before Delete! Please Input Stu NUM:\n";
    int nStuNum;
    cin >> nStuNum;
    vector<Student>::iterator it;
    for(it = Stu.begin(); it != Stu.end(); it++){
       if(it -> nStuNum == nStuNum){
           Stu.erase(it);
           cout << "Delete Successful!\n";
           break;
       }
    }
    if(it == Stu.end())
        cout << "Can't Find!\n";
}
