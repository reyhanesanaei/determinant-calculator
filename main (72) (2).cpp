/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n , m;
int n2 , m2;
string c;
int matrix[100][100];
int check[100][100];
int q[100][100];
int countt = 0;
int T_matrix[100][100];
//int new_matrix[100][100];
void make_new_matrix(int new_matrix[][100],int row, int col){
    //int row , col;
    //cin>>row>>col;
    int a = 0;
    int b = 0;
    for(int i = 0;i < n;i ++){
        b = 0;
        for(int j= 0;j < n;j ++){
            if(j == col){
                continue;
            }
            if(i == row){
                a --;
                break;
                
            }
            new_matrix[a][b] = matrix[i][j];
            b ++;
            //cout<<a<<b<<'\n';
        }
        a ++;
       
    }
    
}
void zero(){
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            check[i][j] = 0;
        }
    }
}
void mark_check(int col , int row,int d){
    for(int i = 0;i < d;i ++){
        if(check[row][i] == 0){
            countt --;
        }
        check[row][i] += 1;
    }
        
    for(int i = 0;i < d;i ++){
        if(check[i][col] == 0){
            countt -- ;
            
        }
        check[i][col] += 1;
    }
}
void clear_check(int j , int row,int d){
    for(int i = 0;i < d;i ++){
        if(check[i][j] == 1){
            countt ++;
        }
        check[i][j] -= 1;
    }
    for(int i = 0;i < d;i ++){
        if(check[row][i] == 1){
            countt ++;
        }
        check[row][i] -= 1;
        
    }
    
}



int det(int row,int d,int mat[][100]){
    //cout<<row<<'\n';
    //cout<<countt<<'\n';
    if(countt == 1){
        return mat[0][0];
    }
    int result = 0;
    //cout<<countt<<'\n';
    if(countt > 4 ){
        int t = 0;
        for(int j = 0;j < d;j ++){
            if(check[row][j] == 0){
                mark_check(j , row , d);
                int k; 
                if(t % 2 == 0){
                    k = 1;
                }
                else{k = - 1;}
                result += (mat[row][j] * det(row + 1 , d ,mat) * k);
                clear_check(j , row , d);
                t ++;
              
            }
        }
        return result;
    }
    int a[5];
    int cnt = 1;
    if(countt == 4){
        for(int i = 0;i < d;i ++){
            for(int j = 0;j < d;j ++){
                if(check[i][j] == 0){
                    a[cnt] = mat[i][j];
                    //cout<<a[cnt]<<" ";
                    cnt++;
                    
                }
                
            }
            
        }
        //cout<<'\n';
      int determinant = a[1] * a[4] - a[2] * a[3];
      //cout<<'\n';
      //cout<<a[1]<<a[2]<<a[3]<<a[4]<<" ";
      //cout<<determinant<<" ";
      return determinant;
    }
    return 0;
    
}
void make_Q(){
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < n;j ++){
            int new_matrix[100][100];
            
            make_new_matrix(new_matrix , i , j);
            int k = pow(-1 , (i + j));
            zero();
            for(int i = 0;i < n - 1;i ++){
                for(int j = 0;j < n - 1;j ++){
                    //cout<<new_matrix[i][j]<<" ";
                }
                //cout<<'\n';
            }
            countt = n * m - n - m + 1;
            int s = det(0, n - 1 , new_matrix);
            q[i][j] = k * s;
            //cout<<s<<" ";
            
            
        }
    }
 
}
void transpose(int n , int m,int arr[][100]){
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            T_matrix[j][i] = arr[i][j];
        }
    }
    
    
}
void  get_input(int n , int m,int matrix[][100]){
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            cin>>matrix[i][j];
        }
    }
}
void add(int n,int m,int mat1[][100],int mat2[][100],int final_mat[][100]){
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                final_mat[i][j] = mat2[i][j] + mat1[i][j];
            }
        }
    
}
void sub(int n , int m , int mat1[][100] , int mat2[][100],int final_mat[][100]){
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            final_mat[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
int multiply(int row,int col,int mat1[][100],int mat2[][100],int final_mat[][100] ,int m){
    int result = 0;
    for(int i = 0;i < m;i ++){
        result += mat1[row][i] * mat2[i][col];
    }
    return result;
}
int main(){
  //getting c   
  cin>>c;
  //sub
  if(c == "sub"){
      cin>>n>>m;
      cin>>n2>>m2;
      int mat1[100][100];
      int mat2[100][100];
      int final_mat[100][100];
      get_input(n , m , mat1);
      get_input(n2 , m2 , mat2);
      if(n == n2 and m == m2){
          sub(n , m , mat1, mat2,final_mat);
          for(int i = 0;i < n;i ++){
              for(int j = 0;j < m;j ++){
                  cout<<final_mat[i][j]<<" ";
              }
              cout<<'\n';
          } 
         
      }
      else{cout<<"it is impossible to sub";};
    }
  //add
  if(c == "add"){
      cin>>n>>m;
      cin>>n2>>m2;
      int mat1[100][100];
      int mat2[100][100];
      int final_mat[100][100];
      get_input(n , m , mat1);
      get_input(n2 , m2 , mat2);
      if(n == n2 and m == m2){
          add(n , m , mat1 , mat2 , final_mat);
          for(int i = 0;i < n;i ++){
              for(int j = 0;j < m;j ++){
                  cout<<final_mat[i][j]<<" ";
              }
              cout<<'\n';
          }
      }
      else{cout<<"it is impossible to add";};
  }
  //determinant
  if(c == "determinant"){
      cin>>n>>m;
      get_input(n , m , matrix);
      if(n != m){
          cout<<"No determinant";
      }
      if(n == m){
          countt = m * n;
          zero();
          cout<<det(0 , n , matrix);
      }
  }
  //inverse
  if(c == "inverse"){
      cin>>m>>n;
      get_input(n , m , matrix);
     if(n != m){
         cout<<"this matrix does not have an inverese";
     }
     if(n == m){
         zero();
         countt = m * n;
         float d =  det(0 , n , matrix);
         if(d == 0){
             cout<<"this matrix does not have an inverese";
             return 0;
         }
         make_Q();
         transpose(n , m , q);
         for(int i = 0;i < n ;i ++){
             for(int j = 0;j < m ;j ++){
                 cout<<q[i][j]<<" ";
             }
             cout<<'\n';
         }
         
         for(int i = 0;i < n;i ++){
             for(int j = 0;j < n;j ++){
                 cout<<T_matrix[i][j] / d<<" ";
             }
             cout<<'\n';
         }
        
     }
  }
  //transpose
  if(c == "transpose"){
      cin>>n>>m;
      get_input(n , m , matrix);
      transpose(n , m , matrix);
      for(int i = 0;i < n;i ++){
          for(int j = 0;j < m;j ++){
              cout<<T_matrix[i][j]<<" ";
          }
          cout<<'\n';
      }
    
  }
   if(c == "multiply"){
        cin>>n>>m;
        cin>>n2>>m2;
        int mat1[100][100];
        int mat2[100][100];
        int final_mat[100][100];
        get_input(n , m , mat1);
        get_input(n2 , m2 , mat2);
        if(m == n2){
            for(int i = 0;i < n;i ++){
                for(int j = 0;j < m2;j ++){
                    final_mat[i][j] = multiply(i , j , mat1 , mat2,final_mat , m);
                }
            }
            for(int i = 0;i < n;i ++){
                for(int j = 0;j < m2;j ++){
                    cout<<final_mat[i][j]<<" ";
                }
                cout<<'\n';
            }
        }
        else{cout<<"it is impossible to multiply";}
        
    }
  
  
  
}