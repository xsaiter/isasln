#include <bits/stdc++.h>

using namespace std;

struct Q {
  int l, r;  
};

class Node {  
public:
  int l, r;
  unique_ptr<Node> l_node, r_node;
  int v;

  Node(int l_, int r_) : l(l_), r(r_), l_node(nullptr), r_node(nullptr), v(0) {}

  void build(const vector<int>& arr) {
    if (l == r) {
      v = arr[l];
      return;
    }

    int c = mid();
    l_node = make_unique<Node>(l, c);
    r_node = make_unique<Node>(c + 1, r);

    l_node->build(arr);
    r_node->build(arr);

    v = gcd(l_node->v, r_node->v);
  }

  int query(const Q &q) const {    
    int l = q.l;
    int r = q.r;
    if (l == r) {
      return 0;
    }    
    if (l < r) {
      r--;
    }    
    return query(l, r);
  }

private:
  int query(int p, int q) const {    
    if (!intersects(p, q)) {
      return 0;
    }
    if (contains(p, q)) {      
      return v;
    }
    return gcd(l_node->query(p, q), r_node->query(p, q));
  }

  int mid() const {
    return l + (r - l) / 2;
  }

  bool intersects(int p, int q) const {   
    return !(q < l || p > r);
  }

  bool contains(int p, int q) const {
    return p <= l && r <= q;
  }
};

Node make_tree(int n, const vector<int> &a) {
  vector<int> b;
  if (n > 1) {
    for (int i = 1; i < n; ++i) {
      b.push_back(abs(a[i] - a[i - 1]));
    }
  } else {
    b.push_back(0);
  }
  Node root(0, (int)b.size() - 1);
  root.build(b);
  return root;
}

Q read_q() {
  Q q;
  cin >> q.l >> q.r;  
  q.l--; q.r--;  
  return q;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    Node tree = make_tree(n, a);    
    for (int i = 0; i < m; ++i) {
      Q q = read_q();      
      cout << tree.query(q) << ' ';
    }
    cout << '\n';
  }
  cout << endl;
  return 0;
}