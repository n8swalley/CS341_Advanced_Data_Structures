// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// n8swalley & k8edwards

#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <fstream>
#include "BitVector.h"
#include "Dictionary.h"

int main()
{
    BitVector a = BitVector(3200000);

    std::ifstream fileToReadIn; //input stream handler
    std::string nameOfInputFile = ""; //user input variable for filenamee
    std::ofstream fileToOutput;
    std::cout<<"Please enter the filename to read in: " << std::endl;
    std::cin >> nameOfInputFile;
    int temp(0);
    int freq(0);
    std::vector<int> duplicates;
    std::vector<int> bits;
    std::vector<Dictionary> frequency;
  
    fileToReadIn.open(nameOfInputFile.c_str());
    if(fileToReadIn.fail()) 
    {
        std::cout << "ERROR: file not found" <<std::endl;
    }
    else
    {
        while(!fileToReadIn.eof())
        {
            fileToReadIn >> temp;
            //a.getBit(temp);
           // a.setBit(temp);
            bits.push_back(temp);
            //std::cout<<"here: "<<std::endl;
        } 
    }   

    a.findDuplicates(bits, duplicates);
    
    //Prints out contents of our BitVector
    // for(int i=0; i < bits.size(); i++)
    // {
    //     std::cout<<"Value: " << /*std::bitset<8>(*/ bits[i] << std::endl;
    // }
    fileToReadIn.close();

   // a.findDuplicates(bits, duplicates);

    //Prints out contents of our duplicate vector
    // for(int i=0; i < duplicates.size(); i++)
    // {
    //     std::cout<<"Repeats: " << /*std::bitset<8>(*/ duplicates[i] << std::endl;
    // }
  
    //file output
std::vector<bool> visited(duplicates.size(), false); 
    for (int i = 0; i < duplicates.size(); i++) 
	{ 
        if (visited[i] == true) 
            continue; 

        int count(2); 
		
        for (int j = i + 1; j < duplicates.size(); j++) 
		{ 
            if (duplicates[i] == duplicates[j]) 
			{ 
               visited[j] = true; 
               count++; 
           } 		
}
	    Dictionary newEntry(duplicates[i], count);
	    frequency.push_back(newEntry);
}
	
    fileToOutput.open("duplicates.txt");
    if(fileToOutput.fail())
    {
        std::cout << "ERROR" << std::endl;	
    }
    else 
    {
	
	for(Dictionary entry : frequency)
	{
    
   	 }
		fileToOutput << entry.getID() << " " << entry.getValue() << std::endl;
	}

    }
    return 0;
}
