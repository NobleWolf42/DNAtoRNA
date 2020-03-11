//This C++ Program is a program that shows how long it takes for DNA to become an oligopeptide
//Dillon Britt
//

#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>
#include <math.h>       /* pow */
#include <algorithm>    // std::count
#include <cstdio>
#include <ctime>

std::vector<char> DNA( int DNA_sequence_length)
{
    //DNA is made of nucleotides; Each nucleotide contains a phosphate group, a sugar group and a nitrogen base.
    //The four types of nitrogen bases are adenine (A), thymine (T), guanine (G) and cytosine (C).
    //The order of these bases is what determines DNA's instructions, or genetic code.
    int i;
    std::vector<char> DNA_letters;
    DNA_letters.push_back('A');//when i = 0, it is adenine
    DNA_letters.push_back('C');//when i = 1, it is cytosine
    DNA_letters.push_back('T');//when i = 2, it is thymine
    DNA_letters.push_back('G');//when i = 3, it is guanine

    std::vector<char> DNA_sequence;
    std::cout << "DNA input code :  ";
    srand (time(NULL));
    int random;
    for(i = 1; i <= DNA_sequence_length; i++)
    {
        random = rand() % 4 ;

        char random_char = DNA_letters[random];
        std::cout << random_char;
        DNA_sequence.push_back(random_char);
    }
    std::cout << "\nRandom Number = " <<random << "\n";
    std::cout << " with a length of " << i - 1<< "\n";
    return DNA_sequence;
}

std::vector<char> DNA_RNA(std::vector<char> DNA_sequence)
{
    //Function gets the DNA from the DNA function and turns it into RNA
    //
    std::vector<char> RNA_strand;
    int size = DNA_sequence.size();
    int i = 0;
    std::cout << "RNA output code : ";
    std::clock_t start_timer, end_timer;
    start_timer = std::clock();
    for( ; i < size; i++ )
        {
            char DNA_char_sequence = DNA_sequence[i];
            RNA_strand.push_back(DNA_char_sequence);
            char RNA = RNA_strand[i];

            if(RNA == 'G')
                {
                    RNA = 'C';
                }

            else if(RNA =='C')
                {
                    RNA = 'G';
                }

            else if(RNA == 'T')
                {
                    RNA = 'A';
                }
            else if(RNA == 'A')
                {
                    RNA = 'U';
                }

                RNA_strand[i] = RNA;
            std::cout << RNA;
        }
        end_timer = std::clock();
        double total = end_timer - start_timer;
        double dur = (total)/(double)CLOCKS_PER_SEC;
        std::cout << "\n Time taken = " << dur << "\n";
    return RNA_strand;
}

std::vector<std::string> Amino_acid()
{
    //This is a list of all the twenty Amino acids that are used in this process
    std::vector<std::string>Amino_acid;
    std::vector<std::string> New_Amino_list;

    Amino_acid.push_back("non");//0
    Amino_acid.push_back("Arg");//1
    Amino_acid.push_back("Lys");//2
    Amino_acid.push_back("Asp");//3
    Amino_acid.push_back("Glu");//4
    Amino_acid.push_back("Gln");//5
    Amino_acid.push_back("Asn");//6
    Amino_acid.push_back("His");//7
    Amino_acid.push_back("Ser");//8
    Amino_acid.push_back("Thr");//9
    Amino_acid.push_back("Tyr");//10
    Amino_acid.push_back("Cys");//11
    Amino_acid.push_back("Met");//12
    Amino_acid.push_back("Trp");//13
    Amino_acid.push_back("Ala");//14
    Amino_acid.push_back("Ile");//15
    Amino_acid.push_back("Leu");//16
    Amino_acid.push_back("Phe");//17
    Amino_acid.push_back("Val");//18
    Amino_acid.push_back("Pro");//19
    Amino_acid.push_back("Gly");//20



    int size = Amino_acid.size();
    for(int i = 1; i < size ; i++)
        {
            std::cout << Amino_acid[i] << " Number  = " << i << "\n";
        }



    int number_picked;
    int count = 1;
    for( ;count <=20 ; count ++)
        {
            std::cout << "Pick an Amino Acid Number (Press zero when you are done picking Amino Acids), 1 - 20 : ";
            std::cin>> number_picked;

            if(number_picked == 0)
                {
                    break;
                }

            while(number_picked < 0 || number_picked > 20)
            {
                std::cout << "Please pick a valid number : ";
                std::cin >> number_picked;

            }
            std::string new_amino_acid_string = Amino_acid[number_picked];
            New_Amino_list.push_back(new_amino_acid_string);
        }



    return New_Amino_list;
}

std::vector<std::string> Codon ( std::vector<char> RNA_strand, std::vector<std::string> sum_returned)
{
    //DNA and RNA is broken up into little three link chains,
    //For the program, only need to do this for the RNA
    int i = 0;
    int b = -1;
    int size = RNA_strand.size();
    //Divides them up into codons
    std::string sum;
    std::vector<std::string>Codon_string;
    Codon_string.resize(size + 1);

    for( ; i <= size ; i++)
    {


        if(i  % 3 == 0)
            {
                b = b + 1;
                std::string one, two, three;
                one = one.append(1, RNA_strand[i]);
                two = two.append(1, RNA_strand[i + 1]);
                three = three.append(1, RNA_strand[i + 2]);
                sum = one + two + three;
                Codon_string[i] = sum;
                std::cout << "\n" << Codon_string[i] << "\n";
                if(Codon_string[i] == "TAG" || Codon_string[i] == "TAA" || Codon_string[i] == "TGG" || Codon_string[i] == "TGA")
                        break;
            }

    }



    Codon_string = sum_returned;
    return  sum_returned;
}

std::vector<char> Ribosome(std::vector<std::string> RNA_Codon, std::vector<std::string> Amino_acid_list)
{
    //The ribosome is a large and complex molecular machine, found within all living cells, that serves as the primary site of biological protein synthesis (translation).
    //Ribosomes link amino acids together in the order specified by messenger RNA (mRNA) molecules.
    for(int i = 0; ; i++)
        {

        }

}
void time_taken(std::vector<std::string> Amino_acid_list, std::vector<char> RNA)
    {
        int num_C = std::count(RNA.begin(), RNA.end(), 'C');
        int num_G = std::count(RNA.begin(), RNA.end(), 'G');
        int num_A = std::count(RNA.begin(), RNA.end(), 'A');
        int num_U = std::count(RNA.begin(), RNA.end(), 'U');
        std::cout << "\nNumber of C's : " << num_C << "\n";
        std::cout << "\nNumber of G's : " << num_G << "\n";
        std::cout << "\nNumber of A's : " << num_A << "\n";
        std::cout << "\nNumber of U's : " << num_U << "\n";
        double RNA_size = RNA.size();
        double Amino_acid_size = Amino_acid_list.size();
        float Precent_of_amino_chain_chance;
        float precent_of_one_Amino_acid = 1/Amino_acid_size;
        int i = 1;
        float max_time = 1;
        for( ; i<= RNA_size; i++)
            {

                Precent_of_amino_chain_chance = pow(precent_of_one_Amino_acid, i);

            }
        for( i = 1; i<= RNA_size; i++)
            {
                max_time = max_time*i;
            }
        std::cout << "\nChance of randomly picking DNA/RNA letters : " << Precent_of_amino_chain_chance*(3.0/4.0) << "\n";
        //the max time is n!/(n - r)! * RNA_size
        //There are 24 ways to pick the three letters out of 4 letters to form the codon.
        //So 24 * how many there are, RNA_size,
        int a = 24 * (RNA_size/3);
        max_time = max_time * a;
        std::cout << "\nMax amout of time it will take to randomly pick the DNA/RNA : " << max_time << " in seconds \n";

    }

int main()
{
    for(int i = 0; ; i++)
    {
    std::cout << "Press Enter\n";
    std::cin.ignore();
    std::vector<std::string> Amino_acid_list = Amino_acid();//You pick the amino acids and returns the vectors of elements you have chosen
    int DNA_sequence_length = Amino_acid_list.size() * 3;
    std::vector<char> DNA_sequence = DNA(DNA_sequence_length);
    std::vector<char> RNA;

    RNA = DNA_RNA(DNA_sequence);
    std::vector<std::string> sum_returned;
    std::vector<std::string>RNA_Codon =  Codon ( RNA, sum_returned);
    //Ribosome(RNA_Codon, Amino_acid_list);
    time_taken(Amino_acid_list, RNA);

    }
}
