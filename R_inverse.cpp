#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void invert(vector<vector<float>> &R,int s){
  float temp;
  float Det;
  //cout<<"Start:"<<s<<endl;
  //cout<<"\n\n\n"<<endl;
  /*for(int j=s;j<s+2;j++){
    for(int k=s;k<s+2;k++){
      cout<<R[j][k]<<"\t";
    }
    cout<<"\n";
  }*/
  //cout<<"\n\n\n"<<endl;
  //cout<<"Before Entering Invert"<<endl;
  Det=abs((R[s][s]*R[s+1][s+1])-(R[s+1][s]*R[s][s+1]));
  temp=R[s][s];
  R[s][s]=R[s+1][s+1];
  R[s+1][s+1]=temp;
  R[s+1][s]=(-1)*R[s+1][s];
  R[s][s+1]=(-1)*R[s][s+1];
  //cout<<Det<<"Determinant"<<endl;
  for(int i=s;i<s+2;i++){
    for(int j=s;j<s+2;j++){
      R[i][j]=R[i][j]/Det;
    }
  }
  /*cout<<"After Invert"<<endl;
  for(int i=s;i<s+2;i++){
    for(int j=s;j<s+2;j++){
      cout<<R[i][j]<<"\t";
  }
    cout<<"\n";
  }*/
}
void matrix_multiply(vector<vector<float>> &R,int s,int e,int nl,int ax){
    int c1;
    int c2;
    int sign;
  if(ax==0){
  c1=s;
  c2=s+nl;
  sign=-1;
  }
  else if(ax==1){
    c1=nl;
    c2=e;
    sign=1;
  }
  vector<vector<float>> M((nl-s),vector<float>((e-nl),0));
  for(int i=s;i<(s+nl);i++){
      for(int j=nl;j<e;j++){
        float sum=0;
          for(int k=c1;k<c2;k++){
            sum+=R[i][k]*R[k][j];
        }
        M[i-s][j-nl]=sum;
      }
    }
    //cout<<"Printing M"<<endl;
    //cout<<"M vars:"<<s<<"\t"<<e<<endl;
    for(int i=s;i<(s+nl);i++){
        for(int j=nl;j<e;j++){
          R[i][j]=sign*M[i-s][j-nl];
  }
}
//for(int i=s;i<(s+nl);i++){
    //for(int j=nl;j<e;j++){
      //cout<<R[i][j]<<"\t";
    //}
    //cout<<"\n";
  //}
}
void compute_inverse(vector<vector<float>> &R,int s,int e){
  //cout<<s<<"\t"<<e<<endl;
  float diff=e-s;
  if(diff==2){
    invert(R,s);
  }
  else if(diff<2){
//cout<<e<<","<<s<<"no-inverse"<<endl;
  R[s][s]=1/R[s][s];
  return;
  }
  else{
    int nl;
    nl=round(diff/2);
    compute_inverse(R,s,nl);
    compute_inverse(R,nl,e);
    //Multiplying left diagonal block with off diagonal on the right.
    matrix_multiply(R,s,e,nl,0);
    matrix_multiply(R,s,e,nl,1);
  }
  //for(int j=0;j<R.size();j++){
    //for(int k=0;k<R[0].size();k++){
      //cout<<R[j][k]<<"\t";
    //}
    //cout<<"\n";
  //}
return;
}
int main(){
  //vector<vector<float>> R{{1,2,3,4,5},{0,6,7,8,9},{0,0,10,11,12},{0,0,0,13,14},{0,0,0,0,15}};//R{{1,2,3},{0,4,5},{0,0,6}};//
  //vector<vector<float>> R{{1,2,3},{0,4,5},{0,0,6}};
  vector<vector<float>> R{{1,2,3,4},{0,5,6,7},{0,0,8,9},{0,0,0,10}};
  compute_inverse(R,0,R.size());
  cout<<"Printing Final output"<<endl;
  for(int j=0;j<R.size();j++){
    for(int k=0;k<R[0].size();k++){
      cout<<R[j][k]<<"\t";
    }
    cout<<"\n";
  }
  return 0;
}
