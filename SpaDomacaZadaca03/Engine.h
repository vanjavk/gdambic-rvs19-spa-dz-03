#pragma once
#include <map>
#include <list> 
#include <string> 
#include <queue>
#include <vector>
#include <set>
#include "Node.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Engine
{
public:
	bool done = false;
	sf::RenderWindow* window;
	Engine(sf::RenderWindow* window) : window{ window } {}
	void next_selection() { current_selection = ++current_selection == std::end(selection) ? std::begin(selection) : current_selection; }
	void previous_selection() { current_selection = --(current_selection == std::begin(selection) ? std::end(selection) : current_selection); }
	int start_x = 2;
	int start_y = 7;
	int end_x = 19;
	int end_y = 19;
	std::priority_queue<Node*, std::vector<Node*>, Comparator> pq;
	std::list<std::string> selection{ "wall", "start", "end" };
	std::list<std::string>::iterator current_selection = selection.begin();


	std::map <std::pair<int, int>, Node*> checked_nodes;
	std::map <std::pair<int, int>, Node*> closed_nodes;
	std::set <std::pair<int, int>> walls{ { 3,5 },{ 3,6 },{ 3,7 },{ 3,8 },{ 3,9 },{ 3,10 },{ 3,11 },{ 18,18 } ,{ 18,19 }, {15,10},{16,11},{17,12},{17,13} };

	int calc_g_cost(int x, int y) { return 10 * (abs(x - start_x) + abs(y - start_y)); }
	int calc_h_cost(int x, int y) { return 10 * (abs(x - end_x) + abs(y - end_y)); }

	Node* winning_node;
	void print();
	void Place(int x, int y);
	void Remove(int x, int y);

	bool check_nodes(int x, int y);


private:
	void reset();
	std::vector<sf::Vertex> drawings;
	const int kPomak = 33;
	const int kSize = 20;
	int width = 37;
	int height = 26;
};

