
#include<string>

class treeNode;

class binaryTree
{
	public:
		binaryTree();
		~binaryTree();
		binaryTree( const binaryTree& copyTree );
		binaryTree& operator=( const binaryTree& copyTree );

		void insert( int key, const std::string& value );
		void deleteElement( int key);
		std::string search( int key ) const;

		void inorderTreeWalk() const ;
		void postorderTreeWalk() const;
		const treeNode* getRoot() const { return root; }	
		int size() const { return m_size; }
	private:
		treeNode* mp_root;
		int m_size;

};
