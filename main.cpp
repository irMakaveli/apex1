#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>
#include <limits.h>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Matrix{
    string name;
    bool is_integer = false;
    int row,column;
    bool isfull =false;
    union type{
        int ** int_memeber;
        string ** str_member;
    }matrixType;
};///  matrix = new Matrix[1000];
void help(){
    cout<<"enetr your command:"<<endl
        <<"add matrix : adding a matrix"<<endl
        <<"like :\nadd matrix matrix_name"<<endl
        <<"add matrix matrix_name [size] or add matrix matrix_name [size][size]"<<endl
        <<"add matrix matrix_name [size] [parametr,parametr,...]"<<endl;

}
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\######///////////////////////////////////////
vector<string> brain(string str, vector<string > &d,char delim)
{
    
    string temp;   
    for (size_t i = 0,j =0 ;i <= str.size(); i++)
    {
        if(delim==',')
        {
            if(str[i]=='['||str[i]==']')
            {
                str[i]=',';
            }
        }
        if(str[i]!=delim && str[i]!='\0' )
        {
            temp+=str[i];
        }
        else if(temp!=""){    

            d.push_back(temp);
            temp.erase();
        }
    }
 
    return d;
}

bool isInteger(string str)
{
    vector<string> s;
    bool intg =true;
    s = brain(str ,s,','); 
    for (size_t i = 0; s[0][i]!='\0'; i++)
    {
       
       if(!(s[0][i]>='0' && s[0][i] <='9'))
       { cout<<"n :"<<s[0][i]<<endl;
           intg = false;
           return false;
       }   
    }
   
    {
        return true;
    }
    
    
}
void getMatrixSize(string str1,string str2,int *size)
{
    stringstream(str1)>>size[0];
    cout<<"str2:"<<str2<<endl;
    if(isInteger(str2)==true)
    {
        stringstream(str2)>>size[1];
        cout<<"jh"<<endl;
        return ;
    }
  
            size[1]=size[0];

    
    cout<<size[0]<<size[1]<<endl;
}
Matrix getMatrix(vector<string >str,Matrix &mat1)
{
    int size[2] ;
    if(str.size()==5)
    {
    getMatrixSize(str[3],str[3],size);

    }
    else{
    getMatrixSize(str[3],str[4],size);

    }

    mat1.name = str[2];
    mat1.isfull=true;
    mat1.row=size[0];
    mat1.column=size[1];
    vector<string>str1;
    str1= brain(str[str.size()-1],str1,',');  
               cout<<str[str.size()-1]<<"\t"<<size[0]<<size[1]<<endl;
    int c = 0;
    mat1.is_integer=true;
    for(int i = 0 ; i<str1.size();i++)
    {
        if(isInteger(str1[i])!=true)
        {
            mat1.is_integer=false;
            break;
        }
    }
    if(mat1.is_integer)
    {
        mat1.matrixType.int_memeber= new int* [size[0]];
        for (size_t i = 0; i < size[0]; i++)
        {
           mat1.matrixType.int_memeber[i]=new int [size[1]];
        }
        for (size_t i = 0; i <size[0]; i++)
        {
            for (size_t j = 0; j < size[1]; j++)
            {
                stringstream(str1[c])>>mat1.matrixType.int_memeber[i][j];
                c++;
                cout<<mat1.matrixType.int_memeber[i][j]<<endl;
            }                 
        }
        return mat1;            
    }
    else
    {
        mat1.matrixType.str_member= new string* [size[0]];
        for (size_t i = 0; i < size[0]; i++)
        {
           mat1.matrixType.str_member[i]=new string [size[1]];
        }
        for (size_t i = 0; i <size[0]; i++)
        {
            for (size_t j = 0; j < size[1]; j++)
            {
                mat1.matrixType.str_member[i][j] = str[c];
                c++;
            }                 
        }
        return mat1;            
    }
}
Matrix addMatrix(vector<string >str,Matrix &mat)
{
    int i = str.size();
    if(i==2)
    {
        string s;
        cout<<"enter matrix name -->";
        getline(cin , s);
        str = brain(s ,str, ' ');
        return addMatrix(str,mat);
    }
    if(i==3)
    {
        string s;
        cout<<"enter matrix size -->";
        getline(cin , s);
        int s1 = str.size();
        str = brain(s ,str, ' ');
        int s2 = str.size();
        if(s2-s1==1)
        {
            //cout<<s2-s1<<s<<endl;
            str.push_back(s);
            return addMatrix(str,mat);
        }
        else{
            return addMatrix(str,mat);
        }
    }
    if(i==4)
    {
        str=brain(str[3],str,' ');
        return addMatrix(str,mat);
    }
    if(i==5)
    {
        string parametrs;
        if(str[4][0]=='[')
        {
            cout<<"ya ali"<<endl;
            return getMatrix(str,mat);
        }          
        else
        {
            cout<<"enter parametrs -->";
            fflush(stdin);

            getline(cin,parametrs);
            if(parametrs[0]=='[')
            {
                str.push_back(parametrs);
                return addMatrix(str,mat);
            }
            else
            { 
           
            int row;// =4;
            int column;//stoi(str[5]);
            stringstream(str[3])>>row;
            stringstream(str[4])>>column;
            mat.row=row;
            mat.column=column;
            mat.isfull=true;
            string param[row][column]; 
            for (int i = 0; i < row; i++)
            {
                for(int j = 0 ; j < column; j++)
                {
                    if(i==0&&j==0)
                    {

                        param[0][0]=parametrs;
                        if(isInteger(param[0][0])==true)
                        {
                            mat.is_integer=true;
                        }
                        else
                        {
                            mat.is_integer=false;
                        }
                        continue;
                    }
                     cout<<"enter parametrs -->";
                     getline(cin,param[i][j],'\n');
                }
            }
            if (mat.is_integer==true)
            {
                mat.matrixType.int_memeber= new int *[row];
                for(int i = 0 ; i < row ; i++)
                {
                    mat.matrixType.int_memeber[i] = new int [column];
                }
                for (size_t i = 0; i < row; i++)
                {
                    for(int j = 0; j < column ; j++)
                    {
                       stringstream(param[i][j])>> mat.matrixType.int_memeber[i][j];// = stoi(param[i][j]);
                    }
                }
                mat.name = str[2];
                mat.isfull=true;
                return mat;
             ///////////////////////////template & overload////////////////////////////   
            }
            else{
                 mat.matrixType.str_member = new string* [row];
                for(int i = 0 ; i < column ; i++)
                {
                    mat.matrixType.str_member[i] = new string [column];
                }
                for (size_t i = 0; i < row; i++)
                {
                    for(int j = 0; j < column ; j++)
                    {
                        mat.matrixType.str_member[i][j] = param[i][j];
                    }
                }
                mat.name = str[2];
                mat.isfull=true;
                return mat;
            }
          }
        }
        
    }
    else
    {    
        
        return getMatrix(str,mat);   
    }

}
int isDiagonal(Matrix * mat , string str)
{
      bool diagonal = true;
      bool identify = true;
      for(int i = 0;diagonal==true && mat[i].isfull  ;i++)
      {
        if(str==mat[i].name)
        {
            if(mat[i].row != mat[i].column)
            {
                cout<<str<<" is not diagonall"<<endl;
                return 1;
            }
            if(mat[i].is_integer==true)
            {
                for (size_t j = 0; diagonal==true && j < mat[i].row; j++)
                {
                    for(int k = 0; k< mat[i].column ; k++)
                    {
                        if(k==j)
                        {
                            if(identify==true && mat[i].matrixType.int_memeber[j][k]!= 1){
                            identify = false;
                            
                             }
                            continue;
                        }
                        else if(mat[i].matrixType.int_memeber[i][j]!=0){
                            diagonal = false;
                            break;
                        }
                    }
               }
            }
            else{
                for (size_t j = 0; diagonal==true && j < mat[i].row; j++)
                {
                    for(int k = 0; k< mat[i].column ; k++)
                    {
                        if(k==j )
                        {
                            if(identify==true && mat[i].matrixType.str_member[j][k]!=mat[i].matrixType.str_member[0][mat[i].column-1]){
                            identify = false;
                            
                             }
                            continue;
                        }
                        else if(mat[i].matrixType.str_member[i][j]!=mat[i].matrixType.str_member[0][mat[i].column-1]){
                            diagonal = false;
                            break;
                         }
                    }
                }
            }
        }
    }

    if(diagonal)
    {
        cout<<str<<" is diagonal"<<endl;
        if(identify==true)
        return 2;

        return 1;
    }
    else{
        cout<<str<<" is not diagonal"<<endl;
        return 1;
    }
}
void isIdentify(Matrix * mat,string str)
{
    if(isDiagonal(mat,str)==2)
    {
        cout<<str<<" is hamani"<<endl;

    }
    else{
        cout<<str<<" is not hamani"<<endl;
    }
}
bool triangular(Matrix * mat , string str , int i)
{
    bool triangular=true;
        if(mat[i].row != mat[i].column)
        {
            return false;
        }
        for(int i = 0 ; mat[i].isfull==true &&  triangular==true;i++)
        {
            if(mat[i].name==str)
            {
                for(int j = 0;j< mat[i].row &&triangular==true; j++)
                {
                    for (size_t k = 0; k < mat[i].column && triangular==true; k++)
                    {
                        
                        if(j<k && i==1)
                        {
                            if((mat[i].matrixType.int_memeber[j][k]!=0 &&mat[i].is_integer==true) ||(mat[i].matrixType.str_member[j][k]!="zero"&&mat[i].is_integer==false))
                            {
                                cout<<str<<" is not lower triangular"<<endl;
                                triangular=false;
                                return triangular;
                            }
                        }
                        else if(j >k && i==2)
                        {
                            if((mat[i].matrixType.int_memeber[j][k]!=0 &&mat[i].is_integer==true) ||(mat[i].matrixType.str_member[j][k]!="zero"&&mat[i].is_integer==false))
                            {
                                cout<<str<<" is not upper triangular"<<endl;
                                triangular=false;
                                return triangular;
                            }   
                        }
                    }
                    
                }
            }
        }
        if(i==1)
        {
         cout<<str<<" is upper triangular"<<endl;   
        }
        if(i==2)
        {
         cout<<str<<" is upper triangular"<<endl;
        }
    return triangular;
}
void triangular(Matrix * mat , string str)
{
    if(triangular(mat,str,1)==true || triangular(mat,str,2)==true)
    {
        cout<<str<<" is triangular"<<endl;
    }
}
void edit(Matrix *mat,vector<string>str )
{
    for (size_t i = 0; mat[i].isfull==true; i++)
    {
        if(mat[i].name == str[1])
        {
            if(mat[i].is_integer==true)
            {
                if(isInteger(str[4])==true)
                {
                    int row,column;
                    stringstream(str[2])>>row;
                    stringstream(str[3])>>column;
                    stringstream(str[4])>>mat[i].matrixType.int_memeber[row][column];
                    cout<<str[1]<<" edited"<<endl;
                    return ;
                }
            }
            else{
                cout<<"wrong validate"<<endl;
                return ;
            }
        }
        else
        {
            int row,column;
            stringstream(str[2])>>row;
            stringstream(str[3])>>column;
            mat[i].matrixType.str_member[row][column] = str[4];
            cout<<str[1]<<" edited"<<endl;
            return ;
        }
    }
    cout<<"I can not find "<<str[1]<<" !!"<<endl;
}
void show(Matrix mat)
{
    cout<<"matrix name : "<<mat.name<<endl;
    
    for(int i = 0 ; i <mat.row ; i++)
    {
        for(int j = 0 ;j < mat.column; ++j)
        {
            if(mat.is_integer==true)
            {
                cout<<left<<setw(7)<<mat.matrixType.int_memeber[i][j];
            }
            else{
                cout<<left<<setw(15)<<mat.matrixType.str_member[i][j];
            }
        }
        cout<<endl;
    }
   
}
void showAll(Matrix *mat , vector<string >&str)
{
    for (size_t i = 0; mat[i].isfull==true; i++)
    {
        cout<<i;
        if(str.size()==2 && str[1]==mat[i].name)
        {
          show(mat[i]);
          return ;
        }
        else if(str.size()==1)
        {
            show(mat[i]);
        }
    }
    
    return;
}
template<typename T>
bool isSymmetic(Matrix mat, T** a)
{
    T mat2[mat.row][mat.column];
    for (size_t i = 0; i < mat.row; i++)
    {
        for(int j = 0; j < mat.column;j++)
        {
            mat2[j][i]=a[i][j];
        }
    }
    bool equal=true;
     for (size_t i = 0; i < mat.row ; i++)
    {
        for(int j = 0; j < mat.column;j++)
        {
            if(mat2[i][j]!=a[i][j])
            {
                return false;
            }
        }
    }
    
        return true;
    

}
void symmetric(Matrix * mat , string name)
{
    bool symmetric=true;
    for(int i = 0 ; mat[i].isfull ; i++)
    {
        if(mat[i].name == name)
        {
            if(mat[i].is_integer==true)
            {
              if(isSymmetic<int>(mat[i] , mat[i].matrixType.int_memeber)==true)
                {
                    cout<<name<<" is symmetric"<<endl;
                }
                else
                {
                 cout<<name<<" is not symmetric"<<endl;   
                }

               
            }
            if(mat[i].is_integer==false)
            {
              if(isSymmetic<string>(mat[i] , mat[i].matrixType.str_member)==true)
                {
                    cout<<name<<" is symmetric"<<endl;
                }
                else
                {
                 cout<<name<<" is not symmetric"<<endl;   
                }

               
            }
            
        }
    }
}
vector<string> getCommand(vector<string>&str){
    string strCommand ="";//="add matrix e 2 2"; 
    cout<<"chizi vared conid\n";
    char ch;
    fflush(stdin);
   for (size_t i = 0; true; i++)
   {
       ch=cin.get();
       if(ch=='\n')
       {
           break;
       }
       strCommand+=ch;
   }
    brain(strCommand,str,' ');
    return str;
}
template<typename T>
void shift(Matrix *mat, T &a ,int j)
{
    for (size_t k = 0; k < mat[j].row; k++)
    {        
       delete []  a[k];//[z];   
    }
    delete [] a;
    if(mat[j+1].isfull)
    {            
        mat[j].row = mat[j+1].row;
        mat[j].name = mat[j+1].name;
        mat[j].column = mat[j+1].column;
        mat[j].is_integer = mat[j+1].is_integer;
        cout<<mat[j].row<<"\t"<<mat[j].column<<"\t"<<mat[j].name<<endl;
        if(!mat[j].is_integer )
        {
            mat[j].matrixType.str_member=new string * [mat[j].row];
            for(int h = 0 ; h < mat[j].row;h++)
            {
                mat[j].matrixType.str_member[h]=new string [mat[j].column];
            }
            for (size_t c = 0; c < mat[j].row; c++)
            {
                for (size_t x = 0; x < mat[j].column; x++)
                {
                    mat[j].matrixType.str_member[c][x] = mat[j+1].matrixType.str_member[c][x];
                }                    
            }
                    
        }
        else{
            mat[j].matrixType.int_memeber=new int * [mat[j].row];
            for(int h = 0 ; h < mat[j].column;h++)
            {
                mat[j].matrixType.int_memeber[h]=new int [mat[j].column];
            }
            for (size_t c = 0; c < mat[j].row; c++)
            {
                for (size_t x = 0; x < mat[j].column; x++)
                {
                    mat[j].matrixType.int_memeber[c][x] = mat[j+1].matrixType.int_memeber[c][x];
                }       
            }
        }
   }
   else
   {
       for (size_t k = 0; k < mat[j].row; k++)
    {        
       delete []  a[k];//[z];   
    }
    delete [] a;            
        mat[j].row = 0;
        mat[j].name = "-0";
        mat[j].column = 0;
        mat[j].is_integer = false;
        mat[j].isfull=false;
    
   }

}

void deletmatrix(Matrix * mat ,string name)
{
    for (size_t i = 0; mat[i].isfull==true; i++)
    {
        if(name == mat[i].name)
        {
            for(int j = i ; mat[j].isfull ; j++)
            {
                if(mat[j].is_integer==true)
                {
                    shift<int **>(mat, mat[j].matrixType.int_memeber,j);
                }
                if(mat[j].is_integer==false)
                {
                    shift<string **>(mat, mat[j].matrixType.str_member,j);
                }
            }
            cout<<"was deleted";
            return;
        }
    }
}
template <typename T>
void invers(T** s ,Matrix &mat)
{
    int number =0;
   
    
    for(int i=0; i<mat.row ; i++)
    {
        for(int j = 0; j < mat.column ; j++)
        {
            if(i<j)
            {    
                T temp = s[i][j];
                s[i][j] = s[j][i];
                s[j][i] = temp;
            }
            
        }
    }
}
void inversing(Matrix * mat,string name)
{
    
    for(int i = 0; mat[i].isfull ;i++)
    {
        if(mat[i].name == name)
        {
            
            if(mat[i].row==mat[i].column && mat[i].row!=1)
            {
                if(mat[i].is_integer)
                {
                    invers<int>(mat[i].matrixType.int_memeber , mat[i]);
                }
                else
                {
                    invers<string>(mat[i].matrixType.str_member , mat[i]);
                }
            }
        }
    }
}
int main()
{   
   
    vector<string>commands;
    int choise;
    Matrix * mat=new Matrix [100];

int i =0;
    while(true){ 
        commands.clear();
        getCommand(commands);
        
        if (commands[0]+commands[1]=="addmatrix")
        {
            mat[i]=addMatrix(commands,mat[i]);
            i++;
                
        }
        if(commands[0]=="is_diagonal")
        {

            isDiagonal(mat,commands[1]);
        }
        if(commands[0]=="is_identify")
        {
            isIdentify(mat,commands[1]);
        }
        if(commands[0].size()>commands[0].find("triangular"))
        {
            if(commands[0]=="is_lower_triangular")
            {
                triangular(mat ,  commands[1] , 1);
            }
            if(commands[0]=="is_upper_triangular")
            {
                triangular(mat ,  commands[1] ,2);
            }
            if(commands[0]=="is_triangular")
            {
                triangular(mat ,  commands[1]);
            }
        }
        if(commands[0]=="edit")
        {
            edit(mat,commands);
        }
        if(commands[0]=="show")
        {
            cout<<"shower"<<endl;
            showAll(mat , commands); 
        }
        if(commands[0]=="delete")
        {
            deletmatrix(mat , commands[1]); 
        }
        if(commands[0].find("symmetric")<commands[0].size())
        {
            if(commands[0]=="is_normal_symmetric")
            {
                symmetric(mat,commands[1]);
            }
        }
   
    }

    help();
   
    return 0;
}