#include<ctime>
#include<windows.h>
#include<vector>

#include"handcard.h"

using namespace std;


inline string SlowDisplay(string str,int sec=0){
	for(string::size_type i=0;i<str.size();++i){
		cout<<str[i];
		Sleep(sec);
	}
	return str;
}


#ifndef CDeck
struct CDeck{
	vector<CHandcard> card;
	CDeck(){}
	CDeck(vector<CHandcard> hdcd):card(hdcd){}
	void Shuffle(){
		srand(time(0));
		for(int __i=0;__i<card.size()*card.size();++__i){
			int __x=rand()%card.size(),__y=rand()%card.size();
			swap(card[__x],card[__y]);
		}
	}
	void Clear(){
		card.clear();
	}
	void Configure(){
		vector<CHandcard> hdcd;
		for(int i=6;i<=10;++i)hdcd.push_back(CHandcard(DIAMOND,i,"É±"));
		hdcd.push_back(CHandcard(SPADE,7,"É±"));
		for(int i=8;i<=10;++i)hdcd.push_back(CHandcard(SPADE,i,"É±")),hdcd.push_back(CHandcard(SPADE,i,"É±"));
		hdcd.push_back(CHandcard(HEART,10,"É±")),hdcd.push_back(CHandcard(HEART,10,"É±"));
		hdcd.push_back(CHandcard(HEART,11,"É±"));
		for(int i=2;i<=11;++i)hdcd.push_back(CHandcard(CLUB,i,"É±"));
		for(int i=8;i<=11;++i)hdcd.push_back(CHandcard(CLUB,i,"É±"));
		hdcd.push_back(CHandcard(DIAMOND,2,"ÉÁ")),hdcd.push_back(CHandcard(DIAMOND,11,"ÉÁ"));
		hdcd.push_back(CHandcard(HEART,2,"ÉÁ")),hdcd.push_back(CHandcard(HEART,2,"ÉÁ"));
		hdcd.push_back(CHandcard(HEART,13,"ÉÁ"));
		for(int i=2;i<=11;++i)hdcd.push_back(CHandcard(DIAMOND,i,"ÉÁ"));
		for(int i=3;i<=9;++i)if(i!=5)hdcd.push_back(CHandcard(HEART,i,"ÌÒ"));
		hdcd.push_back(CHandcard(DIAMOND,12,"ÌÒ"));
		for(int i=3;i<=4;++i)
			hdcd.push_back(CHandcard(SPADE,i,"¹ýºÓ²ðÇÅ")),hdcd.push_back(CHandcard(CLUB,i,"¹ýºÓ²ðÇÅ"));
		hdcd.push_back(CHandcard(SPADE,12,"¹ýºÓ²ðÇÅ")),hdcd.push_back(CHandcard(HEART,12,"¹ýºÓ²ðÇÅ"));
		hdcd.push_back(CHandcard(CLUB,12,"½èµ¶É±ÈË")),hdcd.push_back(CHandcard(CLUB,13,"½èµ¶É±ÈË"));
		hdcd.push_back(CHandcard(SPADE,1,"¾ö¶·")),hdcd.push_back(CHandcard(DIAMOND,1,"¾ö¶·")),
		hdcd.push_back(CHandcard(CLUB,1,"¾ö¶·"));
		for(int i=CLUB;i<=SPADE;++i)hdcd.push_back(CHandcard((colortype)i,6,"ÀÖ²»Ë¼Êñ"));
		hdcd.push_back(CHandcard(SPADE,7,"ÄÏÂùÈëÇÖ")),hdcd.push_back(CHandcard(CLUB,7,"ÄÏÂùÈëÇÖ"));
		hdcd.push_back(CHandcard(SPADE,13,"ÄÏÂùÈëÇÖ"));
		hdcd.push_back(CHandcard(SPADE,1,"ÉÁµç")),hdcd.push_back(CHandcard(HEART,12,"ÉÁµç"));
		hdcd.push_back(CHandcard(SPADE,3,"Ë³ÊÖÇ£Ñò")),hdcd.push_back(CHandcard(SPADE,4,"Ë³ÊÖÇ£Ñò"));
		hdcd.push_back(CHandcard(SPADE,11,"Ë³ÊÖÇ£Ñò"));
		hdcd.push_back(CHandcard(DIAMOND,3,"Ë³ÊÖÇ£Ñò")),hdcd.push_back(CHandcard(DIAMOND,4,"Ë³ÊÖÇ£Ñò"));
		hdcd.push_back(CHandcard(HEART,1,"ÌÒÔ°½áÒå"));
		hdcd.push_back(CHandcard(HEART,1,"Íò¼ýÆë·¢"));
		hdcd.push_back(CHandcard(SPADE,11,"ÎÞÐ¸¿É»÷"));
		hdcd.push_back(CHandcard(CLUB,12,"ÎÞÐ¸¿É»÷")),hdcd.push_back(CHandcard(CLUB,13,"ÎÞÐ¸¿É»÷"));
		for(int i=7;i<=11;++i)if(i!=10)hdcd.push_back(CHandcard(HEART,i,"ÎÞÖÐÉúÓÐ"));
		hdcd.push_back(CHandcard(HEART,3,"Îå¹È·áµÇ")),hdcd.push_back(CHandcard(HEART,4,"Îå¹È·áµÇ"));
		hdcd.push_back(CHandcard(SPADE,2,"°ËØÔÕó")),hdcd.push_back(CHandcard(CLUB,2,"°ËØÔÕó"));
		hdcd.push_back(CHandcard(CLUB,2,"ÈÊÍõ¶Ü"));
		hdcd.push_back(CHandcard(HEART,5,"³àÍÃ")),hdcd.push_back(CHandcard(SPADE,13,"´óÍð"));
		hdcd.push_back(CHandcard(CLUB,5,"µÄÂ¬")),hdcd.push_back(CHandcard(DIAMOND,13,"×ÏóU"));
		hdcd.push_back(CHandcard(SPADE,5,"¾øÓ°")),hdcd.push_back(CHandcard(HEART,13,"×¦»Æ·Éµç"));
		hdcd.push_back(CHandcard(SPADE,2,"´ÆÐÛË«¹É½£"));
		hdcd.push_back(CHandcard(DIAMOND,12,"·½Ìì»­êª"));
		hdcd.push_back(CHandcard(DIAMOND,5,"¹áÊ¯¸«"));
		hdcd.push_back(CHandcard(SPADE,2,"º®±ù½£"));
		hdcd.push_back(CHandcard(HEART,5,"÷è÷ë¹­"));
		hdcd.push_back(CHandcard(SPADE,6,"ÇàâG½£"));
		hdcd.push_back(CHandcard(SPADE,5,"ÇàÁúÙÈÔÂµ¶"));
		hdcd.push_back(CHandcard(DIAMOND,12,"ÒøÔÂÇ¹"));
		hdcd.push_back(CHandcard(SPADE,12,"ÕÉ°ËÉßÃ¬"));
		hdcd.push_back(CHandcard(CLUB,1,"Öî¸ðÁ¬åó")),hdcd.push_back(CHandcard(DIAMOND,1,"Öî¸ðÁ¬åó"));
		card=hdcd;
		Shuffle();
	}
	void AddCard(CHandcard hdcd){
		card.push_back(hdcd);
	}
	CHandcard DeleteCard(){
		CHandcard hdcd=card.back();
		card.pop_back();
		return hdcd;
	}
	CHandcard DeleteCard(int loc){
		vector<CHandcard>::iterator iter=card.begin();
		for(int i=1;i<loc;++i)++iter;
		CHandcard hdcd=*iter;
		card.erase(iter);
		return hdcd;
	}
	void PrintCard(){
		int __i=1;
		for(vector<CHandcard>::iterator iter=card.begin();iter!=card.end();++iter,++__i)
			cout<<__i<<' '<<iter->GetValue()<<iter->name<<"  ";
		cout<<endl;
	}
	void PrintCardS(){
		int __i=1;
		for(vector<CHandcard>::iterator iter=card.begin();iter!=card.end();++iter,++__i){
			cout<<__i;
			Sleep(5);
			SlowDisplay(' '+iter->GetValue()+iter->name+"  ",5);
		}
	}
	int Size(){
		return card.size();
	}
};
#endif
