//插入排序(从小到大) 
#include<stdio.h>
int number[100];     //在外面定义数组 
void insertion_sort(int *number,int n)    //定义一个插入函数"insertion_sort" 
{
    int i=0,ii=0,temp=0;  
    for(i=1;i<n;i++)  //循环遍历 
    {
        temp=number[i];  //将temp每一次赋值为number[i]   
        for(ii=i-1;ii>=0&&temp<number[ii];ii--)   //这里改顺序 (temp后的)"<"为小到大，">"为大到小 ！！！
        {
            number[ii+1]=number[ii];    //将大的元素往前放    
        }
        number[ii+1]=temp;   //与"number[ii+1]=number[ii];"一起意为 
    }              //如果插入的数比之前的大,将number[ii]与number[ii+1]互换 
}
int main() 
{
    int i=0,n;   
    scanf("%d",&n);       //输入要排序的数字的个数 
    for(int j=0;j<n;j++)       //将所有数全放入number数组中 
        scanf("%d",&number[j]) ;
    insertion_sort(number,n);   //引用插入函数 
    for(i=0;i<n-1;i++)    //循环输出 
        printf("%d ",number[i]);    //格式需要  
    printf("%d\n",number[i]);
    return 0;
}
//ENDING