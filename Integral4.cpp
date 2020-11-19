#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;

class Graph {
private:
	int n;
	int m;
  int eMat;
	string fname;
	vector <int>* AdjList;
  bool** adjMat;
  int vertices;


	void swap(vector<int>& vect, int i, int j);
	void sortList();
	void selectionSort(vector<int>& vect);
	void addEadjList(int, int);
	struct vert {
		int nodes;
		float arch;
		vert* sig;

		vert(int n, float a, vert* v) :nodes{ n }, arch{ a }, sig{ v }{}
	};

	vector<vert*> vertex;

	vert* end(int v) {
		vert* band = vertex[v];
		while (band->sig != 0)
			band = band->sig;
		return band;
	}
  	

public:
void addEadjMat(int, int);
int* AdjMat;
  Graph(int vertices){
    this->vertices=vertices;
    adjMat=new bool* [vertices];
    for(int i=0; i<vertices; i++){
      adjMat[i]=new bool [vertices];
      for (int j=0; j<vertices; j++)
      adjMat[i][j]=false;
    }
  }
	void getData();
  void toString();
	void loadGraphMat(string, int, int);

};

void Graph::swap(vector<int>& vect, int i, int j) {
	int sus = vect[i];
	vect[i] = vect[j];
	vect[j] = sus;
}

void Graph::addEadjMat(int i, int j) {
  adjMat[i][j]=true;
  adjMat[j][i]=true;
}

void Graph::selectionSort(vector<int>& vect) {
	int band;

	for (int i = vect.size() - 1; i > 0; i--) {
		band = 0;
		for (int j = 1; j <= i; j++) {
			if (vect[j] > vect[band]) {
				band = j;
			}
		}

		if (band != i) {
			swap(vect, i, band);
		}
	}
}

void Graph::sortList() {
	for (int i = 0; i < n; i++)
		selectionSort(AdjList[i]);
}

void Graph::toString() {
  cout<<"Matrix of posible destinations: "<<endl;
  cout<<"CN being the number of the city"<<endl;
  cout<<"0=Mexico (Mx)"<<endl;
  cout<<"1=LA (L)"<<endl;
  cout<<"2=Madrid (M)"<<endl;
  cout<<"3=Paris (P)"<<endl;
  cout<<"4=Tokio (T)"<<endl;
  cout<<"CN "<<"Mx "<<"L "<<"M "<<"P "<<"T"<<endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << " : ";
            for (int j = 0; j < vertices; j++)
                cout << adjMat[i][j] << " ";
            cout << "\n";
        }
    }

void Graph::getData() {
	string begin;
	string after;
	int m;
	int n;
	string word;

	ifstream infile(fname);
	if (infile.is_open()) {
		int i = 0;
		while (getline(infile, word)) {
			begin = word.substr(1);
			after = word.substr(4);
			m = stoi(begin);
			n = stoi(after);
			addEadjMat(m, n);
			i++;
		}
		infile.close();
	}
	sortList();
}

void Graph::loadGraphMat(string f, int vertex, int arch) {
	fname = f;
	n = vertex;
	m = arch;
	eMat = 0;
	AdjMat = new int[n * m];

	for (int i = 0; i < n * m;i++) {
		AdjMat[i] = 0;
	}

	getData();
}

int main() {
	int option;
	cout << "The following program shows a few cities with posible" << endl;
	cout << "destinations and costs per travel, choose an option from the following menu: " << endl;
	cout << "----------- MENU ------------" << endl;
	cout << "1. Possible destinations and costs" << endl;
	cout << "2. Show a matrix of posible destinations" << endl;

	cin >> option;
	switch (option) {
	case 1: {
		ifstream myfile("g1.txt");
		if (myfile.is_open())
		{
			int N;
			string y;
			string x;
			float w;
			myfile >> N;
			for (int i = 0; i < N; i++)
			{
				myfile >> x;
				while (myfile >> y, y != "None")
				{
					myfile >> w;
					cout << "Traveling from " << x << " to " << y << " would cost " << w << endl;
				}
			}
			myfile.close();
		}
		else
			cout << "Unable to open file";
		return 0;

	}
		  break;

	case 2: {
		Graph g(5);
		g.addEadjMat(0,1);
    g.addEadjMat(0,2);
    g.addEadjMat(0,3);
    g.addEadjMat(0,4);
    g.addEadjMat(1,0);
    g.addEadjMat(1,4);
    g.addEadjMat(2,0);
    g.addEadjMat(3,4);
    g.addEadjMat(3,1);
    g.addEadjMat(3,2);
    g.addEadjMat(4,3);
    g.addEadjMat(4,0);

    g.toString();

	}

	}
}
