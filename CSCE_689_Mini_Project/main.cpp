#include<iostream>
#include<vector>
#include<cmath>
#include<chrono>
#include<random>
using namespace std;
void generate_label(vector<double> &f,unsigned int m,double h){
	unsigned seed = 0;//std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator (seed);
	uniform_real_distribution<double> distribution (-0.05,0.05);
	for(double i=1;i<=m;i++){
		for(double j=1;j<=m;j++){
			f[(i-1)*m+j-1]=1-(pow(i*h-0.5,2)+pow(j*h-0.5,2));//+distribution(generator);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
void generate_K_matrix(vector<vector<double>> &K, unsigned int m,double h,double t){
	for(double i=0;i<K.size();i++){        // using [0,n) as the function value doesnt effect changing bases and mod works with this range only
		for(double j=0;j<K.size();j++){
			K[i][j]=exp(-1*(pow((floor(i/m)-floor(j/m))*h,2)+pow((fmod(i,m)-fmod(j,m))*h,2)));
			if(i==j){ //Adding the tolerance to diagonal elements.
				K[i][j]=exp(-1*(pow((floor(i/m)-floor(j/m))*h,2)+pow((fmod(i,m)-fmod(j,m))*h,2)))+t;
			}
	  }
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<K[i][j]<<"\t";
		}
		cout<<"\n";
	}*/
}
////////////////////////////////////////////////////////////
void LU_decompose(vector<vector<double>> &K,unsigned int m){
long n=m*m;
for(int k=0;k<(n-1);k++){
  double M;
  for(int i=(k+1);i<n;i++){
    M=K[i][k]/K[k][k];
    for(int j=(k+1);j<n;j++){
      K[i][j]=K[i][j]-(M*K[k][j]);
			//cout<<K[i][j]<<"\t";
    }
    K[i][k]=M;
		//cout<<"\n";
  }
}
}
///////////////////////////////////////////////////////////////
void generate_k_vector(vector<double> &k,unsigned int m, double rx, double ry,double h){
	for(double i=0;i<k.size();i++){
		k[i]=exp(-1*(pow((floor(i/m)+1)*h-rx,2)+pow((fmod(i,m)+1)*h-ry,2)));
	}
}
///////////////////////////////////////////////////////////////
vector<double> L_solve(vector<vector<double>> &K, vector<double> &f, int m){
	vector<double> y(f.size(),0);
	double sum;
			for(int i=0;i<f.size();i++){
				sum=0;
			for(int j=0;j<i;j++){
				//cout<<"J-loop started in LU Solve 1"<<endl;
				sum+=K[i][j]*y[j];
			}
			y[i]=(f[i]-sum);
			//cout<<"I-loop ended in LU Solve 1"<<endl;
		}
		return y;
	}
//////////////////////////////////////////////////////////////////
vector<double> U_solve(vector<vector<double>> &K, vector<double> &y1, int m){
	//cout<<"entered U_solve"<<endl;
  long n=y1.size();
	vector<double> y(n,0);
	//cout<<"Entering U_solve I loop"<<endl;
  double sum;
	for(int i=(n-1);i>=0;i--){
		sum=0;
		for(int j=(n-1);j>=i;j--){
			//cout<<"J-loop started in LU Solve 2"<<endl;
				sum+=K[i][j]*y[j];
			}
		y[i]=(y1[i]-sum)/K[i][i];
	//cout<<"I-loop ended in LU Solve 2"<<endl;
}
	return y;
}
///////////////////////////////////////////////////////
double GPR(vector<vector<double>> &K, vector<double> &f, vector<double> &k, unsigned int m){
	//cout<<"Entered GPR"<<endl;
	vector<double> y1;//(f.size(),0.0);
	vector<double> y2;//(f.size(),0.0);
	//cout<<"created y1 and y2"<<endl;
	y1=L_solve(K,f,m);
	//cout<<"L_solve done"<<endl;
	//for(auto i:y1)
	//cout<<i<<endl;
	y2=U_solve(K,y1,m);
	//for(auto i:y1)
	//cout<<i<<endl;
	double fstar;
	for(int i=0;i<k.size();i++){
		fstar+=k[i]*y2[i];
	}
	return fstar;
}
/////////////////////////////////////////////////////////
int main(){
	unsigned int m;
	long n;
	double rx,ry;
	double h,t,fstar;
	t=0.01;
	cout<<"Enter grid size m and x,y co-ordinates of points to be predicted"<<endl;
	cin>>m>>rx>>ry;
	h=1/double(m+1);
	n=m*m;
	//cout<<h<<endl;
	vector<double> f(n,0),k(n,0);
	vector<vector<double>> K(n,vector<double>((m*m),0));
	generate_label(f,m,h);
	//cout<<"label_generated"<<endl;
	generate_K_matrix(K,m,h,t);
	//cout<<"K_matrix generated"<<endl;
	generate_k_vector(k,m,rx,ry,h);
	//cout<<"k_vector generated"<<endl;
	LU_decompose(K,m);
	cout<<"Solving...."<<endl;
	//cout<<"LU_decomposed"<<endl;
	fstar=GPR(K,f,k,m);
	cout<<fstar<<endl;
	/*for(int i=0;i<K.size();i++){
		for(int j=0;j<K.size();j++){
			cout<<K[i][j]<<"\t";
		}
		cout<<endl;
	}
	/*for(auto i:k)
		cout<<i<<"\t";*/
		return 0;
}
