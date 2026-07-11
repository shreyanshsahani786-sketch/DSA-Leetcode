class TrieNode
{
public:
    TrieNode* children[26];
    bool isTerminal;

    TrieNode()
    {
        for(int i=0;i<26;i++)
            children[i]=NULL;

        isTerminal=false;
    }
};

class WordDictionary
{
public:

    TrieNode* root;

    WordDictionary()
    {
        root=new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode* curr=root;

        for(char ch:word)
        {
            int index=ch-'a';

            if(curr->children[index]==NULL)
                curr->children[index]=new TrieNode();

            curr=curr->children[index];
        }

        curr->isTerminal=true;
    }

    bool helper(string word,int pos,TrieNode* node)
    {
        if(node==NULL)
            return false;

        if(pos==word.size())
            return node->isTerminal;

        char ch=word[pos];

        if(ch!='.')
        {
            int index=ch-'a';

            return helper(word,pos+1,node->children[index]);
        }

        for(int i=0;i<26;i++)
        {
            if(node->children[i]!=NULL)
            {
                if(helper(word,pos+1,node->children[i]))
                    return true;
            }
        }

        return false;
    }

    bool search(string word)
    {
        return helper(word,0,root);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */