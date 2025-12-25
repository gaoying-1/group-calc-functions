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
{ //新增：空指针检查
  if(arr==NULL||count==NULL||id==NULL)
  {
    printf("错误：传入空指针，删除操作终止。\n");
    return -2;//用-2区分空指针错误
  }
  int i,pos=-1;
  //检查学生数组是否为空
    if(*count==0){
        printf("学生列表为空，无法删除！\n");
        return -1;//返回-1表示删除失败
}
//2.遍历数组查找目标学号的学生
for(i=0;i<*count;i++){
if(strcmp(arr[i].id,id)==0){
pos=i;//记录目标学生的下标
      break;
}
}
//3.未找到对应学号的学生
if(pos==-1){
printf("未找到学号为%s的学生，删除失败！\n",id);
return -1;
}
//4.找到学生，执行删除（后续元素向前覆盖）
for(i=pos;i<*count-1;i++)
{
        arr[i]=arr[i+1];
}
(*count)--;
printf("学号为%s的学生已成功删除！\n",id);
return 0;
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

