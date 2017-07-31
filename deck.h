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
		for(int i=6;i<=10;++i)hdcd.push_back(CHandcard(DIAMOND,i,"ɱ"));
		hdcd.push_back(CHandcard(SPADE,7,"ɱ"));
		for(int i=8;i<=10;++i)hdcd.push_back(CHandcard(SPADE,i,"ɱ")),hdcd.push_back(CHandcard(SPADE,i,"ɱ"));
		hdcd.push_back(CHandcard(HEART,10,"ɱ")),hdcd.push_back(CHandcard(HEART,10,"ɱ"));
		hdcd.push_back(CHandcard(HEART,11,"ɱ"));
		for(int i=2;i<=11;++i)hdcd.push_back(CHandcard(CLUB,i,"ɱ"));
		for(int i=8;i<=11;++i)hdcd.push_back(CHandcard(CLUB,i,"ɱ"));
		hdcd.push_back(CHandcard(DIAMOND,2,"��")),hdcd.push_back(CHandcard(DIAMOND,11,"��"));
		hdcd.push_back(CHandcard(HEART,2,"��")),hdcd.push_back(CHandcard(HEART,2,"��"));
		hdcd.push_back(CHandcard(HEART,13,"��"));
		for(int i=2;i<=11;++i)hdcd.push_back(CHandcard(DIAMOND,i,"��"));
		for(int i=3;i<=9;++i)if(i!=5)hdcd.push_back(CHandcard(HEART,i,"��"));
		hdcd.push_back(CHandcard(DIAMOND,12,"��"));
		for(int i=3;i<=4;++i)
			hdcd.push_back(CHandcard(SPADE,i,"���Ӳ���")),hdcd.push_back(CHandcard(CLUB,i,"���Ӳ���"));
		hdcd.push_back(CHandcard(SPADE,12,"���Ӳ���")),hdcd.push_back(CHandcard(HEART,12,"���Ӳ���"));
		hdcd.push_back(CHandcard(CLUB,12,"�赶ɱ��")),hdcd.push_back(CHandcard(CLUB,13,"�赶ɱ��"));
		hdcd.push_back(CHandcard(SPADE,1,"����")),hdcd.push_back(CHandcard(DIAMOND,1,"����")),
		hdcd.push_back(CHandcard(CLUB,1,"����"));
		for(int i=CLUB;i<=SPADE;++i)hdcd.push_back(CHandcard((colortype)i,6,"�ֲ�˼��"));
		hdcd.push_back(CHandcard(SPADE,7,"��������")),hdcd.push_back(CHandcard(CLUB,7,"��������"));
		hdcd.push_back(CHandcard(SPADE,13,"��������"));
		hdcd.push_back(CHandcard(SPADE,1,"����")),hdcd.push_back(CHandcard(HEART,12,"����"));
		hdcd.push_back(CHandcard(SPADE,3,"˳��ǣ��")),hdcd.push_back(CHandcard(SPADE,4,"˳��ǣ��"));
		hdcd.push_back(CHandcard(SPADE,11,"˳��ǣ��"));
		hdcd.push_back(CHandcard(DIAMOND,3,"˳��ǣ��")),hdcd.push_back(CHandcard(DIAMOND,4,"˳��ǣ��"));
		hdcd.push_back(CHandcard(HEART,1,"��԰����"));
		hdcd.push_back(CHandcard(HEART,1,"����뷢"));
		hdcd.push_back(CHandcard(SPADE,11,"��и�ɻ�"));
		hdcd.push_back(CHandcard(CLUB,12,"��и�ɻ�")),hdcd.push_back(CHandcard(CLUB,13,"��и�ɻ�"));
		for(int i=7;i<=11;++i)if(i!=10)hdcd.push_back(CHandcard(HEART,i,"��������"));
		hdcd.push_back(CHandcard(HEART,3,"��ȷ��")),hdcd.push_back(CHandcard(HEART,4,"��ȷ��"));
		hdcd.push_back(CHandcard(SPADE,2,"������")),hdcd.push_back(CHandcard(CLUB,2,"������"));
		hdcd.push_back(CHandcard(CLUB,2,"������"));
		hdcd.push_back(CHandcard(HEART,5,"����")),hdcd.push_back(CHandcard(SPADE,13,"����"));
		hdcd.push_back(CHandcard(CLUB,5,"��¬")),hdcd.push_back(CHandcard(DIAMOND,13,"���U"));
		hdcd.push_back(CHandcard(SPADE,5,"��Ӱ")),hdcd.push_back(CHandcard(HEART,13,"צ�Ʒɵ�"));
		hdcd.push_back(CHandcard(SPADE,2,"����˫�ɽ�"));
		hdcd.push_back(CHandcard(DIAMOND,12,"���컭�"));
		hdcd.push_back(CHandcard(DIAMOND,5,"��ʯ��"));
		hdcd.push_back(CHandcard(SPADE,2,"������"));
		hdcd.push_back(CHandcard(HEART,5,"���빭"));
		hdcd.push_back(CHandcard(SPADE,6,"���G��"));
		hdcd.push_back(CHandcard(SPADE,5,"�������µ�"));
		hdcd.push_back(CHandcard(DIAMOND,12,"����ǹ"));
		hdcd.push_back(CHandcard(SPADE,12,"�ɰ���ì"));
		hdcd.push_back(CHandcard(CLUB,1,"�������")),hdcd.push_back(CHandcard(DIAMOND,1,"�������"));
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
