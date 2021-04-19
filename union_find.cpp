class UnionFind {
 public:
  int find(int i) {
    if (parents[i] == i) {
      return i;
    } else {
      parents[i] = find(parents[i]);
      return parents[i];
    }
  }
  
  void union(int first, int second) {
    int id1 = find(first);
    int id2 = find(second);
    parents[id1] = parents[id2];
  }
  
 private:
  vector<int> parents_;
};

UnionFind uf(num_account);
unordered_map<string, int> email_to_first_account_id;

// Pass #1: Build a hash map from every email address to the first account ID that contains it. 
//          Also build a union set of accounts based on shared email addresses.
for (size_t a = 0; a < NumAccounts; ++a) {
  // Iterate over all email addresses for this account (person name is index 0, emails start at index 1)
  for (size_t e = 1; e < accounts[a].size(); ++e) {
    const string& emailAddress = accounts[a][e];
    if (emailToFirstAccountId.count(emailAddress) == 0) {
       // This email address is new.  Create a map entry from email address to this account.
       emailToFirstAccountId[emailAddress] = a;
    } else {
       // This email address has been seen before in a different account.  Union this account
       // account A with the prior account ID to link all their email addresses together.
       uf.union(emailToFirstAccountId[emailAddress], a);
    }
  }
}

// Pass #2: Build a hash map from the unified set IDs to all email addresses contained within.
unordered_map<int,vector<string>> unifiedSetIdToEmails;

for (const pair<string, int>& p : emailToFirstAccountId) {
  int unifiedSetId = uf.find(p.second);
  unifiedSetIdToEmails[unifiedSetId].push_back(p.first);
}
