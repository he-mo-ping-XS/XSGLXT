//�����������Ա����
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
	cout<<year<<"��"<<month<<"��"<<day<<"��";
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

