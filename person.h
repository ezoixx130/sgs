#include<string>
#include<cstring>
#include<vector>
#include<iostream>

#include"skill.h"

using namespace std;


#ifndef CPerson
struct CPerson;


struct CPerson{
	string name;
	int health;
	vector<CSkill> skill;
	CPerson():name(""),health(0){}
	CPerson(string nm,int hp):name(nm),health(hp){}
	CPerson(string nm,int hp,CSkill skl):name(nm),health(hp){skill.push_back(skl);}
	CPerson(string nm,int hp,vector<CSkill> skl):name(nm),health(hp),skill(skl){}
	friend ostream& operator<<(ostream& os,CPerson prs){
		os<<(prs.name+' ')<<prs.health<<(string)""<<endl;
		for(vector<CSkill>::iterator iter=prs.skill.begin();iter!=prs.skill.end();++iter)os<<(string)"\t"<<*iter<<endl;
		return os;
	}
};
#endif
