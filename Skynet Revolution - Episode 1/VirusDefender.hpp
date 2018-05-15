#ifndef VIRUSDEFENDER_HPP
#define VIRUSDEFENDER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

class VirusDefender {
public:
	VirusDefender();
	~VirusDefender();
	
	void addLink(int, int);
	void setGatewayTo(int);
	string setVirusTo(int);
	
private:
	enum STATUS{NONE, GATEWAY, VIRUS};
	
	struct Link
	{
		int node0;
		int node1;
		bool blocked;
	};
	
	struct Node
	{
		STATUS status = NONE;
		vector<Link*> links;
		int width;
	};
	
	vector<int> gateways;
	map<int, Node*> network;
	
	Node* getNode(int const);
	inline Node* getNeighbor(Node* const, int);
	void clearNodes();
	Link* findGatewayLink(int, int, int&);
	bool isGatewayNeighbor(int, int);
};

#endif