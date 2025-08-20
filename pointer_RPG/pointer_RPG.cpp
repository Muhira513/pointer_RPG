#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int denfance;
};

/*
StatInfo CreatePlayer()
{
	StatInfo info;

	cout << "플레이어 생성" << endl;

	info.hp = 100;
	info.attack = 10;
	info.denfance = 2;

	return info;
}
*/
StatInfo* CreatePlayer2()
{
	StatInfo* info = new StatInfo;

	cout << "플레이어 생성" << endl;

	info->hp = 100;
	info->attack = 10;
	info->denfance = 2;

	return info;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->denfance = 1;
}

void Battle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->denfance;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 체력 : " << monster->hp << endl;

		if (monster->hp == 0)
			return;

		damage = monster->attack - player->denfance;
		if (damage < 0)
			damage = 0;

		cout << "플레이어 체력 : " << player->hp << endl;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		if (player->hp == 0)
			return;
	}
}

int main()
{
	StatInfo* player = CreatePlayer2();
	/*
	StatInfo player;
	player = CreatePlayer();
	*/

	StatInfo monsters;
	CreateMonster(&monsters);

	Battle(player, &monsters);

	delete player;
	player = nullptr;

	return 0;
}