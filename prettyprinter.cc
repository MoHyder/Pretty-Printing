#include <iostream>
using namespace std;
void indent(int x) {
  for (int b = 0; b < x; b++) {
    cout << " ";
  }
  return;
}
int main() {
  int ind = 0;
  bool newline = true;
  string toprint;
  while (cin >> toprint) {
    if ( toprint == "{" ) {
      if (newline) indent(ind);
      else cout << " ";
      cout << "{" << endl;
      ind++;
      newline = true;
    }
    else if ( toprint == ";" ) {
      if (newline) indent(ind);
      else cout << " ";
      cout << ";" << endl;
      newline = true;
    }
    else if ( toprint == "}" ) {
      if (ind > 0) ind--;
      if ( ! newline ) cout << endl;
      indent(ind);
      cout << "}" << endl;
      newline = true;
    }
    else if ( toprint == "//" ) {
      getline(cin,toprint);
      if ( newline ) indent(ind);
      else cout << " ";
      cout << "//" << toprint << endl;
      newline = true;
    }
    else {
      if (newline) indent(ind);
      else cout << " ";
      cout << toprint;
      newline = false;
    }
  }
}
