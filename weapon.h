#include<string>
#include<iostream>

#include"handcard.h"

using namespace std;


#ifndef CWeapon
struct CWeapon{
	CHandcard card;
	int range;
	CWeapon():card(),range(1){}
	CWeapon(CHandcard hdcd,int rng):card(hdcd),range(rng){}
	CWeapon(string name,bool ZhugeC=false){
		if(name=="����˫�ɽ�")card=CHandcard(SPADE,2,name),range=2;else
		if(name=="���컭�")card=CHandcard(DIAMOND,12,name),range=4;else
		if(name=="��ʯ��")card=CHandcard(DIAMOND,5,name),range=3;else
		if(name=="������")card=CHandcard(SPADE,2,name),range=2;else
		if(name=="���빭")card=CHandcard(HEART,5,name),range=5;else
		if(name=="���G��")card=CHandcard(SPADE,6,name),range=2;else
		if(name=="�������µ�")card=CHandcard(SPADE,5,name),range=3;else
		if(name=="����ǹ")card=CHandcard(DIAMOND,12,name),range=3;else
		if(name=="�ɰ���ì")card=CHandcard(SPADE,12,name),range=3;else
		if(name=="�������")if(ZhugeC)card=CHandcard(CLUB,1,name),range=1;
				else card=CHandcard(DIAMOND,1,name),range=1;
			else card=CHandcard(),range=0;
	}
	string name(){
		return card.name;
	}
};
#endif
