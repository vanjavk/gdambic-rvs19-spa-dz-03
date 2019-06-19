#include "Engine.h"

void Engine::print(){
	sf::Color boja = sf::Color(255, 255, 255);
	sf::Color crvena = sf::Color(255, 0, 0);
	sf::Color zelena = sf::Color(0, 255, 0);

	sf::Color plava = sf::Color(0, 0, 255);
	sf::Color tamnoplava = sf::Color(0, 0, 150);

	sf::Color siva = sf::Color(150, 150, 150);

	//gornji rub
	drawings.emplace_back(sf::Vector2f(0, kPomak), boja);
	drawings.emplace_back(sf::Vector2f(0, kPomak + kSize), boja);
	drawings.emplace_back(sf::Vector2f(kSize * (width + 2), kPomak + kSize), boja);
	drawings.emplace_back(sf::Vector2f(kSize * (width + 2), kPomak), boja);

	//donji rub
	drawings.emplace_back(sf::Vector2f(0, (height + 1)*kSize + kPomak), boja);
	drawings.emplace_back(sf::Vector2f(0, (height + 1)*kSize + kPomak + kSize), boja);
	drawings.emplace_back(sf::Vector2f(kSize * (width + 2), (height + 1)*kSize + kPomak + kSize), boja);
	drawings.emplace_back(sf::Vector2f(kSize * (width + 2), (height + 1)*kSize + kPomak), boja);

	//lijevi rub
	drawings.emplace_back(sf::Vector2f(0, kPomak + kSize), boja);
	drawings.emplace_back(sf::Vector2f(0, kPomak + kSize + kSize * height), boja);
	drawings.emplace_back(sf::Vector2f(kSize, kPomak + kSize + kSize * height), boja);
	drawings.emplace_back(sf::Vector2f(kSize, kPomak + kSize), boja);

	//desni rub
	drawings.emplace_back(sf::Vector2f(kSize * width + kSize, kPomak + kSize), boja);
	drawings.emplace_back(sf::Vector2f(kSize * width + kSize, kPomak + kSize + kSize * height), boja);
	drawings.emplace_back(sf::Vector2f(kSize * width + kSize * 2, kPomak + kSize + kSize * height), boja);
	drawings.emplace_back(sf::Vector2f(kSize * width + kSize * 2, kPomak + kSize), boja);

	sf::Font font;
	font.loadFromFile("consola.ttf");
	
	
	
	for (auto it : walls) {
		int i = it.first;
		int j = it.second;
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize), siva);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize * 2), siva);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize * 2), siva);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize), siva);

	}


	for (auto it : closed_nodes) {
		int i = it.second->x;
		int j = it.second->y;
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize), crvena);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize * 2), crvena);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize * 2), crvena);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize), crvena);

	}


	for (auto it : checked_nodes) {
		int i = it.second->x;
		int j = it.second->y;
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize), zelena);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize * 2), zelena);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize * 2), zelena);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize), zelena);

	}

	//start
	{
		int i = start_x;
		int j = start_y;
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize), tamnoplava);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize * 2), tamnoplava);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize * 2), tamnoplava);
		drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize), tamnoplava);
	}
	{
	int i = end_x;
	int j = end_y;
	drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize), tamnoplava);
	drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize * 2), tamnoplava);
	drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize * 2), tamnoplava);
	drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize), tamnoplava);
	}

	if (done == true) {
		Node* node = winning_node;
		while (node != nullptr) {
			int i = node->x;
			int j = node->y;
			drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize), plava);
			drawings.emplace_back(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize * 2), plava);
			drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize * 2), plava);
			drawings.emplace_back(sf::Vector2f(j*kSize + kSize * 2, kPomak + kSize * i + kSize), plava);
			node = node->points_at;
		}

	}



	window->draw(&drawings[0], drawings.size(), sf::Quads);
	for (auto it : closed_nodes) {
		int i = it.second->x;
		int j = it.second->y;
		sf::Text text(std::to_string(it.second->g_cost/10), font);
		text.setCharacterSize(15);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize));
		window->draw(text);

	}


	for (auto it : checked_nodes) {
		int i = it.second->x;
		int j = it.second->y;
		sf::Text text(std::to_string(it.second->g_cost / 10), font);
		text.setCharacterSize(15);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(j*kSize + kSize, kPomak + kSize * i + kSize));
		window->draw(text);

	}


	drawings.clear();
}

void Engine::Place(int x, int y)
{
	reset();
	int i = (y - kPomak - kSize) / kSize;
	if (i < 0 || i >= height || y - kPomak - kSize < 0)
		return;
	int j = (x - kSize) / kSize;
	if (j < 0 || j >= width || x - kSize < 0)
		return;
	std::cout << i << " " << j << std::endl;

	if (*current_selection == "wall") {
		if (i == start_x && j == start_y) {
			start_x = -1;
			start_y = -1;
		}
		if (i == end_x && j == end_y) {
			end_x = -1;
			end_y = -1;
		}
		walls.emplace(i,j);
	}else if (*current_selection == "start") {
		if (i == end_x && j == end_y) {
			end_x = -1;
			end_y = -1;
		}
		if (walls.count({ i,j }) != 0) {
			walls.erase({ i,j });
		}
		start_x = i;
		start_y = j;
		
	}
	else if (*current_selection == "end") {
		if (i == start_x && j == start_y) {
			start_x = -1;
			start_y = -1;
		}
		if (walls.count({ i,j }) != 0) {
			walls.erase({ i,j });
		}
		end_x = i;
		end_y = j;
	}
}

void Engine::Remove(int x, int y)
{
	reset();
	int i = (y - kPomak - kSize) / kSize;
	int j = (x - kSize) / kSize;
	if (i == start_x && j == start_y) {
		start_x = -1;
		start_y = -1;
	}
	if (i == end_x && j == end_y) {
		end_x = -1;
		end_y = -1;
	}
	if (walls.count({ i,j }) != 0) {
		walls.erase({ i,j });
	}

}

bool Engine::check_nodes(int x, int y)
{

	if (start_x == -1 || end_x == -1)
		return false;


	x = x == -1 ? start_x : x;
	y = y == -1 ? start_y : y;
	int temp_g_cost = 0;
	Node* current_node;
	Node* nearby_node;
	Node* inspect_node;
	int i = 0;
	int j = 0;

	if (checked_nodes.count({ x + i,y + j }) == 0) {
		current_node = new Node{ x + i, y + j, calc_g_cost(x + i, y + j), calc_h_cost(x + i, y + j), nullptr };
		closed_nodes[{x + i, y + j}] = current_node;
	}
	else {
		current_node = checked_nodes.find({ x + i,y + j })->second;
		temp_g_cost = current_node->g_cost;
		closed_nodes[{x + i, y + j}] = current_node;
		checked_nodes.erase({ x + i, y + j });
	}

	if ((x + 1 == end_x && y == end_y) || (x == end_x && y + 1 == end_y) || (x - 1 == end_x && y == end_y) || (x == end_x && y - 1 == end_y)) {
		winning_node = current_node;
		return true;
	}

	i = 1; j = 0;
	if (x + i < width) {
		if (walls.count({ x + i,y + j }) == 0) {
			if (closed_nodes.count({ x + 1,y }) != 0) {
				inspect_node = closed_nodes[{x + 1, y}];
				if (inspect_node->g_cost + 10 < current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x - 1,y }) != 0) {
				inspect_node = closed_nodes[{x - 1, y}];
				if (inspect_node->g_cost + 10 < current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x,y + 1 }) != 0) {
				inspect_node = closed_nodes[{x, y + 1}];
				if (inspect_node->g_cost + 10 < current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x,y - 1 }) != 0) {
				inspect_node = closed_nodes[{x, y - 1}];
				if (inspect_node->g_cost + 10 < current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x + i,y + j }) == 0) {
				if (checked_nodes.count({ x + i,y + j }) == 0) {
					nearby_node = new Node{ x + i, y + j, temp_g_cost + 10, calc_h_cost(x + i, y + j), current_node };
					checked_nodes[{ x + i, y + j }] = nearby_node;
					pq.push(nearby_node);
				}
				else {
					nearby_node = checked_nodes.find({ x + i,y + j })->second;
					nearby_node->g_cost = temp_g_cost + 10;
					nearby_node->calc_f_cost();
				}
			}
		}
	}

	i = 0; j = 1;
	if (y + j < height) {
		if (walls.count({ x + i,y + j }) == 0) {
			if (closed_nodes.count({ x + 1,y }) != 0) {
				inspect_node = closed_nodes[{x + 1, y}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x - 1,y }) != 0) {
				inspect_node = closed_nodes[{x - 1, y}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x,y + 1 }) != 0) {
				inspect_node = closed_nodes[{x, y + 1}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x,y - 1 }) != 0) {
				inspect_node = closed_nodes[{x, y - 1}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x + i,y + j }) == 0) {
				if (checked_nodes.count({ x + i,y + j }) == 0) {
					nearby_node = new Node{ x + i, y + j, temp_g_cost + 10, calc_h_cost(x + i, y + j), current_node };
					checked_nodes[{ x + i, y + j }] = nearby_node;
					pq.push(nearby_node);
				}
				else {
					nearby_node = checked_nodes.find({ x + i,y + j })->second;
					nearby_node->g_cost = temp_g_cost + 10;
					nearby_node->calc_f_cost();
				}
			}
		}
	}

	i = -1; j = 0;
	if (x + i >= 0) {
		if (walls.count({ x + i,y + j }) == 0) {
			if (closed_nodes.count({ x + 1,y }) != 0) {
				inspect_node = closed_nodes[{x + 1, y}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x - 1,y }) != 0) {
				inspect_node = closed_nodes[{x - 1, y}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x,y + 1 }) != 0) {
				inspect_node = closed_nodes[{x, y + 1}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x,y - 1 }) != 0) {
				inspect_node = closed_nodes[{x, y - 1}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x + i,y + j }) == 0) {
				if (checked_nodes.count({ x + i,y + j }) == 0) {
					nearby_node = new Node{ x + i, y + j, temp_g_cost + 10, calc_h_cost(x + i, y + j), current_node };
					checked_nodes[{ x + i, y + j }] = nearby_node;
					pq.push(nearby_node);
				}
				else {
					nearby_node = checked_nodes.find({ x + i,y + j })->second;
					nearby_node->g_cost = temp_g_cost + 10;
					nearby_node->calc_f_cost();
				}
			}
		}
	}

	i = 0; j = -1;
	if (y + j >= 0) {
		if (walls.count({ x + i,y + j }) == 0) {
			if (closed_nodes.count({ x + 1,y }) != 0) {
				inspect_node = closed_nodes[{x + 1, y}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x - 1,y }) != 0) {
				inspect_node = closed_nodes[{x - 1, y}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x,y + 1 }) != 0) {
				inspect_node = closed_nodes[{x, y + 1}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x,y - 1 }) != 0) {
				inspect_node = closed_nodes[{x, y - 1}];
				if (inspect_node->g_cost + 10 <= current_node->g_cost)
				{
					current_node->g_cost = inspect_node->g_cost + 10;
					temp_g_cost = inspect_node->g_cost + 10;
				}
			}
			if (closed_nodes.count({ x + i,y + j }) == 0) {
				if (checked_nodes.count({ x + i,y + j }) == 0) {
					nearby_node = new Node{ x + i, y + j, temp_g_cost + 10, calc_h_cost(x + i, y + j), current_node };
					checked_nodes[{ x + i, y + j }] = nearby_node;
					pq.push(nearby_node);
				}
				else {
					nearby_node = checked_nodes.find({ x + i,y + j })->second;
					nearby_node->g_cost = temp_g_cost + 10;
					nearby_node->calc_f_cost();
				}
			}
		}
	}




	return false;
}

void Engine::reset()
{
	done = false;
	auto it1 = checked_nodes.begin();
	while (it1 != checked_nodes.end()) {
		delete it1->second;
		checked_nodes.erase(it1++);
	}
	auto it = closed_nodes.begin();
	while (it != closed_nodes.end()) {
		delete it->second;
		closed_nodes.erase(it++);
	}


	while (!pq.empty()) {
		auto node = pq.top();

		pq.pop();

	}

}
