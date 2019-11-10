#ifndef GRAPH_ASSIGNMENT_KARGER_H
#define GRAPH_ASSIGNMENT_KARGER_H

#include <cassert>
#include <sstream>
#include <fstream>

#include "kargerMinCut.txt"

inline void runKargerAssignment(unsigned int repeated_times=1000) 
{

  cout << "\n" << string(80, '-') << "\n" << string(80, '-') << endl;

  typedef long weight_t;
  UndirectedGraph<weight_t> graph;

  string line;
  // create an input file stream
  ifstream ifs("../data/kargerMinCut.txt", std::ifstream::in);

  cout << "Run the random contract for " << repeated_times << " times..." << endl;
  // read the file line by line and put the line into a string
  while ( getline(ifs, line) ) 
  {
    istringstream iss(line);
    string number;

    // read the first entry in a line
    iss >> number;
    size_t src = stoull(number) - 1;
    cout << src << endl;
    // read the rest entries
    while ( iss >> number ) {
      size_t dst = std::stoull(number) - 1;
      cout << dst << endl;
      graph.connect(src, dst);
    }
  }
  ifs.close();
  cout << "Finished reading data!" << endl;

  clock_t t0 = clock();
  assert(karger(graph, repeated_times) == 20);
  cout << "Run time: "<< 1000.0*(clock() - t0)/CLOCKS_PER_SEC << " ms" << endl;
  cout << "Passed!" << endl;
}

#endif //GRAPH_ASSIGNMENT_KARGER_H
