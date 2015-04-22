#include "graph.hpp"

int main( int argc, char **argv )
{
  std::ios::sync_with_stdio( false );
  std::cin.tie( 0 );
  
  int num_node;
  std::cin >> num_node;

  std::vector<std::vector<int> > graph( num_node );
  
  int num_edge;
  int node1;
  int node2;
  int start_node;

  std::cin >> num_edge;
  FOR(i,0,num_edge)
	{
	  std::cin >> node1 >> node2;
	  graph[node1].push_back( node2 );
	  graph[node2].push_back( node1 );
	}
  std::cin >> start_node;

  std::vector<int> visited_nodes;

  bfs<int>( graph, start_node, visited_nodes );

  return EXIT_SUCCESS;
}

template<typename T>
inline void bfs( std::vector<std::vector<T> > graph, T start_node, std::vector<T> visited_nodes )
{
  std::queue<T> q;
  q.push(start_node);
    while ( q.size() )
	{
	  T node1 = q.front();
	  q.pop();
	  std::cout << node1 << std::endl;
	  visited_nodes.push_back(node1);
	  for ( T node2 : graph[node1] )
		{
		  bool is_push = true;
		  for ( T visit_node : visited_nodes )
			{
			  if ( visit_node == node2 )
				{
				  is_push = false;
				  break;
				}
			}
		  if ( is_push ) q.push(node2);
		}
	}
}

template<typename T>
inline void dfs( std::vector<std::vector<T> > graph, T start_node, std::vector<T> visited_nodes )
{
  std::stack<T> s;
  s.push(start_node);
  while ( s.size() )
	{
	  T node1 = s.top();
	  s.pop();
	  std::cout << node1 << std::endl;
	  visited_nodes.push_back(node1);
	  for ( T node2 : graph[node1] )
		{
		  bool is_push = true;
		  for ( T visit_node : visited_nodes )
			{
			  if ( visit_node == node2 )
				{
				  is_push = false;
				  break;
				}
			}
		  if ( is_push ) s.push(node2);
		}
	}
}

