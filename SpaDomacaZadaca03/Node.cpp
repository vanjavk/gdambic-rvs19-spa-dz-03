#include "Node.h"

void Node::calc_f_cost()
{
	f_cost = g_cost + h_cost;
}
