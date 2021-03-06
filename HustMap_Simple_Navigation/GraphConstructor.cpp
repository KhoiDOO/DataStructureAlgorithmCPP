#include "Graph.h"

Graph::Graph(int v_count) {
    this->vertice_count = v_count;
    dist = new double[vertice_count];
    prev = new int[vertice_count];

    // Initialize the Adjacency Matrix of Graph
    Graph_Adj_Matrix_Init();

    // Initialize the Metadata_content
    Graph_Metadata_Init();

    // Initialize Map of Graph
    Graph_Load_Map();

    // Initialize the Adjacency List
    adj_lst = new list<int>[vertice_count]; // Re init the Adj_Lst
    Graph_Adj_List_Init();

    // Initialize the Detailed Adjacency List
    node_adj_lst = new list<node>[vertice_count];
    Graph_Node_Adj_List_Init();

    // Initialize the Grid Map
    //Graph_Grid_Map_Init();
}

Graph::Graph() {
    vertice_count = 0;

    // Initialize Map of Graph
    Graph_Load_Map();
}

Graph::~Graph() {

}

void Graph::Graph_Adj_Matrix_Init() {
    vector<double> row;
    string line, word;

    fstream file(adj_matrix_path, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(stof(word));
            adj_matrix.push_back(row); 
        }
    }
    else cout << "Could not open the file\n";
}

void Graph::Graph_Adj_List_Init() {
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            if (adj_matrix[i][j] != 0) {
                AddEdge(i, j, false);
            }
        }
    }
}

void Graph::Graph_Node_Adj_List_Init() {
    for (int i = 0; i < adj_matrix.size(); i++) {
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            if (adj_matrix[i][j] != 0) {
                AddEdge(i, j, true);
            }
        }
    }
}

void Graph::Graph_Metadata_Init() {
    vector<string> row;
    string line, word;

    fstream file(meta_path, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            meta_content.push_back(row);
        }
    }
    else cout << "Could not open the file\n";
}

void Graph::Graph_Load_Map() {
    map_img = imread(map_path, IMREAD_COLOR);
}


void Graph::Graph_Grid_Map_Init() {
    vector<int> row;
    string line, word;

    fstream file(adj_matrix_path, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(stoi(word));
            grid_map_img.push_back(row);
        }
    }
    else cout << "Could not open the file\n";
}