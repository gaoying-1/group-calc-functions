#ifndef MANAGE_H
#define MANAGE_H

#define MAX_STUDENTS 50

typedef struct
{
	char id[20];
	char name[20];
	int age;
	float score;
}Student;

//菜单展示
void showMenu();
//添加学生
void addStudent(Student arr[],int *count);
//删除学生
int deleteStudent(Student arr[],int *count,char *id);
//按学号查询
int queryStudent(Student arr[],int count,char *id);
//按学号修改
int modifyStudent(Student arr[],int count,char *id);
void clearInputBuffer();
#endif
