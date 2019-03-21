#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Stack {
public:
	using value_type      = T;
	using reference	      = T & ;
	using const_reference = const T &;

	Stack() = default;
	Stack( std::initializer_list<T> list )
		: m_size( list.size() )
	{
		m_buffer.reserve( m_size );
		for ( auto& item : list ) { m_buffer.push_back( item ); } 
	}

	template <typename Arg>
	Stack( std::size_t count, Arg&& args )
		: m_size( count ) 
	{
		for ( int i = 0; i < count; ++i ) { m_buffer.push_back( std::forward<Arg>( args ) ); }
	}

	Stack( const Stack& ) = default;
	Stack( Stack&& ) = default;
	Stack& operator=( const Stack& ) = default;
	Stack& operator=( Stack&& ) = default;

	template <typename Arg>
	void push( Arg&& args ) {
		++m_size;
		m_buffer.push_back( std::forward<Arg>( args ));
	}

	template <typename Arg> 
	void emplace( Arg&& args ) {
		++m_size;
		m_buffer.emplace_back( std::forward<Arg>( args ) );
	}

	void swap( Stack<T>& other ) {
		using std::swap;
		std::swap( m_buffer, other.m_buffer );
		std::swap( m_size, other.m_size );
	}

	void pop() {
		if ( !empty() ) {
			--m_size;
		}
	}

	reference top()				{ return _top( *this ); }
	const_reference top() const { return _top( *this ); }

	bool empty() const { return m_size == 0; }
	std::size_t size() const { return m_size; }

private:
	std::vector<T> m_buffer;
	std::size_t m_size = 0;

	template < typename Self >
	static auto& _top( Self& self ){
		if ( self.empty() ) {
		    throw std::logic_error::logic_error( "Calling top on empty stack!" );
		} 
		return self.m_buffer[ self.m_size - 1 ];
	}
};

