//����ѧ����
#ifndef STU_H
	#define STU_H
	#include <fstream>
	#include <iostream>
	#include <cstdlib>
	#include <string>
	#include <cstring>
	#include "date.h"
	using namespace std;
	class CSTU{
		public:
			CSTU();
			CSTU(int); 
			CSTU(string sno,string sname,string sex,unsigned short int year,unsigned short int month,unsigned short int day,int s1,int s2,int s3);
			void inputStu();					//����ѧ����Ϣ 
			void outPutInfo();					//���ѧ����Ϣ 
			void showMunu();					//��ʾ�˵� 
			bool snoexist(string x);			//����ѧ������ 
			CSTU* serchstu(string x);			//����ѧ�ŷ��ر��ڵ�  
			void editstu();						//�༭ѧ����Ϣ 
			CSTU* re_p(CSTU *p);				//����һ����㣬���ز��ҵ���һ����� 
			void delestu();						//ɾ��ѧ����Ϣ 
			void totalstu(); 					//����ѧ��ƽ���ɼ� 
			void savestu();						//�ѵ�ǰ������ѧ����Ϣ���浽�ļ� 
			void readstu();						//���ļ�������ݶ�ȡ���ļ� 
			void sortstu(); 					//��ѧ����Ϣ����ѧ������ 
			
		private:
			string sNo;
			string sName;
			string sSex;
			CDATE sBirth;
			int sScore[3];
			CSTU *pnext ;
			static CSTU *stulinkhead;
			static CSTU *stulinktail;
			static int num ; 
			float  total; 
		};

#endif
