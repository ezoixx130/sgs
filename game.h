#include"deck.h"

struct Game
{
	CDeck deck;
	Game()
	{
		deck.card.push_back(CHandcard(spade,7,"ɱ"));
		for(int i=8;i<=10;++i)
		{
			deck.card.push_back(CHandcard(spade,i,"ɱ"));
			deck.card.push_back(CHandcard(spade,i,"ɱ"));
			deck.card.push_back(CHandcard(club,i,"ɱ"));
			deck.card.push_back(CHandcard(club,i,"ɱ"));
		}
		for(int i=2;i<=7;++i)
		{
			deck.card.push_back(CHandcard(club,i,"ɱ"));
		}
		deck.card.push_back(CHandcard(club,11,"ɱ"));
		deck.card.push_back(CHandcard(club,11,"ɱ"));
		deck.card.push_back(CHandcard(heart,10,"ɱ"));
		deck.card.push_back(CHandcard(heart,10,"ɱ"));
		deck.card.push_back(CHandcard(heart,11,"ɱ"));
		for(int i=6;i<=10;++i)
		{
			deck.card.push_back(CHandcard(diamond,i,"ɱ"));
		}
		deck.card.push_back(CHandcard(diamond,13,"ɱ"));

		deck.card.push_back(CHandcard(heart,2,"��"));
		deck.card.push_back(CHandcard(heart,2,"��"));
		deck.card.push_back(CHandcard(heart,13,"��"));
		for(int i=2;i<=11;++i)
		{
			deck.card.push_back(CHandcard(diamond,i,"��"));
		}
		deck.card.push_back(CHandcard(diamond,2,"��"));
		deck.card.push_back(CHandcard(diamond,11,"��"));

		for(int i=3;i<=9;++i)
		{
			if(i!=5)
				deck.card.push_back(CHandcard(heart,i,"��"));
		}
		deck.card.push_back(CHandcard(heart,12,"��"));
		deck.card.push_back(CHandcard(diamond,12,"��"));


		deck.card.push_back(CHandcard(spade,1,"����"));
		deck.card.push_back(CHandcard(club,1,"����"));
		deck.card.push_back(CHandcard(diamond,1,"����"));

		deck.card.push_back(CHandcard(spade,3,"���Ӳ���"));
		deck.card.push_back(CHandcard(spade,4,"���Ӳ���"));
		deck.card.push_back(CHandcard(spade,12,"���Ӳ���"));
		deck.card.push_back(CHandcard(heart,12,"���Ӳ���"));
		deck.card.push_back(CHandcard(club,3,"���Ӳ���"));
		deck.card.push_back(CHandcard(club,4,"���Ӳ���"));

		deck.card.push_back(CHandcard(spade,3,"˳��ǣ��"));
		deck.card.push_back(CHandcard(spade,4,"˳��ǣ��"));
		deck.card.push_back(CHandcard(spade,11,"˳��ǣ��"));
		deck.card.push_back(CHandcard(diamond,3,"˳��ǣ��"));
		deck.card.push_back(CHandcard(diamond,4,"˳��ǣ��"));

		deck.card.push_back(CHandcard(heart,7,"��������"));
		deck.card.push_back(CHandcard(heart,8,"��������"));
		deck.card.push_back(CHandcard(heart,9,"��������"));
		deck.card.push_back(CHandcard(heart,11,"��������"));

		deck.card.push_back(CHandcard(club,12,"�赶ɱ��"));
		deck.card.push_back(CHandcard(club,13,"�赶ɱ��"));

		deck.card.push_back(CHandcard(spade,11,"��и�ɻ�"));
		deck.card.push_back(CHandcard(club,12,"��и�ɻ�"));
		deck.card.push_back(CHandcard(club,13,"��и�ɻ�"));
		deck.card.push_back(CHandcard(diamond,12,"��и�ɻ�"));

		deck.card.push_back(CHandcard(spade,7,"��������"));
		deck.card.push_back(CHandcard(spade,13,"��������"));
		deck.card.push_back(CHandcard(club,7,"��������"));

		deck.card.push_back(CHandcard(heart,1,"����뷢"));

		deck.card.push_back(CHandcard(heart,1,"��԰����"));

		deck.card.push_back(CHandcard(heart,3,"��ȷ��"));
		deck.card.push_back(CHandcard(heart,4,"��ȷ��"));

		deck.card.push_back(CHandcard(spade,6,"�ֲ�˼��"));
		deck.card.push_back(CHandcard(heart,6,"�ֲ�˼��"));
		deck.card.push_back(CHandcard(club,6,"�ֲ�˼��"));

		deck.card.push_back(CHandcard(spade,1,"����"));
		deck.card.push_back(CHandcard(heart,12,"����"));


		deck.card.push_back(CHandcard(club,1,"�������"));
		deck.card.push_back(CHandcard(diamond,1,"�������"));

		deck.card.push_back(CHandcard(spade,6,"���G��"));

		deck.card.push_back(CHandcard(spade,2,"����˫�ɽ�"));

		deck.card.push_back(CHandcard(diamond,5,"��ʯ��"));

		deck.card.push_back(CHandcard(spade,5,"�������µ�"));

		deck.card.push_back(CHandcard(spade,12,"�ɰ���ì"));

		deck.card.push_back(CHandcard(diamond,12,"���컭�"));

		deck.card.push_back(CHandcard(heart,5,"���빭"));


		deck.card.push_back(CHandcard(heart,5,"����"));
		deck.card.push_back(CHandcard(diamond,13,"���U"));
		deck.card.push_back(CHandcard(spade,13,"����"));

		deck.card.push_back(CHandcard(heart,13,"צ�Ʒɵ�"));
		deck.card.push_back(CHandcard(club,5,"��¬"));
		deck.card.push_back(CHandcard(spade,5,"��Ӱ"));


		deck.card.push_back(CHandcard(spade,2,"������"));
		deck.card.push_back(CHandcard(club,2,"������"));


		deck.shuffle();
	}
};
