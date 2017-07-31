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
	int health,max_health;
	vector<CSkill> skill;
	CPerson():name(""),health(0),max_health(0){}
	CPerson(string nm,int hp,int mhp):name(nm),health(hp),max_health(mhp){}
	CPerson(string nm,int hp,int mhp,CSkill skl):name(nm),health(hp),max_health(mhp){skill.push_back(skl);}
	CPerson(string nm,int hp,int mhp,vector<CSkill> skl):name(nm),health(hp),max_health(mhp),skill(skl){}
	friend ostream& operator<<(ostream& os,CPerson prs){
		os<<(prs.name+' ')<<prs.health<<(string)""<<endl;
		for(vector<CSkill>::iterator iter=prs.skill.begin();iter!=prs.skill.end();++iter)
			os<<(string)"\t"<<*iter<<endl;
	}
	void AddSkill(CSkill skl){
		skill.push_back(skl);
	}
};
#endif
