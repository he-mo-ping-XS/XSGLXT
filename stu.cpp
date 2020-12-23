//���Ա��������
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
	if(sptr ==NULL) cout<<"��ǰû��ѧ������"<<endl;
	else{
		system("cls"); 
		cout<<endl<<endl;
		while(sptr !=NULL)
		{
			cout<<"==============================ѧ����Ϣ==========================="<<endl; 
			cout<<endl
				<<"ѧ��:"
				<<"����:"
				<<"�Ա�:"
				<<"��������:"
				<<"�ߵ���ѧ:"
				<<"��ѧӢ��:"
				<<"��ѧ����:";
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
		cout<<endl<<endl<<"��ǰ��"<<num <<"ѧ��"; 
	}
	system("pause");
}
void CSTU::showMunu()
{
	char munu='0';
	char s; 
	do{
		system("cls"); 
		cout<<"\t\t========ѧ������ϵͳ========="<<endl;
		cout<<"\t\t\t1.���ѧ����Ϣ"<<endl; 
		cout<<"\t\t\t2.���ѧ����Ϣ"<<endl; 
		cout<<"\t\t\t3.�༭ѧ����Ϣ"<<endl; 
		cout<<"\t\t\t4.ɾ��ѧ����Ϣ"<<endl; 
		cout<<"\t\t\t5.����ѧ��ƽ���ɼ�"<<endl; 
		cout<<"\t\t\t6.ѧ������"<<endl; 
		cout<<"\t\t\t7.���浽�ļ�"<<endl; 
		cout<<"\t\t\t8.�ļ��������뵽����"<<endl; 
		cout<<"\t\t\t0.�˳�ѧ��ϵͳ"<<endl; 
		cin >>munu;
		switch (munu)
		{
			case '1':CSTU *p;p= new CSTU;p->inputStu();system("pause"); break;
			case '2':outPutInfo();break;
			case '3':cout<<"ѡ����Ǳ༭ѧ����Ϣ"<<endl;editstu();system("pause");break;
			case '4':cout<<"ѡ�����ɾ��ѧ����Ϣ"<<endl;delestu ();system("pause");break;
			case '5':cout<<"ѡ����Ǽ���ѧ��ƽ���ɼ�"<<endl;totalstu();system("pause");break;
			case '6':cout<<"ѧ������"<<endl;sortstu();break;
			case '7':cout<<"����ѧ����Ϣ���ļ�"<<endl;savestu();system("pause");break; 
			case '8':cout<<"�ļ��������뵽����"<<endl;readstu();break; 
		 } 
		 if(munu=='0') break; 
	}while(1);
}
void CSTU::inputStu()
{
	system ("cls");
	cout<<"\t\t=====���ѧ����Ϣ"<<endl;
	cout<<"\t\t=====������ѧ��:"; cin>> sNo;
	while(snoexist(sNo) == true) 
		{
			cout<<"\t\t=====ѧ���ظ�������������ѧ��:"; cin>> sNo;
		}
	cout<<"\t\t=====����������:"; cin>> sName;
	cout<<"\t\t=====�������Ա�:"; cin>> sSex;
	cout<<"\t\t=====���������������(xxxx-xx-xx):";
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
	cout<<"\t\t=====�ߵ���ѧ:";cin>>sScore[0]; 
	cout<<"\t\t=====��ѧӢ��:";cin>>sScore[1]; 
	cout<<"\t\t=====��ѧ���������:";cin>>sScore[2]; 
	cout<<"�ļ���ӳɹ�"<<endl; 
	
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
	cout<<"��������Ҫ�༭��ѧ��ѧ�ţ�";cin>>So;
	ptr=serchstu(So);
	if(ptr ==NULL){
		cout <<So<<"ѧ�Ų�����,�˳�ѧ��ɾ��"; 
		return;
	}
	while(1)
	{
		char  munu;
		string x;
		bool y; 
		system("cls"); 
		cout<<"\t\t========��������Ҫ�༭��ѧ����Ϣ���========="<<endl;
		cout<<"\t\t\t1.ѧ��"<<endl; 
		cout<<"\t\t\t2.����"<<endl; 
		cout<<"\t\t\t3.�Ա�"<<endl; 
		cout<<"\t\t\t4.����������(xxxx-xx-xx)"<<endl; 
		cout<<"\t\t\t5.�ߵ���ѧ�ɼ�"<<endl; 
		cout<<"\t\t\t6.��ѧӢ��ɼ�"<<endl; 
		cout<<"\t\t\t7.��ѧ������ɼ�"<<endl; 
		cout<<"\t\t\t8.�˳��༭ϵͳ"<<endl; 
		cin >>munu;
		switch (munu)
		{
			
			case '1':
			{
				cout<<"��������ѧ��:";cin>>x;
				while( snoexist(x) == true) 
					{
						cout<<"\t\t=====ѧ���ظ�������������ѧ��:"; cin>> x;
					}
					ptr->sNo=x;
					break;
			}
			case '2':cout<<"������������:";cin>>ptr->sName; break;
			case '3':cout<<"���������Ա�:";cin>>ptr->sSex ; break;
			case '4': 
				{
					cout<<"�������³���������(xxxx-xx-xx):";
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
			case '5':cout<<"�������¸ߵ���ѧ:";cin>>ptr->sScore[0] ; break;
			case '6':cout<<"�������´�ѧӢ��:";cin>>ptr->sScore[1] ; break;
			case '7':cout<<"�������´�ѧ���������:";cin>>ptr->sScore[2] ; break;
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
	cout<<"��������Ҫɾ����ѧ�ţ�";cin>>x ;
	ptr=serchstu(x);
	if(ptr==NULL) 
	{
		cout<<"ѧ�Ų�����";
		return ;
	}
	if(ptr==stulinkhead) 
	{
		stulinkhead=stulinkhead->pnext;
		delete ptr;
		cout<<"ɾ��ѧ��Ϊ"<< x<<"��ѧ����Ϣ�ɹ�"<<endl; 
		num--; 
		return ;
	}
	if(ptr==stulinktail)
	{
		ptr=re_p(ptr);
		delete stulinktail;
		ptr->pnext=NULL;
		stulinktail=ptr;
		cout<<"ɾ��ѧ��Ϊ"<< x<<"��ѧ����Ϣ�ɹ�"<<endl; 
		num--;
		return ;
	}
	p=ptr;
	ptr= re_p(ptr);
	ptr->pnext=ptr->pnext->pnext;
	delete p;
	num--;
	cout<<"ɾ��ѧ��Ϊ"<< x<<"��ѧ����Ϣ�ɹ�"<<endl; 
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
		cout<<"ѧ��Ϊ"<<p->sNo<<"��ƽ���ɼ�Ϊ"<< y<<endl;
		p=p->pnext;
	}
}
void CSTU::savestu() 
{
	ofstream outstu("stu.txt",ios::out);
	CSTU *p;
	p= stulinkhead;
	if(!outstu) {	cout<<"���ļ�ʧ��"<<endl;return ;}
	if(p==NULL) {	cout<<"��ǰ����û��ѧ����Ϣ"<<endl;return;}
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
	cout<<"�ɹ�����ѧ����Ϣ���ļ�"<<endl; 
} 
void CSTU::readstu() 
{
	CSTU *p1,*t;
	short int yy,mm,dd;
	ifstream readstu("stu.txt",ios::in|ios::app);
	if(!readstu) {	cout<<"���ļ�ʧ�ܣ�";return;}
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
	 cout<<"�ļ���ȡ�ɹ�"<<endl; 
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
	//outPutInfo();//								�鿴���� 
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
			ss->pnext=p1->pnext;//ɾ��s��� 
			p=re_p(pp);
			p->pnext=p3;
			p3->pnext=pp; //���½������� 
		}
		else
		{
			pp=pp->pnext;
		}
	} 
	p1=stulinkhead;
	while(p1!=NULL) stulinktail=p1,p1=p1->pnext; 
	cout<<"��������ɹ���������鿴�����������"<<endl;
	system("pause"); 
	outPutInfo();
} 

