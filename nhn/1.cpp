#include <iostream>
#include <sstream>

using namespace std;

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	char it;
	char pos[26];
	int cnt[26]={0,},it_pos=0;

	for(int i=0;i<numOfAllPlayers-1;i++)
		pos[i]='B'+i;
	
	it='A';
	cnt[it-'A']++;
	for(int i=0;i<numOfGames;i++){
		int mov=numOfMovesPerGame[i];
		int next_pos=(it_pos+mov+100*(numOfAllPlayers-1))%(numOfAllPlayers-1);
		char next=pos[next_pos];
		
		bool quickP=false;
		for(int j=0;j<numOfQuickPlayers;j++)
			if(namesOfQuickPlayers[j]==next){
				quickP=true;
				break;
			}
		
		if(!quickP){
			pos[next_pos]=it;
			it=next;
		}
		
		it_pos=next_pos;
		cnt[it-'A']++;
	}
	
	for(int i=0;i<numOfAllPlayers-1;i++)
		printf("%c %d\n",pos[i],cnt[pos[i]-'A']);
	printf("%c %d\n",it,cnt[it]);
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}
