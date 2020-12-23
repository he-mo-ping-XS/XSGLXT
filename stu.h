//声明学生类
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
			void inputStu();					//输入学生信息 
			void outPutInfo();					//输出学生信息 
			void showMunu();					//显示菜单 
			bool snoexist(string x);			//查找学号有无 
			CSTU* serchstu(string x);			//查找学号返回本节点  
			void editstu();						//编辑学生信息 
			CSTU* re_p(CSTU *p);				//给定一个结点，返回查找的上一个结点 
			void delestu();						//删除学生信息 
			void totalstu(); 					//计算学生平均成绩 
			void savestu();						//把当前的所有学生信息保存到文件 
			void readstu();						//把文件里的数据读取到文件 
			void sortstu(); 					//把学生信息按照学号排序 
			
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
