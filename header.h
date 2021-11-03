#ifndef HEADER_H
#define HEADER_H
struct Matrix{
    string name;
    bool is_integer = false;
    int row,column;
    bool isfull =false;
    union type{
        int ** int_memeber;
        string ** str_member;
    }matrixType;
};
void help();
vector<string> brain(string , vector<string > ,char );
bool isInteger(string );
void getMatrixSize(string ,string ,int size[]);
Matrix getMatrix(vector<string >str);
Matrix addMatrix(vector<string >str);
int isDiagonal(Matrix * mat , string str);
void isIdentify(Matrix * mat,string str);
bool triangular(Matrix * mat , string str , int i);
void triangular(Matrix * mat , string str);
void edit(Matrix *mat,vector<string>str );
void show(Matrix mat);
void showAll(Matrix *mat , vector<string >&str);
template<typename T>
bool isSymmetic(Matrix mat, T** a);
void symmetric(Matrix * mat , string name);
vector<string> getCommand();
template<typename T>
void shift(Matrix *mat, T a ,int j);
void deletmatrix(Matrix * mat ,string name);


#endif // !HEADER_H#def" "" 
