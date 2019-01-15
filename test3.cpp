#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Word{
public:
    string wrd;
    int letter_counter[26];


    Word(){}
    Word(string input);
    friend bool operator==(Word w1, Word w2);
    friend ostream& operator<<(ostream &output, Word &w);
    friend istream& operator>>(istream &input, Word &w)
    {
        string tmp;
        cin>>tmp;
        w.wrd=tmp;
    }
};

ostream& operator<<(ostream &output, Word &w)
{
    cout<<w.wrd;
    return output;
}

class Dictionary{
public:
    vector <vector <Word> > words;
    Dictionary()
    {
        for(int i=0; i<26; i++)
        {
            vector <Word> temp;
            this->words.push_back(temp);
        }
    }

    friend istream& operator>>(istream &input, Dictionary &d);

};


Word::Word(string input)
{
    this->wrd=input;
    for(int i=0; i<26; i++)
    {
        letter_counter[i]=0;
    }
    for(int i=0; i<input.size(); i++)
    {
        this->letter_counter[input[i]-97]++;
    }
}

bool operator==(Word w1, Word w2)
{
    if(w1.wrd[0]!=w2.wrd[0]) return false;
    if(w1.wrd[w1.wrd.size()-1]!=w2.wrd[w2.wrd.size()-1]) return false;
    for(int i=0; i<26; i++)
    {
        if(w1.letter_counter[i]!=w2.letter_counter[i])
        {
            cout<<"here"<<w1.letter_counter[i]<<" "<<w2.letter_counter[i] ; return false;
    }
    }
    return true;
}
////////////////////////////////

istream& operator>>(istream &input, Dictionary &d)
{
    string input_string;
    getline(std::cin, input_string);
    int i;
    int word_beginning=0;
    int word_end=0;
    //cout<<input_string<<input_string.length()<<endl;
    for(i=0; i<=input_string.size(); i++)
    {
        if(input_string[i]==' ' || input_string[i]=='\n')
        {
            //cout<<i<<endl;
            word_end=(i-1);
            d.words[input_string[word_beginning]-97].push_back(input_string.substr(word_beginning,word_end-word_beginning+1));
           // cout<<input_string.substr(word_beginning,(word_end-word_beginning+1))<<" "<<word_beginning<<" "<<word_end<<endl;
            word_beginning=(i+1);

        }
    }
   // cout<<i<<endl;
    word_end=(i-1);
    d.words[input_string[word_beginning]-97].push_back(input_string.substr(word_beginning,word_end-word_beginning+1));
   // cout<<input_string.substr(word_beginning,(word_end-word_beginning+1))<<" "<<word_beginning<<" "<<word_end<<endl;
return input;
}

main()
{
    Word w1("me");
    Word w2("me");
    if(w1==w2) cout<<"true";
    else cout<<"false";


    int cases_left;
    cin>>cases_left;

/*

        Word ab("abc");
        Word ac("abc");
        cout<<ab<<" "<<ac<<endl;
        if(ab==ac) cout<<"dziala";
        else cout<<"nope";*/







    while(cases_left--)
    {
        string input_str;
        Dictionary case_dictionary;
        vector <Word> case_words;
       // cin>>input_string;
        int word_beginning=0;
        int word_end=0;
        cin.ignore();
        cin>>case_dictionary;
        getline(std::cin, input_str);
        int i;
        for(i=0; i<input_str.size(); i++)
        {
            if(input_str[i]==' ')
            {
                word_end=(i-1);
                Word word_input(input_str.substr(word_beginning,(word_end-word_beginning+1)));
                case_words.push_back(word_input);
                word_beginning=(i+1);
            }
        }
        word_end=(i-1);
        Word word_input(input_str.substr(word_beginning,(word_end-word_beginning+1)));
        case_words.push_back(word_input);
        /*for(int i=0; i<case_words.size(); i++)
        {
         cout<<case_words[i]<<endl;
        }*/
        cout<<"Wypisanie wszystkich slow ze slownika zaczynajacych sie na pierwsza litere case_word: "<<endl;
        for(int i=0; i<case_words.size(); i++)
        {
            //cout<<case_words[i].wrd[0]-97<<endl;
            //cout<<"word: "<<case_words[i]<<endl;
            /* for(int j=0; j<26; j++)
            {

                if(case_words[i].wrd[0]-97 == j) cout<<j<<" ";
            }*/
            cout<<"case word: "<<case_words[i]<<" : ";
            for(int j=0; j<(case_dictionary.words[case_words[i].wrd[0]-97].size()); j++)
            {
                cout<<case_dictionary.words[case_words[i].wrd[0]-97][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"//////////"<<endl;


        cout<<"wypisanie slowa ze slownika ktore bedzie wypisane w wyniku dla kazdego case_word: "<<endl;
        for(int i=0; i<case_words.size(); i++)
        {
            bool wypisano=0;
            cout<<"case word: "<<case_words[i]<<" : ";
            for(int j=0; j<(case_dictionary.words[case_words[i].wrd[0]-97].size()); j++)
            {
                if(case_words[i]==case_dictionary.words[case_words[i].wrd[0]-97][j])
                {
                    cout<<case_dictionary.words[case_words[i].wrd[0]-97][j]<<" |"<<endl;
                    wypisano=true;
                     break;
                }
                //else
               // {

                //    break;
               // }

            }
            if(wypisano == false)cout<<case_words[i]<<" ."<<endl;
        }
        cout<<endl;
    }
return 0;
}
