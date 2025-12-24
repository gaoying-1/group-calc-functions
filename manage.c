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
void addStudent(Student arr[], int *count)
{
    int newIndex = *count;
    clearInputBuffer();
    printf("\n输入新学生的信息：\n");
    printf("学号：");
    fgets(arr[newIndex].id, sizeof(arr[newIndex].id), stdin);
    arr[newIndex].id[strcspn(arr[newIndex].id, "\n")] = '\0';
    printf("姓名：");
    fgets(arr[newIndex].name, sizeof(arr[newIndex].name), stdin);
    arr[newIndex].name[strcspn(arr[newIndex].name, "\n")] = '\0';
    printf("年龄：");
    scanf("%d", &arr[newIndex].age);
    clearInputBuffer();
    printf("成绩：");
    scanf("%f", &arr[newIndex].score);
    clearInputBuffer();
    (*count)++;
    printf("\n学生信息添加成功！\n");
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

    clearInputBuffer();

    printf("\n请输入该学生的新信息：\n");
    printf("新姓名：");
    fgets(arr[index].name, sizeof(arr[index].name), stdin);
    arr[index].name[strcspn(arr[index].name, "\n")] = '\0';

    printf("新年龄：");
    scanf("%d", &arr[index].age);
    clearInputBuffer();

    printf("新成绩：");
    scanf("%f", &arr[index].score);
    clearInputBuffer();

    printf("\n学生信息修改成功！\n修改后的信息：\n");
    printf("ID:%s\n Name:%s\n Age:%d\n Score:%.2f\n", arr[index].id, arr[index].name, arr[index].age, arr[index].score);
    return index;
        
}

