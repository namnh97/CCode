#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

vector<string> split(const string &s, char delimiter){
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while(getline(tokenStream, token, delimiter)){
		tokens.push_back(token);
	}
	return tokens;
}

class MatchMaker{
public:
	struct Member{
		int index;
		string name;
		string gender;
		string requestedGender;
		vector<string> answer;
		int similar;
		Member(){

		}
		Member(int _index, string _name, string _gender, string _requestedGender, vector<string> _answer){
			this->index = _index;
			this->name = _name;
			this->gender = _gender;
			this->requestedGender = _requestedGender;
			this->answer = _answer;
		}
	};
	vector<string> getBestMatches(vector<string> members, string currentUser, int sf){
		int index = -1;
		vector<Member> allMember(members.size());
		for(int i = 0; i < members.size(); i++){
			vector<string> member = split(members[i], ' ');
			vector<string> tmp;
			for(int i = 3; i < member.size(); i++){
				tmp.push_back(member[i]);
			}
			allMember[i] = Member(i, member[0], member[1], member[2], tmp);
			if(allMember[i].name == currentUser){
				index = i;
			}
		}
		vector<Member> order;
		for(int i = 0; i < allMember.size(); i++){
			if(i != index && allMember[i].gender == allMember[index].requestedGender){
				int count = 0;
				for(int j = 1; j < allMember[i].answer.size(); i = i + 2){
					if(allMember[i].answer[j] == allMember[index].answer[j]){
						count++;
					}
				}
				if(count >= sf){
					allMember[i].similar = count;
					order.push_back(allMember[i]);
				}
			}
		}
		vector<string> result;
		for(int i = 0; i < order.size(); i++){
			result.push_back(order[i].name);
		}
		return result;
	}
};

int main(void){
	return 0;
}