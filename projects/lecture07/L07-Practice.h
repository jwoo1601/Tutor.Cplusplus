// Lecture 07 Practice Question

/*
	Q1) 게임에서 '플레이어' 를 나타내는 클래스를 모델링.

	Requirements
		- 플레이어 클래스는 해당 플레이어의 name, username, password 를 전달받아 내부에 저장해야 함.
		- 플레이어 데이터(오브젝트)는 복사가 가능해야 함.
		- 플레이어가 만들어질 때 마다 GeneratePlayerId 함수를 이용해 플레이어 마다 unique 한 아이디를 저장해야 함.
		- 플레이어는 자기 자신의 정보에 대해 출력이 가능해야 함.
		- 플레이어는 플레이어의 name, username, password 를 변경하는 기능을 제공해야 함.
		- 플레이어는 name, username, password, playerId 를 리턴하는 함수들을 제공해야 함.
		- 플레이어의 password 는 EncryptPassword 함수를 통해 암호화되어야 함.
		- 모든 플레이어는 playerList array 에 저장되어야 함.
		- 현재까지 저장된 모든 플레이어의 수는 numTotalPlayers 에 저장되어야 함.
		- 플레이어 클래스는 TPlayerId 타입으로 부터 변환이 가능해야 함 (즉, 플레이어id 를 전달받아 playerList 에서 해당 플레이어를 찾은 뒤, 찾은 데이터를 그대로 복사해서 들고있어야 함.)
*/

#include <string>
using namespace std;

typedef unsigned long TPlayerId;

TPlayerId GeneratePlayerId(const string &playerName)
{
	const char* str = playerName.c_str();
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;

	return hash;
}

unsigned long EncryptPassword(unsigned long password)
{
	char buf[256];
	ultoa(password, buf, 16);

	return GeneratePlayerId(buf);
}

class Player playerList[256];
unsigned numTotalPlayers;

// 여기서부터 코드 입력
