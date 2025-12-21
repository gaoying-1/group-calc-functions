#include"manage.h"

#define MAX_STUDENTS 50

int main()
{
Student students[MAX_STUDENTS];
int studentCount=0;
int choice;
char id[20];


while(1)
{
showMenu();
while(scanf(" %d",&choice)!=1)
{
clearInputBuffer();
printf("输入无效！\n");
showMenu();
}
switch(choice)
{
	case 1:
		addStudent(students,&studentCount);
		break;
	case 2:
		printf("请输入要删除的学号：");
		scanf("%19s",id);
		clearInputBuffer();
		deleteStudent(students,&studentCount,id);
		break;
	case 3:
		printf("请输入要查询的学号：");
		scanf("%19s",id);
		clearInputBuffer();
		queryStudent(students,studentCount,id);
		break;
	case 4:
		printf("请输入要修改的学号：");
		scanf("%19s",id);
		clearInputBuffer();
		modifyStudent(students,studentCount,id);
		break;
	case 0:
		printf("退出系统！\n");
		return 0;
	default:
		printf("输入错误，请重新输入！\n");
}
}
}
