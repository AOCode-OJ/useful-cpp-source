/****************************************
********** File: stlp_bst.h 
****************************************/

//#include <bits/stdc++.h>

#include "declaring.h"

#ifndef _STDPLUS_STLP_BST_H_
#define _STDPLUS_STLP_BST_H_ 1

namespace stdplus {

	// Binary Search(Sort) Tree
	template <class T> class BST {
		public:
			typedef T value_type;

		public:
			struct node {
				value_type data;
				node* lchild;
				node* rchild;
				node() : data(value_type()), lchild(nullptr), rchild(nullptr) {}
			};
			node* newNode(const value_type& x) {
				node* Node = new node;
				Node->data = x;
				Node->lchild = Node->rchild = nullptr;
				return Node;
			}
			int len;

		public:
			// Public Declarations
			node* root;
			BST() : root(nullptr) {}
			value_type findMax(node* p) {
				while(p->rchild != nullptr)
					p = p->rchild;
				return p.data;
			}
			value_type findMin(node* p) {
				while(p->lchild != nullptr)
					p = p->lchild;
				return p.data;
			}
			bool find(value_type x, node* p) {
				if(p == nullptr)
					return false;

				if(p->data == x)
					return true;
				else if(p->data > x)
					return find(x, p->lchild);
				else return find(x, p->rchild);
			}
			void insert(value_type x, node* &p) {
				if(p == nullptr) {
					p = newNode(x);
					return;
				}

				if(x < p->data)
					insert(x, p->lchild);
				else
					insert(x, p->rchild);
			}
			void erase(value_type x, node* p) {
				if(p == nullptr)
					return;
				if(p->data == x) {
					if(p->lchild == nullptr && p->rchild == nullptr)
						p = nullptr;
					else if(p->lchild != nullptr) {
						node* pre = findMax(p->lchild);
						p->data = pre->data;
						erase(pre->data, p->lchild);
					} else {
						node* next = findMin(p->rchild);
						p->data = next->data;
						erase(next->data, p->rchild);
					}
				} else if(x < p->data)
					erase(x, p->lchild);
				else
					erase(x, p->rchild);
			}
			void create(value_type data[], int n) {
				for(int i = 1; i <= n; i++)
					insert(data[i]);
			}
			// preorder
			template <class thingdone> void preorder(thingdone do_sth, node* p) {
				if(p == nullptr)
					return;

				do_sth(p->data);
				preorder(do_sth, p->lchild);
				preorder(do_sth, p->rchild);
			}
			// inorder
			template <class thingdone> void inorder(thingdone do_sth, node* p) {
				if(p == nullptr)
					return;

				inorder(do_sth, p->lchild);
				do_sth(p->data);
				inorder(do_sth, p->rchild);
			}
			// postorder
			template <class thingdone> void postorder(thingdone do_sth, node* p) {
				if(p == nullptr)
					return;

				postorder(do_sth, p->lchild);
				postorder(do_sth, p->rchild);
				do_sth(p->data);
			}
			// LayerOrder
			template <class thingdone> void LayerOrder(thingdone do_sth, node* p) {
				if(p == nullptr)
					return;
				std::queue<node*> q;
				q.push(p);
				while(!q.empty()) {
					node* now = q.front();
					q.pop();
					do_sth(now->data);
					if(now->lchild != nullptr)
						q.push(now->lchild);
					if(now->rchild != nullptr)
						q.push(now->rchild);
				}
			}
			value_type get(int pos) {
				if(pos == 1)
					return root->data;
				int tot = 1;
				std::queue<node* > q;
				q.push(root->lchild);
				q.push(root->rchild);
				while(!q.empty()) {
					node* now = q.front();
					q.pop();
					if(now == nullptr)
						continue;
					tot++;
					if(tot == pos)
						return now->data;
				}
				if(tot < pos) {
					std::cerr << "Binary_tree get ERROR: POS OVERFLOW!" << std::endl;
					exit(EXIT_FAILURE);
				}
			}
	};

	template <class T> T max(const BST<T>& bst) {
		return bst.findMax(bst.rt);
	}
	template <class T> T min(const BST<T>& bst) {
		return bst.findMin(bst.rt);
	}

	// AVL tree (update for BST)
	template <class T> class AVL {
		public:
			typedef T value_type;

		public:
			// Private section
			struct node {
				value_type data;
				node* lchild;
				node* rchild;
				int height;
			};
			node* newNode(const value_type& x) {
				node* p = new node;
				p->data = x;
				p->height = 1;
				p->lchild = p->rchild = nullptr;
				return p;
			}
			int getHeight(node* root) {
				if(root == nullptr)
					return 0;
				return root->height;
			}
			int getBalanceFactor(node* root) {
				return getHeight(root->lchild) - getHeight(root->rchild);
			}
			void updateHeight(node* root) {
				root->height = max(getHeight(root->lchild), getHeight(root->rchild) + 1);
			}
			// Left Rotation
			void L(node*& root) {
				node* temp = root->rchild;
				root->rchild = temp->lchild;
				temp->lchild = root;
				updateHeight(root);
				updateHeight(temp);
				root = temp;
			}
			// Right Rotation
			void R(node*& root) {
				node* temp = root->lchild;
				root->lchild = temp->rchild;
				temp->rchild = root;
				updateHeight(root);
				updateHeight(temp);
				root = temp;
			}

		public:
			// Public Declarations
			node* root;

			node* find(value_type x, node* root) {
				if(root == nullptr)
					return nullptr;

				if(root->data == x)
					return root;
				else if(root->data > x)
					return find(x, root->lchild);
				else return find(x, root->rchild);
			}
			void insert(value_type x, node* &p) {
				if(p == nullptr) {
					p = newNode(x);
					return;
				}

				if(x < p->data) {
					insert(x, p->lchild);
					updateHeight(p);
					if(getBalanceFactor(p->lchild) == 1)
						R(p);
					else if(getBalanceFactor(p->lchild) == -1) {
						L(p->lchild);
						R(p);
					}
				} else {
					insert(x, p->rchild);
					updateHeight(p);
					if(getBalanceFactor(p) == -2) {
						if(getBalanceFactor(p->rchild) == -1)
							L(p);
						else if(getBalanceFactor(p->rchild) == 1) {
							R(p->rchild);
							L(p);
						}
					}
				}
			}
			void Create(value_type data, int n) {
				node* root = nullptr;
				for(int i = 1; i <= n; i++)
					insert(data[i], root);
			}
			// preorder
			template <class thingdone> void preorder(thingdone do_sth, node* root) {
				if(root == nullptr)
					return;

				do_sth(root->data);
				preorder(root->lchild, do_sth);
				preorder(root->rchild, do_sth);
			}
			// inorder
			template <class thingdone> void inorder(thingdone do_sth, node* root) {
				if(root == nullptr)
					return;

				inorder(root->lchild, do_sth);
				do_sth(root->data);
				inorder(root->rchild, do_sth);
			}
			// postorder
			template <class thingdone> void postorder(thingdone do_sth, node* root) {
				if(root == nullptr)
					return;

				postorder(root->lchild, do_sth);
				postorder(root->rchild, do_sth);
				do_sth(root);
			}
			// LayerOrder
			template <class thingdone> void LayerOrder(thingdone do_sth, node* root) {
				std::queue<node* > q;
				q.push(root);
				while(!q.empty()) {
					node* now = q.front();
					q.pop();
					do_sth(now);
					if(now->lchild != nullptr)
						q.push(now->lchild);
					if(now->rchild != nullptr)
						q.push(now->rchild);
				}
			}
	};
	
	// namespace stdplus
}

#endif // _STDPLUS_STLP_BST_H_

// end file
