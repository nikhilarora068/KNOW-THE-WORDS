#include<bits/stdc++.h>
using namespace std;

vector <string> s1;
void search(struct node *root);
int ctr;

//rules for the game
void rules()
{
    cout<<"\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t\t RULES"<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"@ The players are provided with a set of 5 random letters and each letter has points ranging from 1 to 5."<<"\n";
    cout<<"\n";
    cout<<"@ A player has to make a word using the provided letters or if unable to do so they can pass their turn to the next player."<<"\n";
    cout<<"\n";
    cout<<"@ The sum of points corresponding to each letter in a word entered by the player is his/her score after that turn."<<"\n";
    cout<<"\n";
    cout<<"@ The game ends when both the players pass their turn."<<"\n";
    cout<<"\n";
    cout<<"@ At the end of the game the player scoring the maximum points wins."<<"\n";
    cout<<"\n\n\n";
    cout<<" \tNOTE : All the words entered here should be meaningful.\n\tRepetation of the given letters is allowed !!"<<"\n";
    cout<<"\n\n\n";
}

//taking words as input from a file and storing in vector
void file_handling()
{
    string s;

    ifstream file;
    file.open("words.txt");
    while(!file.eof())
    {
        file>>s;
        s1.push_back(s);
    }
}

//validating the string entered by the player
int compare(string s)
{
    file_handling();
    int i,ctr=0;
    for(i=0;i<s1.size();i++)
    {
        if((s.compare(s1[i])) == 0)
            ++ctr;
    }
    if(ctr==0)
    {
        //cout<<"invalid word"<<"\n";
        return 0;
    }
    else
    {
        //cout<<"valid"<<"\n";
        return 1;
    }
}

//calculating points for the the entered word
int points(string s)
{
    vector <char> l{'e','a','o','n','r','l','d','i','h','y'};
    vector <int> p{1,2,3,4,5,1,3,4,5,5};
    int i,sum=0,j;
    for(i=0;i<s.length();i++)
    {
        for(j=0;j<l.size();j++)
        {
            if(s[i]==l[j])
            {
                sum=sum+p[j];
            }
        }
    }
    cout<<"Points = "<<sum<<"\n\n";
    return sum;
}

void display()
{
    cout<<"\n";
    cout<<"\n";
    cout<<"Use the given list of letters to make words"<<"\n";
    cout<<"\n";
    vector <char> l1{'e','a','o','n','r','l','d','i','h','y'};
    vector <int> l2{1,2,3,4,5,1,3,4,5,5};
    int l;
    cout<<"\t\tLetters"<<"\t";
    for(l=0;l<l1.size();l++)
    {
        cout<<l1[l]<<" ";
    }
    cout<<"\n";
    cout<<"\t\tPoints"<<"\t";
    for(l=0;l<l2.size();l++)
    {
        cout<<l2[l]<<" ";
    }
    cout<<"\n";
    cout<<"\n";

}

//stroing the valid words in a tree
struct node
{
    string data;
    struct node*left;
    struct node*right;
}*start=NULL,*nn;
void create(string s)
{
    nn=(struct node*)malloc(sizeof(struct node));
    nn->left=NULL;
    nn->right=NULL;
    nn->data=s;
}
void insert()
{
    if(start==NULL)
    {
        start=nn;
    }
    else
    {
        search(start);
    }
}
void search(struct node *root)
{
    if((nn->data.compare(root->data)) < 0 && root->left!=NULL)
        search(root->left);
    else if((nn->data.compare(root->data)) < 0 && root->left==NULL)
        root->left=nn;
    else if((nn->data.compare(root->data)) > 0 && root->right!=NULL)
        search(root->right);
    else if((nn->data.compare(root->data)) > 0 && root->right==NULL)
        root->right=nn;
    else if((nn->data.compare(root->data)) == 0)
    {
        cout<<"the word has been entered previously"<<"\n\n";
        ctr++;
    }
}

//player details
string p1,p2;
void players()
{
        cout<<"\t\t\t:::\tWELCOME TO THE GAME 'KNOW THE WORDS'\t:::"<<"\n\n\n";
        cout<<"Player 1 enter your name"<<"\n";
        cin>>p1;
        cout<<"\n\n";
        cout<<"Player 2 enter your name"<<"\n";
        cin>>p2;
        cout<<"\n\n";
        cout<<"Let's see who know the words better "<<p1<<" or "<<p2<<"\n\n\n";
}

int main()
{
    rules();
    int start,valid,level;
    int score1=0, score2=0, s1, s2;
    int turn=1;
    string str1,str2;
    cout<<"PRESS 1 TO CONTINUE     ....."<<"\n";
    cout<<"PRESS 0 TO EXIT         ....."<<"\n";
    cin>>start;
    if(start==1)
    {
        players();
        display();
    do
    {
        ctr=0;
        if(turn%2!=0)
        {
            cout<<p1<<" enter a word or press p to pass"<<"\n";
            cin>>str1;
            if(str1=="p")
            {
                turn++;
                cout<<"\n";

            }
            else
            {
            valid=compare(str1);
                            if(valid==1)
                            {
                                create(str1);
                                insert();
                                if(ctr==0)
                                {
                                    s1=points(str1);
                                }
                                score1=score1+s1;
                                turn++;
                            }
                            else
                            {
                                cout<<"Invalid word"<<"\n\n";
                                turn++;
                            }

            }
        }
        else if(turn%2==0)
        {
            cout<<p2<<" enter a word or press p to pass"<<"\n";
            cin>>str2;
            if(str2=="p")
            {
                turn++;
                cout<<"\n";
            }
            else
            {
            valid=compare(str2);
                            if(valid==1)
                            {
                                create(str2);
                                insert();
                                if(ctr==0)
                                {
                                    s2=points(str2);
                                }
                                score2=score2+s2;
                                turn++;
                            }
                            else
                            {
                                cout<<"Invalid word"<<"\n\n";
                                turn++;
                            }
            }

        }

    }while(str1!="p" || str2!="p");

        cout<<p1<<"'s score = "<<score1<<"\n";
        cout<<p2<<"'s score = "<<score2<<"\n";

    if(score1>score2)
    {
        cout<<p1<<" knows more than "<<p2<<"\n\n";
    }
    else if(score2>score1)
    {
        cout<<p2<<" knows more than "<<p1<<"\n\n";
    }
    else
    {
        cout<<p1<<" and "<<p2<<" are equally intelligent"<<"\n\n\n";
    }

        cout<<"\n\n";
        cout<<"\t\t\tTHANKS FOR PLAYING"<<"\n";
    }

    else if(start==0)
    {
        exit(0);
    }
}

