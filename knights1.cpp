#include <iostream>
#include <vector>
#include <stdexcept>
#include <istream>
#include <string>
#include <sstream>

void createChessBoard(std::vector <std::vector<int>>& chessboard, int inputChessboardSize)
{
    for (unsigned int i = 0 ; i < inputChessboardSize ; i++)
    {
        for (unsigned int j = 0 ; j < inputChessboardSize ; j++)
        {
            chessboard[i][j] = 0;
        }
    }
}

int getUserCharInput(char userInput)
{
    return userInput - 'a' + 1;
}

int processUserChessboardSizeInput(std::string userChessboardSizeInput)
{
    std::istringstream inSS;
    int chessboardSize;

    inSS.str(userChessboardSizeInput);
    inSS >> chessboardSize;
    inSS.clear();

    return chessboardSize;
}

void processUserSquareInput(std::string userSquareInput, char userSquareChar,
                            int& userSquareCharButInt, int& userSquareInt)
{
    std::istringstream inSS;

    inSS.str(userSquareInput);
    inSS >> userSquareChar;
    inSS.clear();

    for(unsigned int i = 0 ; i < userSquareInput.size() ; i++)
    {
        char tempVal = userSquareChar;

        if(i != userSquareInput.size() - 1)
        {
            userSquareInput.at(i) = userSquareInput.at(i + 1);
        }

        else
        {
            userSquareInput.at(i) = tempVal;
        }    
    }         

    inSS.str(userSquareInput);
    inSS >> userSquareInt;
    inSS.clear();

    userSquareCharButInt = getUserCharInput(userSquareChar);
}

void checkForInputCorrectness(int chessboardSize, int firstSquareCharButInt, int firstSquareInt,
                              int finalSquareCharButInt, int finalSquareInt) 
{
    if((firstSquareCharButInt > chessboardSize) || (firstSquareInt > chessboardSize) ||
       (finalSquareCharButInt > chessboardSize)  || (finalSquareInt > chessboardSize))
    {
        throw std::runtime_error("invalid parameter list");
    }
            
    if((chessboardSize >= 27) || (chessboardSize <= 0))
    {
        throw std::runtime_error("invalid parameter list");
    }

    if((firstSquareInt < 1) || (firstSquareCharButInt < 1) ||
       (finalSquareInt < 1) || (finalSquareCharButInt < 1))
    {
        throw std::runtime_error("invalid parameter list");
    }
}

bool isValidMove(std::vector <std::vector <int>>& chessboard, int xCoord, int yCoord)
{
    if ((xCoord <= chessboard.size()) && (yCoord <= chessboard.size()) && 
        (xCoord >= 1) && (yCoord >= 1) && (chessboard[xCoord - 1][yCoord - 1] < 1))
    {
        return true;
    } 
    return false;

}

bool findKnightsTour(std::vector <std::vector <int>>& chessboard, int xCoord, int yCoord,
                     const int finalSquareCharButInt, const int finalSquareInt, int numSteps)
{
    std::vector <int> xCoordMoves = { 1,  2, 2, 1, -1, -2, -2, -1};
    std::vector <int> yCoordMoves = {-2, -1, 1, 2,  2,  1, -1, -2};
    chessboard[xCoord - 1][yCoord - 1] = numSteps;
    
    if((xCoord == finalSquareCharButInt) && (yCoord == finalSquareInt))
    {
        return true;
    }
    else
    {
        for (unsigned int i = 0 ; i < xCoordMoves.size() ; i++)
        {
            xCoord = xCoord + xCoordMoves.at(i);
            yCoord = yCoord + yCoordMoves.at(i);

            if(isValidMove(chessboard, xCoord, yCoord)) 
            {   
                chessboard[xCoord - 1][yCoord - 1] = numSteps; 
                
                bool success = findKnightsTour(chessboard, xCoord, yCoord, finalSquareCharButInt,
                                               finalSquareInt, numSteps + 1);

                if(success)
                {   
                    return true;
                }  
            
                else
                {
                    chessboard[xCoord - 1][yCoord - 1] = 0;
                }    
            }

            xCoord -= xCoordMoves.at(i);
            yCoord -= yCoordMoves.at(i);
        }    
    }
    return false;    
}

void printKnightsTour(int chessboardSize, std::vector <std::vector<int>> chessboard)
{
    int numVisits = 1;
    bool isPrinted;
    do
    {   isPrinted = false; 
        for (int i = 0 ; i < chessboardSize ; i++)
        {
            for (int j = 0 ; j < chessboardSize ; j++)
            {
                if(chessboard[i][j] == numVisits)
                {  
                    std::cout << char(i + 97) << j + 1 << " "; 
                    numVisits++;
                    isPrinted = true;
                }
            }

        }        
    } while(isPrinted);
}

int main(int argc, char* argv[])
{
    try
    { 
        if (argc == 4)
        {
            std::string chessboardSizeInput = argv[1];
            std::string firstSquareInput = argv[2];
            std::string finalSquareInput = argv[3];

            char firstSquareChar;
            char finalSquareChar;
            int firstSquareInt;
            int firstSquareCharButInt;
            int finalSquareInt;
            int finalSquareCharButInt;
            int chessboardSize = processUserChessboardSizeInput(chessboardSizeInput);
            bool isFound = false;

            processUserSquareInput(firstSquareInput, firstSquareChar,
                                   firstSquareCharButInt, firstSquareInt);
            processUserSquareInput(finalSquareInput, finalSquareChar,
                                   finalSquareCharButInt, finalSquareInt);
                                   
            std::vector <std::vector<int>> chessboard(chessboardSize, std::vector<int>(chessboardSize));

            createChessBoard(chessboard, chessboardSize);

            checkForInputCorrectness(chessboardSize, firstSquareCharButInt, firstSquareInt,
                                     finalSquareCharButInt, finalSquareInt);

            isFound = findKnightsTour(chessboard, firstSquareCharButInt, firstSquareInt,
                                      finalSquareCharButInt, finalSquareInt, 1);

            if(isFound)
            {
                printKnightsTour(chessboardSize, chessboard);
            }

            else
            {
                std::cout << "could not find a knight's tour" << std::endl;
            }      
        }  
        
        else
        {
            throw std::runtime_error("invalid parameter list");
        }
    } 
    catch(std::runtime_error& error1)
    {
        std::cout << error1.what() << std::endl;
    }
    return 0;
}
