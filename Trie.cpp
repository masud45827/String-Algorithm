//https://www.spoj.com/problems/ADAINDEX/
#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
struct node{
    node* edge[26];
    int endmark,cntpath;
    node(){
        endmark = cntpath=0;
        for (int i = 0; i < 26; i++) edge[i] = NULL;
    }
}*root;
void add( string &s)
{
    node *cur = root;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (cur->edge[c] == NULL){
            cur->edge[c] = new node();
        }
        cur = cur->edge[c];
        cur->cntpath++;}
    cur->endmark = 1;
}
  int search(node *cur,string str){
     for(int i=0;i<str.size();i++){
        int c=str[i]-'a';
         if(cur->edge[c]==NULL) return 0;
         cur=cur->edge[c];
     }
     return cur->cntpath;
  }
int main()
{
    int t = 1, cas = 1;
    //cin>>t;
    while (t--){
        int n, i,q;
        cin >> n>>q;
        root = new node();
        string s;
        for (i = 0; i < n; i++){
            cin >> s;
            add(s);
        }
        string s1;
        for (i = 1; i <= q; i++){
            string s;
             cin>>s;
          int x=search(root , s);
             cout<<x<<endl;
        }
    }
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// typedef     long long    ll;
// typedef     unsigned long long    ull;
// typedef     vector<int> vi;
// typedef     vector<long long> vl;
// typedef     pair<int, int>pi;
// typedef     pair<long long, long long>pl;
// #define F   first
// #define S   second
// #define pb  push_back
// #define     all(x)      x.begin() , x.end()
// #define mp  make_pair
// #define mod 1000000007
// #define       FOR(i,a,b) for(i=a;i<=b;i++)
// #define     mem(a)      memset(a , 0 ,sizeof a)
// #define     memn(a)     memset(a , -1 ,sizeof a)
// string p;
// int f = 0;
// std::vector<string> ans;
// struct node
// {
//     node* edge[26];
//     int endmark;
//     node()
//     {
//         endmark = 0;
//         for (int i = 0; i < 26; i++) edge[i] = NULL;
//     }
// }*root;
// void add( string &s)
// {
//     node *cur = root;
//     for (int i = 0; s[i]; i++)
//     {
//         int c = s[i] - 'a';
//         if (cur->edge[c] == NULL)
//         {
//             cur->edge[c] = new node();
//         }
//         cur = cur->edge[c];
//     }
//     cur->endmark = 1;
// }
// void display(node *cur, string str)
// {
//     if (cur->endmark) ans.pb(str);
//     for (int j = 0; j < 26; j++)
//     {
//         if (cur->edge[j] != NULL)
//         {
//             display(cur->edge[j], str + char(j + 'a'));
//         }
//     }
// }
// void search(node *root, string s1)
// {
//     node *cur = root;
//     int n = s1.size();
//     for (int i = 0; i < n; i++)
//     {
//         int c = s1[i] - 'a';
//         if (cur->edge[c] == NULL) return;
//         cur = cur->edge[c];
//     }

//     for (int i = 0; i < 26; i++)
//     {
//         if (cur->edge[i] != NULL)
//         {
//             display(cur->edge[i], s1 + (char)(i + 'a'));
//         }

//     }
// }


// //https://www.spoj.com/problems/DICT/cstart=10
// int main()
// {
//     int t = 1, cas = 1;
//     //cin>>t;
//     while (t--)
//     {
//         int n, i;
//         cin >> n;
//         root = new node();
//         string s;
//         for (i = 0; i < n; i++)
//         {
//             cin >> s;
//             add(s);
//         }
//         int q;
//         cin >> q;
//         string s1;
//         for (i = 1; i <= q; i++)
//         {
//             char str[100];
//             scanf("%s", str);
//             printf( "Case #%d:\n", i );
//             search(root , str);
//             if (ans.size() == 0) {
//                 cout << "No match." << endl;
//             } else 
//             {
//                 for (auto k : ans) cout << k << endl;
//                 ans.clear();
//             }
//         }

//     }
//     return 0;
// }
