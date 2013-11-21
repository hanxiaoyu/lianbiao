lianbiao
========
#include<iostream>
using namespace std;
typedef struct node
{
	int element;
	struct node* next;
}
Listnode;

class List
{
public:
	Listnode* head;
	int number;
public:
	List()
	{
		head=(Listnode*)malloc(sizeof(Listnode));
		head->next=NULL;
		number=0;
	}
	int fpos(int pos,Listnode** ptr)
	{
		Listnode* p=head;
		int i=0;
		while(p&&i<pos)
		{
			i++;
			p=p->next;
		}
		if(p&&i==pos)
		{
			*ptr=p;
		}
		else
		{
			cout<<"指定的位置不存在"<<endl;
		}
		return 0;
	}
	int fnum(int num,int& pos,Listnode** ptr)
	{
		Listnode* p=head->next;
		int i=1;
		while(p)
		{
			if(p->element==num)
			{
				pos=i;
				*ptr=p;
				return 0;
			}
			else
			{
				p=p->next;
				i++;
			}
		}
		cout<<"未找到指定的值"<<endl;
		return 0;
	}
	int ins(int num=0,int pos=0)
	{	
		if(pos>number)
		{
			cout<<"位置越界"<<endl;
			return 0;
		}
		Listnode* pre;
		fpos(pos,&pre);
		Listnode* p=(Listnode*)malloc(sizeof(Listnode));
		p->element=num;
		p->next=pre->next;
		pre->next=p;
		number++;
		return 0;
	}
	int del(int pos)
	{
		if(pos>number)
		{
			cout<<"位置越界"<<endl;
			return 0;
		}
		Listnode* ptr;
		Listnode* q;
		fpos(pos-1,&ptr);
		q=ptr->next;
		ptr->next=q->next;
		free(q);
		number--;
		return 0;
	}
	void count()
	{
		cout<<"头结点后存在"<<number<<"个结点"<<endl;
	}
};

int main()
{
	List list;
	list.ins(1);
	list.ins(2);
	list.count();
	Listnode* p=(list.head)->next;
	while(p)
	{
		cout<<p->element<<endl;
		p=p->next;
	}
	list.del(1);
	list.count();
	p=(list.head)->next;
	while(p)
	{
		cout<<p->element<<endl;
		p=p->next;
	}
	return 0;
}
