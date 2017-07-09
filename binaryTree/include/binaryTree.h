
#include<string>

class treeNode;

class binaryTree
{
	public:
		binaryTree();
		~binaryTree();
		void insert( int key, const std::string& value );
		std::string search( int key ) const;
		const treeNode* getRoot() const { return root; }	
		int size() const { return m_size; }
	private:
		treeNode* root;
		int m_size;

};
