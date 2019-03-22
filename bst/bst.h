#pragma once
#include <memory>
#include <optional>




struct Node;


template < typename T >
class BST {

private:
	struct Node {
		Node( T key )
			: m_key( key ) {}

		Node* left() { return m_left.get(); }
		const Node* left() const { return m_left.get(); }

		Node* right() { return m_right.get(); }
		const Node* right() const { return m_right.get(); }

		Node* parent() { return m_parent; }
		const Node* parent() const { return m_parent; }

		T key() { return m_key; }
		const T key() const { return m_key; }

		std::unique_ptr< Node > m_left = nullptr;
		std::unique_ptr< Node > m_right = nullptr;
		Node* m_parent = nullptr;
		T m_key;
		friend BST;
	};
public:
	using value_type = T;
	using reference = T & ;
	using const_reference = const T &;

	BST() = default;
	BST( const BST& ) = delete;
	BST( BST&& ) = delete;
	BST& operator=( const BST& ) = delete;
	BST& operator=( BST&& ) = delete;


	void insert( const T& value ) {
		if ( m_root == nullptr ) {
			auto new_node = std::make_unique<Node>( value );
			m_root = std::move( new_node );
		}
		else {
			auto node = m_root.get();
			while ( node->right() != nullptr && node->left() != nullptr ) {
				if ( node->key() < value ) {
					node = node->right();
				}
				else {
					node = node->left();
				}
			}
			auto new_node = std::make_unique<Node>( value );
			if ( node->key() < value ) {
				node->m_right = std::move( new_node );
			}
			else {
				node->m_left = std::move( new_node );
			}
		}
	}

	Node* search( const T& value )			   { _search( *this, value );}
	const Node* search( const T& value ) const { _search( *this, value );	}

	Node* search( const Node* n )			  { return _search( *this, n ); }
	const Node* search( const Node* n ) const {	return _search( *this, n );	}

	Node* root()			 { return m_root.get(); }
	const Node* root() const { return m_root.get(); }


private:
	std::unique_ptr< Node > m_root = nullptr;
	friend Node;

	template < typename Self >
	auto _search( Self& self, const Node* n ) {
		auto node = m_root.get();
		while ( n != node && node != nullptr ) {
			if ( n->key() > node->key() ) {
				node = node->left();
			} else {
				node = node->right();
			}
		}
		return node;
	}

	template < typename Self >
	auto _search( Self& self, const T& value ) {
		auto node = m_root.get();
		while ( node != nullptr && node->key() != value ) {
			if ( value > node->key() ) {
				node = node->right();
			} else {
				node = node->left();
			}
		}
		return node;
	}


};
