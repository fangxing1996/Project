#include "function.h"
extern Node* pHead;

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
    cout << "Please Input Stu Information: StuName, StuNum, Age, Score\n";
    if(pHead == NULL){
        pHead = (Node*)malloc(sizeof(Node));
        pHead -> next = NULL;
        cin >> pHead -> stu.chName >> pHead -> stu.nAge >> pHead -> stu.nStuNum >> pHead -> stu.nScore;
    }
    else{
        Node* p;
        p = pHead;
        while(p -> next != NULL){
            p = p -> next;
        }
        Node* pNewNode = (Node*)malloc(sizeof(Node));
        pNewNode -> next = NULL;
        cin >> pNewNode -> stu.chName >> pNewNode -> stu.nAge >> pNewNode -> stu.nStuNum >> pNewNode -> stu.nScore;
        p -> next = pNewNode;
    }
    cout << "Input Successful!\n";    
}

void printStudent(){
    system("cls");
    Node* p;
    p = pHead;
    while(p != NULL){
        cout << p -> stu.chName << " " << p -> stu.nAge << " " << p -> stu.nStuNum << " " << p -> stu.nScore << endl;
        p = p -> next;
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
    Node* p;
    p = pHead;
    while(p != NULL){
        fprintf(fp, "%s %d %d %d\n", p -> stu.chName, p -> stu.nAge, p -> stu.nStuNum, p -> stu.nScore);
        p = p -> next;
    }
    cout << "Save Successful!" << endl;
    fclose(fp);
}

void readStudent(){
    system("cls");
    Node *p0, *p1, *p2;
    p0 = pHead;
    p1 = p0;
    while(p0 != NULL){
        p0 = p0 -> next;
        free(p1);
        p1 = p0;
    }
    pHead = NULL;
    FILE* fp;
    fp = fopen("./stuinfo.data", "r");
    if(fp == NULL){
        cout << "Open sutinfo.data Failed!\n";
        return ;
    }
    while(!feof(fp)){
        Node* ptemp = (Node*)malloc(sizeof(Node));
        ptemp -> next = NULL;
        fscanf(fp, "%s %d %d %d\n", &ptemp -> stu.chName, &ptemp -> stu.nAge, &ptemp -> stu.nStuNum, &ptemp -> stu.nScore);
        if(pHead == NULL){
            pHead = ptemp;
            p2 = pHead;
            p2 -> next = NULL;
        }
        else{
            p2 -> next = ptemp;
            p2 = p2 -> next;
        }
    }
    cout << "Read stuinfo.data Successful!\n";
    fclose(fp);
}

void countStudent(){
    system("cls");
    cout << "Num Of Student Is: ";
    int count = 0;
    Node* p = pHead;
    while(p != NULL){
        count++;
        p = p -> next;
    }
    cout << count << endl;
}

void findStudent(){
    system("cls");
    cout << "Please Input Stu NUM:\n";
    int nStuNum;
    cin >> nStuNum;
    Node* p = pHead;
    while(p != NULL){
        if(p -> stu.nStuNum == nStuNum){
            cout << p -> stu.chName << ' ' << p -> stu.nAge << ' ' << p -> stu.nStuNum << ' ' << p -> stu.nScore << endl;
            break;
        }
        p = p -> next;
    }
    if(p == NULL)
        cout << "Can't Find!\n";
}

void modifyStudent(){
     system("cls");
    cout << "Before Modify! Please Input Stu NUM:\n";
    int nStuNum;
    cin >> nStuNum;
    Node* p = pHead;
    while(p != NULL){
        if(p -> stu.nStuNum == nStuNum){
            cout << "Input The New Info:\n";
            cin >> p -> stu.chName >> p -> stu.nAge >> p -> stu.nStuNum >> p -> stu.nScore;
            cout << "Modify Successful!\n";
            break;
        }
        p = p -> next;
    }
    if(p == NULL)
        cout << "Can't Find!\n";
}

void deleteStudent(){
     system("cls");
    cout << "Before Delete! Please Input Stu NUM:\n";
    int nStuNum;
    cin >> nStuNum;
    Node* p = pHead, *p1;
    p1 = p;
    while(p != NULL){
        if(p -> stu.nStuNum == nStuNum){
            if(p == pHead){
                pHead = pHead -> next;
                free(p);
                cout << "Delete Successful!\n";
                break;
            }
            else{
                p1 -> next = p -> next;
                free(p);
                cout << "Delete Successful!\n";
                break;
            }
        }
        p1 = p;
        p = p -> next;
    }
    if(p == NULL)
        cout << "Can't Find!\n";
}
