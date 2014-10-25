#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> Split(const string &s)
{
	vector <string> vs;
	stringstream ss(s);
	string e;
	while(ss >> e)
		vs.push_back(e);
	return vs;
}

void get_pos_and_word(const string &line_of_tree, vector<string> &pos_vec, vector<string> &word_vec)
{
	vector<string> toks = Split(line_of_tree);
	for(size_t i=0;i<toks.size();i++)
	{
		//左括号情形，且去除"("作为终结符的特例(做终结符时，后继为“）”)
		if(toks[i]=="(" && i+1<toks.size() && toks[i+1]!=")")
		{
			continue;
		}

		//右括号情形，去除右括号“）”做终结符的特例（做终结符时，前驱的前驱为“（,而且前驱不是")"
		else if(toks[i]==")" && !(i-2>=0 && toks[i-2] =="(" && toks[i-1] != ")"))
		{
			continue;
		}
		//处理形如 （ VV 需要 ）其中VV节点这样的情形
		else if((i-1>=0 && toks[i-1]=="(") && (i+2<toks.size() && toks[i+2]==")"))
		{
			pos_vec.push_back(toks[i]);
		}
		//处理形如 VP （ VV 需要 ） VP这样的节点 或 需要 这样的节点
		else
		{
			//如果是“需要”的情形，则记录中文词的序号
			if(toks[i+1]==")")
			{
				word_vec.push_back(toks[i]);
			}
		}
	}
}

int main()
{
	ifstream fin("fbis.en.parse");
	string line;
	while(getline(fin,line))
	{
		vector<string> pos_vec;
		vector<string> word_vec;
		if (line.size() <= 3)
		{
			cout<<endl;
			continue;
		}
		get_pos_and_word(line,pos_vec,word_vec);
		size_t i = 0;
		for (i=0; i<pos_vec.size()-1; i++)
		{
			cout<<word_vec[i]<<'_'<<pos_vec[i]<<' ';
		}
		cout<<word_vec[i]<<'_'<<pos_vec[i]<<endl;
	}
}
