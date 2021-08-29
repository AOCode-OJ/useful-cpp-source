////////////////////////////////////////////////
// File: stlp_list.h ///////////////////////////
////////////////////////////////////////////////

#include "declaring.h"

namespace stdplus {

	// list(normal)
	template <class T> class List {
		public:
			typedef T        value_type;
			typedef size_t   size_type;

		public:
			struct node {
				value_type val;
				node* pre,* next;
				node() : pre(NULL), next(NULL) {};
				node(const value_type& _val) : val(_val) {};
			};
			node *head, *tail;
			size_type len;
			bool is_sorted;

			node* newNode(const value_type& _val) {
				node* p = new node(_val);
				return p;
			}
			void make_loop() {
				head->pre = tail;
				tail->next = head;
			}
			void make_connect(node* &front, node* &back) {
				front->next = back;
				back->pre = front;
			}

		public:
			List() : head(NULL), tail(NULL), len(0), is_sorted(false) {};
			void push_back(const value_type& val) {
				if(head == NULL) {
					head = newNode(val);
					tail = head;
					make_loop();
					return;
				}
				node* p = newNode(val);
				make_connect(tail, p);
				tail = p;
				make_loop();
				len++;
				is_sorted = false;
			}
			void pop_back() {
				if(head == NULL) {
					std::cerr << "List Pop Error: EMPTY LIST!" << std::endl;
					exit(EXIT_FAILURE);
				}
				if(head == tail) {
					delete head;
					head = tail = NULL;
					return;
				}
				node* p = tail->pre;
				delete tail;
				tail = p;
				make_loop();
				len--;
			}
			void push_front(const value_type& val) {
				if(head == NULL) {
					head = newNode(val);
					tail = head;
					make_loop();
					return;
				}
				node* p = newNode(val);
				make_connect(p, head);
				head = p;
				make_loop();
				len++;
				is_sorted = false;
			}
			void pop_front() {
				if(head == NULL) {
					std::cerr << "List Pop Error: EMPTY LIST!" << std::endl;
					exit(EXIT_FAILURE);
				}
				if(head == tail) {
					delete head;
					head = tail = NULL;
				}
				node* p = head->next;
				delete head;
				head = p;
				make_loop();
				len--;
			}
			template <class compare> void sort(compare cmp = std::less<value_type>()) {
				node* fr, ba;
				node* p;
				while(p != tail) {
					fr = p;
					ba = fr->next;
					while(ba != head) {
						if(cmp(ba->val, fr->val))
							if(fr == head) {
								node* ne = ba->next;
								make_connect(ba, fr);
								make_connect(fr, ne);
								head = ba;
								make_loop();
							} else {
								node* pr = fr->pre, ne = ba->next;
								make_connect(ba, fr);
								make_connect(pr, ba);
								make_connect(fr, ne);
							}
						fr = ba;
						ba = fr->next;
					}
					p = p->next;
				}
				is_sorted = true;
			}
			template <class compare> void insert_sort(const value_type& val, compare cmp = std::less<value_type>()) {
				if(!is_sorted) {
					std::cerr << "List Insert_sort Error: THE LIST IS NOT SORTED! " << std::endl;
					exit(EXIT_FAILURE);
				}
				if(cmp(val, head->val)) {
					push_front(val);
					is_sorted = true;
					len++;
					return;
				}
				if(cmp(tail->val, val)) {
					push_back(val);
					is_sorted = true;
					len++;
					return;
				}
				node* p = head->next;
				while(p != tail && !cmp(p->val, val))
					p = p->next;
				p = p->pre;
				node* q = newNode(val);
				make_connect(q, p->next);
				make_connect(p, q);
				make_loop();
				is_sorted = true;
			}
			bool empty() const {
				return (head == NULL && tail == NULL && len == 0);
			}
			size_type size() const {
				return len;
			}
		private:
			node* get_pos(const int& pos) {
				int mid = len / 2;
				if(pos > mid) {
					node* p = tail;
					int pos_new = len - pos;
					for(int i = 1; i <= pos_new; i++)
						p = p->pre;
					return p;
				} else {
					node* p = head;
					for(int i = 1; i <= pos; i++)
						p = p->next;
					return p;
				}
			}
		public:
			void insert(const value_type& val, const int& which) {
				if(which > len) {
					std::cerr << "List Insert Error: INSERT PLACE OVERFLOW! " << std::endl;
					exit(EXIT_FAILURE);
				}
				if(which == 0) {
					push_front(val);
					len++;
					return;
				}
				if(which == len) {
					push_back(val);
					len++;
					return;
				}
				node* p = get_pos(which);
				node* q = newNode(val);
				make_connect(q, p->next);
				make_connect(p, q);
				make_loop();
				is_sorted = false;
				len++;
			}

			value_type& front() {
				if(empty()) {
					std::cout << "List Get Front Error: THE LIST IS EMPTY! " << std::endl;
					exit(EXIT_FAILURE);
				}
				return head->val;
			}
			const value_type& front() const {
				if(empty()) {
					std::cout << "List Get Front Error: THE LIST IS EMPTY! " << std::endl;
					exit(EXIT_FAILURE);
				}
				return head->val;
			}
			value_type& back() {
				if(empty()) {
					std::cout << "List Get Back Error: THE LIST IS EMPTY! " << std::endl;
					exit(EXIT_FAILURE);
				}
				return tail->val;
			}
			const value_type& back() const {
				if(empty()) {
					std::cout << "List Get Back Error: THE LIST IS EMPTY! " << std::endl;
					exit(EXIT_FAILURE);
				}
				return tail->val;
			}
	};

	// namespace stdplus
}