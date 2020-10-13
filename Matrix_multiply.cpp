#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<vector<float>> matrix_multiply(vector<vector<float>> R1,vector<vector<float>> R2){
  //wi=(Width)Denotes column number (distance from first column)
//di=(Depth)Denotes column number (distance from top row)
  int d1=R1.size();
  int w1=R1[0].size();
  int d2=R2.size();
  int w2=R2[0].size();
  //cout<<"d1:"<<d1<<"\t"<<"w1"<<w1<<endl;
  //cout<<"d2:"<<d2<<"\t"<<"w2:"<<w2<<endl;
  if(d2!=w1){
    cout<<"Invalid Matrix Multiplication Query"<<endl;
    return {{0}};
  }
  else{
  //cout<<"Matrix valid"<<endl;
  vector<vector<float>> M;
  for(int i=0;i<d1;i++){
    vector<float> temp(w2,0);
    for(int j=0;j<w2;j++){
      float sum=0;
      for(int k=0;k<w1;k++){
        sum+=R1[i][k]*R2[k][j];
        }
        temp[j]=sum;
      //cout<<"sum:"<<sum<<endl;
      //M[i][j]=sum;
      }
      M.push_back(temp);
    }
    return M;
  }

}
int main(){
  vector<vector<float>> R1{{1,1,1},{1,1,1}};
  vector<vector<float>> R2{{2,2},{2,2},{2,2}};
  vector<vector<float>> M;
  M=matrix_multiply(R2,R1);
  for(int i=0;i<M.size();i++){
    for(int j=0;j<M[0].size();j++){
      cout<<M[i][j]<<"\t";
    }
    cout<<"\n";
  }
}
