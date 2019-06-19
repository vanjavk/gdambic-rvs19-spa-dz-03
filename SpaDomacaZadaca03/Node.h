#pragma once
struct Node
{


	Node* points_at = nullptr;
	bool path = false;
	int x, y, g_cost, h_cost, f_cost;
	Node(int x, int y, int g_cost, int h_cost, int f_cost, Node* points_at) : x{ x }, y{ y }, g_cost{ g_cost }, h_cost{ h_cost }, f_cost{ f_cost }, points_at{ points_at }{}
	Node(int x, int y, int g_cost, int h_cost, Node* points_at) : x{ x }, y{ y }, g_cost{ g_cost }, h_cost{ h_cost }, f_cost{ g_cost+h_cost}, points_at{ points_at }{}
	void calc_f_cost();
};

struct Comparator
{
	bool operator ()(const Node* a, const Node* b) { return a->f_cost == b->f_cost ? a->h_cost > b->h_cost : a->f_cost > b->f_cost; }
};

