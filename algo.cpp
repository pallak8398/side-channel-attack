#include<bits/stdc++.h>
using namespace std;

struct Dictionary{
	struct Dictionary *children[60];
	bool WordEnd;
};

struct Dictionary* root;

struct Dictionary* getNode()
{
	struct Dictionary *node =  new Dictionary;
    node->WordEnd = false;
    for (int i = 0; i < 60; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct Dictionary *root, string key)
{
    struct Dictionary *node = root;
    for (int i = 0; i < key.length(); i++)
    {
    	int index;
        if(key[i]>='a' && key[i]<='z')
         index = key[i] - 'a';
    	else
    		index = key[i] - 'A'+'z'-'a';
        if (!node->children[index])
        {
            node->children[index] = getNode();
		}
        node = node->children[index];
    }
    node->WordEnd = true;
}

bool search(struct Dictionary *root, string key)
{
    struct Dictionary *node = root;

    for (int i = 0; i < key.length(); i++)
    {
    	int index;
    	if(key[i]>='a' && key[i]<='z')
            index = key[i] - 'a';
    	else
    		index = key[i] - 'A'+'z'-'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
    }

    return (node != NULL && node->WordEnd);
}

vector<string> read_words(vector<string> keys)
{	
	string line;
	ifstream myfile1 ("1letterwords.txt");
	ifstream myfile2 ("2letterwords.txt");
	ifstream myfile3 ("3letterwords.txt");
  	if (myfile1.is_open())
  	{
    	while ( getline (myfile1,line) )
    	{
      		keys.push_back(line);
      		cout<<line<<endl;
    	}
    	myfile1.close();
  	}
  	else
  	{
  		cout<<"FILE NOT FOUND"<<endl;
  	}
  	if (myfile2.is_open())
  	{
    	while ( getline (myfile2,line) )
    	{
      		keys.push_back(line);
      		cout<<line<<endl;
    	}
    	myfile2.close();
  	}
  	else
  	{
  		cout<<"FILE NOT FOUND"<<endl;
  	}
  	if (myfile3.is_open())
  	{
    	while ( getline (myfile3,line) )
    	{
      		keys.push_back(line);
      		cout<<line<<endl;
    	}
    	myfile3.close();
  	}
  	else
  	{
  		cout<<"FILE NOT FOUND"<<endl;
  	}
  	return keys;
}

struct Dictionary* create()
{
	vector<string>keys;
	keys = read_words(keys);

	int n = keys.size();
    root = getNode();

    for (int i = 0; i < n; i++){
        insert(root, keys[i]);
        cout<<keys[i]<<endl;
    }
    return root;
}

//ALGORITHM-------------------------

int toInt(string a)
{
    int i,num=0;
    for(i=0;i<a.length();i++)
    {
        num = (num*10)+(a[i]-'0');
    }
    return num;
}

vector<string> process(vector<string> temp , int len)
{
    vector<int> prob;
    vector<string> sol;
    cout<<"IN PROCESS"<<endl;
    string query = "APP";
    if(search(root, query))
    	cout << "Yes"<<endl;
    else
        cout << "No"<<endl;
    return temp;
}

int main()
{
	root=create(); // DICTIONARY CREATED 
    ifstream myfile ("length_input.txt");    
    int len = 0;
    vector<string> solution;
    solution.push_back("");
    string line="";
    if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
    		len=toInt(line);
            solution = process(solution,len);
    	}
    	myfile.close();
  	}
    else
    {
    	cout<<"FILE NOT FOUND"<<endl;
    }
    
    
    for(int i=0;i<solution.size();i++)
    {
        cout<<solution[i]<<endl;
    }
    return 0;
}
