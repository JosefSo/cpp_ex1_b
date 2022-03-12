#include "mat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

constexpr int MIN_VALUE = 33;
constexpr int MAX_VALUE = 126;
constexpr int FLAG_ELSE = 1;

using namespace std;
namespace ariel
{
    void transpose(vector<vector<char>> &transp, vector<vector<char>> &matrix, int row, int col){
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                transp[j][i] = matrix[i][j];
            }
        }
        //return transp;
    } 
    void init(vector<vector<char>> &matrix, int row, int col, char symbol1, char symbol2){
        for (int i = 0; i<row; i++){
            for (int j = 0; j<col; j++){
                int flag = 1;
                if (i <= row/2 && matrix[i][j] != symbol1)
                {
                    if (i%2 == 0 && j>=i && j<=col-(i+1)){
                        matrix[i][j] = symbol1;
                        flag = 0;
                    }
                    if (j==0 && flag == 1){
                        matrix[i][j] = symbol1;
                        flag = 0;
                    }
                    if (j==col-1 && flag == 1){
                        matrix[i][j] = symbol1;
                        flag = 0;
                    }
                    if(flag == 1){
                        matrix[i][j] = symbol2;
                    }
                }
                else if (matrix[i][j] != symbol1)
                {
                    if (i%2 == 0 && j>=row-(i+1) && j<=col-(row-i)){
                        matrix[i][j] = symbol1;
                        flag = 0;
                    }
                    if (j==0 && flag == 1){
                        matrix[i][j] = symbol1;
                        flag = 0;
                    }
                    if (j==col-1 && flag == 1){
                        matrix[i][j] = symbol1;
                        flag = 0;
                    }
                    if(flag == 1){
                        matrix[i][j] = symbol2;
                    }
                }
            }
        }
        //return matrix;
    }

    string mat(int col, int row, char symbol1, char symbol2)
    {
        string ans;

        if (row % 2 == 0 || col % 2 == 0)
        {
            throw runtime_error("Mat size is always odd");
        }
        if (row == 0 || col == 0)
        {
            throw runtime_error("Mat size is always non-zero");
        }
        if (row < 0 || col < 0)
        {
            throw runtime_error("Mat size is always positive");
        }
        if (symbol1 < MIN_VALUE  || symbol2 < MIN_VALUE || symbol1 > MAX_VALUE || symbol2 > MAX_VALUE)
        {
            throw runtime_error("wrong symbol values");
        }
        // else if (symbol1 == symbol2)
        // {
        //     throw runtime_error("Entered wrong values: symbol1 and symbol2 need be a different symbols");
        // }
        if(FLAG_ELSE==1)
        {
            //CREATE  MATRIX
            vector<vector<char>> matrix( row, vector<char>( col ) );
            // char** matrix = new char*[row];
            // for (int i = 0; i < row; ++i)
            //     matrix[i] = new char[col];
            //CALL INIT FUNC
            init(matrix, row, col, symbol1, symbol2);

            //CREATE TRANSP MATRIX
            vector<vector<char>> transp( col, vector<char>( row ) );
            // char** transp = new char*[col];
            // for (int i = 0; i < col; ++i)
            //     transp[i] = new char[row];
            //CALL TRANSPOSE FUNC    
            transpose(transp, matrix, row, col);
            
            //CALL INIT FUNC
            init(transp, col, row, symbol1, symbol2);

            //CALL TRANSPOSE FUNC    
            transpose(matrix, transp, col, row);

            //CONVERSE MARIX TO STRING
            for (int i = 0; i<row; i++){
                for (int j = 0; j<col; j++){
                    ans += matrix[i][j];
                }
                ans +="\n";
            }

            
        }
        return ans;
    }
}
