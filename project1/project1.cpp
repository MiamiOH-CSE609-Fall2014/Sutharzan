#include <iostream>
#include <vector>
using namespace std;

// Declaring and initializing variables and vectors
int nr = 0, nc = 0, el=0, nr2 = 0, nc2 = 0, mati = 0;
vector<int> mat1, vectemp, mat2;
vector<vector<int> > vecmat1, vecmat2; // These vectors will hold matrix rows as vectors

int main(){ // Main method
  cin >> nr; // Num of rows in matrix A
  cin >> nc; // Num of columns in matrix A
  cin >> nr2; // Num of rows in matrix B 
  cin >> nc2; // Num of columns in matrix B 

  // Validating matrix diamensions
  if(nc != nr2 || nr <= 0 || nc <= 0 || nr2 <= 0 || nc2 <= 0){ 
    cout << "Invalid input" << endl; 
    return 1; 
  }

  // Reading the matrices data  
   for(int i=0; i< nr*nc+nr2*nc2;++i) {
    cin >> el;   
    mat1.push_back(el);
  }

  // Creating and Printing the matrices
  //// Storing matrix A as a vector of vectors
  for(int i=0; i<nc*nr; i=i+nc){
    for(int j=i; j<i+nc; ++j){
      vectemp.push_back(mat1[j]);
    }
    vecmat1.push_back(vectemp);
    vectemp.clear();    
  }
  //// Printing matrix B as a vector of vectors
  for(int k=0; k<nc2*nr2; k=k+nc2){
    for(int l=k; l<k+nc2; ++l){
      vectemp.push_back(mat1[l+nc*nr]);
    }
    vecmat2.push_back(vectemp);
    vectemp.clear();    
  }  
  //// Printing the matrices A and B
  for(int i=0; i<nr; ++i){
    for(int j=0; j<nc; ++j){
      cout << vecmat1[i][j];
      cout << " ";
    }
    cout << endl;
  }
  cout << endl;
  for(int k=0; k<nr2; ++k){
    for(int l=0; l<nc2; ++l){
      cout << vecmat2[k][l];
      cout << " ";
    }
    cout << endl;
  }
  cout << endl;
  /*
  // Printing the resulting matrix (Matrix C)
  for(int k=0; k<nr; ++k){  
    for(int i=0; i<nc2; ++i){
      for(int j=0; j<nc; ++j){
	mati += vecmat1[k][j] * vecmat2[j][i];
      }
      cout << mati << " ";
      mati = 0;
    }
    cout << endl;
    } */
 
  return 0;
}
