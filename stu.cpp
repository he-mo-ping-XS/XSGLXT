//类成员函数定义
#include "stu.h"
#include "cstring" 
CSTU *CSTU::stulinkhead=NULL;
CSTU *CSTU::stulinktail=NULL;
int CSTU::num=0;
CSTU::CSTU()
{
	this->pnext=NULL;
	if (stulinkhead==NULL)  stulinkhead=this,stulinktail=this;
	else  stulinktail->pnext=this,stulinktail=this;
	num++;
} 
CSTU::CSTU(int x) 
{
} 
CSTU::CSTU(string sno,string sname,string sex,unsigned short int year,unsigned short int month,unsigned short int day,int s1,int s2,int s3):sBirth(year,month,day)
{
		sNo=sno,sName=sname,sSex=sex,sScore[0]=s1,sScore[1]=s2,sScore[2]=s3;
}
void CSTU::outPutInfo()
{
	CSTU *sptr; 
	sptr=stulinkhead;
	if(sptr ==NULL) cout<<"当前没有学生数据"<<endl;
	else{
		system("cls"); 
		cout<<endl<<endl;
		while(sptr !=NULL)
		{
			cout<<"==============================学生信息==========================="<<endl; 
			cout<<endl
				<<"学号:"
				<<"姓名:"
				<<"性别:"
				<<"出生日期:"
				<<"高等数学:"
				<<"大学英语:"
				<<"大学计算:";
			cout<<endl
				<<sptr->sNo
				<<","<<sptr->sName
				<<","<<sptr->sSex
				<<",";sptr->sBirth.outputDate();
			cout<<","<<sptr->sScore[0]
				<<","<<sptr->sScore[1]
				<<","<<sptr->sScore[2]<<endl;
			sptr=sptr->pnext;
		}
		cout<<endl<<endl<<"当前有"<<num <<"学生"; 
	}
	system("pause");
}
void CSTU::showMunu()
{
	char munu='0';
	char s; 
	do{
		system("cls"); 
		cout<<"\t\t========学生管理系统========="<<endl;
		cout<<"\t\t\t1.添加学生信息"<<endl; 
		cout<<"\t\t\t2.输出学生信息"<<endl; 
		cout<<"\t\t\t3.编辑学生信息"<<endl; 
		cout<<"\t\t\t4.删除学生信息"<<endl; 
		cout<<"\t\t\t5.计算学生平均成绩"<<endl; 
		cout<<"\t\t\t6.学号排序"<<endl; 
		cout<<"\t\t\t7.保存到文件"<<endl; 
		cout<<"\t\t\t8.文件数据输入到程序"<<endl; 
		cout<<"\t\t\t0.退出学生系统"<<endl; 
		cin >>munu;
		switch (munu)
		{
			case '1':CSTU *p;p= new CSTU;p->inputStu();system("pause"); break;
			case '2':outPutInfo();break;
			case '3':cout<<"选择的是编辑学生信息"<<endl;editstu();system("pause");break;
			case '4':cout<<"选择的是删除学生信息"<<endl;delestu ();system("pause");break;
			case '5':cout<<"选择的是计算学生平均成绩"<<endl;totalstu();system("pause");break;
			case '6':cout<<"学号排序"<<endl;sortstu();break;
			case '7':cout<<"保存学生信息到文件"<<endl;savestu();system("pause");break; 
			case '8':cout<<"文件数据输入到程序"<<endl;readstu();break; 
		 } 
		 if(munu=='0') break; 
	}while(1);
}
void CSTU::inputStu()
{
	system ("cls");
	cout<<"\t\t=====添加学生信息"<<endl;
	cout<<"\t\t=====请输入学号:"; cin>> sNo;
	while(snoexist(sNo) == true) 
		{
			cout<<"\t\t=====学号重复，请重新输入学号:"; cin>> sNo;
		}
	cout<<"\t\t=====请输入姓名:"; cin>> sName;
	cout<<"\t\t=====请输入性别:"; cin>> sSex;
	cout<<"\t\t=====请输入出生年月日(xxxx-xx-xx):";
	{
		char sDate[11]={0};
		char sY[5]={0};
		int pos=0,i=0,j=1;
		int y,m,d;
		cin >>sDate;
		for(;pos<strlen(sDate);pos++)
		{
			if(sDate[pos]=='-')
			{
				i=0,j++;
				memset(sY,'\0',sizeof(sY));
			 } else{
			 	sY[i]= sDate[pos];
			 	i++;
			 }
			 switch (j)
			 {
			 	case 1:y=atoi(sY);break;
			 	case 2:m=atoi(sY);break;
			 	case 3:d=atoi(sY);break;
			 }
		}
		this->sBirth=CDATE(y,m,d);	
	}
	cout<<"\t\t=====高等数学:";cin>>sScore[0]; 
	cout<<"\t\t=====大学英语:";cin>>sScore[1]; 
	cout<<"\t\t=====大学计算机基础:";cin>>sScore[2]; 
	cout<<"文件添加成功"<<endl; 
	
}
bool CSTU::snoexist(string x)
{ 
	CSTU *sptr;
	sptr=stulinkhead;
	while (sptr!=stulinktail) 
	{
		if(sptr->sNo==x) return true;
		else sptr=sptr -> pnext;
	 } 
	 return false;
}
CSTU* CSTU::serchstu(string x)
{
	CSTU *ptr; 
	ptr=stulinkhead;
	while (ptr!=NULL) 
	{
		if(ptr->sNo==x){ return ptr;}
		else ptr=ptr-> pnext;
	 } 
	 return NULL;
}
void CSTU::editstu()
{
	CSTU *ptr=NULL;
	string So;
	cout<<"请输入你要编辑的学生学号：";cin>>So;
	ptr=serchstu(So);
	if(ptr ==NULL){
		cout <<So<<"学号不存在,退出学生删除"; 
		return;
	}
	while(1)
	{
		char  munu;
		string x;
		bool y; 
		system("cls"); 
		cout<<"\t\t========请输入你要编辑的学生信息编号========="<<endl;
		cout<<"\t\t\t1.学号"<<endl; 
		cout<<"\t\t\t2.姓名"<<endl; 
		cout<<"\t\t\t3.性别"<<endl; 
		cout<<"\t\t\t4.出生年月日(xxxx-xx-xx)"<<endl; 
		cout<<"\t\t\t5.高等数学成绩"<<endl; 
		cout<<"\t\t\t6.大学英语成绩"<<endl; 
		cout<<"\t\t\t7.大学计算机成绩"<<endl; 
		cout<<"\t\t\t8.退出编辑系统"<<endl; 
		cin >>munu;
		switch (munu)
		{
			
			case '1':
			{
				cout<<"请输入新学号:";cin>>x;
				while( snoexist(x) == true) 
					{
						cout<<"\t\t=====学号重复，请重新输入学号:"; cin>> x;
					}
					ptr->sNo=x;
					break;
			}
			case '2':cout<<"请输入新姓名:";cin>>ptr->sName; break;
			case '3':cout<<"请输入新性别:";cin>>ptr->sSex ; break;
			case '4': 
				{
					cout<<"请输入新出生年月日(xxxx-xx-xx):";
					char sDate[11]={0};
					char sY[5]={0};
					int pos=0,i=0,j=1;
					int y,m,d;
					cin >>sDate;
					for(;pos<strlen(sDate);pos++){
						if(sDate[pos]=='-')
						{
							i=0,j++;
							memset(sY,'\0',sizeof(sY));
						 } else{
						 	sY[i]= sDate[pos];
						 	i++;
						 }
						 switch (j)
						 {
						 	case 1:y=atoi(sY);break;
						 	case 2:m=atoi(sY);break;
						 	case 3:d=atoi(sY);break;
						 }
					}
					ptr->sBirth=CDATE(y,m,d);	
				} 
				break;
			case '5':cout<<"请输入新高等数学:";cin>>ptr->sScore[0] ; break;
			case '6':cout<<"请输入新大学英语:";cin>>ptr->sScore[1] ; break;
			case '7':cout<<"请输入新大学计算机基础:";cin>>ptr->sScore[2] ; break;
			case '8':return ;
		 } 
	} 
} 
CSTU* CSTU::re_p(CSTU *p)
{
	CSTU *x;
	x=stulinkhead;
	while(x->pnext !=p && x->pnext!=NULL) x=x->pnext;
	if(x->pnext==p ) return x;
	else {return NULL;} 
}
void CSTU::delestu() 
{
	CSTU *ptr,*p;
	string x;
	cout<<"请输入你要删除的学号：";cin>>x ;
	ptr=serchstu(x);
	if(ptr==NULL) 
	{
		cout<<"学号不存在";
		return ;
	}
	if(ptr==stulinkhead) 
	{
		stulinkhead=stulinkhead->pnext;
		delete ptr;
		cout<<"删除学号为"<< x<<"的学生信息成功"<<endl; 
		num--; 
		return ;
	}
	if(ptr==stulinktail)
	{
		ptr=re_p(ptr);
		delete stulinktail;
		ptr->pnext=NULL;
		stulinktail=ptr;
		cout<<"删除学号为"<< x<<"的学生信息成功"<<endl; 
		num--;
		return ;
	}
	p=ptr;
	ptr= re_p(ptr);
	ptr->pnext=ptr->pnext->pnext;
	delete p;
	num--;
	cout<<"删除学号为"<< x<<"的学生信息成功"<<endl; 
} 
void CSTU::totalstu() 
{
	int x;
	CSTU *p= stulinkhead;
	float y;
	while(p!=NULL)
	{
		x=0;
		x+= p->sScore[0];
		x+= p->sScore[1];
		x+= p->sScore[2];
		y=x/3.0;
		p->total=y;
		cout<<"学号为"<<p->sNo<<"，平均成绩为"<< y<<endl;
		p=p->pnext;
	}
}
void CSTU::savestu() 
{
	ofstream outstu("stu.txt",ios::out);
	CSTU *p;
	p= stulinkhead;
	if(!outstu) {	cout<<"打开文件失败"<<endl;return ;}
	if(p==NULL) {	cout<<"当前程序没有学生信息"<<endl;return;}
	while(p !=NULL)
	{
		outstu<<endl<<p->sNo
				<<"\t"<<p->sName
				<<"\t"<<p->sSex
				<<"\t"<<p->sBirth.outDy()
				<<"\t"<<p->sBirth.outDm()
				<<"\t"<<p->sBirth.outDd()
				<<"\t"<<p->sScore[0]
				<<"\t"<<p->sScore[1]
				<<"\t"<<p->sScore[2];
		p=p->pnext;
	}	
	cout<<"成功保存学生信息到文件"<<endl; 
} 
void CSTU::readstu() 
{
	CSTU *p1,*t;
	short int yy,mm,dd;
	ifstream readstu("stu.txt",ios::in|ios::app);
	if(!readstu) {	cout<<"打开文件失败！";return;}
	readstu.seekg(0,ios::beg);
	while(readstu.peek() !=EOF)
	{
		p1=new CSTU; 
		readstu >>p1->sNo
				 >>p1->sName
				 >>p1->sSex
				 >>yy
				 >>mm
				 >>dd
				 >>p1->sScore[0]
				 >>p1->sScore[1]
				 >>p1->sScore[2];
		p1->sBirth=CDATE(yy,mm,dd);
		if(snoexist(p1->sNo)) 
		{
			stulinktail=re_p(stulinktail);
			stulinktail->pnext=NULL; 
			delete p1;
			num--;
		}
		else stulinktail=p1;
	 } outPutInfo();
	 cout<<"文件读取成功"<<endl; 
	 readstu.close ();
 } 
 void CSTU::sortstu()
{ 
	CSTU *p,*p1,*ss,*pp,*p3;
	ss=p1=p=stulinkhead;
	int x;
	while(p!=NULL)
	{
		x=ss->sNo.compare(p->sNo) ;
		if(x>0) ss=p;
		p=p->pnext; 
	}
	p1=ss;
	ss=re_p(ss);
	ss->pnext=p1->pnext;//scjd
	p1->pnext=stulinkhead; 
	stulinkhead=p1;
	while(p1!=NULL) stulinktail=p1,p1=p1->pnext;
	pp=stulinkhead->pnext;
	//outPutInfo();//								查看数据 
	while(pp->pnext!=NULL)
	{
		ss=pp;
		p=ss->pnext; 
		while(p!=NULL)
		{
			x=ss->sNo.compare(p->sNo) ;
			if(x>0) ss=p;
			p=p->pnext; 
		}
		p3=p1=ss;
		if(p3 != pp)
		{
			ss=re_p(ss);
			ss->pnext=p1->pnext;//删除s结点 
			p=re_p(pp);
			p->pnext=p3;
			p3->pnext=pp; //重新建立链接 
		}
		else
		{
			pp=pp->pnext;
		}
	} 
	p1=stulinkhead;
	while(p1!=NULL) stulinktail=p1,p1=p1->pnext; 
	cout<<"数据排序成功，任意键查看已排序的数据"<<endl;
	system("pause"); 
	outPutInfo();
} 

