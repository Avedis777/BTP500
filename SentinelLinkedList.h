#include <iostream>
using namespace std;

template <typename T>
class SList{
	struct Node{
		T data_;
		Node* next_;
		Node(const T& data=T(),Node* next=nullptr){
			data_=data;
			next_=next;
		}
	};
	Node* front_;
	Node* back_;
public:
	SList(){
		front_=nullptr;
		back_=nullptr;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	~SList();
};

template <typename T>
void SList<T>::push_front(const T& data){
	Node* node = new Node(data,front_);
	if (front_ == nullptr)
		back_ =	node;
	front_ = node;
}

template <typename T>
void SList<T>::push_back(const T& data){
	Node* node = new Node(data, nullptr);
	if (front_ == nullptr)
		front_ = node;
	else
		back_->next_ = node;
	back_ = node;
}

template <typename T>
void SList<T>::pop_front(){
	Node* tmp = front_;
	if (front_ == back_){
		front_ = nullptr;
		back_ = nullptr;
	}
	if (front_ != nullptr)
		front_ = front_->next_;
	delete tmp;
}

template <typename T>
void SList<T>::pop_back(){
	Node* tmp = back_;
	if (front_ == back_){
		front_ = nullptr;
		back_ = nullptr;
	}
	if (front_ != nullptr){
		Node* node = front_;
		while(node){
			if(node->next_ == back_)
				break;
			node = node->next_;
		}
		node->next_ = nullptr;
		back_ = node;
	}
	delete tmp;
}

template <typename T>
void SList<T>::print() const{
	Node* curr=front_;
	while(curr){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	std::cout << std::endl;
}

template <typename T>
SList<T>::~SList(){
	Node* curr=front_;
	while(curr){
		Node* rm=curr;
		curr=curr->next_;
		delete rm;
	}
}

template <typename T>
class Sentinel{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T(),Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	Sentinel(){
		front_=new Node();
		back_=new Node();
		front_->next_=back_;
		back_->prev_=front_;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	void print() const;
	void reversePrint() const;
	~Sentinel();
};

template <typename T>
void Sentinel<T>::push_front(const T& data){
	Node* node = new Node(data,front_->next_, front_);
		front_->next_->prev_ = node;
		front_->next_ = node;
}

template <typename T>
void Sentinel<T>::push_back(const T& data){
	Node* node = new Node(data, back_, back_->prev_);
		back_->prev_->next_ = node;
		back_->prev_ = node;
}

template <typename T>
void Sentinel<T>::pop_front(){
	if (front_->next_ != back_){
		Node* tmp = front_->next_;
		front_->next_ = front_->next_->next_;
		front_->next_->prev_ = front_;
		delete tmp;
	}
}

template <typename T>
void Sentinel<T>::pop_back(){
	if (front_->next_ != back_){
		Node* tmp = back_->prev_;
		back_->prev_ = back_->prev_->prev_;
		back_->prev_->next_ = back_;
		delete tmp;
	}
}

template <typename T>
void Sentinel<T>::print() const{
	Node* curr=front_->next_;
	while(curr!=back_){
		std::cout << curr->data_ << " ";
		curr=curr->next_;
	}
	std::cout << std::endl;
}

template <typename T>
void Sentinel<T>::reversePrint() const{
	Node* curr=back_->prev_;
	while(curr!=front_){
		std::cout << curr->data_ << " ";
		curr=curr->prev_;
	}
	std::cout << std::endl;
}

template <typename T>
Sentinel<T>::~Sentinel(){
	Node* curr=front_;
	while(curr){
		Node* rm=curr;
		curr=curr->next_;
		delete rm;
	}
}