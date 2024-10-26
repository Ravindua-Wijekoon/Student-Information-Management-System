#include<stdio.h>
#include<string.h>

//structure for course details
struct courses{
    char ID[20];
    char cName[50];
    int cValue;
};

//structures for student details
struct courseCounter{
    char ID[50][20];
    char grade[50][3];
    char Following[50][200];
}cc;

struct students{
    char index[50];
    char name[200];
    char dep[50];
    int courseNo;
    float GPA;
    struct courseCounter cc;
}st;

//structure for update student data
struct courseCounter2{
    char ID[50][20];
    char grade[50][3];
    char Following[50][200];
}cc2;

//structure for update student data
struct students2{
    char index[50];
    char name[200];
    char dep[50];
    int courseNo;
    float GPA;
    struct courseCounter cc2;
}st2[];

//Start menu
int startMenu(){
    int selection=0;
    printf("\n-----------------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\t     STUDENT INFOMATION SYSTEM");
    printf("\n\n\-----------------------------------------------------------------------------------------------------------------");
    printf("\n\n\n\t\t\t\t============================================\n\n");
    printf("\t\t\t\t\t\t  Main Menu\n\n\n");
    printf("\t\t\t\tStudents Info Section \n\n");
    printf("\t\t\t\t\t1 - Enter Student Details\n");
    printf("\t\t\t\t\t2 - Search Student Details\n");
    printf("\t\t\t\t\t3 - Display List Of Students Details\n");
    printf("\t\t\t\t\t4 - Edit Student Details\n\n");
    printf("\t\t\t\tCourse Info Section\n\n");
    printf("\t\t\t\t\t5 - Display List Of Courses We Have\n");
    printf("\t\t\t\t\t6 - Add Courses\n");
    printf("\n\n\t\t\t\t\t7 - To Exit\n\n");
    printf("\t\t\t\t============================================\n\n\n\n");
    printf("\t\tEnter your selection number from Main Menu : ");
    scanf("%d",&selection);
    fgetc(stdin);
    system("cls");
    return selection;
};

float calScore(int creditValue,int k){
    float score=0;
    int c=1;
    float credit;
    int g;
    printf("\t\t\tEnter course Grade - A,B,C,D,E or ab (for absent) : ");
    gets(st.cc.grade[k]);

    while(c!=0){

        if(strcmp("A",st.cc.grade[k])==0){
            credit=4;
            c=0;
        }else if(strcmp("B",st.cc.grade[k])==0){
            credit=3;
            c=0;
        }else if(strcmp("C",st.cc.grade[k])==0){
            credit=2.5;
            c=0;
        }else if(strcmp("D",st.cc.grade[k])==0){
            credit=1.5;
            c=0;
        }else if(strcmp("E",st.cc.grade[k])==0){
            credit=0;
            c=0;
        }else if(strcmp("ab",st.cc.grade[k])==0){
            credit=0;
            c=0;
        }else{
            printf("\n\t\t\t\t Invalid Grade\n");
            printf("\t\t\tEnter course Grade - A,B,C,D,E or ab (for absent) : ");
            gets(st.cc.grade[k]);
        }
    }
    score=creditValue*credit;
    return score;
}

float calScorefor_Update(int creditValue,int i,int k){
    float score=0;
    int c=1;
    float credit;
    int g;
    printf("\t\t\tEnter course Grade - A,B,C,D,E or ab (for absent) : ");
    gets(st2[i].cc2.grade[k]);

    while(c!=0){

        if(strcmp("A",st2[i].cc2.grade[k])==0){
            credit=4;
            c=0;
        }else if(strcmp("B",st2[i].cc2.grade[k])==0){
            credit=3;
            c=0;
        }else if(strcmp("C",st2[i].cc2.grade[k])==0){
            credit=2.5;
            c=0;
        }else if(strcmp("D",st2[i].cc2.grade[k])==0){
            credit=1.5;
            c=0;
        }else if(strcmp("E",st2[i].cc2.grade[k])==0){
            credit=0;
            c=0;
        }else if(strcmp("ab",st2[i].cc2.grade[k])==0){
            credit=0;
            c=0;
        }else{
            printf("\n\t\t\t\t Invalid Grade\n");
            printf("\t\t\tEnter course Grade - A,B,C,D,E or ab (for absent) : ");
            gets(st2[i].cc2.grade[k]);
        }
    }
    score=creditValue*credit;
    return score;
}

void StuInfo(FILE *fstu ,FILE *fcourse){
        struct courses cr;
        int no_ofCourse=0;
        float TotScore=0,TotCredit=0;

        fstu=fopen("students.txt","r");
        if(fstu==NULL){
            fstu=fopen("students.txt","w");
        }

        //check file empty or not
        int empty=0;
        while(fread(&st,sizeof(struct students),1,fstu)){
                empty++;
        }
        fclose(fstu);
        printf ("\n\n\n\t\t\t\t\t### Student details entering section ###\n\n\n");

        char testIndex[50];

        //Get data from user and save data in files
        int check=0;
        printf("\t\tEnter Index number :");
        gets(testIndex);
                fstu=fopen("students.txt","r");
                if(fstu==NULL){
                    printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
                    scanf(stdin);
                    main();
                }
                while(fread(&st,sizeof(struct students),1,fstu)){
                    check=strcmp(testIndex,st.index);
                    while(check==0){
                        printf("\t\t\t\tIndex already exist\n ");
                        printf("\n\t\tEnter Index number :");
                        gets(testIndex);
                        check=strcmp(testIndex,st.index);
                    }
                }
                fclose(fstu);
        strcpy(st.index,testIndex);
        printf("\t\tEnter Student name :");
        gets(st.name);
        printf("\t\tEnter Department :");
        gets(st.dep);
        printf("\t\tNumber of Courses Followed/Following by Student : ");
        scanf("%d",&no_ofCourse);
        st.courseNo=no_ofCourse;
        fgetc(stdin);

        //displaying list of courses
        fcourse=fopen("courses.txt","r");
            if(fcourse==NULL){
                printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
                scanf(stdin);
                main();
            }
        printf("\n\t\t\t\t\tcourse list\n");
        while(fread(&cr,sizeof(struct courses),1,fcourse)){
                    printf("\n\t\t\t\t%s -  %s",cr.ID,cr.cName);
        }
        fclose(fcourse);
        printf("\n");

        int k=0;
        int state=1;
        while( k<no_ofCourse){
            fcourse=fopen("courses.txt","r");
            if(fcourse==NULL){
                printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
                scanf(stdin);
                main();
            }
            printf("\n\n\t\t Enter Course %d ID : ",(k+1));
            gets(st.cc.ID[k]);
            while(fread(&cr,sizeof(struct courses),1,fcourse)){
                state=strcmp(st.cc.ID[k],cr.ID);
                if(state==0){
                        //Get GPV
                        TotCredit=TotCredit+cr.cValue;
                        TotScore =TotScore+ calScore(cr.cValue,k);
                        strcpy(st.cc.Following[k],cr.cName);
                        fclose(fcourse);
                        k++;
                        break;
                }
                state=1;
            }
            if(state!=0){
                printf("\t\t\tInvalic course ID\n");
            }
            fclose(fcourse);
        }
        st.GPA=TotScore/TotCredit;

        fstu=fopen("students.txt","a");
        if(fstu==NULL){
            printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
            scanf(stdin);
            main();
        }
        fwrite(&st,sizeof(struct students),1,fstu);
        fclose(fstu);

        printf("\n\n\t\t\t\t\tData Saved press ENTER to main menu\n");
        scanf(stdin);
        system("cls");
}

void courseInfo(FILE *fcourse){

    struct courses cr;
    char check[20];
    int count=0;

    //open file for append
    fcourse=fopen("courses.txt","a");
    if(fcourse==NULL){
        printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
        scanf(stdin);
        main();
    }
    printf ("\n\n\n\t\t\t\t### Course Details Entering Section ###\n\n\n");

    //get data form user
    printf("\n\n\t\tEnter course ID : ");
    gets(check);
    while(fread(&cr,sizeof(struct courses),1,fcourse)){

        if(strcmp(cr.ID,check)==0){
                printf("\n\n\t\t\t\t\tCourse ID already have");
                count=1;
                break;
        }else{
            count=0;
        }
    }
    if(count==0){
        strcpy(cr.ID,check);
        printf("\t\tEnter course name : ");
        gets(cr.cName);
        printf("\t\tEnter Credit Value : ");
        scanf("%d",&cr.cValue);
        fgetc(stdin);

        //save data in file
        fwrite(&cr,sizeof(struct courses),1,fcourse);
        printf("\n\n\t\t\tSuccessfully Added ");
    }
    scanf(stdin);
    fclose(fcourse);
    system("cls");
}

void searchStudentInfo(FILE *fstu){
    printf ("\n\n\n\t\t\t\t\t### Students Details ###\n\n\n");
    char getIndex[50];
    int state;
    int loop=0;
    printf("\n\n\n\t\t\tEnter Student Index : ");
    gets(getIndex);

    fstu=fopen("students.txt","r");
    if(fstu==NULL){
            printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
            scanf(stdin);
            main();
    }
    while(fread(&st,sizeof(struct students),1,fstu)){
        state=strcmp(getIndex,st.index);
        if(state==0){
            loop++;
            printf("\n\n\n\t\tStudent Name  \t\t: %s\n",st.name);
            printf("\t\tDepartment  \t\t: %s\n",st.dep);
            printf("\t\tNo.of Courses Followed  : %d\n",st.courseNo);

            for(int i=0; i<st.courseNo; i++){
                printf("\t\tCourse %d  \t\t: %s - %s (%s)\n",(i+1),st.cc.ID[i],st.cc.Following[i],st.cc.grade[i]);
            }
            printf("\t\tGPA  \t\t\t: %.2f\n",st.GPA);
        }
    }
    fclose(fstu);
    if(loop==0){
        printf("\n\n\n\t\t\t\t Invalid Index, there is no record to that Index");
    }
        printf("\n\n\t\t\t\t\t   Press ENTER for Main Menu");
        scanf(stdin);
        system("cls");
}

void displayStudents(FILE *fstu){
        int i=0;
        printf ("\n\n\n\t\t\t\t\t### All Students Details ###\n\n\n");
        fstu=fopen("students.txt","r");
        if(fstu==NULL){
            printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
            scanf(stdin);
            main();
        }
        while(fread(&st,sizeof(struct students),1,fstu)){
                printf("\n\n\t\t\tStudent Index  \t\t= %s",st.index);
                printf("\n\t\t\tStudent Name  \t\t= %s",st.name);
                printf("\n\t\t\tDepartment  \t\t= %s",st.dep);
                printf("\n\t\t\tNo.of courses followed  = %d",st.courseNo);
                for(int i=0;i<(st.courseNo); i++){
                    printf("\n\t\t\tCourse %d  \t\t: %s - %s (%s)",(i+1),st.cc.ID[i],st.cc.Following[i],st.cc.grade[i]);
                }
                printf("\n\t\t\tGPA = \t\t\t= %.2f",st.GPA);
                printf("\n\t\t\t====================================================\n");
            }
        fclose(fstu);
        printf("\n\n\n\t\t\tpress ENTER for main menu ");
        scanf(stdin);
        system("cls");
}

void displaycourses(FILE *fcourse){
    struct courses cr;
    fcourse=fopen("courses.txt","r");
    if(fcourse==0){
        printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
        scanf(stdin);
        main();
    }
    printf ("\n\n\n\t\t\t\t\t### All Course Details ###\n\n\n");
    while(fread(&cr,sizeof(struct courses),1,fcourse)){
        printf("\t\t==============================================\n");
        printf("\t\tCourse ID\t\t:%s\n",cr.ID);
        printf("\t\tCourse Name\t\t:%s\n",cr.cName);
        printf("\t\tCredit Value\t\t:%d\n\n",cr.cValue);

    }
    close(fcourse);
    printf("\t\tPress 'Enter' to Exit ");
    scanf(stdin);
    system("cls");
}

void editStuInfo(FILE *fstu,FILE *fcourse){

    struct courses cr;
    FILE *copy;
    char getindex[50];
    int check;
    int no_ofCourse;
    float TotScore=0,TotCredit=0;
    printf ("\n\n\t\t\t\t### Edit Student Details ###\n\n\n");

    //get no of records in student file
    fstu=fopen("students.txt","r");
    if(fstu==0){
        printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
        scanf(stdin);
        main();
    }
    int no_of_rec=0;
    while(fread(&st,sizeof(struct students),1,fstu)){
            no_of_rec++;
    }
    fclose(fstu);
    printf("\n\tEnter index of student you want to edit : ");
    gets(getindex);

    fstu=fopen("students.txt","r");
    if(fstu==0){
        printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
        scanf(stdin);
        main();
    }
    int update=0;
    int c=0;
    while(fread(&st,sizeof(struct students),1,fstu)){
        check=strcmp(st.index,getindex);
        if(check==0){
            update=1;
            printf("\n\t\tEnter NEW Index number :");
            gets(st2[c].index);
            printf("\t\tEnter NEW Student name :");
            gets(st2[c].name);
            printf("\t\tEnter NEW Department :");
            gets(st2[c].dep);

            printf("\t\tNumber of Courses Followed/Following by Student : ");
            scanf("%d",&no_ofCourse);
            st2[c].courseNo=no_ofCourse;
            fgetc(stdin);

            //displaying list of courses
            fcourse=fopen("courses.txt","r");
            if(fcourse==0){
                printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
                scanf(stdin);
                main();
            }
            printf("\n\t\t\t\t\tcourse list\n");
            while(fread(&cr,sizeof(struct courses),1,fcourse)){
                        printf("\n\t\t\t\t%s -  %s",cr.ID,cr.cName);
            }
            printf("\n");
            fclose(fcourse);

            int k=0;
            int state=1;
            while( k<no_ofCourse){
                fcourse=fopen("courses.txt","r");
                if(fcourse==0){
                    printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
                    scanf(stdin);
                    main();
                }
                printf("\n\t\t Enter Course %d ID : ",(k+1));
                gets(st2[c].cc2.ID[k]);
                while(fread(&cr,sizeof(struct courses),1,fcourse)){
                    state=strcmp(st2[c].cc2.ID[k],cr.ID);
                    if(state==0){

                            //Get GPV
                            TotCredit=TotCredit+cr.cValue;
                            TotScore =TotScore+ calScorefor_Update(cr.cValue,c,k);
                            strcpy(st2[c].cc2.Following[k],cr.cName);
                            fclose(fcourse);
                            k++;
                            break;
                    }
                    state=1;
                }
                if(state!=0){
                    printf("\t\t\tInvalic course ID\n");
                }
                fclose(fcourse);
            }
            st2[c].GPA=TotScore/TotCredit;

        }else{
            strcpy(st2[c].index,st.index);
            strcpy(st2[c].name,st.name);
            strcpy(st2[c].dep,st.dep);
            st2[c].courseNo=st.courseNo;
            st2[c].GPA=st.GPA;
            for(int i=0;i<st.courseNo; i++){
                strcpy(st2[c].cc2.ID[i],st.cc.ID[i]);
                strcpy(st2[c].cc2.Following[i],st.cc.Following[i]);
                strcpy(st2[c].cc2.grade[i],st.cc.grade[i]);
            }
        }
        c++;
    }
    fclose(fstu);
    if(update==1){
            fstu=fopen("students.txt","w");
            if(fstu==0){
                printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
                scanf(stdin);
                main();
            }
            for(int k=0; k<no_of_rec; k++){
                fwrite(&st2[k],sizeof(struct students2),1,fstu);
            }
            printf("\n\n\n\t\t\t\tSaving successful press ENTER for main menu");
            scanf(stdin);
            fclose(fstu);
            system("cls");
    }else{
        printf("\n\n\n\t\t\tInvalid Index, there is no any record to this index. press ENTER for main menu");
        scanf(stdin);
        system("cls");
    }
}

void predefineCourses(FILE *fcourse){
    fcourse=fopen("courses.txt","a");
    if(fcourse==0){
        printf("\n\n\t\tSomthing wrong, can't open file, press ENTER to exit");
        scanf(stdin);
        main();
    }
    //predefine courses
    struct courses cr0={"FT 1201","Basic Mathematics",2};
    struct courses cr1={"FT 1301","Physics",3};
    struct courses cr2={"IC 1101","Essentials ICT",1};
    struct courses cr3={"IC 1201","Introduction to Computer Systems",2};
    struct courses cr4={"IC 1301","Application Laboratory I",3};
    struct courses cr5={"IC 1302","Programming I",3};
    struct courses cr6={"FT 1204","Computer Applications",2};
    struct courses cr7={"IC 1202","Information System Modeling",2};
    struct courses cr8={"IC 1203","Web Application Development",2};
    struct courses cr9={"IC 1304","Database Management Systems I",2};

    //append to file
    fwrite(&cr0,sizeof(struct courses),1,fcourse);
    fwrite(&cr1,sizeof(struct courses),1,fcourse);
    fwrite(&cr2,sizeof(struct courses),1,fcourse);
    fwrite(&cr3,sizeof(struct courses),1,fcourse);
    fwrite(&cr4,sizeof(struct courses),1,fcourse);
    fwrite(&cr5,sizeof(struct courses),1,fcourse);
    fwrite(&cr6,sizeof(struct courses),1,fcourse);
    fwrite(&cr7,sizeof(struct courses),1,fcourse);
    fwrite(&cr8,sizeof(struct courses),1,fcourse);
    fwrite(&cr9,sizeof(struct courses),1,fcourse);

    fclose(fcourse);
}

int main(){
    struct courses cr;
    //create files
    FILE *fstu=NULL;
    FILE *fcourse=NULL;

    fcourse=fopen("courses.txt","r");
    if(fcourse==NULL){
        fcourse=fopen("courses.txt","w");
    }
    //check courses file is empty or not
    int counter=0;
    while(fread(&cr,sizeof(struct courses),1,fcourse)){
            counter++;
    }
    if(counter==0){
            predefineCourses(fcourse);
    }

    //select section from main menu according to user input
    int select=0;
    while(0<1){
        select=startMenu();
        if(select==1){
            StuInfo(fstu,fcourse);
        }else if(select==2){
            searchStudentInfo(fstu);
        }else if (select==3){
            displayStudents(fstu);
        }else if(select==4){
            editStuInfo(fstu,fcourse);
        }else if(select==5){
            displaycourses(fcourse);
        }else if(select==6){
            courseInfo(fcourse);
        }else if(select==7){
            exit(0);
        }
    }
    return 0;
}

