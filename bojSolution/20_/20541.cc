#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tup;
struct Trie;
typedef pair<string, Trie*> pct;

struct Trie {
	map<string, Trie*> child;
   set<string> photo;
   string label; Trie* par;

	Trie(string& L, Trie* parent) {
      label = L;
      par = parent;
	}
	~Trie() {
		for (pct c : child) delete c.second;
	}

	void mkalb(string& name) {
		if (child.find(name) == child.end()) {
         child.insert({name, new Trie(name, this)});
      }
      else cout << "duplicated album name\n";
	}

   void rmalb(string& oper) {
      pii ret = {0, 0};
      if (oper == "-1") { // erase begin
         if (child.size() != 0) {
            ret = {1, 0};
            auto tar = child.begin();

            pii req = tar->second->blow();
            ret.first += req.first;
            ret.second += req.second;
            child.erase(tar->first);
         }
      }
      else if (oper == "0") { // erase all
         if (child.size() != 0) {
            ret = {child.size(), 0};

            for (pct c : child) {
               pii req = c.second->blow();
               ret.first += req.first;
               ret.second += req.second;
            }

            child.clear();
         }
      }
      else if (oper == "1") { // erase rbegin
         if (child.size() != 0) {
            ret = {1, 0};
            auto tar = --child.end();

            pii req = tar->second->blow();
            ret.first += req.first;
            ret.second += req.second;

            child.erase(tar);
         }
      }
      else {
         if (child.find(oper) != child.end()) {
            ret = {1, 0};
            auto tar = child.find(oper);

            pii req = tar->second->blow();
            ret.first += req.first;
            ret.second += req.second;

            child.erase(tar);
         }
      }

      cout << ret.first << " " << ret.second << "\n";
   }
   pii blow() { // erase all
      pii ret = {child.size(), photo.size()};
      for (pct c : child) {
         pii req = c.second->blow();
         ret.first += req.first;
         ret.second += req.second;
      }
      return ret;
   }

   void putPhoto(string& s) {
      if (photo.find(s) == photo.end()) {
         photo.insert(s);
      }
      else cout << "duplicated photo name\n";
   }

   void erasePhoto(string& s) {
      int ret = 0;
      if (s == "-1") {
         if (!photo.empty()) {
            ret = 1;
            photo.erase(photo.begin());
         }
      }
      else if (s == "0") {
         if (!photo.empty()) {
            ret = photo.size();
            photo.clear();
         }
      }
      else if (s == "1") {
         if (!photo.empty()) {
            ret = 1;
            photo.erase(--photo.end());
         }
      }
      else {
         if (photo.find(s) != photo.end()) {
            ret = 1;
            photo.erase(s);
         }
      }

      cout << ret << "\n";
   }

   Trie* ca(string& s) {
      Trie* ret = nullptr;
      if (s == "..") {
         ret = par;
      }
      else if (s == "/") {
         ret = nullptr;
      }
      else {
         if (child.find(s) != child.end()) ret = child.find(s)->second;
         else ret = this;
      }
      return ret;
   }

};


int main() {
   ios::sync_with_stdio(0); cin.tie(0);

   string ALBUM = "album";
   Trie* root = new Trie(ALBUM, nullptr);
   Trie* cur = root;

   int QUERY; cin >> QUERY; while (QUERY--) {
      string oper, x; cin >> oper >> x;
      if (oper == "mkalb") {
         cur->mkalb(x);
      }
      else if (oper == "rmalb") {
         cur->rmalb(x);
      }
      else if (oper == "insert") {
         cur->putPhoto(x);
      }
      else if (oper == "delete") {
         cur->erasePhoto(x);
      }
      else if (oper == "ca") {
         Trie* req = cur->ca(x);
         if (req) cur = req; else cur = root;
         cout << cur->label << "\n";
      }
   } 
	
   return_0;
}