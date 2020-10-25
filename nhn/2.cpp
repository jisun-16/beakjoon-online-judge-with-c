#include <iostream>
#include<algorithm>
#include <sstream>

using namespace std;

void solution(int day, int width, int **blocks) {
	int cement=0;
	int hei[101]={0,};

	for(int i=0;i<day;i++){
		for(int j=0;j<width;j++)
			hei[j]+=blocks[i][j];
		
		int l=0;
		for(int r=1;r<width;r++){
			for(int k=l+1;k<r;k++){
				if(hei[k]<=min(hei[l],hei[r])){
					cement+=min(hei[l],hei[r])-hei[k];
					hei[k]=min(hei[l],hei[r]);
				}
			}
			if(hei[r]>hei[l])
				l=r;
		}
	}
	
	printf("%d\n",cement);
}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}
