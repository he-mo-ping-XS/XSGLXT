//声明日期类成员函数
#include "date.h"

CDATE::CDATE(){
	year=1970;  month=1;   day=1;
}
CDATE::CDATE(unsigned short int year,unsigned short int month,unsigned short int day)
{
	this->year=year;this->month=month;this->day=day; 
}
void CDATE::setDate(unsigned short int year,unsigned short int month,unsigned short int day)
{
	this->year=year;this->month=month;this->day=day;
	return;
} 
void CDATE::outputDate()
{
	cout<<year<<"年"<<month<<"月"<<day<<"日";
	return;
}
int CDATE::outDy()
{
	return this->year; 
} 
int CDATE::outDm()
{
	return this->month; 
} 
int CDATE::outDd()
{
	return this->day; 
} 

