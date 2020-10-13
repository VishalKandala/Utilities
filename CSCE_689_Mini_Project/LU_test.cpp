#include<iostream>
#include<cmath>
#include<vector>
#include<chrono>
#include<random>
using namespace std;
//int n;
//int n=m*m;
int main(){
vector<vector<double>> K{{3,1,6},{-6,0,-16},{0,8,-17}};//(vector<double>(n,0));
int n=K.size();
cout<<"Size: "<<n<<endl;
cout<<"Original Matrix"<<endl;
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    cout<<K[i][j]<<"\t";
  }
  cout<<"\n";
}
////////////////////////////////

for(int k=0;k<(n-1);k++){
  vector<double> m((n-k),1);
  for(int i=(k+1);i<n;i++){
    m[i]=K[i][k]/K[k][k];
    for(int j=(k+1);j<n;j++){
      K[i][j]=K[i][j]-(m[i]*K[k][j]);
    }
    K[i][k]=m[i];
  }
}
cout<<"LU Factorized"<<endl;
/////////////////////////////////
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    cout<<K[i][j]<<"\t";
  }
  cout<<"\n";
}
}
