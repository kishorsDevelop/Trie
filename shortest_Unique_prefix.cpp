struct Trie{
    unordered_map<char,Trie*> mp;
    bool isWord;
    int freq=0;
    Trie(){                   // Making a Trie   with an additional field freq for frequency
        isWord = false;
    }
};
void insert(Trie* root,string s){
    Trie* curr = root;
    for(char c:s){
        if(!curr->mp.count(c)){                 //Insretion in Tree and counting each word frequency
            curr->mp[c] = new Trie();
        }
        curr->freq++;
        curr = curr->mp[c];
    }
    curr->isWord = true;
}
void search(Trie* root,string word,string &s){
     Trie* curr = root;
     
     for(char c : word){
           s+=c; 
           curr = curr->mp[c];            //searching for unique prefix  
          
           if(curr->freq == 1){
               return;
           }
     }
    
}

vector<string> Solution::prefix(vector<string> &A) {
    Trie* root = new Trie();
    string s;
    vector<string> ans;
    for(int i=0;i<A.size();i++){
        insert(root,A[i]);
    }
    for(int i=0;i<A.size();i++){        // Driver Function
        s="";
        search(root,A[i],s);
        ans.push_back(s);
    }
    return ans;
}
