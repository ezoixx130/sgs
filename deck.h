#include<ctime>
#include<windows.h>
#include<vector>
#include"handcard.h"

using namespace std;

#ifndef CDeck

#define shuffleConst 2
struct CDeck;


struct CDeck{
	vector<CHandcard> card;
	CDeck(){}
	CDeck(vector<CHandcard> hdcd):card(hdcd){}
	void shuffle(){
		srand(time(0));
		for(unsigned __i=0;__i<shuffleConst*card.size();++__i){
			int __x=rand()%card.size(),__y=rand()%card.size();
			swap(card[__x],card[__y]);
		}
	}
	unsigned size(){
		return card.size();
	}
};
#endif
