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
		if(name=="´ÆĞÛË«¹É½£")card=CHandcard(SPADE,2,name),range=2;else
		if(name=="·½Ìì»­êª")card=CHandcard(DIAMOND,12,name),range=4;else
		if(name=="¹áÊ¯¸«")card=CHandcard(DIAMOND,5,name),range=3;else
		if(name=="º®±ù½£")card=CHandcard(SPADE,2,name),range=2;else
		if(name=="÷è÷ë¹­")card=CHandcard(HEART,5,name),range=5;else
		if(name=="ÇàâG½£")card=CHandcard(SPADE,6,name),range=2;else
		if(name=="ÇàÁúÙÈÔÂµ¶")card=CHandcard(SPADE,5,name),range=3;else
		if(name=="ÒøÔÂÇ¹")card=CHandcard(DIAMOND,12,name),range=3;else
		if(name=="ÕÉ°ËÉßÃ¬")card=CHandcard(SPADE,12,name),range=3;else
		if(name=="Öî¸ğÁ¬åó")if(ZhugeC)card=CHandcard(CLUB,1,name),range=1;
				else card=CHandcard(DIAMOND,1,name),range=1;
			else card=CHandcard(),range=0;
	}
	string name(){
		return card.name;
	}
};
#endif
