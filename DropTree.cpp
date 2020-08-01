// DropTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int64_t N, P[800000], H[800000];

int main()
{
    int64_t leftpos, rightpos, maxlen, globalmax, i, j;
   // N = 3;
   // P[0] = 0; H[0] = 5;  // position 0, height 5
   // P[1] = 9; H[1] = 3; // position 9, height 3
   // P[2] = 2; H[2] = 6; // position 2, height 6


    N = 5;
    P[0] = 3; H[0] = 2;  
    P[1] = 2; H[1] = 8; 
    P[2] = -4; H[2] = 5;
    P[3] = 8; H[3] = 5;
    P[4] = 1; H[4] = 4;

    std::cout << "Tree intervals\n";
    globalmax = 0;
    // first tree fall to right
    for (j = 0; j < N; j++)
    {
       leftpos = P[j];
       rightpos = H[j] + P[j]; // first tree fall to right
       maxlen = H[j];
       for (int i = 0; i < N; i++)
       {
          if (P[i] - H[i] == rightpos) // falls to left matches rightpos
          {
              maxlen = maxlen + H[i];
              rightpos = rightpos + H[i];
          }
          else if (H[i] + P[i] == leftpos) // falls to right matches leftpos
          {
              maxlen = maxlen + H[i];
              leftpos = leftpos - H[i];
          }
       }
       if (maxlen > globalmax)
       {
           globalmax = maxlen;
       }


       rightpos = P[j];
       leftpos = P[j] - H[j]; // first tree fall to left
       maxlen = H[j];
       for (int i = 0; i < N; i++)
       {
           if (P[i] - H[i] == rightpos) // falls to left matches rightpos
           {
               maxlen = maxlen + H[i];
               rightpos = rightpos + H[i];
           }
           else if (H[i] + P[i] == leftpos) // falls to right matches leftpos
           {
               maxlen = maxlen + H[i];
               leftpos = leftpos - H[i];
           }
       }
       if (maxlen > globalmax)
       {
           globalmax = maxlen;
       }
    }
    std::cout << globalmax;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
