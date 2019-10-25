////// Includes //////
#include "../graph.cpp"
#include <iostream>
#include <string>
#include <random>

using namespace std;

double drand() {
    return ((double) rand() / (RAND_MAX)) + 1;
}

////// Tests //////
void test0() {
    /* null test */
    // Create
    vector<struct Node> nodes = {
        Node{"jay"}, 
        Node{"raj"}, 
        Node{"kitav"}, 
        Node{"bhavna"}, 
        Node{"mody"}
    };
    Graph* mygraph = new Graph(nodes);

    mygraph->print();
}
void test1() {
    /* circle test */
    // Create
    vector<struct Node> nodes = {
        Node{"jay"}, 
        Node{"raj"}, 
        Node{"kitav"}, 
        Node{"bhavna"}, 
        Node{"mody"}
    };
    Graph* mygraph = new Graph(nodes);

    mygraph->addEdge(0,1,drand());
    mygraph->addEdge(1,2,drand());
    mygraph->addEdge(2,3,drand());
    mygraph->addEdge(3,4,drand());
    mygraph->addEdge(4,0,drand());

    mygraph->print();
}
void test2() {
    /* sparse test */
    // Create
    vector<struct Node> nodes = {
        Node{"jay"}, 
        Node{"raj"}, 
        Node{"kitav"}, 
        Node{"bhavna"}, 
        Node{"mody"}
    };
    Graph* mygraph = new Graph(nodes);

    mygraph->addEdge(0,1,drand());
    mygraph->addEdge(1,3,drand());
    mygraph->addEdge(2,1,drand());
    mygraph->addEdge(3,0,drand());
    mygraph->addEdge(4,0,drand());
    mygraph->addEdge(0,4,drand());
    mygraph->addEdge(4,1,drand());
    mygraph->addEdge(4,2,drand());

    mygraph->print();
}
void test3() {
    /* dense test */
    // Create
    vector<struct Node> nodes = {
        Node{"jay"}, 
        Node{"raj"}, 
        Node{"kitav"}, 
        Node{"bhavna"}, 
        Node{"mody"}
    };
    Graph* mygraph = new Graph(nodes);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j)
                mygraph->addEdge(i,j,drand());
        }
    }

    mygraph->print();
}
void test4() {
    /* add node test */
    // Create
    vector<struct Node> nodes = {
        Node{"jay"}, 
        Node{"raj"}, 
        Node{"kitav"}, 
        Node{"bhavna"}, 
        Node{"mody"}
    };
    Graph* mygraph = new Graph(nodes);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j)
                mygraph->addEdge(i,j,drand());
        }
    }

    mygraph->print();

    mygraph->addNode("imposter");
    mygraph->addEdge(5,4,drand());
    mygraph->addEdge(4,5,drand());
    mygraph->addEdge(5,1,drand());
    mygraph->addEdge(0,5,drand());

    cout << endl;
    mygraph->print();
}

////// Run Test //////
void run_test(string name, void (*test)()) {
    cout << "############################################################" << endl;
    cout << "##########\t" << name << endl;
    cout << "############################################################" << endl;
    (*test)();
    cout << "\n\n\n";
}

////// Main //////
int main() {
    run_test("NULL TEST", test0);
    run_test("BASIC TEST", test1);
    run_test("SPARSE TEST", test2);
    run_test("DENSE TEST", test3);
    run_test("ADD NODE TEST", test4);
    return 1;
}
