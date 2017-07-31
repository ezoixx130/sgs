#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>

#include"deck.h"
#include"person.h"
#include"weapon.h"

using namespace std;


CHandcard DrawCard(CDeck&,CDeck&);
CHandcard DrawCard(CDeck&,CDeck&,const int&);


inline CHandcard DrawCard(CDeck& source,CDeck& target){
	CHandcard hdcd=source.DeleteCard();
	target.AddCard(hdcd);
	return hdcd;
}

inline CHandcard DrawCard(CDeck& source,CDeck& target,const int& loc){
	CHandcard hdcd=source.DeleteCard(loc);
	target.AddCard(hdcd);
	return hdcd;
}


#ifndef CPlayer
struct CPlayer;


struct CPlayer{
	CDeck handcard,judgearea;
	CPerson person;
	CWeapon weapon;
	CHandcard armor,horse1,horse2;
	identitytype identity;
	stagetype nowstage;
	bool c_horse1,c_horse2,died;
	CPlayer():handcard(),person(),identity(NEUTRALITY),died(false),nowstage(RESPOND),
		weapon(),armor(),horse1(),horse2(),c_horse1(),c_horse2(),judgearea(){}
	CPlayer(CDeck hdcd,CPerson prs,identitytype idnt):
		handcard(hdcd),person(prs),identity(idnt),died(false),nowstage(RESPOND),
		weapon(),armor(),horse1(),horse2(),c_horse1(),c_horse2(),judgearea(){}
	CHandcard PlayCard(const int& loc,CDeck& target){
		CHandcard hdcd=this->handcard.DeleteCard(loc);
		target.AddCard(hdcd);
		return hdcd;
	}
	CHandcard PlayCard(vector<CHandcard>::iterator loc,CDeck& target){
		CHandcard hdcd=*loc;
		this->handcard.card.erase(loc);
		target.AddCard(hdcd);
		return hdcd;
	}
	void PrintCard(int tab=0){
		int __i=1;
		for(int i=1;i<=tab;++i)SlowDisplay("\t",5);
		for(vector<CHandcard>::iterator iter=handcard.card.begin();iter!=handcard.card.end();++iter,++__i){
			cout<<__i;
			Sleep(5);
			SlowDisplay(' '+iter->GetValue()+iter->name+"  ",5);
		}
	}
	void PrintSituation(){
		SlowDisplay(person.name+"   ÑªÁ¿£º",5);
		cout<<person.health<<'/'<<person.max_health;
		SlowDisplay("   ÊÖÅÆÊýÁ¿£º",5);
		cout<<handcard.Size();
		SlowDisplay("\nÎäÆ÷£º"+weapon.card.GetValue()+weapon.card.name+"  ·À¾ß£º"+armor.GetValue()+armor.name
			+"  ×øÆï£º"+horse1.GetValue()+horse1.name+' '+horse2.GetValue()+horse2.name+'\n',5);
	}
	void PrintSituationF(){
		ofstream fout;
		fout<<person.health<<' '<<handcard.Size()<<endl;
		for(vector<CHandcard>::iterator iter=handcard.card.begin();iter!=handcard.card.end();++iter)
			fout<<iter->GetValue()<<iter->name<<' ';
		fout<<endl;
		if(weapon.name()=="")fout<<"0";else fout<<weapon.card.GetValue()<<weapon.name()<<' ';
		if(armor.name=="")fout<<"0";else fout<<armor.GetValue()<<armor.name<<' ';
		if(c_horse1==false)fout<<"0";else fout<<horse1.GetValue()<<horse1.name<<' ';
		if(c_horse2==false)fout<<"0";else fout<<horse2.GetValue()<<horse2.name<<' ';
	}
	CHandcard Equip(CHandcard equ){
		if(equ.name=="´ÆÐÛË«¹É½£"||equ.name=="·½Ìì»­êª"||equ.name=="¹áÊ¯¸«"||equ.name=="º®±ù½£"||equ.name=="÷è÷ë¹­"
			||equ.name=="ÇàâG½£"||equ.name=="ÇàÁúÙÈÔÂµ¶"||equ.name=="ÒøÔÂÇ¹"||equ.name=="ÕÉ°ËÉßÃ¬"
			||equ.name=="Öî¸ðÁ¬åó")weapon.card=equ;
		if(equ.name=="°ËØÔÕó"||equ.name=="ÈÊÍõ¶Ü")armor=equ;
		if(equ.name=="³àÍÃ"||equ.name=="´óÍð"||equ.name=="×ÏóU"){
			horse1=equ;
			c_horse1=true;
		}
		if(equ.name=="µÄÂ¬"||equ.name=="¾øÓ°"||equ.name=="×¦»Æ·Éµç"){
			horse2=equ;
			c_horse2=true;
		}
		return equ;
	}
	void DrawCard(CDeck& source){
		CHandcard hdcd=source.DeleteCard();
		this->handcard.AddCard(hdcd);
	}
	void DrawCard(CDeck& source,int num){
		for(int i=1;i<=min(num,source.Size());++i)DrawCard(source);
	}
	int& Health(){
		return person.health;
	}
	int& MaxHealth(){
		return person.max_health;
	}
	void Die(){
		died=true;
		handcard.card.clear();
		person.health=0;
	}
};
#endif
