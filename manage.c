#include"manage.h"
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
for(int i=0;i<count;i++)
{
	if(strcmp(arr[i].id, id)==0)
	{
		printf("Student found:\n");
		printf("ID:%s\n Name:%s\n Age:%d\n Score:%.2f\n",arr[i].id, arr[i].name, arr[i].age, arr[i].score);
		return i;
	}
}
printf("Student with ID %s not found!\n", id);
return -1;
}

//改：
int modifyStudent(Student arr[],int count,char *id)
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

