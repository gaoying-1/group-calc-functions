#include<stdio.h>
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






int modifyStudent(Student arr[], int count, char *id)
{
    int index = queryStudent(arr, count, id);
    if (index == -1)
    {
        return -1;
    }

    printf("\n开始修改该学生的信息（直接回车表示保留原信息）：\n");

    char newName[20] = {0};
    int newAge = 0;
    float newScore = 0.0f;
    char tempBuffer[50] = {0};

    printf("原姓名：%s，请输入新姓名：", arr[index].name);
    fgets(tempBuffer, sizeof(tempBuffer), stdin);
    tempBuffer[strcspn(tempBuffer, "\n")] = '\0';
    if (strlen(tempBuffer) > 0)
    {
        strncpy(newName, tempBuffer, sizeof(newName) - 1);
        newName[sizeof(newName) - 1] = '\0';
        strcpy(arr[index].name, newName);
    }

    printf("原年龄：%d，请输入新年龄：", arr[index].age);
    fgets(tempBuffer, sizeof(tempBuffer), stdin);
    tempBuffer[strcspn(tempBuffer, "\n")] = '\0';
    if (strlen(tempBuffer) > 0)
    {
        if (sscanf(tempBuffer, "%d", &newAge) == 1 && newAge > 0 && newAge < 100)
        {
            arr[index].age = newAge;
        }
        else
        {
            printf("年龄输入无效，保留原年龄！\n");
        }
    }

    printf("原成绩：%.2f，请输入新成绩：", arr[index].score);
    fgets(tempBuffer, sizeof(tempBuffer), stdin);
    tempBuffer[strcspn(tempBuffer, "\n")] = '\0';
    if (strlen(tempBuffer) > 0)
    {
        if (sscanf(tempBuffer, "%f", &newScore) == 1 && newScore >= 0.0f && newScore <= 100.0f)
        {
            arr[index].score = newScore;
        }
        else
        {
            printf("成绩输入无效，保留原成绩！\n");
        }
    }

    printf("\n学生信息修改成功！\n");
    printf("修改后的信息：\n");
    printf("ID:%s\n Name:%s\n Age:%d\n Score:%.2f\n", arr[index].id, arr[index].name, arr[index].age, arr[index].score);
    return index;
}
