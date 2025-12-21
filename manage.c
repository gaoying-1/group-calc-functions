#include"../manage.h"
#include<stdio.h>
#include<string.h>

void clearInputBuffer()
{
while(getchar()!='\n');
}

//菜单展示
void showMenu()
{
printf("\n=====学生管理系统=====\n");
printf("1.添加学生 2.删除学生\n");
printf("3.查询学生 4.修改学生\n");
printf("0.退出系统\n");
printf("========================\n");
printf("请选择操作: ");
}
//增：
void addStudent(Student arr[],int *count)
{
printf("添加函数待完成\n");
}

//删：
int deleteStudent(Student arr[],int *count,char *id)
{
printf("删除函数待完成\n");
return 0;
}

//查：
int queryStudent(Student arr[],int count,char *id)
{
printf("查询函数待完成\n");
return -1;
}

//改：
int modifyStudent(Student arr[],int count,char *id)
{
printf("修改函数待完成\n");
return 0;
}

